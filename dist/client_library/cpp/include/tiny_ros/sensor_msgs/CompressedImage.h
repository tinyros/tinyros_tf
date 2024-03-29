#ifndef _TINYROS_sensor_msgs_CompressedImage_h
#define _TINYROS_sensor_msgs_CompressedImage_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"

namespace tinyros
{
namespace sensor_msgs
{

  class CompressedImage : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef std::string _format_type;
      _format_type format;
      typedef uint8_t _data_type;
      std::vector<_data_type> data;

    CompressedImage():
      header(),
      format(""),
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_format = this->format.size();
      varToArr(outbuffer + offset, length_format);
      offset += 4;
      memcpy(outbuffer + offset, this->format.c_str(), length_format);
      offset += length_format;
      uint32_t data_length = this->data.size();
      *(outbuffer + offset + 0) = (data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(data_length);
      for( uint32_t i = 0; i < data_length; i++) {
        *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
        offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_format;
      arrToVar(length_format, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_format; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_format-1]=0;
      this->format = (char *)(inbuffer + offset-1);
      offset += length_format;
      uint32_t data_length = ((uint32_t) (*(inbuffer + offset))); 
      data_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->data.resize(data_length); 
      offset += sizeof(data_length);
      for( uint32_t i = 0; i < data_length; i++) {
        this->data[i] =  ((uint8_t) (*(inbuffer + offset)));
        offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      uint32_t length_format = this->format.size();
      length += 4;
      length += length_format;
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
      std::size_t format_pos = format.find("\"");
      while(format_pos != std::string::npos){
        format.replace(format_pos, 1,"\\\"");
        format_pos = format.find("\"", format_pos+2);
      }
      string_echo += "\"format\":\"";
      string_echo += format;
      string_echo += "\",";
      uint32_t data_length = this->data.size();
      string_echo += "data:[";
      for( uint32_t i = 0; i < data_length; i++) {
        if( i == (data_length - 1)) {
          std::stringstream ss_datai; ss_datai << (uint16_t)data[i] <<"";
          string_echo += ss_datai.str();
        } else {
          std::stringstream ss_datai; ss_datai << (uint16_t)data[i] <<",";
          string_echo += ss_datai.str();
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "sensor_msgs/CompressedImage"; }
    static std::string getTypeStatic(){ return "sensor_msgs/CompressedImage"; }
    virtual std::string getMD5(){ return "eed57d856457441995644e6294152301"; }
    static std::string getMD5Static(){ return "eed57d856457441995644e6294152301"; }
    virtual std::string getDefinition(){ return "Header header\nstring format\nuint8[] data\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nstring format\nuint8[] data\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::sensor_msgs::CompressedImage> Ptr;
    typedef std::shared_ptr<tinyros::sensor_msgs::CompressedImage const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::sensor_msgs::CompressedImage> CompressedImagePtr;
typedef std::shared_ptr<tinyros::sensor_msgs::CompressedImage const> CompressedImageConstPtr;

}
}
#endif
