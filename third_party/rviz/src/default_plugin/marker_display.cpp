/*
 * Copyright (c) 2008, Willow Garage, Inc.
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
 */

#include "marker_display.h"
#include "rviz/visualization_manager.h"
#include "rviz/properties/property_manager.h"
#include "rviz/properties/property.h"
#include "rviz/common.h"
#include "rviz/selection/selection_manager.h"
#include "markers/shape_marker.h"
#include "markers/arrow_marker.h"
#include "markers/line_list_marker.h"
#include "markers/line_strip_marker.h"
#include "markers/sphere_list_marker.h"
#include "markers/cube_list_marker.h"
#include "markers/points_marker.h"

#include <ogre_tools/arrow.h>
#include <ogre_tools/shape.h>
#include <ogre_tools/billboard_line.h>

#include <tiny_ros/tf/transform_listener.h>

#include <OGRE/OgreSceneNode.h>
#include <OGRE/OgreSceneManager.h>

namespace rviz
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

MarkerDisplay::MarkerDisplay( const std::string& name, VisualizationManager* manager )
: Display( name, manager )
, tf_filter_(*manager->getTFClient(), "", 1000)
, marker_topic_("visualization_marker")
, array_sub_(new tinyros::Subscriber<tinyros::visualization_msgs::MarkerArray, MarkerDisplay>("", &MarkerDisplay::incomingMarkerArray, this))
{
  scene_node_ = scene_manager_->getRootSceneNode()->createChildSceneNode();

  tf_filter_.registerCallback(std::bind(&MarkerDisplay::incomingMarker, this, std::placeholders::_1));
}

MarkerDisplay::~MarkerDisplay()
{
  unsubscribe();

  clearMarkers();
}

MarkerBasePtr MarkerDisplay::getMarker(MarkerID id)
{
  M_IDToMarker::iterator it = markers_.find(id);
  if (it != markers_.end())
  {
    return it->second;
  }

  return MarkerBasePtr();
}

void MarkerDisplay::clearMarkers()
{
  markers_.clear();
  markers_with_expiration_.clear();
  tf_filter_.clear();
}

void MarkerDisplay::onEnable()
{
  subscribe();

  scene_node_->setVisible( true );
}

void MarkerDisplay::onDisable()
{
  unsubscribe();
  tf_filter_.clear();

  clearMarkers();

  scene_node_->setVisible( false );
}

void MarkerDisplay::setMarkerTopic(const std::string& topic)
{
  unsubscribe();
  marker_topic_ = topic;
  subscribe();

  propertyChanged(marker_topic_property_);
}

void MarkerDisplay::subscribe()
{
  if ( !isEnabled() )
  {
    return;
  }

  if (!marker_topic_.empty())
  {
  tf_filter_.connectInput(marker_topic_);
  tf_filter_.connectEnable(true);
  
    if (array_sub_->topic_.empty()) {
      array_sub_->topic_ = marker_topic_ + "_array";
      tinyros::nh()->subscribe(*array_sub_);
    } else if (array_sub_->topic_ != (marker_topic_ + "_array")) {
    array_sub_->setEnabled(false);
      array_sub_ = new tinyros::Subscriber<tinyros::visualization_msgs::MarkerArray, MarkerDisplay>
      (marker_topic_ + "_array", &MarkerDisplay::incomingMarkerArray, this);
      tinyros::nh()->subscribe(*array_sub_);
    }
  array_sub_->setEnabled(true);
  }
}

void MarkerDisplay::unsubscribe()
{
  tf_filter_.connectEnable(false);
  array_sub_->setEnabled(false);
}

void MarkerDisplay::incomingMarkerArray(const tinyros::visualization_msgs::MarkerArrayConstPtr& array)
{
  std::vector<tinyros::visualization_msgs::Marker>::const_iterator it = array->markers.begin();
  std::vector<tinyros::visualization_msgs::Marker>::const_iterator end = array->markers.end();
  for (; it != end; ++it)
  {
    const tinyros::visualization_msgs::Marker& marker = *it;
    tf_filter_.add(tinyros::visualization_msgs::MarkerPtr(new tinyros::visualization_msgs::Marker(marker)));
  }
}

void MarkerDisplay::incomingMarker( const tinyros::visualization_msgs::MarkerConstPtr& message )
{
  std::scoped_lock lock(queue_mutex_);

  message_queue_.push_back( message );
}

void MarkerDisplay::processMessage( const tinyros::visualization_msgs::MarkerConstPtr& message )
{
  switch ( message->action )
  {
  case tinyros::visualization_msgs::Marker::ADD:
    processAdd( message );
    break;

  case tinyros::visualization_msgs::Marker::DELETE:
    processDelete( message );
    break;

  default:
    tinyros_log_error( "Unknown marker action: %d\n", message->action );
  }
}

void MarkerDisplay::processAdd( const tinyros::visualization_msgs::MarkerConstPtr& message )
{
  bool create = true;

  MarkerBasePtr marker;

  M_IDToMarker::iterator it = markers_.find( MarkerID(message->ns, message->id) );
  if ( it != markers_.end() )
  {
    marker = it->second;
    markers_with_expiration_.erase(marker);
    if ( message->type == marker->getMessage()->type )
    {
      create = false;
    }
    else
    {
      markers_.erase( it );
    }
  }

  if ( create )
  {
    switch ( message->type )
    {
    case tinyros::visualization_msgs::Marker::CUBE:
    case tinyros::visualization_msgs::Marker::CYLINDER:
    case tinyros::visualization_msgs::Marker::SPHERE:
      {
        marker.reset(new ShapeMarker(vis_manager_, scene_node_));
      }
      break;

    case tinyros::visualization_msgs::Marker::ARROW:
      {
        marker.reset(new ArrowMarker(vis_manager_, scene_node_));
      }
      break;

    case tinyros::visualization_msgs::Marker::LINE_STRIP:
      {
        marker.reset(new LineStripMarker(vis_manager_, scene_node_));
      }
      break;
    case tinyros::visualization_msgs::Marker::LINE_LIST:
      {
        marker.reset(new LineListMarker(vis_manager_, scene_node_));
      }
      break;
    case tinyros::visualization_msgs::Marker::CUBE_LIST:
      {
        marker.reset(new CubeListMarker(vis_manager_, scene_node_));
      }
      break;
    case tinyros::visualization_msgs::Marker::SPHERE_LIST:
      {
        marker.reset(new SphereListMarker(vis_manager_, scene_node_));
      }
      break;
    case tinyros::visualization_msgs::Marker::POINTS:
      {
        marker.reset(new PointsMarker(vis_manager_, scene_node_));
      }
      break;
    default:
      tinyros_log_error( "Unknown marker type: %d", message->type );
    }

    markers_.insert(std::make_pair(MarkerID(message->ns, message->id), marker));
  }

  if (marker)
  {
    marker->setMessage(message);

    if (message->lifetime.toSec() > 0.0001f)
    {
      markers_with_expiration_.insert(marker);
    }

    causeRender();
  }
}

void MarkerDisplay::processDelete( const tinyros::visualization_msgs::MarkerConstPtr& message )
{
  M_IDToMarker::iterator it = markers_.find( MarkerID(message->ns, message->id) );
  if ( it != markers_.end() )
  {
    markers_.erase( it );
  }

  causeRender();
}

void MarkerDisplay::update(float wall_dt, float ros_dt)
{
  V_MarkerMessage local_queue;

  {
    std::scoped_lock lock(queue_mutex_);

    local_queue.swap( message_queue_ );
  }

  if ( !local_queue.empty() )
  {
    V_MarkerMessage::iterator message_it = local_queue.begin();
    V_MarkerMessage::iterator message_end = local_queue.end();
    for ( ; message_it != message_end; ++message_it )
    {
      tinyros::visualization_msgs::MarkerConstPtr& marker = *message_it;

      processMessage( marker );
    }
  }

  S_MarkerBase::iterator it = markers_with_expiration_.begin();
  S_MarkerBase::iterator end = markers_with_expiration_.end();
  for (; it != end;)
  {
    MarkerBasePtr marker = *it;
    if (marker->expired())
    {
      S_MarkerBase::iterator copy = it;
      ++it;
      markers_with_expiration_.erase(copy);
      markers_.erase(MarkerID(marker->getMessage()->ns, marker->getMessage()->id));
    }
    else
    {
      ++it;
    }
  }
}

void MarkerDisplay::targetFrameChanged()
{
}

void MarkerDisplay::fixedFrameChanged()
{
  tf_filter_.setTargetFrame( fixed_frame_ );

  clearMarkers();
}

void MarkerDisplay::reset()
{
  clearMarkers();
}

void MarkerDisplay::createProperties()
{
  marker_topic_property_ = property_manager_->createProperty<ROSTopicStringProperty>( "Marker Topic", property_prefix_, std::bind( &MarkerDisplay::getMarkerTopic, this ),
                                                                                std::bind( &MarkerDisplay::setMarkerTopic, this, std::placeholders::_1 ), parent_category_, this );
  ROSTopicStringPropertyPtr topic_prop = marker_topic_property_.lock();
  topic_prop->setMessageType(tinyros::visualization_msgs::Marker::getTypeStatic());
}

} // namespace rviz
