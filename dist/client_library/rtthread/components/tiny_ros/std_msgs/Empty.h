#ifndef _TINYROS_std_msgs_Empty_h
#define _TINYROS_std_msgs_Empty_h

#include <stdint.h>
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

    ~Empty()
    {
      deconstructor();
    }

    void deconstructor()
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

    virtual tinyros::string getType(){ return "std_msgs/Empty"; }
    static tinyros::string getTypeStatic(){ return "std_msgs/Empty"; }
    virtual tinyros::string getMD5(){ return "140bdcb7bbc50b4a936e90ff2350c8d3"; }
    static tinyros::string getMD5Static(){ return "140bdcb7bbc50b4a936e90ff2350c8d3"; }
    virtual tinyros::string getDefinition(){ return ""; }
    static tinyros::string getDefinitionStatic(){ return ""; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
