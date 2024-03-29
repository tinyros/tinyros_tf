#ifndef _TINYROS_tinyros_msgs_Log_h
#define _TINYROS_tinyros_msgs_Log_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace tinyros_msgs
{

  class Log : public tinyros::Msg
  {
    public:
      typedef uint8_t _level_type;
      _level_type level;
      typedef std::string _msg_type;
      _msg_type msg;
      enum { ROSDEBUG = 0 };
      enum { ROSINFO = 1 };
      enum { ROSWARN = 2 };
      enum { ROSERROR = 3 };
      enum { ROSFATAL = 4 };

    Log():
      level(0),
      msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->level >> (8 * 0)) & 0xFF;
      offset += sizeof(this->level);
      uint32_t length_msg = this->msg.size();
      varToArr(outbuffer + offset, length_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->msg.c_str(), length_msg);
      offset += length_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->level =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->level);
      uint32_t length_msg;
      arrToVar(length_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->level);
      uint32_t length_msg = this->msg.size();
      length += 4;
      length += length_msg;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::stringstream ss_level; ss_level << "\"level\":" << (uint16_t)level <<",";
      string_echo += ss_level.str();
      std::size_t msg_pos = msg.find("\"");
      while(msg_pos != std::string::npos){
        msg.replace(msg_pos, 1,"\\\"");
        msg_pos = msg.find("\"", msg_pos+2);
      }
      string_echo += "\"msg\":\"";
      string_echo += msg;
      string_echo += "\"";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "tinyros_msgs/Log"; }
    static std::string getTypeStatic(){ return "tinyros_msgs/Log"; }
    virtual std::string getMD5(){ return "0bd74339b4d77cb15766d831a3d15eeb"; }
    static std::string getMD5Static(){ return "0bd74339b4d77cb15766d831a3d15eeb"; }
    virtual std::string getDefinition(){ return "uint8 level\nstring msg\n"; }
    static std::string getDefinitionStatic(){ return "uint8 level\nstring msg\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::tinyros_msgs::Log> Ptr;
    typedef std::shared_ptr<tinyros::tinyros_msgs::Log const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::tinyros_msgs::Log> LogPtr;
typedef std::shared_ptr<tinyros::tinyros_msgs::Log const> LogConstPtr;

}
}
#endif
