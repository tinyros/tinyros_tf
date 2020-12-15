#ifndef _TINYROS_sensor_msgs_Image_h
#define _TINYROS_sensor_msgs_Image_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"

namespace tinyros
{
namespace sensor_msgs
{

  class Image : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _height_type;
      _height_type height;
      typedef uint32_t _width_type;
      _width_type width;
      typedef tinyros::string _encoding_type;
      _encoding_type encoding;
      typedef uint8_t _is_bigendian_type;
      _is_bigendian_type is_bigendian;
      typedef uint32_t _step_type;
      _step_type step;
      uint32_t data_length;
      typedef uint8_t _data_type;
      _data_type st_data;
      _data_type * data;

    Image():
      header(),
      height(0),
      width(0),
      encoding(""),
      is_bigendian(0),
      step(0),
      data_length(0), data(NULL)
    {
    }

    ~Image()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(data != NULL)
      {
        free(data);
      }
      data = NULL;
      data_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      uint32_t length_encoding = this->encoding.size();
      varToArr(outbuffer + offset, length_encoding);
      offset += 4;
      memcpy(outbuffer + offset, this->encoding.c_str(), length_encoding);
      offset += length_encoding;
      *(outbuffer + offset + 0) = (this->is_bigendian >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_bigendian);
      *(outbuffer + offset + 0) = (this->step >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->step >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->step >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->step >> (8 * 3)) & 0xFF;
      offset += sizeof(this->step);
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
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
      this->height =  ((uint32_t) (*(inbuffer + offset)));
      this->height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->height);
      this->width =  ((uint32_t) (*(inbuffer + offset)));
      this->width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->width);
      uint32_t length_encoding;
      arrToVar(length_encoding, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_encoding; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_encoding-1]=0;
      this->encoding = (char *)(inbuffer + offset-1);
      offset += length_encoding;
      this->is_bigendian =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->is_bigendian);
      this->step =  ((uint32_t) (*(inbuffer + offset)));
      this->step |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->step |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->step |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->step);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (uint8_t*)realloc(this->data, data_lengthT * sizeof(uint8_t));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++) {
        this->st_data =  ((uint8_t) (*(inbuffer + offset)));
        offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(uint8_t));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += sizeof(this->height);
      length += sizeof(this->width);
      uint32_t length_encoding = this->encoding.size();
      length += 4;
      length += length_encoding;
      length += sizeof(this->is_bigendian);
      length += sizeof(this->step);
      length += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++) {
        length += sizeof(this->data[i]);
      }
      return length;
    }

    virtual tinyros::string getType(){ return "sensor_msgs/Image"; }
    static tinyros::string getTypeStatic(){ return "sensor_msgs/Image"; }
    virtual tinyros::string getMD5(){ return "886f928dc81bf7f1496a8b452057c5b2"; }
    static tinyros::string getMD5Static(){ return "886f928dc81bf7f1496a8b452057c5b2"; }
    virtual tinyros::string getDefinition(){ return "Header header        \nuint32 height         \nuint32 width          \nstring encoding       \nuint8 is_bigendian    \nuint32 step           \nuint8[] data          \n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header        \nuint32 height         \nuint32 width          \nstring encoding       \nuint8 is_bigendian    \nuint32 step           \nuint8[] data          \n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
