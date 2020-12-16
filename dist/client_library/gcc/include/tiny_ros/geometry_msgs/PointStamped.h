#ifndef _TINYROS_geometry_msgs_PointStamped_h
#define _TINYROS_geometry_msgs_PointStamped_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Point.h"

namespace tinyros
{
namespace geometry_msgs
{

  class PointStamped : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Point _point_type;
      _point_type point;

    PointStamped():
      header(),
      point()
    {
    }

    ~PointStamped()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->point.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->point.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->point.serializedLength();
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      string_echo += "\"point\":";
      string_echo += this->point.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "geometry_msgs/PointStamped"; }
    static std::string getTypeStatic(){ return "geometry_msgs/PointStamped"; }
    virtual std::string getMD5(){ return "d34e83bdbef7bf4b617a6293aab8390e"; }
    static std::string getMD5Static(){ return "d34e83bdbef7bf4b617a6293aab8390e"; }
    virtual std::string getDefinition(){ return "Header header\nPoint point\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nPoint point\n"; }
    static bool hasHeader(){ return true; }
  };

typedef std::shared_ptr<tinyros::geometry_msgs::PointStamped> PointStampedPtr;
typedef std::shared_ptr<tinyros::geometry_msgs::PointStamped const> PointStampedConstPtr;

}
}
#endif
