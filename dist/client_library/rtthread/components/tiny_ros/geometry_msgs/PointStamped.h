#ifndef _TINYROS_geometry_msgs_PointStamped_h
#define _TINYROS_geometry_msgs_PointStamped_h

#include <stdint.h>
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

    virtual tinyros::string getType(){ return "geometry_msgs/PointStamped"; }
    static tinyros::string getTypeStatic(){ return "geometry_msgs/PointStamped"; }
    virtual tinyros::string getMD5(){ return "d34e83bdbef7bf4b617a6293aab8390e"; }
    static tinyros::string getMD5Static(){ return "d34e83bdbef7bf4b617a6293aab8390e"; }
    virtual tinyros::string getDefinition(){ return "Header header\nPoint point\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\nPoint point\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
