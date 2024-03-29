#ifndef _TINYROS_geometry_msgs_InertiaStamped_h
#define _TINYROS_geometry_msgs_InertiaStamped_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Inertia.h"

namespace tinyros
{
namespace geometry_msgs
{

  class InertiaStamped : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Inertia _inertia_type;
      _inertia_type inertia;

    InertiaStamped():
      header(),
      inertia()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->inertia.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->inertia.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->inertia.serializedLength();
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      string_echo += "\"inertia\":";
      string_echo += this->inertia.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "geometry_msgs/InertiaStamped"; }
    static std::string getTypeStatic(){ return "geometry_msgs/InertiaStamped"; }
    virtual std::string getMD5(){ return "2b3c9b263c59f65da44508cd041d18a0"; }
    static std::string getMD5Static(){ return "2b3c9b263c59f65da44508cd041d18a0"; }
    virtual std::string getDefinition(){ return "Header header\nInertia inertia\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nInertia inertia\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::geometry_msgs::InertiaStamped> Ptr;
    typedef std::shared_ptr<tinyros::geometry_msgs::InertiaStamped const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::geometry_msgs::InertiaStamped> InertiaStampedPtr;
typedef std::shared_ptr<tinyros::geometry_msgs::InertiaStamped const> InertiaStampedConstPtr;

}
}
#endif
