#ifndef _TINYROS_geometry_msgs_AccelStamped_h
#define _TINYROS_geometry_msgs_AccelStamped_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Accel.h"

namespace tinyros
{
namespace geometry_msgs
{

  class AccelStamped : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Accel _accel_type;
      _accel_type accel;

    AccelStamped():
      header(),
      accel()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->accel.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->accel.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->accel.serializedLength();
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      string_echo += "\"accel\":";
      string_echo += this->accel.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "geometry_msgs/AccelStamped"; }
    static std::string getTypeStatic(){ return "geometry_msgs/AccelStamped"; }
    virtual std::string getMD5(){ return "fa35432963826361a1073b1df905a559"; }
    static std::string getMD5Static(){ return "fa35432963826361a1073b1df905a559"; }
    virtual std::string getDefinition(){ return "Header header\nAccel accel\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nAccel accel\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::geometry_msgs::AccelStamped> Ptr;
    typedef std::shared_ptr<tinyros::geometry_msgs::AccelStamped const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::geometry_msgs::AccelStamped> AccelStampedPtr;
typedef std::shared_ptr<tinyros::geometry_msgs::AccelStamped const> AccelStampedConstPtr;

}
}
#endif
