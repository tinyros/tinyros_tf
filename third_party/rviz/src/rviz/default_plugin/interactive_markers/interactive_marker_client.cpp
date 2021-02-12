/*
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * 
 * Author: David Gossow
 */

#include "interactive_marker_client.h"
#include "single_client.h"

#include <boost/bind.hpp>
#include <boost/make_shared.hpp>

#define DBG_MSG(format, ...) tinyros::mtrace(tinyros::tinyros_msgs::Log::ROSDEBUG, format, ##__VA_ARGS__)

namespace rviz
{

InteractiveMarkerClient::InteractiveMarkerClient(
    tinyros::tf::Transformer& tf,
    const std::string& target_frame,
    const std::string &topic_ns )
: state_("InteractiveMarkerClient",IDLE)
, tf_(tf)
, last_num_publishers_(0)
, enable_autocomplete_transparency_(true)
, update_sub_(new tinyros::Subscriber<tinyros::visualization_msgs::InteractiveMarkerUpdate, InteractiveMarkerClient>("", &InteractiveMarkerClient::processUpdate, this))
, init_sub_(new tinyros::Subscriber<tinyros::visualization_msgs::InteractiveMarkerInit, InteractiveMarkerClient>("", &InteractiveMarkerClient::processInit, this))
{
  target_frame_ = target_frame;
  if ( !topic_ns.empty() )
  {
    subscribe( topic_ns );
  }
  callbacks_.setStatusCb( boost::bind( &InteractiveMarkerClient::statusCb, this, _1, _2, _3 ) );
}

InteractiveMarkerClient::~InteractiveMarkerClient()
{
  shutdown();
}

/// Subscribe to given topic
void InteractiveMarkerClient::subscribe( std::string topic_ns )
{
  topic_ns_ = topic_ns;
  subscribeUpdate();
  subscribeInit();
}

void InteractiveMarkerClient::setInitCb( const InitCallback& cb )
{
  callbacks_.setInitCb( cb );
}

void InteractiveMarkerClient::setUpdateCb( const UpdateCallback& cb )
{
  callbacks_.setUpdateCb( cb );
}

void InteractiveMarkerClient::setResetCb( const ResetCallback& cb )
{
  callbacks_.setResetCb( cb );
}

void InteractiveMarkerClient::setStatusCb( const StatusCallback& cb )
{
  status_cb_ = cb;
}

void InteractiveMarkerClient::setTargetFrame( std::string target_frame )
{
  target_frame_ = target_frame;
  DBG_MSG("Target frame is now %s", target_frame_.c_str() );

  switch ( state_ )
  {
  case IDLE:
    break;

  case INIT:
  case RUNNING:
    shutdown();
    subscribeUpdate();
    subscribeInit();
    break;
  }
}

void InteractiveMarkerClient::shutdown()
{
  switch ( state_ )
  {
  case IDLE:
    break;

  case INIT:
  case RUNNING:
    init_sub_->setEnabled(false);
    update_sub_->setEnabled(false);
    boost::lock_guard<boost::mutex> lock(publisher_contexts_mutex_);
    publisher_contexts_.clear();
    last_num_publishers_=0;
    state_=IDLE;
    break;
  }
}

void InteractiveMarkerClient::subscribeUpdate()
{
  if ( !topic_ns_.empty() )
  {
    try
    {
      std::string topic = topic_ns_+"/update";
      if (update_sub_->topic_.empty()) {
        update_sub_->topic_ = topic;
        tinyros::nh()->subscribe(*update_sub_);
      } else if (update_sub_->topic_ != topic) {
        update_sub_->setEnabled(false);
        update_sub_ = new tinyros::Subscriber<tinyros::visualization_msgs::InteractiveMarkerUpdate, 
          InteractiveMarkerClient>(topic, &InteractiveMarkerClient::processUpdate, this);
        tinyros::nh()->subscribe(*update_sub_);
      }
      update_sub_->setEnabled(true);
    }
    catch( std::exception& e )
    {
      callbacks_.statusCb( ERROR, "General", "Error subscribing: " + std::string(e.what()) );
      return;
    }
  }
  callbacks_.statusCb( OK, "General", "Waiting for messages.");
}

void InteractiveMarkerClient::subscribeInit()
{
  if ( state_ != INIT && !topic_ns_.empty() )
  {
    try
    {
      DBG_MSG( "Subscribed to init topic: %s", (topic_ns_+"/update_full").c_str() );
      std::string topic = topic_ns_+"/update_full";
      if (init_sub_->topic_.empty()) {
        init_sub_->topic_ = topic;
        tinyros::nh()->subscribe(*init_sub_);
      } else if (init_sub_->topic_ != topic) {
        init_sub_->setEnabled(false);
        init_sub_ = new tinyros::Subscriber<tinyros::visualization_msgs::InteractiveMarkerInit, 
          InteractiveMarkerClient>(topic, &InteractiveMarkerClient::processInit, this);
        tinyros::nh()->subscribe(*init_sub_);
      }
      init_sub_->setEnabled(true);
      
      state_ = INIT;
    }
    catch( std::exception& e )
    {
      callbacks_.statusCb( ERROR, "General", "Error subscribing: " + std::string(e.what()) );
    }
  }
}

template<class MsgConstPtrT>
void InteractiveMarkerClient::process( const MsgConstPtrT& msg )
{
  callbacks_.statusCb( OK, "General", "Receiving messages.");

  // get caller ID of the sending entity
  if ( msg->server_id.empty() )
  {
    callbacks_.statusCb( ERROR, "General", "Received message with empty server_id!");
    return;
  }

  SingleClientPtr client;
  {
    boost::lock_guard<boost::mutex> lock(publisher_contexts_mutex_);

    M_SingleClient::iterator context_it = publisher_contexts_.find(msg->server_id);

    // If we haven't seen this publisher before, we need to reset the
    // display and listen to the init topic, plus of course add this
    // publisher to our list.
    if ( context_it == publisher_contexts_.end() )
    {
      DBG_MSG( "New publisher detected: %s", msg->server_id.c_str() );

      SingleClientPtr pc(new SingleClient( msg->server_id, tf_, target_frame_, callbacks_ ));
      context_it = publisher_contexts_.insert( std::make_pair(msg->server_id,pc) ).first;
      client = pc;

      // we need to subscribe to the init topic again
      subscribeInit();
    }

    client = context_it->second;
  }

  // forward init/update to respective context
  client->process( msg, enable_autocomplete_transparency_ );
}

void InteractiveMarkerClient::processInit( const InitConstPtr& msg )
{
  process<InitConstPtr>(msg);
}

void InteractiveMarkerClient::processUpdate( const UpdateConstPtr& msg )
{
  process<UpdateConstPtr>(msg);
}

void InteractiveMarkerClient::update()
{
  switch ( state_ )
  {
  case IDLE:
    break;

  case INIT:
  case RUNNING:
  {
    // check if one publisher has gone offline
    if ( update_sub_.getNumPublishers() < last_num_publishers_ )
    {
      callbacks_.statusCb( ERROR, "General", "Server is offline. Resetting." );
      shutdown();
      subscribeUpdate();
      subscribeInit();
      return;
    }
    last_num_publishers_ = update_sub_.getNumPublishers();

    // check if all single clients are finished with the init channels
    bool initialized = true;
    boost::lock_guard<boost::mutex> lock(publisher_contexts_mutex_);
    M_SingleClient::iterator it;
    for ( it = publisher_contexts_.begin(); it!=publisher_contexts_.end(); ++it )
    {
      // Explicitly reference the pointer to the client here, because the client
      // might call user code, which might call shutdown(), which will delete
      // the publisher_contexts_ map...

      SingleClientPtr single_client = it->second;
      single_client->update();
      if ( !single_client->isInitialized() )
      {
        initialized = false;
      }

      if ( publisher_contexts_.empty() )
        break; // Yep, someone called shutdown()...
    }
    if ( state_ == INIT && initialized )
    {
      init_sub_.shutdown();
      state_ = RUNNING;
    }
    if ( state_ == RUNNING && !initialized )
    {
      subscribeInit();
    }
    break;
  }
  }
}

void InteractiveMarkerClient::statusCb( StatusT status, const std::string& server_id, const std::string& msg )
{
  switch ( status )
  {
  case OK:
    DBG_MSG( "%s: %s (Status: OK)", server_id.c_str(), msg.c_str() );
    break;
  case WARN:
    DBG_MSG( "%s: %s (Status: WARNING)", server_id.c_str(), msg.c_str() );
    break;
  case ERROR:
    DBG_MSG( "%s: %s (Status: ERROR)", server_id.c_str(), msg.c_str() );
    break;
  }

  if ( status_cb_ )
  {
    status_cb_( status, server_id, msg );
  }
}

}
