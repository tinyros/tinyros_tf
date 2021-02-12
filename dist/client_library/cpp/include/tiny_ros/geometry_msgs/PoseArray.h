#ifndef _TINYROS_geometry_msgs_PoseArray_h
#define _TINYROS_geometry_msgs_PoseArray_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Pose.h"

namespace tinyros
{
namespace geometry_msgs
{

  class PoseArray : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Pose _poses_type;
      std::vector<_poses_type> poses;

    PoseArray():
      header(),
      poses(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t poses_length = this->poses.size();
      *(outbuffer + offset + 0) = (poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(poses_length);
      for( uint32_t i = 0; i < poses_length; i++) {
        offset += this->poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t poses_length = ((uint32_t) (*(inbuffer + offset))); 
      poses_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      poses_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      poses_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->poses.resize(poses_length); 
      offset += sizeof(poses_length);
      for( uint32_t i = 0; i < poses_length; i++) {
        offset += this->poses[i].deserialize(inbuffer + offset);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      uint32_t poses_length = this->poses.size();
      length += sizeof(poses_length);
      for( uint32_t i = 0; i < poses_length; i++) {
        length += this->poses[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      uint32_t poses_length = this->poses.size();
      string_echo += "poses:[";
      for( uint32_t i = 0; i < poses_length; i++) {
        if( i == (poses_length - 1)) {
          string_echo += this->poses[i].echo();
          string_echo += "";
        } else {
          string_echo += this->poses[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "geometry_msgs/PoseArray"; }
    static std::string getTypeStatic(){ return "geometry_msgs/PoseArray"; }
    virtual std::string getMD5(){ return "184f43246f3bc9cb5d0613694e6641a6"; }
    static std::string getMD5Static(){ return "184f43246f3bc9cb5d0613694e6641a6"; }
    virtual std::string getDefinition(){ return "Header header\nPose[] poses\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nPose[] poses\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::geometry_msgs::PoseArray> Ptr;
    typedef std::shared_ptr<tinyros::geometry_msgs::PoseArray const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::geometry_msgs::PoseArray> PoseArrayPtr;
typedef std::shared_ptr<tinyros::geometry_msgs::PoseArray const> PoseArrayConstPtr;

}
}
#endif
