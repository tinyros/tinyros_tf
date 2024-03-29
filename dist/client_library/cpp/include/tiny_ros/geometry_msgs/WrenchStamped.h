#ifndef _TINYROS_geometry_msgs_WrenchStamped_h
#define _TINYROS_geometry_msgs_WrenchStamped_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Wrench.h"

namespace tinyros
{
namespace geometry_msgs
{

  class WrenchStamped : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Wrench _wrench_type;
      _wrench_type wrench;

    WrenchStamped():
      header(),
      wrench()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->wrench.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->wrench.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->wrench.serializedLength();
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      string_echo += "\"wrench\":";
      string_echo += this->wrench.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "geometry_msgs/WrenchStamped"; }
    static std::string getTypeStatic(){ return "geometry_msgs/WrenchStamped"; }
    virtual std::string getMD5(){ return "cf53874aa63609de4155ec8e9cf2c540"; }
    static std::string getMD5Static(){ return "cf53874aa63609de4155ec8e9cf2c540"; }
    virtual std::string getDefinition(){ return "Header header\nWrench wrench\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nWrench wrench\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::geometry_msgs::WrenchStamped> Ptr;
    typedef std::shared_ptr<tinyros::geometry_msgs::WrenchStamped const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::geometry_msgs::WrenchStamped> WrenchStampedPtr;
typedef std::shared_ptr<tinyros::geometry_msgs::WrenchStamped const> WrenchStampedConstPtr;

}
}
#endif
