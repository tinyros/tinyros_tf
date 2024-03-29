#ifndef _TINYROS_std_msgs_Char_h
#define _TINYROS_std_msgs_Char_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace std_msgs
{

  class Char : public tinyros::Msg
  {
    public:
      typedef char _data_type;
      _data_type data;

    Char():
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        char real;
        uint8_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        char real;
        uint8_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->data = u_data.real;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->data);
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::stringstream ss_data; ss_data << "\"data\":" << (int16_t)data <<"";
      string_echo += ss_data.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "std_msgs/Char"; }
    static std::string getTypeStatic(){ return "std_msgs/Char"; }
    virtual std::string getMD5(){ return "18741a80dcc02fcae20538073fcb0872"; }
    static std::string getMD5Static(){ return "18741a80dcc02fcae20538073fcb0872"; }
    virtual std::string getDefinition(){ return "char data\n"; }
    static std::string getDefinitionStatic(){ return "char data\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::std_msgs::Char> Ptr;
    typedef std::shared_ptr<tinyros::std_msgs::Char const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::std_msgs::Char> CharPtr;
typedef std::shared_ptr<tinyros::std_msgs::Char const> CharConstPtr;

}
}
#endif
