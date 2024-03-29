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
#include "tiny_ros/tf/transform_listener.h"
#include "tiny_ros/ros.h"

class echoListener
{
public:

  tinyros::tf::TransformListener tf;

  //constructor with name
  echoListener()
  {

  };

  ~echoListener()
  {

  };

private:

};


int main(int argc, char ** argv)
{
  //Initialize ROS
  tinyros::init("tinyros_tf_echo");

  if (argc != 3)
  {
    printf("Usage: tinyros_tf_echo source_frame target_frame\n\n");
    printf("This will echo the transform from the coordinate frame of the source_frame\n");
    printf("to the coordinate frame of the target_frame. \n");
    printf("Note: This is the transform to get data from target_frame into the source_frame.\n");
    return -1;
  }

  //Instantiate a local listener
  echoListener echoListener;


  std::string source_frameid = std::string(argv[1]);
  std::string target_frameid = std::string(argv[2]);

  // Wait for up to one second for the first transforms to become avaiable. 
  echoListener.tf.waitForTransform(source_frameid, target_frameid, tinyros::Time(), tinyros::Duration(1.0));

  //Nothing needs to be done except wait for a quit
  //The callbacks withing the listener class
  //will take care of everything
  while(true)
    {
      try
      {
        tinyros::tf::StampedTransform echo_transform;
        echoListener.tf.lookupTransform(source_frameid, target_frameid, tinyros::Time(), echo_transform);
        std::cout.precision(3);
        std::cout.setf(std::ios::fixed,std::ios::floatfield);
        std::cout << "At time " << echo_transform.stamp_.toSec() << " (source: " 
          << source_frameid.c_str() << ", target:" << target_frameid.c_str() << ")" << std::endl;
        double yaw, pitch, roll;
        echo_transform.getBasis().getRPY(roll, pitch, yaw);
        tinyros::tf::Quaternion q = echo_transform.getRotation();
        tinyros::tf::Vector3 v = echo_transform.getOrigin();
        std::cout << "- Translation: [" << v.getX() << ", " << v.getY() << ", " << v.getZ() << "]" << std::endl;
        std::cout << "- Rotation: in Quaternion [" << q.getX() << ", " << q.getY() << ", " 
                  << q.getZ() << ", " << q.getW() << "]" << std::endl
                  << "            in RPY [" <<  roll << ", " << pitch << ", " << yaw << "]" << std::endl << std::endl;

        //print transform
      }
      catch(tinyros::tf::TransformException& ex)
      {
        tinyros::Time now = tinyros::Time::now();
        std::cout << "Failure at "<< now.sec << "." << now.nsec << std::endl;
        std::cout << "Exception thrown:" << ex.what()<< std::endl;
        std::cout << "The current list of frames is:" <<std::endl;
        std::cout << echoListener.tf.allFramesAsString()<<std::endl;
        
      }
      sleep(1);
    }

  return 0;
};

