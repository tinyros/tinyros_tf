#ifndef _TINYROS_geometry_msgs_Polygon_h
#define _TINYROS_geometry_msgs_Polygon_h

#include <stdint.h>
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
      uint32_t points_length;
      typedef tinyros::geometry_msgs::Point32 _points_type;
      _points_type st_points;
      _points_type * points;

    Polygon():
      points_length(0), points(NULL)
    {
    }

    ~Polygon()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(points != NULL)
      {
        for( uint32_t i = 0; i < points_length; i++){
          points[i].deconstructor();
        }
        free(points);
      }
      points = NULL;
      points_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        offset += this->points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (tinyros::geometry_msgs::Point32*)realloc(this->points, points_lengthT * sizeof(tinyros::geometry_msgs::Point32));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++) {
        offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(tinyros::geometry_msgs::Point32));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        length += this->points[i].serializedLength();
      }
      return length;
    }

    virtual tinyros::string getType(){ return "geometry_msgs/Polygon"; }
    static tinyros::string getTypeStatic(){ return "geometry_msgs/Polygon"; }
    virtual tinyros::string getMD5(){ return "f94a78a947b7879954bd14397db4bc9d"; }
    static tinyros::string getMD5Static(){ return "f94a78a947b7879954bd14397db4bc9d"; }
    virtual tinyros::string getDefinition(){ return "Point32[] points\n"; }
    static tinyros::string getDefinitionStatic(){ return "Point32[] points\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
