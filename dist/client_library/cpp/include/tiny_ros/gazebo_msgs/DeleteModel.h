#ifndef _TINYROS_SERVICE_DeleteModel_h
#define _TINYROS_SERVICE_DeleteModel_h
#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace gazebo_msgs
{

static const char DELETEMODEL[] = "gazebo_msgs/DeleteModel";

  class DeleteModelRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef std::string _model_name_type;
      _model_name_type model_name;

    DeleteModelRequest():
      model_name("")
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
      uint32_t length_model_name = this->model_name.size();
      varToArr(outbuffer + offset, length_model_name);
      offset += 4;
      memcpy(outbuffer + offset, this->model_name.c_str(), length_model_name);
      offset += length_model_name;
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
      uint32_t length_model_name;
      arrToVar(length_model_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model_name-1]=0;
      this->model_name = (char *)(inbuffer + offset-1);
      offset += length_model_name;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_model_name = this->model_name.size();
      length += 4;
      length += length_model_name;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::size_t model_name_pos = model_name.find("\"");
      while(model_name_pos != std::string::npos){
        model_name.replace(model_name_pos, 1,"\\\"");
        model_name_pos = model_name.find("\"", model_name_pos+2);
      }
      string_echo += "\"model_name\":\"";
      string_echo += model_name;
      string_echo += "\"";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return DELETEMODEL; }
    static std::string getTypeStatic(){ return DELETEMODEL; }
    virtual std::string getMD5(){ return "c4e25cd35d75c6c2f51ee0d986d8e556"; }
    static std::string getMD5Static(){ return "c4e25cd35d75c6c2f51ee0d986d8e556"; }
    virtual std::string getDefinition(){ return "string model_name\n"; }
    static std::string getDefinitionStatic(){ return "string model_name\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::DeleteModelRequest> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::DeleteModelRequest const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::DeleteModelRequest> DeleteModelRequestPtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::DeleteModelRequest const> DeleteModelRequestConstPtr;

  class DeleteModelResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef bool _success_type;
      _success_type success;
      typedef std::string _status_message_type;
      _status_message_type status_message;

    DeleteModelResponse():
      success(0),
      status_message("")
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
      uint32_t length_status_message = this->status_message.size();
      varToArr(outbuffer + offset, length_status_message);
      offset += 4;
      memcpy(outbuffer + offset, this->status_message.c_str(), length_status_message);
      offset += length_status_message;
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
      uint32_t length_status_message;
      arrToVar(length_status_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status_message; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status_message-1]=0;
      this->status_message = (char *)(inbuffer + offset-1);
      offset += length_status_message;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->success);
      uint32_t length_status_message = this->status_message.size();
      length += 4;
      length += length_status_message;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::stringstream ss_success; ss_success << "\"success\":" << success <<",";
      string_echo += ss_success.str();
      std::size_t status_message_pos = status_message.find("\"");
      while(status_message_pos != std::string::npos){
        status_message.replace(status_message_pos, 1,"\\\"");
        status_message_pos = status_message.find("\"", status_message_pos+2);
      }
      string_echo += "\"status_message\":\"";
      string_echo += status_message;
      string_echo += "\"";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return DELETEMODEL; }
    static std::string getTypeStatic(){ return DELETEMODEL; }
    virtual std::string getMD5(){ return "3feb2eeea1c45bcf64067e4dd162726f"; }
    static std::string getMD5Static(){ return "3feb2eeea1c45bcf64067e4dd162726f"; }
    virtual std::string getDefinition(){ return "bool success\nstring status_message\n"; }
    static std::string getDefinitionStatic(){ return "bool success\nstring status_message\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::DeleteModelResponse> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::DeleteModelResponse const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::DeleteModelResponse> DeleteModelResponsePtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::DeleteModelResponse const> DeleteModelResponseConstPtr;

  class DeleteModel {
    public:
    typedef DeleteModelRequest Request;
    typedef DeleteModelResponse Response;
  };

}
}
#endif
