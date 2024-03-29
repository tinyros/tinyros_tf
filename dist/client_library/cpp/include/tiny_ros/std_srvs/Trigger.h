#ifndef _TINYROS_SERVICE_Trigger_h
#define _TINYROS_SERVICE_Trigger_h
#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace std_srvs
{

static const char TRIGGER[] = "std_srvs/Trigger";

  class TriggerRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:

    TriggerRequest()
    {
      this->__id__ = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->__id__ >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->__id__ >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->__id__ >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->__id__ >> (8 * 3)) & 0xFF;
      offset += sizeof(this->__id__);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->__id__ =  ((uint32_t) (*(inbuffer + offset)));
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->__id__);
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

    virtual std::string getType(){ return TRIGGER; }
    static std::string getTypeStatic(){ return TRIGGER; }
    virtual std::string getMD5(){ return "23ce35174a691cb0bfbbdb21395edbac"; }
    static std::string getMD5Static(){ return "23ce35174a691cb0bfbbdb21395edbac"; }
    virtual std::string getDefinition(){ return ""; }
    static std::string getDefinitionStatic(){ return ""; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::std_srvs::TriggerRequest> Ptr;
    typedef std::shared_ptr<tinyros::std_srvs::TriggerRequest const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::std_srvs::TriggerRequest> TriggerRequestPtr;
typedef std::shared_ptr<tinyros::std_srvs::TriggerRequest const> TriggerRequestConstPtr;

  class TriggerResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef bool _success_type;
      _success_type success;
      typedef std::string _message_type;
      _message_type message;

    TriggerResponse():
      success(0),
      message("")
    {
      this->__id__ = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->__id__ >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->__id__ >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->__id__ >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->__id__ >> (8 * 3)) & 0xFF;
      offset += sizeof(this->__id__);
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_message = this->message.size();
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message.c_str(), length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->__id__ =  ((uint32_t) (*(inbuffer + offset)));
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->__id__);
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->success);
      uint32_t length_message = this->message.size();
      length += 4;
      length += length_message;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::stringstream ss_success; ss_success << "\"success\":" << success <<",";
      string_echo += ss_success.str();
      std::size_t message_pos = message.find("\"");
      while(message_pos != std::string::npos){
        message.replace(message_pos, 1,"\\\"");
        message_pos = message.find("\"", message_pos+2);
      }
      string_echo += "\"message\":\"";
      string_echo += message;
      string_echo += "\"";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return TRIGGER; }
    static std::string getTypeStatic(){ return TRIGGER; }
    virtual std::string getMD5(){ return "08d111154ed595049573252ba929a6d8"; }
    static std::string getMD5Static(){ return "08d111154ed595049573252ba929a6d8"; }
    virtual std::string getDefinition(){ return "bool success\nstring message\n"; }
    static std::string getDefinitionStatic(){ return "bool success\nstring message\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::std_srvs::TriggerResponse> Ptr;
    typedef std::shared_ptr<tinyros::std_srvs::TriggerResponse const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::std_srvs::TriggerResponse> TriggerResponsePtr;
typedef std::shared_ptr<tinyros::std_srvs::TriggerResponse const> TriggerResponseConstPtr;

  class Trigger {
    public:
    typedef TriggerRequest Request;
    typedef TriggerResponse Response;
  };

}
}
#endif
