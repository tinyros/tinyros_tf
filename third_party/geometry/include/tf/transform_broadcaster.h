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


/** \author Tully Foote */

#ifndef TINYROS_TF_TRANSFORMBROADCASTER_H
#define TINYROS_TF_TRANSFORMBROADCASTER_H

#include "tiny_ros/tf/tf.h"
#include "tiny_ros/tf/tfMessage.h"
#include "tiny_ros/ros.h"

namespace tinyros
{
namespace tf
{


/** \brief This class provides an easy way to publish coordinate frame transform information.  
 * It will handle all the messaging and stuffing of messages.  And the function prototypes lay out all the 
 * necessary data needed for each message.  */

class TransformBroadcaster{
public:
  /** \brief Constructor (needs a ros::Node reference) */
  TransformBroadcaster(std::string prefix = "")
  : tf_prefix_(prefix)
  , publisher_("/tf", new tinyros::tf::tfMessage())
  {
    tinyros::nh()->advertise(publisher_);
  }

  /** \brief Send a StampedTransform 
   * The stamped data structure includes frame_id, and time, and parent_id already.  */
  void sendTransform(const StampedTransform & transform)
  {
    std::vector<StampedTransform> v1;
    v1.push_back(transform);
    sendTransform(v1);
  } 

  /** \brief Send a vector of StampedTransforms 
   * The stamped data structure includes frame_id, and time, and parent_id already.  */
  void sendTransform(const std::vector<StampedTransform> & transforms)
  {
    std::vector<tinyros::geometry_msgs::TransformStamped> msgtfs;
    for (std::vector<StampedTransform>::const_iterator it = transforms.begin(); it != transforms.end(); ++it)
    {
      tinyros::geometry_msgs::TransformStamped msgtf;
      transformStampedTFToMsg(*it, msgtf);
      msgtfs.push_back(msgtf);

    }
    sendTransform(msgtfs);
  }

  /** \brief Send a TransformStamped message
   * The stamped data structure includes frame_id, and time, and parent_id already.  */
  void sendTransform(const tinyros::geometry_msgs::TransformStamped & msgtf)
  {
    std::vector<tinyros::geometry_msgs::TransformStamped> v1;
    v1.push_back(msgtf);
    sendTransform(v1);
  }

  /** \brief Send a vector of TransformStamped messages
   * The stamped data structure includes frame_id, and time, and parent_id already.  */
  void sendTransform(const std::vector<tinyros::geometry_msgs::TransformStamped> & msgtf)
  {
    tinyros::tf::tfMessage message;
    message.transforms_length = msgtf.size();
    message.transforms = (tinyros::geometry_msgs::TransformStamped*)realloc(message.transforms, message.transforms_length * sizeof(tinyros::geometry_msgs::TransformStamped));
    TINYROS_ASSERT(message.transforms);
    for (unsigned int i = 0; i < message.transforms_length; i++)
    {
      memcpy(&(message.transforms[i]), &(msgtf[i]), sizeof(tinyros::geometry_msgs::TransformStamped));
      message.transforms[i].header.frame_id = tinyros::tf::resolve(tf_prefix_, message.transforms[i].header.frame_id);
      message.transforms[i].child_frame_id = tinyros::tf::resolve(tf_prefix_, message.transforms[i].child_frame_id);
    }
    publisher_.publish(&message);
  }

private:
  tinyros::Publisher publisher_;

  std::string tf_prefix_;

};
}
}

#endif
