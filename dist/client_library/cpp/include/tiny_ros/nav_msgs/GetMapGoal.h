#ifndef _TINYROS_nav_msgs_GetMapGoal_h
#define _TINYROS_nav_msgs_GetMapGoal_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace nav_msgs
{

  class GetMapGoal : public tinyros::Msg
  {
    public:

    GetMapGoal()
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

    virtual std::string getType(){ return "nav_msgs/GetMapGoal"; }
    static std::string getTypeStatic(){ return "nav_msgs/GetMapGoal"; }
    virtual std::string getMD5(){ return "b39e6b705afaad0184bd2c87f4bd870f"; }
    static std::string getMD5Static(){ return "b39e6b705afaad0184bd2c87f4bd870f"; }
    virtual std::string getDefinition(){ return ""; }
    static std::string getDefinitionStatic(){ return ""; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::nav_msgs::GetMapGoal> Ptr;
    typedef std::shared_ptr<tinyros::nav_msgs::GetMapGoal const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::nav_msgs::GetMapGoal> GetMapGoalPtr;
typedef std::shared_ptr<tinyros::nav_msgs::GetMapGoal const> GetMapGoalConstPtr;

}
}
#endif
