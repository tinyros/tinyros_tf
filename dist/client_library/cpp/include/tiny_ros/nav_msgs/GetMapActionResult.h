#ifndef _TINYROS_nav_msgs_GetMapActionResult_h
#define _TINYROS_nav_msgs_GetMapActionResult_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/actionlib_msgs/GoalStatus.h"
#include "tiny_ros/nav_msgs/GetMapResult.h"

namespace tinyros
{
namespace nav_msgs
{

  class GetMapActionResult : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef tinyros::nav_msgs::GetMapResult _result_type;
      _result_type result;

    GetMapActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->status.serializedLength();
      length += this->result.serializedLength();
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      string_echo += "\"status\":";
      string_echo += this->status.echo();
      string_echo += ",";
      string_echo += "\"result\":";
      string_echo += this->result.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "nav_msgs/GetMapActionResult"; }
    static std::string getTypeStatic(){ return "nav_msgs/GetMapActionResult"; }
    virtual std::string getMD5(){ return "9c9f64758f2627a010c16b17ea745028"; }
    static std::string getMD5Static(){ return "9c9f64758f2627a010c16b17ea745028"; }
    virtual std::string getDefinition(){ return "Header header\nactionlib_msgs/GoalStatus status\nGetMapResult result\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nactionlib_msgs/GoalStatus status\nGetMapResult result\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::nav_msgs::GetMapActionResult> Ptr;
    typedef std::shared_ptr<tinyros::nav_msgs::GetMapActionResult const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::nav_msgs::GetMapActionResult> GetMapActionResultPtr;
typedef std::shared_ptr<tinyros::nav_msgs::GetMapActionResult const> GetMapActionResultConstPtr;

}
}
#endif
