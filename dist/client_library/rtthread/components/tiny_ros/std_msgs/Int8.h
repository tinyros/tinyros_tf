#ifndef _TINYROS_std_msgs_Int8_h
#define _TINYROS_std_msgs_Int8_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace std_msgs
{

  class Int8 : public tinyros::Msg
  {
    public:
      typedef int8_t _data_type;
      _data_type data;

    Int8():
      data(0)
    {
    }

    ~Int8()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
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
        int8_t real;
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

    virtual tinyros::string getType(){ return "std_msgs/Int8"; }
    static tinyros::string getTypeStatic(){ return "std_msgs/Int8"; }
    virtual tinyros::string getMD5(){ return "36c967b84bec6cd7c260bffc7f4dfbe0"; }
    static tinyros::string getMD5Static(){ return "36c967b84bec6cd7c260bffc7f4dfbe0"; }
    virtual tinyros::string getDefinition(){ return "int8 data\n"; }
    static tinyros::string getDefinitionStatic(){ return "int8 data\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
