#ifndef _TINYROS_sensor_msgs_MultiDOFJointState_h
#define _TINYROS_sensor_msgs_MultiDOFJointState_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Transform.h"
#include "tiny_ros/geometry_msgs/Twist.h"
#include "tiny_ros/geometry_msgs/Wrench.h"

namespace tinyros
{
namespace sensor_msgs
{

  class MultiDOFJointState : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef std::string _joint_names_type;
      std::vector<_joint_names_type> joint_names;
      typedef tinyros::geometry_msgs::Transform _transforms_type;
      std::vector<_transforms_type> transforms;
      typedef tinyros::geometry_msgs::Twist _twist_type;
      std::vector<_twist_type> twist;
      typedef tinyros::geometry_msgs::Wrench _wrench_type;
      std::vector<_wrench_type> wrench;

    MultiDOFJointState():
      header(),
      joint_names(0),
      transforms(0),
      twist(0),
      wrench(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t joint_names_length = this->joint_names.size();
      *(outbuffer + offset + 0) = (joint_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (joint_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (joint_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (joint_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_joint_namesi = this->joint_names[i].size();
        varToArr(outbuffer + offset, length_joint_namesi);
        offset += 4;
        memcpy(outbuffer + offset, this->joint_names[i].c_str(), length_joint_namesi);
        offset += length_joint_namesi;
      }
      uint32_t transforms_length = this->transforms.size();
      *(outbuffer + offset + 0) = (transforms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (transforms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (transforms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (transforms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++) {
        offset += this->transforms[i].serialize(outbuffer + offset);
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
      uint32_t wrench_length = this->wrench.size();
      *(outbuffer + offset + 0) = (wrench_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (wrench_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (wrench_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (wrench_length >> (8 * 3)) & 0xFF;
      offset += sizeof(wrench_length);
      for( uint32_t i = 0; i < wrench_length; i++) {
        offset += this->wrench[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t joint_names_length = ((uint32_t) (*(inbuffer + offset))); 
      joint_names_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_names_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_names_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->joint_names.resize(joint_names_length); 
      offset += sizeof(joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_joint_namesi;
        arrToVar(length_joint_namesi, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_joint_namesi; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_joint_namesi-1]=0;
        this->joint_names[i] = (char *)(inbuffer + offset-1);
        offset += length_joint_namesi;
      }
      uint32_t transforms_length = ((uint32_t) (*(inbuffer + offset))); 
      transforms_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      transforms_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      transforms_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->transforms.resize(transforms_length); 
      offset += sizeof(transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++) {
        offset += this->transforms[i].deserialize(inbuffer + offset);
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
      uint32_t wrench_length = ((uint32_t) (*(inbuffer + offset))); 
      wrench_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      wrench_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      wrench_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->wrench.resize(wrench_length); 
      offset += sizeof(wrench_length);
      for( uint32_t i = 0; i < wrench_length; i++) {
        offset += this->wrench[i].deserialize(inbuffer + offset);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      uint32_t joint_names_length = this->joint_names.size();
      length += sizeof(joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_joint_namesi = this->joint_names[i].size();
        length += 4;
        length += length_joint_namesi;
      }
      uint32_t transforms_length = this->transforms.size();
      length += sizeof(transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++) {
        length += this->transforms[i].serializedLength();
      }
      uint32_t twist_length = this->twist.size();
      length += sizeof(twist_length);
      for( uint32_t i = 0; i < twist_length; i++) {
        length += this->twist[i].serializedLength();
      }
      uint32_t wrench_length = this->wrench.size();
      length += sizeof(wrench_length);
      for( uint32_t i = 0; i < wrench_length; i++) {
        length += this->wrench[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      uint32_t joint_names_length = this->joint_names.size();
      string_echo += "joint_names:[";
      for( uint32_t i = 0; i < joint_names_length; i++) {
        if( i == (joint_names_length - 1)) {
          std::stringstream ss_joint_namesi; ss_joint_namesi << "\"";
          string_echo += ss_joint_namesi.str();
          std::size_t joint_namesi_pos = joint_names[i].find("\"");
          while(joint_namesi_pos != std::string::npos){
            joint_names[i].replace(joint_namesi_pos, 1,"\\\"");
            joint_namesi_pos = joint_names[i].find("\"", joint_namesi_pos+2);
          }
          string_echo += joint_names[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_joint_namesi; ss_joint_namesi << "\"";
          string_echo += ss_joint_namesi.str();
          std::size_t joint_namesi_pos = joint_names[i].find("\"");
          while(joint_namesi_pos != std::string::npos){
            joint_names[i].replace(joint_namesi_pos, 1,"\\\"");
            joint_namesi_pos = joint_names[i].find("\"", joint_namesi_pos+2);
          }
          string_echo += joint_names[i];
          string_echo += "\",";
        }
      }
      string_echo += "],";
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
      string_echo += "],";
      uint32_t wrench_length = this->wrench.size();
      string_echo += "wrench:[";
      for( uint32_t i = 0; i < wrench_length; i++) {
        if( i == (wrench_length - 1)) {
          string_echo += this->wrench[i].echo();
          string_echo += "";
        } else {
          string_echo += this->wrench[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "sensor_msgs/MultiDOFJointState"; }
    static std::string getTypeStatic(){ return "sensor_msgs/MultiDOFJointState"; }
    virtual std::string getMD5(){ return "c1b0232d8e5071b24db76eb143f286eb"; }
    static std::string getMD5Static(){ return "c1b0232d8e5071b24db76eb143f286eb"; }
    virtual std::string getDefinition(){ return "Header header\nstring[] joint_names\ngeometry_msgs/Transform[] transforms\ngeometry_msgs/Twist[] twist\ngeometry_msgs/Wrench[] wrench\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nstring[] joint_names\ngeometry_msgs/Transform[] transforms\ngeometry_msgs/Twist[] twist\ngeometry_msgs/Wrench[] wrench\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::sensor_msgs::MultiDOFJointState> Ptr;
    typedef std::shared_ptr<tinyros::sensor_msgs::MultiDOFJointState const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::sensor_msgs::MultiDOFJointState> MultiDOFJointStatePtr;
typedef std::shared_ptr<tinyros::sensor_msgs::MultiDOFJointState const> MultiDOFJointStateConstPtr;

}
}
#endif
