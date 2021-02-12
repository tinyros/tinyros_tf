#ifndef _TINYROS_nav_msgs_GetMapAction_h
#define _TINYROS_nav_msgs_GetMapAction_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/nav_msgs/GetMapActionGoal.h"
#include "tiny_ros/nav_msgs/GetMapActionResult.h"
#include "tiny_ros/nav_msgs/GetMapActionFeedback.h"

namespace tinyros
{
namespace nav_msgs
{

  class GetMapAction : public tinyros::Msg
  {
    public:
      typedef tinyros::nav_msgs::GetMapActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef tinyros::nav_msgs::GetMapActionResult _action_result_type;
      _action_result_type action_result;
      typedef tinyros::nav_msgs::GetMapActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    GetMapAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->action_goal.serializedLength();
      length += this->action_result.serializedLength();
      length += this->action_feedback.serializedLength();
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"action_goal\":";
      string_echo += this->action_goal.echo();
      string_echo += ",";
      string_echo += "\"action_result\":";
      string_echo += this->action_result.echo();
      string_echo += ",";
      string_echo += "\"action_feedback\":";
      string_echo += this->action_feedback.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "nav_msgs/GetMapAction"; }
    static std::string getTypeStatic(){ return "nav_msgs/GetMapAction"; }
    virtual std::string getMD5(){ return "10a4e277d7b8e53bfc3df54d98b3edb1"; }
    static std::string getMD5Static(){ return "10a4e277d7b8e53bfc3df54d98b3edb1"; }
    virtual std::string getDefinition(){ return "GetMapActionGoal action_goal\nGetMapActionResult action_result\nGetMapActionFeedback action_feedback\n"; }
    static std::string getDefinitionStatic(){ return "GetMapActionGoal action_goal\nGetMapActionResult action_result\nGetMapActionFeedback action_feedback\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::nav_msgs::GetMapAction> Ptr;
    typedef std::shared_ptr<tinyros::nav_msgs::GetMapAction const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::nav_msgs::GetMapAction> GetMapActionPtr;
typedef std::shared_ptr<tinyros::nav_msgs::GetMapAction const> GetMapActionConstPtr;

}
}
#endif
