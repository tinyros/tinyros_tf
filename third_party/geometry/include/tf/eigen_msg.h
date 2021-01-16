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

/*
 * Author: Stuart Glaser
 */

#ifndef TINYROS_EIGEN_MSG_CONVERSIONS_H
#define TINYROS_EIGEN_MSG_CONVERSIONS_H

#include "tiny_ros/std_msgs/Float64MultiArray.h"
#include "tiny_ros/geometry_msgs/PoseStamped.h"
#include "tiny_ros/geometry_msgs/Pose.h"
#include "tiny_ros/geometry_msgs/Twist.h"
#include "tiny_ros/geometry_msgs/Wrench.h"

#include <Eigen/Core>
#include <Eigen/Geometry>

namespace tinyros {
namespace tf {

/// Converts a Pose message into an Eigen Transform
void poseMsgToEigen(const tinyros::geometry_msgs::Pose &m, Eigen::Affine3d &e)
{
  e = Eigen::Translation3d(m.position.x,
                           m.position.y,
                           m.position.z) *
    Eigen::Quaterniond(m.orientation.w,
                       m.orientation.x,
                       m.orientation.y,
                       m.orientation.z);
}

/// Converts an Eigen transform into a Pose message
void poseEigenToMsg(const Eigen::Affine3d &e, tinyros::geometry_msgs::Pose &m)
{
  m.position.x = e.translation()[0];
  m.position.y = e.translation()[1];
  m.position.z = e.translation()[2];
  Eigen::Quaterniond q = (Eigen::Quaterniond)e.linear();
  m.orientation.x = q.x();
  m.orientation.y = q.y();
  m.orientation.z = q.z();
  m.orientation.w = q.w();
  if (m.orientation.w < 0) {
    m.orientation.x *= -1;
    m.orientation.y *= -1;
    m.orientation.z *= -1;
    m.orientation.w *= -1;
  }
}

/// Converts a Twist message into an Eigen matrix
void twistMsgToEigen(const tinyros::geometry_msgs::Twist &m, Eigen::Matrix<double,6,1> &e)
{
  e[0] = m.linear.x;
  e[1] = m.linear.y;
  e[2] = m.linear.z;
  e[3] = m.angular.x;
  e[4] = m.angular.y;
  e[5] = m.angular.z;
}

/// Converts an Eigen matrix into a Twist message
void twistEigenToMsg(const Eigen::Matrix<double,6,1> &e, tinyros::geometry_msgs::Twist &m)
{
  m.linear.x = e[0];
  m.linear.y = e[1];
  m.linear.z = e[2];
  m.angular.x = e[3];
  m.angular.y = e[4];
  m.angular.z = e[5];
}

/// Converts a Wrench message into an Eigen matrix
void wrenchMsgToEigen(const tinyros::geometry_msgs::Wrench &m, Eigen::Matrix<double,6,1> &e)
{
  e[0] = m.force.x;
  e[1] = m.force.y;
  e[2] = m.force.z;
  e[3] = m.torque.x;
  e[4] = m.torque.y;
  e[5] = m.torque.z;
}

/// Converts an Eigen matrix into a Wrench message
void wrenchEigenToMsg(const Eigen::Matrix<double,6,1> &e, tinyros::geometry_msgs::Wrench &m)
{
  m.force.x = e[0];
  m.force.y = e[1];
  m.force.z = e[2];
  m.torque.x = e[3];
  m.torque.y = e[4];
  m.torque.z = e[5];
}

/// Converts an Eigen matrix into a Float64MultiArray message
template <class Derived>
void matrixEigenToMsg(const Eigen::MatrixBase<Derived> &e, tinyros::std_msgs::Float64MultiArray &m)
{
  if (m.layout.dim.size() != 2)
    m.layout.dim.resize(2);
  m.layout.dim[0].stride = e.rows() * e.cols();
  m.layout.dim[0].size = e.rows();
  m.layout.dim[1].stride = e.cols();
  m.layout.dim[1].size = e.cols();
  if ((int)m.data.size() != e.size())
    m.data.resize(e.size());
  int ii = 0;
  for (int i = 0; i < e.rows(); ++i)
    for (int j = 0; j < e.cols(); ++j)
      m.data[ii++] = e.coeff(i, j);
}

}
} // namespace

#endif
