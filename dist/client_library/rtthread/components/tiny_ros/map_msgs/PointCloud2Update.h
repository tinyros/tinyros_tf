#ifndef _TINYROS_map_msgs_PointCloud2Update_h
#define _TINYROS_map_msgs_PointCloud2Update_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/sensor_msgs/PointCloud2.h"

namespace tinyros
{
namespace map_msgs
{

  class PointCloud2Update : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _type_type;
      _type_type type;
      typedef tinyros::sensor_msgs::PointCloud2 _points_type;
      _points_type points;
      enum { ADD = 0 };
      enum { DELETE = 1 };

    PointCloud2Update():
      header(),
      type(0),
      points()
    {
    }

    ~PointCloud2Update()
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
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->type >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->type >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->type >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      offset += this->points.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->type =  ((uint32_t) (*(inbuffer + offset)));
      this->type |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->type |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->type |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->type);
      offset += this->points.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += sizeof(this->type);
      length += this->points.serializedLength();
      return length;
    }

    virtual tinyros::string getType(){ return "map_msgs/PointCloud2Update"; }
    static tinyros::string getTypeStatic(){ return "map_msgs/PointCloud2Update"; }
    virtual tinyros::string getMD5(){ return "e79dfbefd7336861352e1bc7148491c4"; }
    static tinyros::string getMD5Static(){ return "e79dfbefd7336861352e1bc7148491c4"; }
    virtual tinyros::string getDefinition(){ return "Header header\nuint32 type          \nsensor_msgs/PointCloud2 points\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\nuint32 type          \nsensor_msgs/PointCloud2 points\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
