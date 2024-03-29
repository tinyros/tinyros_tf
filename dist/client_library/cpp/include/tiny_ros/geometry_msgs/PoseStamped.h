#ifndef _TINYROS_geometry_msgs_PoseStamped_h
#define _TINYROS_geometry_msgs_PoseStamped_h

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

  class PoseStamped : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Pose _pose_type;
      _pose_type pose;

    PoseStamped():
      header(),
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->pose.serializedLength();
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      string_echo += "\"pose\":";
      string_echo += this->pose.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "geometry_msgs/PoseStamped"; }
    static std::string getTypeStatic(){ return "geometry_msgs/PoseStamped"; }
    virtual std::string getMD5(){ return "c7084e6b27c3d6e62efd9bf6d2f6540f"; }
    static std::string getMD5Static(){ return "c7084e6b27c3d6e62efd9bf6d2f6540f"; }
    virtual std::string getDefinition(){ return "Header header\nPose pose\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nPose pose\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::geometry_msgs::PoseStamped> Ptr;
    typedef std::shared_ptr<tinyros::geometry_msgs::PoseStamped const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::geometry_msgs::PoseStamped> PoseStampedPtr;
typedef std::shared_ptr<tinyros::geometry_msgs::PoseStamped const> PoseStampedConstPtr;

}
}
#endif
