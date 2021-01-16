#ifndef _TINYROS_std_msgs_UInt8_h
#define _TINYROS_std_msgs_UInt8_h

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

  class UInt8 : public tinyros::Msg
  {
    public:
      typedef uint8_t _data_type;
      _data_type data;

    UInt8():
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->data >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->data =  ((uint8_t) (*(inbuffer + offset)));
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
      std::stringstream ss_data; ss_data << "\"data\":" << (uint16_t)data <<"";
      string_echo += ss_data.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "std_msgs/UInt8"; }
    static std::string getTypeStatic(){ return "std_msgs/UInt8"; }
    virtual std::string getMD5(){ return "6f90555707d539e508484b884b2acc65"; }
    static std::string getMD5Static(){ return "6f90555707d539e508484b884b2acc65"; }
    virtual std::string getDefinition(){ return "uint8 data\n"; }
    static std::string getDefinitionStatic(){ return "uint8 data\n"; }
    static bool hasHeader(){ return false; }
  };

typedef std::shared_ptr<tinyros::std_msgs::UInt8> UInt8Ptr;
typedef std::shared_ptr<tinyros::std_msgs::UInt8 const> UInt8ConstPtr;

}
}
#endif
