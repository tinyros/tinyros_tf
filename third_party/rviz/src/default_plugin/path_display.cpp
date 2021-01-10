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

#include "path_display.h"
#include "rviz/visualization_manager.h"
#include "rviz/properties/property.h"
#include "rviz/properties/property_manager.h"
#include "rviz/common.h"

#include "ogre_tools/arrow.h"

#include <tiny_ros/tf/transform_listener.h>

#include <functional>

#include <OGRE/OgreSceneNode.h>
#include <OGRE/OgreSceneManager.h>
#include <OGRE/OgreManualObject.h>
#include <OGRE/OgreBillboardSet.h>

namespace rviz
{

PathDisplay::PathDisplay( const std::string& name, VisualizationManager* manager )
: Display( name, manager )
, color_( 0.1f, 1.0f, 0.0f )
, tf_filter_(*manager->getTFClient(), "", 10, update_nh_)
{
  scene_node_ = scene_manager_->getRootSceneNode()->createChildSceneNode();

  static int count = 0;
  std::stringstream ss;
  ss << "Path" << count++;
  manual_object_ = scene_manager_->createManualObject( ss.str() );
  manual_object_->setDynamic( true );
  scene_node_->attachObject( manual_object_ );

  setAlpha( 1.0f );

  tf_filter_.registerCallback(std::bind(&PathDisplay::incomingMessage, this, std::placeholders::_1));
}

PathDisplay::~PathDisplay()
{
  unsubscribe();
  clear();

  scene_manager_->destroyManualObject( manual_object_ );
  scene_manager_->destroySceneNode(scene_node_->getName());
}

void PathDisplay::clear()
{
  manual_object_->clear();
}

void PathDisplay::setTopic( const std::string& topic )
{
  unsubscribe();

  topic_ = topic;

  subscribe();

  propertyChanged(topic_property_);

  causeRender();
}

void PathDisplay::setColor( const Color& color )
{
  color_ = color;

  propertyChanged(color_property_);

  processMessage(current_message_);
  causeRender();
}

void PathDisplay::setAlpha( float alpha )
{
  alpha_ = alpha;

  propertyChanged(alpha_property_);

  processMessage(current_message_);
  causeRender();
}

void PathDisplay::subscribe()
{
  if ( !isEnabled() )
  {
    return;
  }

  tf_filter_.connectInput(topic_);
  tf_filter_.connectEnable(true);
}

void PathDisplay::unsubscribe()
{
  tf_filter_.connectEnable(false);
}

void PathDisplay::onEnable()
{
  scene_node_->setVisible( true );
  subscribe();
}

void PathDisplay::onDisable()
{
  unsubscribe();
  clear();
  scene_node_->setVisible( false );
}

void PathDisplay::fixedFrameChanged()
{
  clear();

  tf_filter_.setTargetFrame( fixed_frame_ );
}

void PathDisplay::update(float wall_dt, float ros_dt)
{
}

void PathDisplay::processMessage(const tinyros::nav_msgs::PathConstPtr& msg)
{
  if (!msg)
  {
    return;
  }

  clear();

  std::string frame_id = msg->header.frame_id;
  if (frame_id.empty())
  {
    frame_id = "/map";
  }

  tinyros::tf::Stamped<tinyros::tf::Pose> pose( tinyros::tf::Transform( tinyros::tf::Quaternion( 0.0f, 0.0f, 0.0f, 1.0f ), tinyros::tf::Vector3( 0.0f, 0.0f, 0.0f ) ),
                                tinyros::Time(), frame_id);

  if (vis_manager_->getTFClient()->canTransform(fixed_frame_, frame_id, tinyros::Time()))
  {
    try
    {
      vis_manager_->getTFClient()->transformPose( fixed_frame_, pose, pose );
    }
    catch(tinyros::tf::TransformException& e)
    {
      tinyros_log_error( "Error transforming from frame 'map' to frame '%s'", fixed_frame_.c_str() );
    }
  }

  Ogre::Vector3 position = Ogre::Vector3( pose.getOrigin().x(), pose.getOrigin().y(), pose.getOrigin().z() );
  robotToOgre( position );

  tinyros::tf::Quaternion quat;
  pose.getBasis().getRotation( quat );
  Ogre::Quaternion orientation( Ogre::Quaternion::IDENTITY );
  ogreToRobot( orientation );
  orientation = Ogre::Quaternion( quat.w(), quat.x(), quat.y(), quat.z() ) * orientation;
  robotToOgre( orientation );

  scene_node_->setPosition( position );
  scene_node_->setOrientation( orientation );

  manual_object_->clear();

  Ogre::ColourValue color( color_.r_, color_.g_, color_.b_, alpha_ );;

  uint32_t num_points = msg->poses.size();
  manual_object_->estimateVertexCount( num_points );
  manual_object_->begin( "BaseWhiteNoLighting", Ogre::RenderOperation::OT_LINE_STRIP );
  for( uint32_t i=0; i < num_points; ++i)
  {
    Ogre::Vector3 pos(msg->poses[i].pose.position.x, msg->poses[i].pose.position.y, msg->poses[i].pose.position.z);
    robotToOgre(pos);
    manual_object_->position(pos);
    manual_object_->colour( color );
  }

  manual_object_->end();
}

void PathDisplay::incomingMessage(const tinyros::nav_msgs::PathConstPtr& msg)
{
  processMessage(msg);
}

void PathDisplay::reset()
{
  clear();
}

void PathDisplay::createProperties()
{
  color_property_ = property_manager_->createProperty<ColorProperty>( "Color", property_prefix_, std::bind( &PathDisplay::getColor, this ),
                                                                      std::bind( &PathDisplay::setColor, this, std::placeholders::_1 ), parent_category_, this );
  alpha_property_ = property_manager_->createProperty<FloatProperty>( "Alpha", property_prefix_, std::bind( &PathDisplay::getAlpha, this ),
                                                                       std::bind( &PathDisplay::setAlpha, this, std::placeholders::_1 ), parent_category_, this );

  topic_property_ = property_manager_->createProperty<ROSTopicStringProperty>( "Topic", property_prefix_, std::bind( &PathDisplay::getTopic, this ),
                                                                                std::bind( &PathDisplay::setTopic, this, std::placeholders::_1 ), parent_category_, this );
  ROSTopicStringPropertyPtr topic_prop = topic_property_.lock();
  topic_prop->setMessageType(tinyros::nav_msgs::Path::getTypeStatic());
}

const char* PathDisplay::getDescription()
{
  return "Displays data from a nav_msgs::Path message as lines.";
}

} // namespace rviz

