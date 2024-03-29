#ifndef _TINYROS_nav_msgs_Odometry_h
#define _TINYROS_nav_msgs_Odometry_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/PoseWithCovariance.h"
#include "tiny_ros/geometry_msgs/TwistWithCovariance.h"

namespace tinyros
{
namespace nav_msgs
{

  class Odometry : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef std::string _child_frame_id_type;
      _child_frame_id_type child_frame_id;
      typedef tinyros::geometry_msgs::PoseWithCovariance _pose_type;
      _pose_type pose;
      typedef tinyros::geometry_msgs::TwistWithCovariance _twist_type;
      _twist_type twist;

    Odometry():
      header(),
      child_frame_id(""),
      pose(),
      twist()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_child_frame_id = this->child_frame_id.size();
      varToArr(outbuffer + offset, length_child_frame_id);
      offset += 4;
      memcpy(outbuffer + offset, this->child_frame_id.c_str(), length_child_frame_id);
      offset += length_child_frame_id;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_child_frame_id;
      arrToVar(length_child_frame_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_child_frame_id; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_child_frame_id-1]=0;
      this->child_frame_id = (char *)(inbuffer + offset-1);
      offset += length_child_frame_id;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      uint32_t length_child_frame_id = this->child_frame_id.size();
      length += 4;
      length += length_child_frame_id;
      length += this->pose.serializedLength();
      length += this->twist.serializedLength();
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      std::size_t child_frame_id_pos = child_frame_id.find("\"");
      while(child_frame_id_pos != std::string::npos){
        child_frame_id.replace(child_frame_id_pos, 1,"\\\"");
        child_frame_id_pos = child_frame_id.find("\"", child_frame_id_pos+2);
      }
      string_echo += "\"child_frame_id\":\"";
      string_echo += child_frame_id;
      string_echo += "\",";
      string_echo += "\"pose\":";
      string_echo += this->pose.echo();
      string_echo += ",";
      string_echo += "\"twist\":";
      string_echo += this->twist.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "nav_msgs/Odometry"; }
    static std::string getTypeStatic(){ return "nav_msgs/Odometry"; }
    virtual std::string getMD5(){ return "8fbd8c2e0caeb7be9b30b66a3e735193"; }
    static std::string getMD5Static(){ return "8fbd8c2e0caeb7be9b30b66a3e735193"; }
    virtual std::string getDefinition(){ return "Header header\nstring child_frame_id\ngeometry_msgs/PoseWithCovariance pose\ngeometry_msgs/TwistWithCovariance twist\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nstring child_frame_id\ngeometry_msgs/PoseWithCovariance pose\ngeometry_msgs/TwistWithCovariance twist\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::nav_msgs::Odometry> Ptr;
    typedef std::shared_ptr<tinyros::nav_msgs::Odometry const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::nav_msgs::Odometry> OdometryPtr;
typedef std::shared_ptr<tinyros::nav_msgs::Odometry const> OdometryConstPtr;

}
}
#endif
