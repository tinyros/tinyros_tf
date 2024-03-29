#ifndef _TINYROS_std_msgs_Float32_h
#define _TINYROS_std_msgs_Float32_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace std_msgs
{

  class Float32 : public tinyros::Msg
  {
    public:
      typedef float _data_type;
      _data_type data;

    Float32():
      data(0)
    {
    }

    ~Float32()
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
        float real;
        uint32_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_data.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_data.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_data.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_data.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
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

    virtual tinyros::string getType(){ return "std_msgs/Float32"; }
    static tinyros::string getTypeStatic(){ return "std_msgs/Float32"; }
    virtual tinyros::string getMD5(){ return "2aff5d2343e8e80ceea1362fc770035c"; }
    static tinyros::string getMD5Static(){ return "2aff5d2343e8e80ceea1362fc770035c"; }
    virtual tinyros::string getDefinition(){ return "float32 data\n"; }
    static tinyros::string getDefinitionStatic(){ return "float32 data\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
