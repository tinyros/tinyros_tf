#ifndef _TINYROS_geometry_msgs_Vector3Stamped_h
#define _TINYROS_geometry_msgs_Vector3Stamped_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Vector3.h"

namespace tinyros
{
namespace geometry_msgs
{

  class Vector3Stamped : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Vector3 _vector_type;
      _vector_type vector;

    Vector3Stamped():
      header(),
      vector()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->vector.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->vector.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->vector.serializedLength();
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      string_echo += "\"vector\":";
      string_echo += this->vector.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "geometry_msgs/Vector3Stamped"; }
    static std::string getTypeStatic(){ return "geometry_msgs/Vector3Stamped"; }
    virtual std::string getMD5(){ return "4b85025eb6f70f6b1e0cefbb75f69ac2"; }
    static std::string getMD5Static(){ return "4b85025eb6f70f6b1e0cefbb75f69ac2"; }
    virtual std::string getDefinition(){ return "Header header\nVector3 vector\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nVector3 vector\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::geometry_msgs::Vector3Stamped> Ptr;
    typedef std::shared_ptr<tinyros::geometry_msgs::Vector3Stamped const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::geometry_msgs::Vector3Stamped> Vector3StampedPtr;
typedef std::shared_ptr<tinyros::geometry_msgs::Vector3Stamped const> Vector3StampedConstPtr;

}
}
#endif
