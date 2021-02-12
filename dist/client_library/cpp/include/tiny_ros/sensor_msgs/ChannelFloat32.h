#ifndef _TINYROS_sensor_msgs_ChannelFloat32_h
#define _TINYROS_sensor_msgs_ChannelFloat32_h

#include <stdint.h>
#include <string>
#include <stdio.h>
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
      typedef std::string _name_type;
      _name_type name;
      typedef float _values_type;
      std::vector<_values_type> values;

    ChannelFloat32():
      name(""),
      values(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = this->name.size();
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name.c_str(), length_name);
      offset += length_name;
      uint32_t values_length = this->values.size();
      *(outbuffer + offset + 0) = (values_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (values_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (values_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (values_length >> (8 * 3)) & 0xFF;
      offset += sizeof(values_length);
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
      uint32_t values_length = ((uint32_t) (*(inbuffer + offset))); 
      values_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      values_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      values_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->values.resize(values_length); 
      offset += sizeof(values_length);
      for( uint32_t i = 0; i < values_length; i++) {
        union {
          float real;
          uint32_t base;
        } u_valuesi;
        u_valuesi.base = 0;
        u_valuesi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_valuesi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_valuesi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_valuesi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
        this->values[i] = u_valuesi.real;
        offset += sizeof(this->values[i]);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_name = this->name.size();
      length += 4;
      length += length_name;
      uint32_t values_length = this->values.size();
      length += sizeof(values_length);
      for( uint32_t i = 0; i < values_length; i++) {
        length += sizeof(this->values[i]);
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::size_t name_pos = name.find("\"");
      while(name_pos != std::string::npos){
        name.replace(name_pos, 1,"\\\"");
        name_pos = name.find("\"", name_pos+2);
      }
      string_echo += "\"name\":\"";
      string_echo += name;
      string_echo += "\",";
      uint32_t values_length = this->values.size();
      string_echo += "values:[";
      for( uint32_t i = 0; i < values_length; i++) {
        if( i == (values_length - 1)) {
          std::stringstream ss_valuesi; ss_valuesi << values[i] <<"";
          string_echo += ss_valuesi.str();
        } else {
          std::stringstream ss_valuesi; ss_valuesi << values[i] <<",";
          string_echo += ss_valuesi.str();
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "sensor_msgs/ChannelFloat32"; }
    static std::string getTypeStatic(){ return "sensor_msgs/ChannelFloat32"; }
    virtual std::string getMD5(){ return "c4cf01c81334c609dca1afd3a227daff"; }
    static std::string getMD5Static(){ return "c4cf01c81334c609dca1afd3a227daff"; }
    virtual std::string getDefinition(){ return "string name\nfloat32[] values\n"; }
    static std::string getDefinitionStatic(){ return "string name\nfloat32[] values\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::sensor_msgs::ChannelFloat32> Ptr;
    typedef std::shared_ptr<tinyros::sensor_msgs::ChannelFloat32 const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::sensor_msgs::ChannelFloat32> ChannelFloat32Ptr;
typedef std::shared_ptr<tinyros::sensor_msgs::ChannelFloat32 const> ChannelFloat32ConstPtr;

}
}
#endif
