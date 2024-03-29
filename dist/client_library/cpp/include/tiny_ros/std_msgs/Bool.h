#ifndef _TINYROS_std_msgs_Bool_h
#define _TINYROS_std_msgs_Bool_h

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

  class Bool : public tinyros::Msg
  {
    public:
      typedef bool _data_type;
      _data_type data;

    Bool():
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
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
        bool real;
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
      std::stringstream ss_data; ss_data << "\"data\":" << data <<"";
      string_echo += ss_data.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "std_msgs/Bool"; }
    static std::string getTypeStatic(){ return "std_msgs/Bool"; }
    virtual std::string getMD5(){ return "cf6f397ea93618cea833f64b7eef203e"; }
    static std::string getMD5Static(){ return "cf6f397ea93618cea833f64b7eef203e"; }
    virtual std::string getDefinition(){ return "bool data\n"; }
    static std::string getDefinitionStatic(){ return "bool data\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::std_msgs::Bool> Ptr;
    typedef std::shared_ptr<tinyros::std_msgs::Bool const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::std_msgs::Bool> BoolPtr;
typedef std::shared_ptr<tinyros::std_msgs::Bool const> BoolConstPtr;

}
}
#endif
