#ifndef _TINYROS_std_msgs_Float64_h
#define _TINYROS_std_msgs_Float64_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace std_msgs
{

  class Float64 : public tinyros::Msg
  {
    public:
      typedef double _data_type;
      _data_type data;

    Float64():
      data(0)
    {
    }

    ~Float64()
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
        double real;
        uint64_t base;
      } u_data;
      u_data.real = this->data;
      *(outbuffer + offset + 0) = (u_data.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_data.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_data.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_data.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_data.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_data.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_data.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_data.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->data);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_data;
      u_data.base = 0;
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_data.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
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

    virtual tinyros::string getType(){ return "std_msgs/Float64"; }
    static tinyros::string getTypeStatic(){ return "std_msgs/Float64"; }
    virtual tinyros::string getMD5(){ return "3439fe880debfd63cf4e61e62e285345"; }
    static tinyros::string getMD5Static(){ return "3439fe880debfd63cf4e61e62e285345"; }
    virtual tinyros::string getDefinition(){ return "float64 data\n"; }
    static tinyros::string getDefinitionStatic(){ return "float64 data\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif