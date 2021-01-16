#ifndef _TINYROS_sensor_msgs_JoyFeedbackArray_h
#define _TINYROS_sensor_msgs_JoyFeedbackArray_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/sensor_msgs/JoyFeedback.h"

namespace tinyros
{
namespace sensor_msgs
{

  class JoyFeedbackArray : public tinyros::Msg
  {
    public:
      typedef tinyros::sensor_msgs::JoyFeedback _array_type;
      std::vector<_array_type> array;

    JoyFeedbackArray():
      array(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t array_length = this->array.size();
      *(outbuffer + offset + 0) = (array_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (array_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (array_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (array_length >> (8 * 3)) & 0xFF;
      offset += sizeof(array_length);
      for( uint32_t i = 0; i < array_length; i++) {
        offset += this->array[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t array_length = ((uint32_t) (*(inbuffer + offset))); 
      array_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      array_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      array_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->array.resize(array_length); 
      offset += sizeof(array_length);
      for( uint32_t i = 0; i < array_length; i++) {
        offset += this->array[i].deserialize(inbuffer + offset);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t array_length = this->array.size();
      length += sizeof(array_length);
      for( uint32_t i = 0; i < array_length; i++) {
        length += this->array[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      uint32_t array_length = this->array.size();
      string_echo += "array:[";
      for( uint32_t i = 0; i < array_length; i++) {
        if( i == (array_length - 1)) {
          string_echo += this->array[i].echo();
          string_echo += "";
        } else {
          string_echo += this->array[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "sensor_msgs/JoyFeedbackArray"; }
    static std::string getTypeStatic(){ return "sensor_msgs/JoyFeedbackArray"; }
    virtual std::string getMD5(){ return "45361e458d526d5670706a9f083819b6"; }
    static std::string getMD5Static(){ return "45361e458d526d5670706a9f083819b6"; }
    virtual std::string getDefinition(){ return "JoyFeedback[] array\n"; }
    static std::string getDefinitionStatic(){ return "JoyFeedback[] array\n"; }
    static bool hasHeader(){ return false; }
  };

typedef std::shared_ptr<tinyros::sensor_msgs::JoyFeedbackArray> JoyFeedbackArrayPtr;
typedef std::shared_ptr<tinyros::sensor_msgs::JoyFeedbackArray const> JoyFeedbackArrayConstPtr;

}
}
#endif
