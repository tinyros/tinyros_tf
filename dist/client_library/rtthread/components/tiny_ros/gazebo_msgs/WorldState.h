#ifndef _TINYROS_gazebo_msgs_WorldState_h
#define _TINYROS_gazebo_msgs_WorldState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Pose.h"
#include "tiny_ros/geometry_msgs/Twist.h"
#include "tiny_ros/geometry_msgs/Wrench.h"

namespace tinyros
{
namespace gazebo_msgs
{

  class WorldState : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      uint32_t name_length;
      typedef tinyros::string _name_type;
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
      uint32_t wrench_length;
      typedef tinyros::geometry_msgs::Wrench _wrench_type;
      _wrench_type st_wrench;
      _wrench_type * wrench;

    WorldState():
      header(),
      name_length(0), name(NULL),
      pose_length(0), pose(NULL),
      twist_length(0), twist(NULL),
      wrench_length(0), wrench(NULL)
    {
    }

    ~WorldState()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(name != NULL)
      {
        free(name);
      }
      name = NULL;
      name_length = 0;
      if(pose != NULL)
      {
        for( uint32_t i = 0; i < pose_length; i++){
          pose[i].deconstructor();
        }
        free(pose);
      }
      pose = NULL;
      pose_length = 0;
      if(twist != NULL)
      {
        for( uint32_t i = 0; i < twist_length; i++){
          twist[i].deconstructor();
        }
        free(twist);
      }
      twist = NULL;
      twist_length = 0;
      if(wrench != NULL)
      {
        for( uint32_t i = 0; i < wrench_length; i++){
          wrench[i].deconstructor();
        }
        free(wrench);
      }
      wrench = NULL;
      wrench_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
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
      uint32_t name_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->name_length);
      if(name_lengthT > name_length)
        this->name = (tinyros::string*)realloc(this->name, name_lengthT * sizeof(tinyros::string));
      name_length = name_lengthT;
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
        memcpy( &(this->name[i]), &(this->st_name), sizeof(tinyros::string));
      }
      uint32_t pose_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      pose_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->pose_length);
      if(pose_lengthT > pose_length)
        this->pose = (tinyros::geometry_msgs::Pose*)realloc(this->pose, pose_lengthT * sizeof(tinyros::geometry_msgs::Pose));
      pose_length = pose_lengthT;
      for( uint32_t i = 0; i < pose_length; i++) {
        offset += this->st_pose.deserialize(inbuffer + offset);
        memcpy( &(this->pose[i]), &(this->st_pose), sizeof(tinyros::geometry_msgs::Pose));
      }
      uint32_t twist_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      twist_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      twist_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      twist_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->twist_length);
      if(twist_lengthT > twist_length)
        this->twist = (tinyros::geometry_msgs::Twist*)realloc(this->twist, twist_lengthT * sizeof(tinyros::geometry_msgs::Twist));
      twist_length = twist_lengthT;
      for( uint32_t i = 0; i < twist_length; i++) {
        offset += this->st_twist.deserialize(inbuffer + offset);
        memcpy( &(this->twist[i]), &(this->st_twist), sizeof(tinyros::geometry_msgs::Twist));
      }
      uint32_t wrench_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      wrench_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      wrench_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      wrench_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->wrench_length);
      if(wrench_lengthT > wrench_length)
        this->wrench = (tinyros::geometry_msgs::Wrench*)realloc(this->wrench, wrench_lengthT * sizeof(tinyros::geometry_msgs::Wrench));
      wrench_length = wrench_lengthT;
      for( uint32_t i = 0; i < wrench_length; i++) {
        offset += this->st_wrench.deserialize(inbuffer + offset);
        memcpy( &(this->wrench[i]), &(this->st_wrench), sizeof(tinyros::geometry_msgs::Wrench));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
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
      length += sizeof(this->wrench_length);
      for( uint32_t i = 0; i < wrench_length; i++) {
        length += this->wrench[i].serializedLength();
      }
      return length;
    }

    virtual tinyros::string getType(){ return "gazebo_msgs/WorldState"; }
    static tinyros::string getTypeStatic(){ return "gazebo_msgs/WorldState"; }
    virtual tinyros::string getMD5(){ return "0e1997127271c4d021f99645c28f1c09"; }
    static tinyros::string getMD5Static(){ return "0e1997127271c4d021f99645c28f1c09"; }
    virtual tinyros::string getDefinition(){ return "Header header\nstring[] name\ngeometry_msgs/Pose[] pose\ngeometry_msgs/Twist[] twist\ngeometry_msgs/Wrench[] wrench\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\nstring[] name\ngeometry_msgs/Pose[] pose\ngeometry_msgs/Twist[] twist\ngeometry_msgs/Wrench[] wrench\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
