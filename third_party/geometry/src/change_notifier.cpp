/*
 * Copyright (c) 2009, Willow Garage, Inc.
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

/** \author Tully Foote */

#include <cstdio>
#include "tiny_ros/ros.h"
#include "tiny_ros/tf/tf.h"
#include "tiny_ros/tf/transform_listener.h"

class FramePair
{
public:
  FramePair(const std::string& source_frame, const std::string& target_frame, double translational_update_distance, double angular_update_distance) : 
    source_frame_(source_frame), 
    target_frame_(target_frame),
    translational_update_distance_(translational_update_distance),
    angular_update_distance_(angular_update_distance)
  {
    pose_in_ = tinyros::tf::Stamped<tinyros::tf::Pose>(tinyros::tf::Pose(tinyros::tf::createIdentityQuaternion(), tinyros::tf::Vector3(0, 0, 0)), tinyros::Time(), source_frame_);
  }

public:
  std::string source_frame_;
  std::string target_frame_;

  tinyros::tf::Stamped<tinyros::tf::Pose> pose_in_;
  tinyros::tf::Stamped<tinyros::tf::Pose> pose_out_;
  tinyros::tf::Stamped<tinyros::tf::Pose> last_sent_pose_;
  
  double translational_update_distance_;
  double angular_update_distance_;
};

/** This is a program to provide notifications of changes of state within tf 
 * It was written for providing an easy way to on demand update a web graphic of 
 * where the robot is located.  It's not designed or recommended for use in live 
 * operation for feedback.  */
int main(int argc, char** argv)
{
  tinyros::init("tinyros_change_notifier");

  if (argc < 3) {
    printf("A command line utility for manually sending a change.\n");
    printf("Usage: tinyros_change_notifier source_frame target_frame frequency translational_distance angular_distance\n");
    printf("Example:\n");
    printf("tinyros_change_notifier child_link base_link 10.0 0.10 0.10\n");
    tinyros_log_error("tinyros_change_notifier exited due to not having the right number of arguments");
    return -1;
  }

  double polling_frequency = 10.0, translational_update_distance = 0.10, angular_update_distance = 0.10;
  
  if (argc == 4) {
    polling_frequency = atof(argv[3]);
  }
  
  if (argc == 5) {
    polling_frequency = atof(argv[3]);
    translational_update_distance = atof(argv[4]);
  }
  
  if (argc >= 6) {
    polling_frequency = atof(argv[3]);
    translational_update_distance = atof(argv[4]);
    angular_update_distance = atof(argv[5]);
  }

  std::vector<FramePair> frame_pairs;
  frame_pairs.push_back(FramePair(argv[1], argv[2], translational_update_distance, angular_update_distance));

  tinyros::tf::TransformListener tfl;

  // Advertise the service
  tinyros::Publisher pub ("/tf_changes", new tinyros::tf::tfMessage());
  tinyros::nh()->advertise(pub);
    
  while (tinyros::nh()->ok())
  {
    try
    {
      tinyros::tf::tfMessage msg;

      for (std::vector<FramePair>::iterator i = frame_pairs.begin(); i != frame_pairs.end(); i++)
      {
        FramePair& fp = *i;

        tfl.transformPose(fp.target_frame_, fp.pose_in_, fp.pose_out_);

        const tinyros::tf::Vector3&    origin   = fp.pose_out_.getOrigin();
        const tinyros::tf::Quaternion& rotation = fp.pose_out_.getRotation();

        if (origin.distance(fp.last_sent_pose_.getOrigin()) > fp.translational_update_distance_ ||
            rotation.angle(fp.last_sent_pose_.getRotation()) > fp.angular_update_distance_)
        {
          fp.last_sent_pose_ = fp.pose_out_;
          tinyros::tf::StampedTransform stampedTf(tinyros::tf::Transform(rotation, origin), fp.pose_out_.stamp_, "/" + fp.target_frame_, "/" + fp.source_frame_);
          tinyros::geometry_msgs::TransformStamped msgtf;
          tinyros::tf::transformStampedTFToMsg(stampedTf, msgtf);
          msg.transforms.push_back(msgtf);
        }
      }

      if (msg.transforms.size() > 0)
        pub.publish(&msg);
    }
    catch (tinyros::tf::TransformException& ex)
    {
      tinyros_log_error("Exception: %s\n", ex.what());
    }
    
    // Sleep until next polling
    if (polling_frequency > 0)
      tinyros::Duration().fromSec(1.0 / polling_frequency).sleep();
  }

  return 0;
}
