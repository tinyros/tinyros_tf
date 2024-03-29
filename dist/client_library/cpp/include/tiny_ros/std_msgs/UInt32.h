#ifndef _TINYROS_std_msgs_UInt32_h
#define _TINYROS_std_msgs_UInt32_h

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

  class UInt32 : public tinyros::Msg
  {
    public:
      typedef uint32_t _data_type;
      _data_type data;

    UInt32():
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->data >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->data =  ((uint32_t) (*(inbuffer + offset)));
      this->data |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->data |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
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

    virtual std::string getType(){ return "std_msgs/UInt32"; }
    static std::string getTypeStatic(){ return "std_msgs/UInt32"; }
    virtual std::string getMD5(){ return "d4e8dc9c9e9d5076e594a3e342c2d4e3"; }
    static std::string getMD5Static(){ return "d4e8dc9c9e9d5076e594a3e342c2d4e3"; }
    virtual std::string getDefinition(){ return "uint32 data\n"; }
    static std::string getDefinitionStatic(){ return "uint32 data\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::std_msgs::UInt32> Ptr;
    typedef std::shared_ptr<tinyros::std_msgs::UInt32 const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::std_msgs::UInt32> UInt32Ptr;
typedef std::shared_ptr<tinyros::std_msgs::UInt32 const> UInt32ConstPtr;

}
}
#endif
