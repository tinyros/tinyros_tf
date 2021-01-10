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

#include "goal_tool.h"
#include "common.h"
#include "visualization_manager.h"
#include "viewport_mouse_event.h"
#include "properties/property.h"
#include "properties/property_manager.h"

#include "ogre_tools/camera_base.h"
#include "ogre_tools/arrow.h"
#include "ogre_tools/wx_ogre_render_window.h"

#include <tiny_ros/geometry_msgs/PoseStamped.h>

#include <OGRE/OgreRay.h>
#include <OGRE/OgrePlane.h>
#include <OGRE/OgreCamera.h>
#include <OGRE/OgreSceneNode.h>
#include <OGRE/OgreViewport.h>

#include <tiny_ros/tf/transform_listener.h>

#include <wx/event.h>

namespace rviz
{

GoalTool::GoalTool( const std::string& name, char shortcut_key, VisualizationManager* manager )
: PoseTool( name, shortcut_key, manager )
, pub_(new tinyros::Publisher("", new tinyros::geometry_msgs::PoseStamped()))
{
  setTopic("goal");
}

GoalTool::~GoalTool()
{
}

void GoalTool::setTopic(const std::string& topic)
{
  topic_ = topic;
  if (!topic_.empty())
  {
    if (pub_->topic_.empty())
    {
      pub_->topic_ = topic_;
      tinyros::nh()->advertise(*pub_);
    }
    else if (pub_->topic_ != topic_)
    {
      pub_ = new tinyros::Publisher(topic_, new tinyros::geometry_msgs::PoseStamped());
      tinyros::nh()->advertise(*pub_);
    }
  }
}

void GoalTool::onPoseSet(double x, double y, double theta)
{
  std::string fixed_frame = manager_->getFixedFrame();
  tinyros::tf::Quaternion quat;
  quat.setRPY(0.0, 0.0, theta);
  tinyros::tf::Stamped<tinyros::tf::Pose> p = tinyros::tf::Stamped<tinyros::tf::Pose>(tinyros::tf::Pose(quat, tinyros::tf::Point(x, y, 0.0)), tinyros::Time::now(), fixed_frame);
  tinyros::geometry_msgs::PoseStamped goal;
  tinyros::tf::poseStampedTFToMsg(p, goal);
  tinyros_log_info("Setting goal: Frame:%s, Position(%.3f, %.3f, %.3f), Orientation(%.3f, %.3f, %.3f, %.3f) = Angle: %.3f\n", fixed_frame.c_str(),
      goal.pose.position.x, goal.pose.position.y, goal.pose.position.z,
      goal.pose.orientation.x, goal.pose.orientation.y, goal.pose.orientation.z, goal.pose.orientation.w, theta);
  pub_->publish(&goal);
}

void GoalTool::enumerateProperties(PropertyManager* property_manager, const CategoryPropertyWPtr& parent)
{
  topic_property_ = property_manager->createProperty<StringProperty>("Topic", "Tool " + getName(), std::bind(&GoalTool::getTopic, this), std::bind(&GoalTool::setTopic, this, std::placeholders::_1), parent, this);
  //ROSTopicStringPropertyPtr topic_prop = topic_property_.lock();
  //topic_prop->setMessageType(tinyros::geometry_msgs::PoseStamped::getTypeStatic());
}

}

