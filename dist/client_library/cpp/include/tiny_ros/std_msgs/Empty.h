#ifndef _TINYROS_std_msgs_Empty_h
#define _TINYROS_std_msgs_Empty_h

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

  class Empty : public tinyros::Msg
  {
    public:

    Empty()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "std_msgs/Empty"; }
    static std::string getTypeStatic(){ return "std_msgs/Empty"; }
    virtual std::string getMD5(){ return "140bdcb7bbc50b4a936e90ff2350c8d3"; }
    static std::string getMD5Static(){ return "140bdcb7bbc50b4a936e90ff2350c8d3"; }
    virtual std::string getDefinition(){ return ""; }
    static std::string getDefinitionStatic(){ return ""; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::std_msgs::Empty> Ptr;
    typedef std::shared_ptr<tinyros::std_msgs::Empty const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::std_msgs::Empty> EmptyPtr;
typedef std::shared_ptr<tinyros::std_msgs::Empty const> EmptyConstPtr;

}
}
#endif
