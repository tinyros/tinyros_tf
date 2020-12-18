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
      uint32_t joint_names_length;
      typedef std::string _joint_names_type;
      _joint_names_type st_joint_names;
      _joint_names_type * joint_names;
      uint32_t transforms_length;
      typedef tinyros::geometry_msgs::Transform _transforms_type;
      _transforms_type st_transforms;
      _transforms_type * transforms;
      uint32_t twist_length;
      typedef tinyros::geometry_msgs::Twist _twist_type;
      _twist_type st_twist;
      _twist_type * twist;
      uint32_t wrench_length;
      typedef tinyros::geometry_msgs::Wrench _wrench_type;
      _wrench_type st_wrench;
      _wrench_type * wrench;

    MultiDOFJointState():
      header(),
      joint_names_length(0), joint_names(NULL),
      transforms_length(0), transforms(NULL),
      twist_length(0), twist(NULL),
      wrench_length(0), wrench(NULL)
    {
    }

    ~MultiDOFJointState()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(this->joint_names != NULL)
      {
        delete[] this->joint_names;
      }
      this->joint_names = NULL;
      this->joint_names_length = 0;
      if(this->transforms != NULL)
      {
        for( uint32_t i = 0; i < this->transforms_length; i++){
          this->transforms[i].deconstructor();
        }
        delete[] this->transforms;
      }
      this->transforms = NULL;
      this->transforms_length = 0;
      if(this->twist != NULL)
      {
        for( uint32_t i = 0; i < this->twist_length; i++){
          this->twist[i].deconstructor();
        }
        delete[] this->twist;
      }
      this->twist = NULL;
      this->twist_length = 0;
      if(this->wrench != NULL)
      {
        for( uint32_t i = 0; i < this->wrench_length; i++){
          this->wrench[i].deconstructor();
        }
        delete[] this->wrench;
      }
      this->wrench = NULL;
      this->wrench_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->joint_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_joint_namesi = this->joint_names[i].size();
        varToArr(outbuffer + offset, length_joint_namesi);
        offset += 4;
        memcpy(outbuffer + offset, this->joint_names[i].c_str(), length_joint_namesi);
        offset += length_joint_namesi;
      }
      *(outbuffer + offset + 0) = (this->transforms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->transforms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->transforms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->transforms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++) {
        offset += this->transforms[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->twist_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->twist_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->twist_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->twist_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->twist_length);
      for( uint32_t i = 0; i < twist_length; i++) {
        offset += this->twist[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->wrench_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wrench_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->wrench_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->wrench_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wrench_length);
      for( uint32_t i = 0; i < wrench_length; i++) {
        offset += this->wrench[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t joint_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->joint_names_length);
      if(!this->joint_names || joint_names_lengthT > this->joint_names_length) {
        this->deconstructor();
        this->joint_names = new std::string[joint_names_lengthT];
      }
      this->joint_names_length = joint_names_lengthT;
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_st_joint_names;
        arrToVar(length_st_joint_names, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_st_joint_names; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_st_joint_names-1]=0;
        this->st_joint_names = (char *)(inbuffer + offset-1);
        offset += length_st_joint_names;
        this->joint_names[i] = this->st_joint_names;
      }
      uint32_t transforms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->transforms_length);
      if(!this->transforms || transforms_lengthT > this->transforms_length) {
        this->deconstructor();
        this->transforms = new tinyros::geometry_msgs::Transform[transforms_lengthT];
      }
      this->transforms_length = transforms_lengthT;
      for( uint32_t i = 0; i < transforms_length; i++) {
        offset += this->st_transforms.deserialize(inbuffer + offset);
        this->transforms[i] = this->st_transforms;
      }
      uint32_t twist_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      twist_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      twist_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      twist_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->twist_length);
      if(!this->twist || twist_lengthT > this->twist_length) {
        this->deconstructor();
        this->twist = new tinyros::geometry_msgs::Twist[twist_lengthT];
      }
      this->twist_length = twist_lengthT;
      for( uint32_t i = 0; i < twist_length; i++) {
        offset += this->st_twist.deserialize(inbuffer + offset);
        this->twist[i] = this->st_twist;
      }
      uint32_t wrench_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      wrench_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      wrench_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      wrench_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->wrench_length);
      if(!this->wrench || wrench_lengthT > this->wrench_length) {
        this->deconstructor();
        this->wrench = new tinyros::geometry_msgs::Wrench[wrench_lengthT];
      }
      this->wrench_length = wrench_lengthT;
      for( uint32_t i = 0; i < wrench_length; i++) {
        offset += this->st_wrench.deserialize(inbuffer + offset);
        this->wrench[i] = this->st_wrench;
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += sizeof(this->joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_joint_namesi = this->joint_names[i].size();
        length += 4;
        length += length_joint_namesi;
      }
      length += sizeof(this->transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++) {
        length += this->transforms[i].serializedLength();
      }
      length += sizeof(this->twist_length);
      for( uint32_t i = 0; i < twist_length; i++) {
        length += this->twist[i].serializedLength();
      }
      length += sizeof(this->wrench_length);
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
  };

typedef std::shared_ptr<tinyros::sensor_msgs::MultiDOFJointState> MultiDOFJointStatePtr;
typedef std::shared_ptr<tinyros::sensor_msgs::MultiDOFJointState const> MultiDOFJointStateConstPtr;

}
}
#endif
