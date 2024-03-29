#ifndef _TINYROS_geometry_msgs_PoseWithCovarianceStamped_h
#define _TINYROS_geometry_msgs_PoseWithCovarianceStamped_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/PoseWithCovariance.h"

namespace tinyros
{
namespace geometry_msgs
{

  class PoseWithCovarianceStamped : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::PoseWithCovariance _pose_type;
      _pose_type pose;

    PoseWithCovarianceStamped():
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

    virtual std::string getType(){ return "geometry_msgs/PoseWithCovarianceStamped"; }
    static std::string getTypeStatic(){ return "geometry_msgs/PoseWithCovarianceStamped"; }
    virtual std::string getMD5(){ return "14ff1431078f35103bf1b202333b4704"; }
    static std::string getMD5Static(){ return "14ff1431078f35103bf1b202333b4704"; }
    virtual std::string getDefinition(){ return "Header header\nPoseWithCovariance pose\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nPoseWithCovariance pose\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::geometry_msgs::PoseWithCovarianceStamped> Ptr;
    typedef std::shared_ptr<tinyros::geometry_msgs::PoseWithCovarianceStamped const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::geometry_msgs::PoseWithCovarianceStamped> PoseWithCovarianceStampedPtr;
typedef std::shared_ptr<tinyros::geometry_msgs::PoseWithCovarianceStamped const> PoseWithCovarianceStampedConstPtr;

}
}
#endif
