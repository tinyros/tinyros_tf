#ifndef _TINYROS_geometry_msgs_PolygonStamped_h
#define _TINYROS_geometry_msgs_PolygonStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Polygon.h"

namespace tinyros
{
namespace geometry_msgs
{

  class PolygonStamped : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Polygon _polygon_type;
      _polygon_type polygon;

    PolygonStamped():
      header(),
      polygon()
    {
    }

    ~PolygonStamped()
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
      offset += this->polygon.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->polygon.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->polygon.serializedLength();
      return length;
    }

    virtual tinyros::string getType(){ return "geometry_msgs/PolygonStamped"; }
    static tinyros::string getTypeStatic(){ return "geometry_msgs/PolygonStamped"; }
    virtual tinyros::string getMD5(){ return "33bdf94066425e572879b25c9a51ed50"; }
    static tinyros::string getMD5Static(){ return "33bdf94066425e572879b25c9a51ed50"; }
    virtual tinyros::string getDefinition(){ return "Header header\nPolygon polygon\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\nPolygon polygon\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
