#ifndef _TINYROS_geometry_msgs_Polygon_h
#define _TINYROS_geometry_msgs_Polygon_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/geometry_msgs/Point32.h"

namespace tinyros
{
namespace geometry_msgs
{

  class Polygon : public tinyros::Msg
  {
    public:
      typedef tinyros::geometry_msgs::Point32 _points_type;
      std::vector<_points_type> points;

    Polygon():
      points(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t points_length = this->points.size();
      *(outbuffer + offset + 0) = (points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        offset += this->points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t points_length = ((uint32_t) (*(inbuffer + offset))); 
      points_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->points.resize(points_length); 
      offset += sizeof(points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        offset += this->points[i].deserialize(inbuffer + offset);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t points_length = this->points.size();
      length += sizeof(points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        length += this->points[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      uint32_t points_length = this->points.size();
      string_echo += "points:[";
      for( uint32_t i = 0; i < points_length; i++) {
        if( i == (points_length - 1)) {
          string_echo += this->points[i].echo();
          string_echo += "";
        } else {
          string_echo += this->points[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "geometry_msgs/Polygon"; }
    static std::string getTypeStatic(){ return "geometry_msgs/Polygon"; }
    virtual std::string getMD5(){ return "f94a78a947b7879954bd14397db4bc9d"; }
    static std::string getMD5Static(){ return "f94a78a947b7879954bd14397db4bc9d"; }
    virtual std::string getDefinition(){ return "Point32[] points\n"; }
    static std::string getDefinitionStatic(){ return "Point32[] points\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::geometry_msgs::Polygon> Ptr;
    typedef std::shared_ptr<tinyros::geometry_msgs::Polygon const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::geometry_msgs::Polygon> PolygonPtr;
typedef std::shared_ptr<tinyros::geometry_msgs::Polygon const> PolygonConstPtr;

}
}
#endif
