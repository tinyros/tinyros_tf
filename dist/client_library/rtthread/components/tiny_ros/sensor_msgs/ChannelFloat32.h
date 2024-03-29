#ifndef _TINYROS_sensor_msgs_ChannelFloat32_h
#define _TINYROS_sensor_msgs_ChannelFloat32_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace sensor_msgs
{

  class ChannelFloat32 : public tinyros::Msg
  {
    public:
      typedef tinyros::string _name_type;
      _name_type name;
      uint32_t values_length;
      typedef float _values_type;
      _values_type st_values;
      _values_type * values;

    ChannelFloat32():
      name(""),
      values_length(0), values(NULL)
    {
    }

    ~ChannelFloat32()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(values != NULL)
      {
        free(values);
      }
      values = NULL;
      values_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = this->name.size();
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name.c_str(), length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->values_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->values_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->values_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->values_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->values_length);
      for( uint32_t i = 0; i < values_length; i++) {
        union {
          float real;
          uint32_t base;
        } u_valuesi;
        u_valuesi.real = this->values[i];
        *(outbuffer + offset + 0) = (u_valuesi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_valuesi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_valuesi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_valuesi.base >> (8 * 3)) & 0xFF;
        offset += sizeof(this->values[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t values_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      values_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      values_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      values_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->values_length);
      if(values_lengthT > values_length)
        this->values = (float*)realloc(this->values, values_lengthT * sizeof(float));
      values_length = values_lengthT;
      for( uint32_t i = 0; i < values_length; i++) {
        union {
          float real;
          uint32_t base;
        } u_st_values;
        u_st_values.base = 0;
        u_st_values.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_values.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_values.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_values.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
        this->st_values = u_st_values.real;
        offset += sizeof(this->st_values);
        memcpy( &(this->values[i]), &(this->st_values), sizeof(float));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_name = this->name.size();
      length += 4;
      length += length_name;
      length += sizeof(this->values_length);
      for( uint32_t i = 0; i < values_length; i++) {
        length += sizeof(this->values[i]);
      }
      return length;
    }

    virtual tinyros::string getType(){ return "sensor_msgs/ChannelFloat32"; }
    static tinyros::string getTypeStatic(){ return "sensor_msgs/ChannelFloat32"; }
    virtual tinyros::string getMD5(){ return "c4cf01c81334c609dca1afd3a227daff"; }
    static tinyros::string getMD5Static(){ return "c4cf01c81334c609dca1afd3a227daff"; }
    virtual tinyros::string getDefinition(){ return "string name\nfloat32[] values\n"; }
    static tinyros::string getDefinitionStatic(){ return "string name\nfloat32[] values\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
