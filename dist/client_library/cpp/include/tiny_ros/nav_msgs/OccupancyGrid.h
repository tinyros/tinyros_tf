#ifndef _TINYROS_nav_msgs_OccupancyGrid_h
#define _TINYROS_nav_msgs_OccupancyGrid_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/nav_msgs/MapMetaData.h"

namespace tinyros
{
namespace nav_msgs
{

  class OccupancyGrid : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::nav_msgs::MapMetaData _info_type;
      _info_type info;
      typedef int8_t _data_type;
      std::vector<_data_type> data;

    OccupancyGrid():
      header(),
      info(),
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->info.serialize(outbuffer + offset);
      uint32_t data_length = this->data.size();
      *(outbuffer + offset + 0) = (data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(data_length);
      for( uint32_t i = 0; i < data_length; i++) {
        union {
          int8_t real;
          uint8_t base;
        } u_datai;
        u_datai.real = this->data[i];
        *(outbuffer + offset + 0) = (u_datai.base >> (8 * 0)) & 0xFF;
        offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->info.deserialize(inbuffer + offset);
      uint32_t data_length = ((uint32_t) (*(inbuffer + offset))); 
      data_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->data.resize(data_length); 
      offset += sizeof(data_length);
      for( uint32_t i = 0; i < data_length; i++) {
        union {
          int8_t real;
          uint8_t base;
        } u_datai;
        u_datai.base = 0;
        u_datai.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
        this->data[i] = u_datai.real;
        offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->info.serializedLength();
      uint32_t data_length = this->data.size();
      length += sizeof(data_length);
      for( uint32_t i = 0; i < data_length; i++) {
        length += sizeof(this->data[i]);
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      string_echo += "\"info\":";
      string_echo += this->info.echo();
      string_echo += ",";
      uint32_t data_length = this->data.size();
      string_echo += "data:[";
      for( uint32_t i = 0; i < data_length; i++) {
        if( i == (data_length - 1)) {
          std::stringstream ss_datai; ss_datai <<(int16_t)data[i] <<"";
          string_echo += ss_datai.str();
        } else {
          std::stringstream ss_datai; ss_datai <<(int16_t)data[i] <<",";
          string_echo += ss_datai.str();
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "nav_msgs/OccupancyGrid"; }
    static std::string getTypeStatic(){ return "nav_msgs/OccupancyGrid"; }
    virtual std::string getMD5(){ return "e489a26457224a97799696f3642f16a0"; }
    static std::string getMD5Static(){ return "e489a26457224a97799696f3642f16a0"; }
    virtual std::string getDefinition(){ return "Header header\nMapMetaData info\nint8[] data\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nMapMetaData info\nint8[] data\n"; }
    static bool hasHeader(){ return true; }
  };

typedef std::shared_ptr<tinyros::nav_msgs::OccupancyGrid> OccupancyGridPtr;
typedef std::shared_ptr<tinyros::nav_msgs::OccupancyGrid const> OccupancyGridConstPtr;

}
}
#endif
