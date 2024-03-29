#ifndef _TINYROS_std_msgs_UInt16_h
#define _TINYROS_std_msgs_UInt16_h

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

  class UInt16 : public tinyros::Msg
  {
    public:
      typedef uint16_t _data_type;
      _data_type data;

    UInt16():
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->data >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data >> (8 * 1)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->data =  ((uint16_t) (*(inbuffer + offset)));
      this->data |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
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

    virtual std::string getType(){ return "std_msgs/UInt16"; }
    static std::string getTypeStatic(){ return "std_msgs/UInt16"; }
    virtual std::string getMD5(){ return "a4caad902eedb84b728d8369c50ffc39"; }
    static std::string getMD5Static(){ return "a4caad902eedb84b728d8369c50ffc39"; }
    virtual std::string getDefinition(){ return "uint16 data\n"; }
    static std::string getDefinitionStatic(){ return "uint16 data\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::std_msgs::UInt16> Ptr;
    typedef std::shared_ptr<tinyros::std_msgs::UInt16 const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::std_msgs::UInt16> UInt16Ptr;
typedef std::shared_ptr<tinyros::std_msgs::UInt16 const> UInt16ConstPtr;

}
}
#endif
