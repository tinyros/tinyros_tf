#ifndef _TINYROS_std_msgs_UInt16_h
#define _TINYROS_std_msgs_UInt16_h

#include <stdint.h>
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

    ~UInt16()
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

    virtual tinyros::string getType(){ return "std_msgs/UInt16"; }
    static tinyros::string getTypeStatic(){ return "std_msgs/UInt16"; }
    virtual tinyros::string getMD5(){ return "a4caad902eedb84b728d8369c50ffc39"; }
    static tinyros::string getMD5Static(){ return "a4caad902eedb84b728d8369c50ffc39"; }
    virtual tinyros::string getDefinition(){ return "uint16 data\n"; }
    static tinyros::string getDefinitionStatic(){ return "uint16 data\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
