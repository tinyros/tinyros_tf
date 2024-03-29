#ifndef _TINYROS_sensor_msgs_Range_h
#define _TINYROS_sensor_msgs_Range_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"

namespace tinyros
{
namespace sensor_msgs
{

  class Range : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef uint8_t _radiation_type_type;
      _radiation_type_type radiation_type;
      typedef float _field_of_view_type;
      _field_of_view_type field_of_view;
      typedef float _min_range_type;
      _min_range_type min_range;
      typedef float _max_range_type;
      _max_range_type max_range;
      typedef float _range_type;
      _range_type range;
      enum { ULTRASOUND = 0 };
      enum { INFRARED = 1 };

    Range():
      header(),
      radiation_type(0),
      field_of_view(0),
      min_range(0),
      max_range(0),
      range(0)
    {
    }

    ~Range()
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
      *(outbuffer + offset + 0) = (this->radiation_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->radiation_type);
      union {
        float real;
        uint32_t base;
      } u_field_of_view;
      u_field_of_view.real = this->field_of_view;
      *(outbuffer + offset + 0) = (u_field_of_view.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_field_of_view.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_field_of_view.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_field_of_view.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->field_of_view);
      union {
        float real;
        uint32_t base;
      } u_min_range;
      u_min_range.real = this->min_range;
      *(outbuffer + offset + 0) = (u_min_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_range);
      union {
        float real;
        uint32_t base;
      } u_max_range;
      u_max_range.real = this->max_range;
      *(outbuffer + offset + 0) = (u_max_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_range);
      union {
        float real;
        uint32_t base;
      } u_range;
      u_range.real = this->range;
      *(outbuffer + offset + 0) = (u_range.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->radiation_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->radiation_type);
      union {
        float real;
        uint32_t base;
      } u_field_of_view;
      u_field_of_view.base = 0;
      u_field_of_view.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_field_of_view.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_field_of_view.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_field_of_view.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->field_of_view = u_field_of_view.real;
      offset += sizeof(this->field_of_view);
      union {
        float real;
        uint32_t base;
      } u_min_range;
      u_min_range.base = 0;
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_range = u_min_range.real;
      offset += sizeof(this->min_range);
      union {
        float real;
        uint32_t base;
      } u_max_range;
      u_max_range.base = 0;
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_range = u_max_range.real;
      offset += sizeof(this->max_range);
      union {
        float real;
        uint32_t base;
      } u_range;
      u_range.base = 0;
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range = u_range.real;
      offset += sizeof(this->range);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += sizeof(this->radiation_type);
      length += sizeof(this->field_of_view);
      length += sizeof(this->min_range);
      length += sizeof(this->max_range);
      length += sizeof(this->range);
      return length;
    }

    virtual tinyros::string getType(){ return "sensor_msgs/Range"; }
    static tinyros::string getTypeStatic(){ return "sensor_msgs/Range"; }
    virtual tinyros::string getMD5(){ return "54d647e3a481f5b87ce39d1b97e84d53"; }
    static tinyros::string getMD5Static(){ return "54d647e3a481f5b87ce39d1b97e84d53"; }
    virtual tinyros::string getDefinition(){ return "Header header           \nuint8 radiation_type    \nfloat32 field_of_view   \nfloat32 min_range       \nfloat32 max_range       \nfloat32 range           \n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header           \nuint8 radiation_type    \nfloat32 field_of_view   \nfloat32 min_range       \nfloat32 max_range       \nfloat32 range           \n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
