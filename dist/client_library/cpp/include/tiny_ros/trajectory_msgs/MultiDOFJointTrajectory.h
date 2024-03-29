#ifndef _TINYROS_trajectory_msgs_MultiDOFJointTrajectory_h
#define _TINYROS_trajectory_msgs_MultiDOFJointTrajectory_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/trajectory_msgs/MultiDOFJointTrajectoryPoint.h"

namespace tinyros
{
namespace trajectory_msgs
{

  class MultiDOFJointTrajectory : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef std::string _joint_names_type;
      std::vector<_joint_names_type> joint_names;
      typedef tinyros::trajectory_msgs::MultiDOFJointTrajectoryPoint _points_type;
      std::vector<_points_type> points;

    MultiDOFJointTrajectory():
      header(),
      joint_names(0),
      points(0)
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
      uint32_t points_length = this->points.size();
      *(outbuffer + offset + 0) = (points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        offset += this->points[i].serialize(outbuffer + offset);
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
      uint32_t points_length = ((uint32_t) (*(inbuffer + offset))); 
      points_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->points.resize(points_length); 
      offset += sizeof(points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        offset += this->points[i].deserialize(inbuffer + offset);
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
      uint32_t points_length = this->points.size();
      length += sizeof(points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        length += this->points[i].serializedLength();
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
      uint32_t points_length = this->points.size();
      string_echo += "points:[";
      for( uint32_t i = 0; i < points_length; i++) {
        if( i == (points_length - 1)) {
          string_echo += this->points[i].echo();
          string_echo += "";
        } else {
          string_echo += this->points[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "trajectory_msgs/MultiDOFJointTrajectory"; }
    static std::string getTypeStatic(){ return "trajectory_msgs/MultiDOFJointTrajectory"; }
    virtual std::string getMD5(){ return "19f97d4cdcae9d0ef55126c1495f6c91"; }
    static std::string getMD5Static(){ return "19f97d4cdcae9d0ef55126c1495f6c91"; }
    virtual std::string getDefinition(){ return "Header header\nstring[] joint_names\nMultiDOFJointTrajectoryPoint[] points\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nstring[] joint_names\nMultiDOFJointTrajectoryPoint[] points\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::trajectory_msgs::MultiDOFJointTrajectory> Ptr;
    typedef std::shared_ptr<tinyros::trajectory_msgs::MultiDOFJointTrajectory const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::trajectory_msgs::MultiDOFJointTrajectory> MultiDOFJointTrajectoryPtr;
typedef std::shared_ptr<tinyros::trajectory_msgs::MultiDOFJointTrajectory const> MultiDOFJointTrajectoryConstPtr;

}
}
#endif
