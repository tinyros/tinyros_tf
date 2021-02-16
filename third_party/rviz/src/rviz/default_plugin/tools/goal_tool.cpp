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

#include <tiny_ros/tf/transform_listener.h>

#include <tiny_ros/geometry_msgs/PoseStamped.h>

#include "rviz/display_context.h"
#include "rviz/properties/string_property.h"

#include "rviz/default_plugin/tools/goal_tool.h"

namespace rviz
{

GoalTool::GoalTool() : pub_("", new tinyros::geometry_msgs::PoseStamped)
{
  shortcut_key_ = 'g';

  topic_property_ = new StringProperty( "Topic", "goal",
                                        "The topic on which to publish navigation goals.",
                                        getPropertyContainer(), SLOT( updateTopic() ), this );
}

void GoalTool::onInitialize()
{
  PoseTool::onInitialize();
  setName( "2D Nav Goal" );
  updateTopic();
}

void GoalTool::updateTopic()
{
  pub_ = tinyros::Publisher(topic_property_->getStdString(), new tinyros::geometry_msgs::PoseStamped);
  tinyros::nh()->advertise(pub_);
}

void GoalTool::onPoseSet(double x, double y, double theta)
{
  std::string fixed_frame = context_->getFixedFrame().toStdString();
  tinyros::tf::Quaternion quat;
  quat.setRPY(0.0, 0.0, theta);
  tinyros::tf::Stamped<tinyros::tf::Pose> p = tinyros::tf::Stamped<tinyros::tf::Pose>(
    tinyros::tf::Pose(quat, tinyros::tf::Point(x, y, 0.0)), tinyros::Time::now(), fixed_frame);
  tinyros::geometry_msgs::PoseStamped goal;
  tinyros::tf::poseStampedTFToMsg(p, goal);
  tinyros_log_info("Setting goal: Frame:%s, Position(%.3f, %.3f, %.3f), Orientation(%.3f, %.3f, %.3f, %.3f) = Angle: %.3f\n", fixed_frame.c_str(),
      goal.pose.position.x, goal.pose.position.y, goal.pose.position.z,
      goal.pose.orientation.x, goal.pose.orientation.y, goal.pose.orientation.z, goal.pose.orientation.w, theta);
  pub_.publish(&goal);
}

} // end namespace rviz

