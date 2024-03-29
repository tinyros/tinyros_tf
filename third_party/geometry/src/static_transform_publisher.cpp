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

#include <cstdio>
#include "tiny_ros/ros.h"
#include "tiny_ros/tf/transform_broadcaster.h"

class TransformSender
{
public:
  //constructor
  TransformSender(double x, double y, double z, double yaw, double pitch, double roll, tinyros::Time time, const std::string& frame_id, const std::string& child_frame_id)
  { 
    tinyros::tf::Quaternion q;
    q.setRPY(roll, pitch,yaw);
    transform_ = tinyros::tf::StampedTransform(tinyros::tf::Transform(q, tinyros::tf::Vector3(x,y,z)), time, frame_id, child_frame_id );
  };
  TransformSender(double x, double y, double z, double qx, double qy, double qz, double qw, tinyros::Time time, const std::string& frame_id, const std::string& child_frame_id) :
    transform_(tinyros::tf::Transform(tinyros::tf::Quaternion(qx,qy,qz,qw), tinyros::tf::Vector3(x,y,z)), time, frame_id, child_frame_id){};
  //Clean up ros connections
  ~TransformSender() { }

  //A pointer to the rosTFServer class
  tinyros::tf::TransformBroadcaster broadcaster;



  // A function to call to send data periodically
  void send (tinyros::Time time) {
    transform_.stamp_ = time;
    broadcaster.sendTransform(transform_);
  };

private:
  tinyros::tf::StampedTransform transform_;

};

int main(int argc, char ** argv)
{
  //Initialize tinyros
  tinyros::init("tinyros_static_transform_publisher");

  if(argc == 11)
  {
    tinyros::Duration sleeper(atof(argv[10])/1000.0);

    if (strcmp(argv[8], argv[9]) == 0)
      tinyros_log_error("target_frame and source frame are the same (%s, %s) this cannot work", argv[8], argv[9]);

    TransformSender tf_sender(atof(argv[1]), atof(argv[2]), atof(argv[3]),
                              atof(argv[4]), atof(argv[5]), atof(argv[6]), atof(argv[7]),
                              tinyros::Time() + sleeper, //Future dating to allow slower sending w/o timeout
                              argv[8], argv[9]);



    while(tinyros::nh()->ok())
    {
      tf_sender.send(tinyros::Time::now()/* + sleeper*/);
      sleeper.sleep();
    }

    return 0;
  } 
  else if (argc == 10)
  {
    tinyros::Duration sleeper(atof(argv[9])/1000.0);

    if (strcmp(argv[7], argv[8]) == 0)
      tinyros_log_error("target_frame and source frame are the same (%s, %s) this cannot work", argv[7], argv[8]);

    TransformSender tf_sender(atof(argv[1]), atof(argv[2]), atof(argv[3]),
                              atof(argv[4]), atof(argv[5]), atof(argv[6]),
                              tinyros::Time() + sleeper, //Future dating to allow slower sending w/o timeout
                              argv[7], argv[8]);



    while(tinyros::nh()->ok())
    {
      tf_sender.send(tinyros::Time::now()/* + sleeper*/);
      sleeper.sleep();
    }

    return 0;

  }
  else
  {
    printf("A command line utility for manually sending a transform.\n");
    printf("It will periodicaly republish the given transform. \n");
    printf("Usage: tinyros_static_transform_publisher x y z yaw pitch roll frame_id child_frame_id  period(milliseconds) \n");
    printf("OR \n");
    printf("Usage: tinyros_static_transform_publisher x y z qx qy qz qw frame_id child_frame_id  period(milliseconds) \n");
    printf("\nThis transform is the transform of the coordinate frame from frame_id into the coordinate frame \n");
    printf("of the child_frame_id.  \n");
    tinyros_log_error("static_transform_publisher exited due to not having the right number of arguments");
    return -1;
  }


};

