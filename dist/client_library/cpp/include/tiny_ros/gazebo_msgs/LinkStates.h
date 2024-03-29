#ifndef _TINYROS_gazebo_msgs_LinkStates_h
#define _TINYROS_gazebo_msgs_LinkStates_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/geometry_msgs/Pose.h"
#include "tiny_ros/geometry_msgs/Twist.h"

namespace tinyros
{
namespace gazebo_msgs
{

  class LinkStates : public tinyros::Msg
  {
    public:
      typedef std::string _name_type;
      std::vector<_name_type> name;
      typedef tinyros::geometry_msgs::Pose _pose_type;
      std::vector<_pose_type> pose;
      typedef tinyros::geometry_msgs::Twist _twist_type;
      std::vector<_twist_type> twist;

    LinkStates():
      name(0),
      pose(0),
      twist(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t name_length = this->name.size();
      *(outbuffer + offset + 0) = (name_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (name_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (name_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (name_length >> (8 * 3)) & 0xFF;
      offset += sizeof(name_length);
      for( uint32_t i = 0; i < name_length; i++) {
        uint32_t length_namei = this->name[i].size();
        varToArr(outbuffer + offset, length_namei);
        offset += 4;
        memcpy(outbuffer + offset, this->name[i].c_str(), length_namei);
        offset += length_namei;
      }
      uint32_t pose_length = this->pose.size();
      *(outbuffer + offset + 0) = (pose_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (pose_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (pose_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (pose_length >> (8 * 3)) & 0xFF;
      offset += sizeof(pose_length);
      for( uint32_t i = 0; i < pose_length; i++) {
        offset += this->pose[i].serialize(outbuffer + offset);
      }
      uint32_t twist_length = this->twist.size();
      *(outbuffer + offset + 0) = (twist_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (twist_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (twist_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (twist_length >> (8 * 3)) & 0xFF;
      offset += sizeof(twist_length);
      for( uint32_t i = 0; i < twist_length; i++) {
        offset += this->twist[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t name_length = ((uint32_t) (*(inbuffer + offset))); 
      name_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      name_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      name_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->name.resize(name_length); 
      offset += sizeof(name_length);
      for( uint32_t i = 0; i < name_length; i++) {
        uint32_t length_namei;
        arrToVar(length_namei, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_namei; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_namei-1]=0;
        this->name[i] = (char *)(inbuffer + offset-1);
        offset += length_namei;
      }
      uint32_t pose_length = ((uint32_t) (*(inbuffer + offset))); 
      pose_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pose_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pose_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->pose.resize(pose_length); 
      offset += sizeof(pose_length);
      for( uint32_t i = 0; i < pose_length; i++) {
        offset += this->pose[i].deserialize(inbuffer + offset);
      }
      uint32_t twist_length = ((uint32_t) (*(inbuffer + offset))); 
      twist_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      twist_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      twist_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->twist.resize(twist_length); 
      offset += sizeof(twist_length);
      for( uint32_t i = 0; i < twist_length; i++) {
        offset += this->twist[i].deserialize(inbuffer + offset);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t name_length = this->name.size();
      length += sizeof(name_length);
      for( uint32_t i = 0; i < name_length; i++) {
        uint32_t length_namei = this->name[i].size();
        length += 4;
        length += length_namei;
      }
      uint32_t pose_length = this->pose.size();
      length += sizeof(pose_length);
      for( uint32_t i = 0; i < pose_length; i++) {
        length += this->pose[i].serializedLength();
      }
      uint32_t twist_length = this->twist.size();
      length += sizeof(twist_length);
      for( uint32_t i = 0; i < twist_length; i++) {
        length += this->twist[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      uint32_t name_length = this->name.size();
      string_echo += "name:[";
      for( uint32_t i = 0; i < name_length; i++) {
        if( i == (name_length - 1)) {
          std::stringstream ss_namei; ss_namei << "\"";
          string_echo += ss_namei.str();
          std::size_t namei_pos = name[i].find("\"");
          while(namei_pos != std::string::npos){
            name[i].replace(namei_pos, 1,"\\\"");
            namei_pos = name[i].find("\"", namei_pos+2);
          }
          string_echo += name[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_namei; ss_namei << "\"";
          string_echo += ss_namei.str();
          std::size_t namei_pos = name[i].find("\"");
          while(namei_pos != std::string::npos){
            name[i].replace(namei_pos, 1,"\\\"");
            namei_pos = name[i].find("\"", namei_pos+2);
          }
          string_echo += name[i];
          string_echo += "\",";
        }
      }
      string_echo += "],";
      uint32_t pose_length = this->pose.size();
      string_echo += "pose:[";
      for( uint32_t i = 0; i < pose_length; i++) {
        if( i == (pose_length - 1)) {
          string_echo += this->pose[i].echo();
          string_echo += "";
        } else {
          string_echo += this->pose[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "],";
      uint32_t twist_length = this->twist.size();
      string_echo += "twist:[";
      for( uint32_t i = 0; i < twist_length; i++) {
        if( i == (twist_length - 1)) {
          string_echo += this->twist[i].echo();
          string_echo += "";
        } else {
          string_echo += this->twist[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "gazebo_msgs/LinkStates"; }
    static std::string getTypeStatic(){ return "gazebo_msgs/LinkStates"; }
    virtual std::string getMD5(){ return "a6f8cc7b3dee31015716313fe2d419eb"; }
    static std::string getMD5Static(){ return "a6f8cc7b3dee31015716313fe2d419eb"; }
    virtual std::string getDefinition(){ return "string[] name\ngeometry_msgs/Pose[] pose\ngeometry_msgs/Twist[] twist\n"; }
    static std::string getDefinitionStatic(){ return "string[] name\ngeometry_msgs/Pose[] pose\ngeometry_msgs/Twist[] twist\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::LinkStates> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::LinkStates const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::LinkStates> LinkStatesPtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::LinkStates const> LinkStatesConstPtr;

}
}
#endif
