#ifndef _TINYROS_std_msgs_Time_h
#define _TINYROS_std_msgs_Time_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/ros/time.h"

namespace tinyros
{
namespace std_msgs
{

  class Time : public tinyros::Msg
  {
    public:
      typedef tinyros::Time _data_type;
      _data_type data;

    Time():
      data()
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

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::stringstream ss_data;
      ss_data << "\"data\":{\"sec\":" << data.sec;
      ss_data << ",\"nsec\":" << data.nsec << "}";
      string_echo += ss_data.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "std_msgs/Time"; }
    static std::string getTypeStatic(){ return "std_msgs/Time"; }
    virtual std::string getMD5(){ return "64602ed67393e1e61260ab68d6fa2045"; }
    static std::string getMD5Static(){ return "64602ed67393e1e61260ab68d6fa2045"; }
    virtual std::string getDefinition(){ return "time data\n"; }
    static std::string getDefinitionStatic(){ return "time data\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::std_msgs::Time> Ptr;
    typedef std::shared_ptr<tinyros::std_msgs::Time const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::std_msgs::Time> TimePtr;
typedef std::shared_ptr<tinyros::std_msgs::Time const> TimeConstPtr;

}
}
#endif
