#ifndef _TINYROS_std_msgs_UInt32_h
#define _TINYROS_std_msgs_UInt32_h

#include <stdint.h>
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

    ~UInt32()
    {
      deconstructor();
    }

    void deconstructor()
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

    virtual tinyros::string getType(){ return "std_msgs/UInt32"; }
    static tinyros::string getTypeStatic(){ return "std_msgs/UInt32"; }
    virtual tinyros::string getMD5(){ return "d4e8dc9c9e9d5076e594a3e342c2d4e3"; }
    static tinyros::string getMD5Static(){ return "d4e8dc9c9e9d5076e594a3e342c2d4e3"; }
    virtual tinyros::string getDefinition(){ return "uint32 data\n"; }
    static tinyros::string getDefinitionStatic(){ return "uint32 data\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
