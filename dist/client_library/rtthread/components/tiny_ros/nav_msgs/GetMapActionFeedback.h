#ifndef _TINYROS_nav_msgs_GetMapActionFeedback_h
#define _TINYROS_nav_msgs_GetMapActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/actionlib_msgs/GoalStatus.h"
#include "tiny_ros/nav_msgs/GetMapFeedback.h"

namespace tinyros
{
namespace nav_msgs
{

  class GetMapActionFeedback : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef tinyros::nav_msgs::GetMapFeedback _feedback_type;
      _feedback_type feedback;

    GetMapActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    ~GetMapActionFeedback()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->status.serializedLength();
      length += this->feedback.serializedLength();
      return length;
    }

    virtual tinyros::string getType(){ return "nav_msgs/GetMapActionFeedback"; }
    static tinyros::string getTypeStatic(){ return "nav_msgs/GetMapActionFeedback"; }
    virtual tinyros::string getMD5(){ return "9ebb88ff2cf2120160bf2197071a69b6"; }
    static tinyros::string getMD5Static(){ return "9ebb88ff2cf2120160bf2197071a69b6"; }
    virtual tinyros::string getDefinition(){ return "Header header\nactionlib_msgs/GoalStatus status\nGetMapFeedback feedback\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\nactionlib_msgs/GoalStatus status\nGetMapFeedback feedback\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
