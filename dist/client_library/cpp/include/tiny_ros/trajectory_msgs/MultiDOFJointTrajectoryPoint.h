#ifndef _TINYROS_trajectory_msgs_MultiDOFJointTrajectoryPoint_h
#define _TINYROS_trajectory_msgs_MultiDOFJointTrajectoryPoint_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/geometry_msgs/Transform.h"
#include "tiny_ros/geometry_msgs/Twist.h"
#include "tiny_ros/ros/duration.h"

namespace tinyros
{
namespace trajectory_msgs
{

  class MultiDOFJointTrajectoryPoint : public tinyros::Msg
  {
    public:
      typedef tinyros::geometry_msgs::Transform _transforms_type;
      std::vector<_transforms_type> transforms;
      typedef tinyros::geometry_msgs::Twist _velocities_type;
      std::vector<_velocities_type> velocities;
      typedef tinyros::geometry_msgs::Twist _accelerations_type;
      std::vector<_accelerations_type> accelerations;
      typedef tinyros::Duration _time_from_start_type;
      _time_from_start_type time_from_start;

    MultiDOFJointTrajectoryPoint():
      transforms(0),
      velocities(0),
      accelerations(0),
      time_from_start()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t transforms_length = this->transforms.size();
      *(outbuffer + offset + 0) = (transforms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (transforms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (transforms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (transforms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++) {
        offset += this->transforms[i].serialize(outbuffer + offset);
      }
      uint32_t velocities_length = this->velocities.size();
      *(outbuffer + offset + 0) = (velocities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (velocities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (velocities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (velocities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(velocities_length);
      for( uint32_t i = 0; i < velocities_length; i++) {
        offset += this->velocities[i].serialize(outbuffer + offset);
      }
      uint32_t accelerations_length = this->accelerations.size();
      *(outbuffer + offset + 0) = (accelerations_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (accelerations_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (accelerations_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (accelerations_length >> (8 * 3)) & 0xFF;
      offset += sizeof(accelerations_length);
      for( uint32_t i = 0; i < accelerations_length; i++) {
        offset += this->accelerations[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->time_from_start.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.sec);
      *(outbuffer + offset + 0) = (this->time_from_start.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t transforms_length = ((uint32_t) (*(inbuffer + offset))); 
      transforms_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      transforms_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      transforms_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->transforms.resize(transforms_length); 
      offset += sizeof(transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++) {
        offset += this->transforms[i].deserialize(inbuffer + offset);
      }
      uint32_t velocities_length = ((uint32_t) (*(inbuffer + offset))); 
      velocities_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocities_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocities_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->velocities.resize(velocities_length); 
      offset += sizeof(velocities_length);
      for( uint32_t i = 0; i < velocities_length; i++) {
        offset += this->velocities[i].deserialize(inbuffer + offset);
      }
      uint32_t accelerations_length = ((uint32_t) (*(inbuffer + offset))); 
      accelerations_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      accelerations_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      accelerations_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->accelerations.resize(accelerations_length); 
      offset += sizeof(accelerations_length);
      for( uint32_t i = 0; i < accelerations_length; i++) {
        offset += this->accelerations[i].deserialize(inbuffer + offset);
      }
      this->time_from_start.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.sec);
      this->time_from_start.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.nsec);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t transforms_length = this->transforms.size();
      length += sizeof(transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++) {
        length += this->transforms[i].serializedLength();
      }
      uint32_t velocities_length = this->velocities.size();
      length += sizeof(velocities_length);
      for( uint32_t i = 0; i < velocities_length; i++) {
        length += this->velocities[i].serializedLength();
      }
      uint32_t accelerations_length = this->accelerations.size();
      length += sizeof(accelerations_length);
      for( uint32_t i = 0; i < accelerations_length; i++) {
        length += this->accelerations[i].serializedLength();
      }
      length += sizeof(this->time_from_start.sec);
      length += sizeof(this->time_from_start.nsec);
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      uint32_t transforms_length = this->transforms.size();
      string_echo += "transforms:[";
      for( uint32_t i = 0; i < transforms_length; i++) {
        if( i == (transforms_length - 1)) {
          string_echo += this->transforms[i].echo();
          string_echo += "";
        } else {
          string_echo += this->transforms[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "],";
      uint32_t velocities_length = this->velocities.size();
      string_echo += "velocities:[";
      for( uint32_t i = 0; i < velocities_length; i++) {
        if( i == (velocities_length - 1)) {
          string_echo += this->velocities[i].echo();
          string_echo += "";
        } else {
          string_echo += this->velocities[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "],";
      uint32_t accelerations_length = this->accelerations.size();
      string_echo += "accelerations:[";
      for( uint32_t i = 0; i < accelerations_length; i++) {
        if( i == (accelerations_length - 1)) {
          string_echo += this->accelerations[i].echo();
          string_echo += "";
        } else {
          string_echo += this->accelerations[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "],";
      std::stringstream ss_time_from_start;
      ss_time_from_start << "\"time_from_start\":{\"sec\":" << time_from_start.sec;
      ss_time_from_start << ",\"nsec\":" << time_from_start.nsec << "}";
      string_echo += ss_time_from_start.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "trajectory_msgs/MultiDOFJointTrajectoryPoint"; }
    static std::string getTypeStatic(){ return "trajectory_msgs/MultiDOFJointTrajectoryPoint"; }
    virtual std::string getMD5(){ return "f8b4a74b416279b5c5d565029308ff08"; }
    static std::string getMD5Static(){ return "f8b4a74b416279b5c5d565029308ff08"; }
    virtual std::string getDefinition(){ return "geometry_msgs/Transform[] transforms\ngeometry_msgs/Twist[] velocities\ngeometry_msgs/Twist[] accelerations\nduration time_from_start\n"; }
    static std::string getDefinitionStatic(){ return "geometry_msgs/Transform[] transforms\ngeometry_msgs/Twist[] velocities\ngeometry_msgs/Twist[] accelerations\nduration time_from_start\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::trajectory_msgs::MultiDOFJointTrajectoryPoint> Ptr;
    typedef std::shared_ptr<tinyros::trajectory_msgs::MultiDOFJointTrajectoryPoint const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::trajectory_msgs::MultiDOFJointTrajectoryPoint> MultiDOFJointTrajectoryPointPtr;
typedef std::shared_ptr<tinyros::trajectory_msgs::MultiDOFJointTrajectoryPoint const> MultiDOFJointTrajectoryPointConstPtr;

}
}
#endif
