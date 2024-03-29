#ifndef _TINYROS_std_msgs_Duration_h
#define _TINYROS_std_msgs_Duration_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/ros/duration.h"

namespace tinyros
{
namespace std_msgs
{

  class Duration : public tinyros::Msg
  {
    public:
      typedef tinyros::Duration _data_type;
      _data_type data;

    Duration():
      data()
    {
    }

    ~Duration()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->data.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data.sec);
      *(outbuffer + offset + 0) = (this->data.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->data.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->data.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->data.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->data.sec);
      this->data.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->data.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->data.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->data.nsec);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->data.sec);
      length += sizeof(this->data.nsec);
      return length;
    }

    virtual tinyros::string getType(){ return "std_msgs/Duration"; }
    static tinyros::string getTypeStatic(){ return "std_msgs/Duration"; }
    virtual tinyros::string getMD5(){ return "5dc598a1f3dfbcf0b7343c41b15d6ab2"; }
    static tinyros::string getMD5Static(){ return "5dc598a1f3dfbcf0b7343c41b15d6ab2"; }
    virtual tinyros::string getDefinition(){ return "duration data\n"; }
    static tinyros::string getDefinitionStatic(){ return "duration data\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
