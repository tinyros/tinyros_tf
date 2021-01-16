#ifndef _TINYROS_sensor_msgs_PointCloud_h
#define _TINYROS_sensor_msgs_PointCloud_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Point32.h"
#include "tiny_ros/sensor_msgs/ChannelFloat32.h"

namespace tinyros
{
namespace sensor_msgs
{

  class PointCloud : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Point32 _points_type;
      std::vector<_points_type> points;
      typedef tinyros::sensor_msgs::ChannelFloat32 _channels_type;
      std::vector<_channels_type> channels;

    PointCloud():
      header(),
      points(0),
      channels(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t points_length = this->points.size();
      *(outbuffer + offset + 0) = (points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        offset += this->points[i].serialize(outbuffer + offset);
      }
      uint32_t channels_length = this->channels.size();
      *(outbuffer + offset + 0) = (channels_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (channels_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (channels_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (channels_length >> (8 * 3)) & 0xFF;
      offset += sizeof(channels_length);
      for( uint32_t i = 0; i < channels_length; i++) {
        offset += this->channels[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t points_length = ((uint32_t) (*(inbuffer + offset))); 
      points_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->points.resize(points_length); 
      offset += sizeof(points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        offset += this->points[i].deserialize(inbuffer + offset);
      }
      uint32_t channels_length = ((uint32_t) (*(inbuffer + offset))); 
      channels_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      channels_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      channels_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->channels.resize(channels_length); 
      offset += sizeof(channels_length);
      for( uint32_t i = 0; i < channels_length; i++) {
        offset += this->channels[i].deserialize(inbuffer + offset);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      uint32_t points_length = this->points.size();
      length += sizeof(points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        length += this->points[i].serializedLength();
      }
      uint32_t channels_length = this->channels.size();
      length += sizeof(channels_length);
      for( uint32_t i = 0; i < channels_length; i++) {
        length += this->channels[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
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
      string_echo += "],";
      uint32_t channels_length = this->channels.size();
      string_echo += "channels:[";
      for( uint32_t i = 0; i < channels_length; i++) {
        if( i == (channels_length - 1)) {
          string_echo += this->channels[i].echo();
          string_echo += "";
        } else {
          string_echo += this->channels[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "sensor_msgs/PointCloud"; }
    static std::string getTypeStatic(){ return "sensor_msgs/PointCloud"; }
    virtual std::string getMD5(){ return "b01249148cae0106a561ab36cd1e48a8"; }
    static std::string getMD5Static(){ return "b01249148cae0106a561ab36cd1e48a8"; }
    virtual std::string getDefinition(){ return "Header header\ngeometry_msgs/Point32[] points\nChannelFloat32[] channels\n"; }
    static std::string getDefinitionStatic(){ return "Header header\ngeometry_msgs/Point32[] points\nChannelFloat32[] channels\n"; }
    static bool hasHeader(){ return true; }
  };

typedef std::shared_ptr<tinyros::sensor_msgs::PointCloud> PointCloudPtr;
typedef std::shared_ptr<tinyros::sensor_msgs::PointCloud const> PointCloudConstPtr;

}
}
#endif
