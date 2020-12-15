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

#ifndef TINYROS_CONVERSIONS_TF_KDL_H
#define TINYROS_CONVERSIONS_TF_KDL_H

#include "tiny_ros/tf/transform_datatypes.h"
#include "tiny_ros/geometry_msgs/Twist.h"
#include "tiny_ros/geometry_msgs/Pose.h"
#include <kdl/frames.hpp>

namespace tinyros
{
namespace tf
{
/// Converts a tf Vector3 into a KDL Vector
void VectorTFToKDL(const tinyros::tf::Vector3& t, KDL::Vector& k)
{
  k = KDL::Vector(t[0], t[1], t[2]);
}

/// Converts a tf Quaternion into a KDL Rotation
void RotationTFToKDL(const tinyros::tf::Quaternion& t, KDL::Rotation& k)
{
  k = KDL::Rotation::Quaternion(t[0], t[1], t[2], t[3]);
}

/// Converts a tf Transform into a KDL Frame
void TransformTFToKDL(const tinyros::tf::Transform &t, KDL::Frame &k)
{
  for (unsigned int i = 0; i < 3; ++i)
    k.p[i] = t.getOrigin()[i];
  for (unsigned int i = 0; i < 9; ++i)
    k.M.data[i] = t.getBasis()[i/3][i%3];
}

/// Converts a tf Pose into a KDL Frame
void PoseTFToKDL(const tinyros::tf::Pose& pose, KDL::Frame& frame)
{
  for (unsigned int i = 0; i < 3; ++i)
    k.p[i] = t.getOrigin()[i];
  for (unsigned int i = 0; i < 9; ++i)
    k.M.data[i] = t.getBasis()[i/3][i%3];
}

/// Converts a KDL Frame into a tf Transform
void TransformKDLToTF(const KDL::Frame &k, tinyros::tf::Transform &t)
{
  t.setOrigin(tinyros::tf::Vector3(k.p[0], k.p[1], k.p[2]));
  t.setBasis(tinyros::tf::Matrix3x3(k.M.data[0], k.M.data[1], k.M.data[2],
                         k.M.data[3], k.M.data[4], k.M.data[5],
                         k.M.data[6], k.M.data[7], k.M.data[8]));
}

/// Converts a KDL Frame into a tf Pose
void PoseKDLToTF(const KDL::Frame& k, tinyros::tf::Pose& t)
{
  t.setOrigin(tinyros::tf::Vector3(k.p[0], k.p[1], k.p[2]));
  t.setBasis(tinyros::tf::Matrix3x3(k.M.data[0], k.M.data[1], k.M.data[2],
                         k.M.data[3], k.M.data[4], k.M.data[5],
                         k.M.data[6], k.M.data[7], k.M.data[8]));
}

/// Converts a KDL Twist into a Twist message
void TwistKDLToMsg(const KDL::Twist &t, tinyros::geometry_msgs::Twist &m)
{
  m.linear.x = t.vel[0];
  m.linear.y = t.vel[1];
  m.linear.z = t.vel[2];
  m.angular.x = t.rot[0];
  m.angular.y = t.rot[1];
  m.angular.z = t.rot[2];
}

/// Converts a Twist message into a KDL Twist
void TwistMsgToKDL(const tinyros::geometry_msgs::Twist &m, KDL::Twist &t)
{
  t.vel[0] = m.linear.x;
  t.vel[1] = m.linear.y;
  t.vel[2] = m.linear.z;
  t.rot[0] = m.angular.x;
  t.rot[1] = m.angular.y;
  t.rot[2] = m.angular.z;
}

/// Converts a Pose message into a KDL Frame
void PoseMsgToKDL(const tinyros::geometry_msgs::Pose &p, KDL::Frame &t)
{
  tinyros::tf::Pose pose_tf;
  tinyros::tf::poseMsgToTF(p,pose_tf);
  PoseTFToKDL(pose_tf,t);
}

/// Converts a KDL Frame into a Pose message 
void PoseKDLToMsg(const KDL::Frame &t, tinyros::geometry_msgs::Pose &p)
{
  tinyros::tf::Pose pose_tf;
  PoseKDLToTF(t,pose_tf);
  tinyros::tf::poseTFToMsg(pose_tf,p);
}

/* DEPRECATED FUNCTIONS */
/// Starting from a Pose from A to B, apply a Twist with reference frame A and reference point B, during a time t.
tinyros::geometry_msgs::Pose addDelta(const tinyros::geometry_msgs::Pose &pose, const tinyros::geometry_msgs::Twist &twist, const double &t)
{
  tinyros::geometry_msgs::Pose result;
  KDL::Twist kdl_twist;
  KDL::Frame kdl_pose_id, kdl_pose;

  PoseMsgToKDL(pose,kdl_pose);
  TwistMsgToKDL(twist,kdl_twist);
  kdl_pose = KDL::addDelta(kdl_pose_id,kdl_twist,t)*kdl_pose;
  PoseKDLToMsg(kdl_pose,result);
  return result;
}
}
}

#endif
