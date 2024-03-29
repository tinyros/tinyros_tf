#ifndef _TINYROS_diagnostic_msgs_KeyValue_h
#define _TINYROS_diagnostic_msgs_KeyValue_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace diagnostic_msgs
{

  class KeyValue : public tinyros::Msg
  {
    public:
      typedef tinyros::string _key_type;
      _key_type key;
      typedef tinyros::string _value_type;
      _value_type value;

    KeyValue():
      key(""),
      value("")
    {
    }

    ~KeyValue()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_key = this->key.size();
      varToArr(outbuffer + offset, length_key);
      offset += 4;
      memcpy(outbuffer + offset, this->key.c_str(), length_key);
      offset += length_key;
      uint32_t length_value = this->value.size();
      varToArr(outbuffer + offset, length_value);
      offset += 4;
      memcpy(outbuffer + offset, this->value.c_str(), length_value);
      offset += length_value;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_key;
      arrToVar(length_key, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_key; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_key-1]=0;
      this->key = (char *)(inbuffer + offset-1);
      offset += length_key;
      uint32_t length_value;
      arrToVar(length_value, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value-1]=0;
      this->value = (char *)(inbuffer + offset-1);
      offset += length_value;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_key = this->key.size();
      length += 4;
      length += length_key;
      uint32_t length_value = this->value.size();
      length += 4;
      length += length_value;
      return length;
    }

    virtual tinyros::string getType(){ return "diagnostic_msgs/KeyValue"; }
    static tinyros::string getTypeStatic(){ return "diagnostic_msgs/KeyValue"; }
    virtual tinyros::string getMD5(){ return "1baa904b80c685c77d1a42a872ca1d07"; }
    static tinyros::string getMD5Static(){ return "1baa904b80c685c77d1a42a872ca1d07"; }
    virtual tinyros::string getDefinition(){ return "string key \nstring value \n"; }
    static tinyros::string getDefinitionStatic(){ return "string key \nstring value \n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
