#ifndef _TINYROS_SERVICE_AddDiagnostics_h
#define _TINYROS_SERVICE_AddDiagnostics_h
#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace diagnostic_msgs
{

static const char ADDDIAGNOSTICS[] = "diagnostic_msgs/AddDiagnostics";

  class AddDiagnosticsRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef std::string _load_namespace_type;
      _load_namespace_type load_namespace;

    AddDiagnosticsRequest():
      load_namespace("")
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
      uint32_t length_load_namespace = this->load_namespace.size();
      varToArr(outbuffer + offset, length_load_namespace);
      offset += 4;
      memcpy(outbuffer + offset, this->load_namespace.c_str(), length_load_namespace);
      offset += length_load_namespace;
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
      uint32_t length_load_namespace;
      arrToVar(length_load_namespace, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_load_namespace; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_load_namespace-1]=0;
      this->load_namespace = (char *)(inbuffer + offset-1);
      offset += length_load_namespace;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_load_namespace = this->load_namespace.size();
      length += 4;
      length += length_load_namespace;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::size_t load_namespace_pos = load_namespace.find("\"");
      while(load_namespace_pos != std::string::npos){
        load_namespace.replace(load_namespace_pos, 1,"\\\"");
        load_namespace_pos = load_namespace.find("\"", load_namespace_pos+2);
      }
      string_echo += "\"load_namespace\":\"";
      string_echo += load_namespace;
      string_echo += "\"";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return ADDDIAGNOSTICS; }
    static std::string getTypeStatic(){ return ADDDIAGNOSTICS; }
    virtual std::string getMD5(){ return "005ba76b3cd04edebfe46acad928fbeb"; }
    static std::string getMD5Static(){ return "005ba76b3cd04edebfe46acad928fbeb"; }
    virtual std::string getDefinition(){ return "string load_namespace\n"; }
    static std::string getDefinitionStatic(){ return "string load_namespace\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::diagnostic_msgs::AddDiagnosticsRequest> Ptr;
    typedef std::shared_ptr<tinyros::diagnostic_msgs::AddDiagnosticsRequest const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::diagnostic_msgs::AddDiagnosticsRequest> AddDiagnosticsRequestPtr;
typedef std::shared_ptr<tinyros::diagnostic_msgs::AddDiagnosticsRequest const> AddDiagnosticsRequestConstPtr;

  class AddDiagnosticsResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef bool _success_type;
      _success_type success;
      typedef std::string _message_type;
      _message_type message;

    AddDiagnosticsResponse():
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

    virtual std::string getType(){ return ADDDIAGNOSTICS; }
    static std::string getTypeStatic(){ return ADDDIAGNOSTICS; }
    virtual std::string getMD5(){ return "9bd37b30a2340a31743d1e80a2c52ed0"; }
    static std::string getMD5Static(){ return "9bd37b30a2340a31743d1e80a2c52ed0"; }
    virtual std::string getDefinition(){ return "bool success\nstring message\n"; }
    static std::string getDefinitionStatic(){ return "bool success\nstring message\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::diagnostic_msgs::AddDiagnosticsResponse> Ptr;
    typedef std::shared_ptr<tinyros::diagnostic_msgs::AddDiagnosticsResponse const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::diagnostic_msgs::AddDiagnosticsResponse> AddDiagnosticsResponsePtr;
typedef std::shared_ptr<tinyros::diagnostic_msgs::AddDiagnosticsResponse const> AddDiagnosticsResponseConstPtr;

  class AddDiagnostics {
    public:
    typedef AddDiagnosticsRequest Request;
    typedef AddDiagnosticsResponse Response;
  };

}
}
#endif
