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

#ifndef TINYROS_TF_TRANSFORMLISTENER_H
#define TINYROS_TF_TRANSFORMLISTENER_H
#include "tiny_ros/ros.h"
#include "tiny_ros/sensor_msgs/PointCloud.h"
#include "tiny_ros/std_msgs/Empty.h"
#include "tiny_ros/tf/tfMessage.h"
#include "tiny_ros/tf/tf.h"
#include "tiny_ros/tf/FrameGraph.h" //frame graph service

namespace tinyros{
namespace tf{
inline void transformPointMatVec(const tinyros::tf::Vector3 &origin, const tinyros::tf::Matrix3x3 &basis,
                                  const tinyros::geometry_msgs::Point32 &in, tinyros::geometry_msgs::Point32 &out)
{
  // Use temporary variables in case &in == &out
  double x = basis[0].x() * in.x + basis[0].y() * in.y + basis[0].z() * in.z + origin.x();
  double y = basis[1].x() * in.x + basis[1].y() * in.y + basis[1].z() * in.z + origin.y();
  double z = basis[2].x() * in.x + basis[2].y() * in.y + basis[2].z() * in.z + origin.z();
  
  out.x = x; out.y = y; out.z = z;
}

/** \brief This class inherits from Transformer and automatically subscribes to ROS transform messages */
class TransformListener : public Transformer { //subscribes to message and automatically stores incoming data

public:
  /**@brief Constructor for transform listener
   * \param max_cache_time How long to store transform information */
  TransformListener(tinyros::Duration max_cache_time = tinyros::Duration(DEFAULT_CACHE_TIME), std::string prefix = "")
  : Transformer(true, max_cache_time)
  , message_subscriber_tf_("/tf", &TransformListener::subscription_callback, this)
  , tf_frames_srv_("/tf_frames", &TransformListener::getFrames, this)
  {
    tinyros::nh()->subscribe(message_subscriber_tf_);
    tinyros::nh()->advertiseService(tf_frames_srv_);
    
    tf_prefix_ = prefix;
    last_update_ros_time_ = tinyros::Time::now();
  }
  
  ~TransformListener()
  {
  }

  /* Methods from transformer unhiding them here */
  using Transformer::transformQuaternion;
  using Transformer::transformVector;
  using Transformer::transformPoint;
  using Transformer::transformPose;


  /** \brief Transform a Stamped Quaternion Message into the target frame 
   * This can throw all that lookupTransform can throw as well as tf::InvalidTransform */
  void transformQuaternion(const std::string& target_frame, const tinyros::geometry_msgs::QuaternionStamped& msg_in, tinyros::geometry_msgs::QuaternionStamped& msg_out) const
  {
    tinyros::tf::assertQuaternionValid(msg_in.quaternion);

    Stamped<Quaternion> pin, pout;
    quaternionStampedMsgToTF(msg_in, pin);  
    transformQuaternion(target_frame, pin, pout);
    quaternionStampedTFToMsg(pout, msg_out);
  }
  /** \brief Transform a Stamped Vector Message into the target frame 
   * This can throw all that lookupTransform can throw as well as tf::InvalidTransform */
  void transformVector(const std::string& target_frame, const tinyros::geometry_msgs::Vector3Stamped& msg_in, tinyros::geometry_msgs::Vector3Stamped& msg_out) const
  {
    Stamped<Vector3> pin, pout;
    vector3StampedMsgToTF(msg_in, pin);
    transformVector(target_frame, pin, pout);
    vector3StampedTFToMsg(pout, msg_out);
  }
  /** \brief Transform a Stamped Point Message into the target frame 
   * This can throw all that lookupTransform can throw as well as tf::InvalidTransform */
  void transformPoint(const std::string& target_frame, const tinyros::geometry_msgs::PointStamped& msg_in, tinyros::geometry_msgs::PointStamped& msg_out) const
  {
    Stamped<Point> pin, pout;
    pointStampedMsgToTF(msg_in, pin);
    transformPoint(target_frame, pin, pout);
    pointStampedTFToMsg(pout, msg_out);
  }
  /** \brief Transform a Stamped Pose Message into the target frame 
   * This can throw all that lookupTransform can throw as well as tf::InvalidTransform */
  void transformPose(const std::string& target_frame, const tinyros::geometry_msgs::PoseStamped& msg_in, tinyros::geometry_msgs::PoseStamped& msg_out) const
  {
    tinyros::tf::assertQuaternionValid(msg_in.pose.orientation);

    Stamped<Pose> pin, pout;
    poseStampedMsgToTF(msg_in, pin);
    transformPose(target_frame, pin, pout);
    poseStampedTFToMsg(pout, msg_out);
  }
  /** \brief Transform a Stamped Twist Message into the target frame 
   * This can throw all that lookupTransform can throw as well as tf::InvalidTransform */
  // http://www.ros.org/wiki/tf/Reviews/2010-03-12_API_Review
  //  void transformTwist(const std::string& target_frame, const tinyros::geometry_msgs::TwistStamped& stamped_in, tinyros::geometry_msgs::TwistStamped& stamped_out) const;

  /** \brief Transform a Stamped Quaternion Message into the target frame
   * This can throw all that lookupTransform can throw as well as tf::InvalidTransform */
  void transformQuaternion(const std::string& target_frame, const tinyros::Time& target_time,
                           const tinyros::geometry_msgs::QuaternionStamped& msg_in,
                           const std::string& fixed_frame, tinyros::geometry_msgs::QuaternionStamped& msg_out) const
  {
    tinyros::tf::assertQuaternionValid(msg_in.quaternion);
    Stamped<Quaternion> pin, pout;
    quaternionStampedMsgToTF(msg_in, pin);
    transformQuaternion(target_frame, target_time, pin, fixed_frame, pout);
    quaternionStampedTFToMsg(pout, msg_out);
  }
  /** \brief Transform a Stamped Vector Message into the target frame and time 
   * This can throw all that lookupTransform can throw as well as tf::InvalidTransform */
  void transformVector(const std::string& target_frame, const tinyros::Time& target_time,
                       const tinyros::geometry_msgs::Vector3Stamped& msg_in,
                           const std::string& fixed_frame, tinyros::geometry_msgs::Vector3Stamped& msg_out) const
  {
    Stamped<Vector3> pin, pout;
    vector3StampedMsgToTF(msg_in, pin);
    transformVector(target_frame, target_time, pin, fixed_frame, pout);
    vector3StampedTFToMsg(pout, msg_out);
  }
  /** \brief Transform a Stamped Point Message into the target frame and time  
   * This can throw all that lookupTransform can throw as well as tf::InvalidTransform */
  void transformPoint(const std::string& target_frame, const tinyros::Time& target_time,
                           const tinyros::geometry_msgs::PointStamped& msg_in,
                           const std::string& fixed_frame, tinyros::geometry_msgs::PointStamped& msg_out) const
  {
    Stamped<Point> pin, pout;
    pointStampedMsgToTF(msg_in, pin);
    transformPoint(target_frame, target_time, pin, fixed_frame, pout);
    pointStampedTFToMsg(pout, msg_out);
  }
  /** \brief Transform a Stamped Pose Message into the target frame and time  
   * This can throw all that lookupTransform can throw as well as tf::InvalidTransform */
  void transformPose(const std::string& target_frame, const tinyros::Time& target_time,
                     const tinyros::geometry_msgs::PoseStamped& msg_in,
                     const std::string& fixed_frame, tinyros::geometry_msgs::PoseStamped& msg_out) const
  {
    tinyros::tf::assertQuaternionValid(msg_in.pose.orientation);

    Stamped<Pose> pin, pout;
    poseStampedMsgToTF(msg_in, pin);
    transformPose(target_frame, target_time, pin, fixed_frame, pout);
    poseStampedTFToMsg(pout, msg_out);
  }

  /** \brief Transform a sensor_msgs::PointCloud natively 
   * This can throw all that lookupTransform can throw as well as tf::InvalidTransform */
    void transformPointCloud(const std::string& target_frame, const tinyros::sensor_msgs::PointCloud& cloudIn, tinyros::sensor_msgs::PointCloud& cloudOut) const
    {
      StampedTransform transform;
      lookupTransform(target_frame, cloudIn.header.frame_id, cloudIn.header.stamp, transform);

      transformPointCloud(target_frame, transform, cloudIn.header.stamp, cloudIn, cloudOut);
    }

  /** @brief Transform a sensor_msgs::PointCloud in space and time 
   * This can throw all that lookupTransform can throw as well as tf::InvalidTransform */
  void transformPointCloud(const std::string& target_frame, const tinyros::Time& target_time,
                           const tinyros::sensor_msgs::PointCloud& cloudIn,
                           const std::string& fixed_frame, tinyros::sensor_msgs::PointCloud& cloudOut) const
  {
    StampedTransform transform;
    lookupTransform(target_frame, target_time,
        cloudIn.header.frame_id, cloudIn.header.stamp,
        fixed_frame,
        transform);

    transformPointCloud(target_frame, transform, target_time, cloudIn, cloudOut);
  }



    ///\todo move to high precision laser projector class  void projectAndTransformLaserScan(const sensor_msgs::LaserScan& scan_in, sensor_msgs::PointCloud& pcout);

  void getFrames(const tinyros::tf::FrameGraph::Request& req, tinyros::tf::FrameGraph::Response& res) 
  {
    res.dot_graph = allFramesAsDot();
  }

  /* \brief Resolve frame_name into a frame_id using tf_prefix parameter */
  std::string resolve(const std::string& frame_name)
  {
    return tinyros::tf::resolve(tf_prefix_, frame_name);
  };

protected:
  bool ok() const { return tinyros::nh()->ok(); }

private:
  /// last time
  tinyros::Time last_update_ros_time_;

  /// Callback function for ros message subscriptoin
  void subscription_callback(const tinyros::tf::tfMessage& msg)
  {
    tinyros::Time time_now = tinyros::Time::now();
    tinyros::Duration tinyros_diff = time_now - last_update_ros_time_;
    double tinyros_dt = tinyros_diff.toSec();

    if (tinyros_dt < 0.0)
    {
      tinyros_log_warn("Saw a negative time change of %f seconds, clearing the tf buffer.", tinyros_dt);
      clear();
    }

    last_update_ros_time_ = time_now;

    const tinyros::tf::tfMessage& msg_in = msg;
    for (unsigned int i = 0; i < msg_in.transforms.size(); i++)
    {
      StampedTransform trans;
      transformStampedMsgToTF(msg_in.transforms[i], trans);
      try
      {
        std::string authority = msg_in.transforms[i].header.frame_id;
        authority += "->";
        authority += msg_in.transforms[i].child_frame_id;
        setTransform(trans, authority);
      }
      catch (TransformException& ex)
      {
        ///\todo Use error reporting
        std::string temp = ex.what();
        tinyros_log_error("Failure to set recieved transform from %s to %s with error: %s\n", msg_in.transforms[i].child_frame_id.c_str(), msg_in.transforms[i].header.frame_id.c_str(), temp.c_str());
      }
    }
  }

  /** @brief a helper function to be used for both transfrom pointCloud methods */
  void transformPointCloud(const std::string & target_frame, const Transform& net_transform, const tinyros::Time& target_time, 
                              const tinyros::sensor_msgs::PointCloud& cloudIn, tinyros::sensor_msgs::PointCloud& cloudOut) const
  {
    tinyros::tf::Vector3 origin = net_transform.getOrigin();
    tinyros::tf::Matrix3x3 basis  = net_transform.getBasis();

    unsigned int length = cloudIn.points.size();

    // Copy relevant data from cloudIn, if needed
    if (&cloudIn != &cloudOut)
    {
      cloudOut.header = cloudIn.header;
      cloudOut.points.resize(length);
      cloudOut.channels.resize(cloudIn.channels.size());
      for (unsigned int i = 0 ; i < cloudIn.channels.size() ; ++i)
      {
        cloudOut.channels[i] = cloudIn.channels[i];
      }
    }

    // Transform points
    cloudOut.header.stamp = target_time;
    cloudOut.header.frame_id = target_frame;
    for (unsigned int i = 0; i < length ; i++) {
      transformPointMatVec(origin, basis, cloudIn.points[i], cloudOut.points[i]);
    }
  }

  /// clear the cached data
  tinyros::std_msgs::Empty empty_;
  tinyros::ServiceServer<tinyros::tf::FrameGraph::Request, 
      tinyros::tf::FrameGraph::Response, TransformListener> tf_frames_srv_;
  tinyros::Subscriber<tinyros::tf::tfMessage, TransformListener> message_subscriber_tf_;
};
}
}

#endif
