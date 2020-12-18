#ifndef _TINYROS_gazebo_msgs_ModelStates_h
#define _TINYROS_gazebo_msgs_ModelStates_h

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

  class ModelStates : public tinyros::Msg
  {
    public:
      uint32_t name_length;
      typedef std::string _name_type;
      _name_type st_name;
      _name_type * name;
      uint32_t pose_length;
      typedef tinyros::geometry_msgs::Pose _pose_type;
      _pose_type st_pose;
      _pose_type * pose;
      uint32_t twist_length;
      typedef tinyros::geometry_msgs::Twist _twist_type;
      _twist_type st_twist;
      _twist_type * twist;

    ModelStates():
      name_length(0), name(NULL),
      pose_length(0), pose(NULL),
      twist_length(0), twist(NULL)
    {
    }

    ~ModelStates()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(this->name != NULL)
      {
        delete[] this->name;
      }
      this->name = NULL;
      this->name_length = 0;
      if(this->pose != NULL)
      {
        for( uint32_t i = 0; i < this->pose_length; i++){
          this->pose[i].deconstructor();
        }
        delete[] this->pose;
      }
      this->pose = NULL;
      this->pose_length = 0;
      if(this->twist != NULL)
      {
        for( uint32_t i = 0; i < this->twist_length; i++){
          this->twist[i].deconstructor();
        }
        delete[] this->twist;
      }
      this->twist = NULL;
      this->twist_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->name_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->name_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->name_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->name_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->name_length);
      for( uint32_t i = 0; i < name_length; i++) {
        uint32_t length_namei = this->name[i].size();
        varToArr(outbuffer + offset, length_namei);
        offset += 4;
        memcpy(outbuffer + offset, this->name[i].c_str(), length_namei);
        offset += length_namei;
      }
      *(outbuffer + offset + 0) = (this->pose_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->pose_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->pose_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->pose_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pose_length);
      for( uint32_t i = 0; i < pose_length; i++) {
        offset += this->pose[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->twist_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->twist_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->twist_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->twist_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->twist_length);
      for( uint32_t i = 0; i < twist_length; i++) {
        offset += this->twist[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t name_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->name_length);
      if(!this->name || name_lengthT > this->name_length) {
        this->deconstructor();
        this->name = new std::string[name_lengthT];
      }
      this->name_length = name_lengthT;
      for( uint32_t i = 0; i < name_length; i++) {
        uint32_t length_st_name;
        arrToVar(length_st_name, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_st_name; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_st_name-1]=0;
        this->st_name = (char *)(inbuffer + offset-1);
        offset += length_st_name;
        this->name[i] = this->st_name;
      }
      uint32_t pose_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pose_length);
      if(!this->pose || pose_lengthT > this->pose_length) {
        this->deconstructor();
        this->pose = new tinyros::geometry_msgs::Pose[pose_lengthT];
      }
      this->pose_length = pose_lengthT;
      for( uint32_t i = 0; i < pose_length; i++) {
        offset += this->st_pose.deserialize(inbuffer + offset);
        this->pose[i] = this->st_pose;
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
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->name_length);
      for( uint32_t i = 0; i < name_length; i++) {
        uint32_t length_namei = this->name[i].size();
        length += 4;
        length += length_namei;
      }
      length += sizeof(this->pose_length);
      for( uint32_t i = 0; i < pose_length; i++) {
        length += this->pose[i].serializedLength();
      }
      length += sizeof(this->twist_length);
      for( uint32_t i = 0; i < twist_length; i++) {
        length += this->twist[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
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

    virtual std::string getType(){ return "gazebo_msgs/ModelStates"; }
    static std::string getTypeStatic(){ return "gazebo_msgs/ModelStates"; }
    virtual std::string getMD5(){ return "05074231128e3d50825a5f46d9217fda"; }
    static std::string getMD5Static(){ return "05074231128e3d50825a5f46d9217fda"; }
    virtual std::string getDefinition(){ return "string[] name                 \ngeometry_msgs/Pose[] pose     \ngeometry_msgs/Twist[] twist   \n"; }
    static std::string getDefinitionStatic(){ return "string[] name                 \ngeometry_msgs/Pose[] pose     \ngeometry_msgs/Twist[] twist   \n"; }
    static bool hasHeader(){ return false; }
  };

typedef std::shared_ptr<tinyros::gazebo_msgs::ModelStates> ModelStatesPtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::ModelStates const> ModelStatesConstPtr;

}
}
#endif
