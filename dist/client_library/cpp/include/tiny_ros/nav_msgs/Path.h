#ifndef _TINYROS_nav_msgs_Path_h
#define _TINYROS_nav_msgs_Path_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/PoseStamped.h"

namespace tinyros
{
namespace nav_msgs
{

  class Path : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::PoseStamped _poses_type;
      std::vector<_poses_type> poses;

    Path():
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

    virtual std::string getType(){ return "nav_msgs/Path"; }
    static std::string getTypeStatic(){ return "nav_msgs/Path"; }
    virtual std::string getMD5(){ return "4a185240c929c496a7e0d6202e3c89af"; }
    static std::string getMD5Static(){ return "4a185240c929c496a7e0d6202e3c89af"; }
    virtual std::string getDefinition(){ return "Header header\ngeometry_msgs/PoseStamped[] poses\n"; }
    static std::string getDefinitionStatic(){ return "Header header\ngeometry_msgs/PoseStamped[] poses\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::nav_msgs::Path> Ptr;
    typedef std::shared_ptr<tinyros::nav_msgs::Path const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::nav_msgs::Path> PathPtr;
typedef std::shared_ptr<tinyros::nav_msgs::Path const> PathConstPtr;

}
}
#endif
