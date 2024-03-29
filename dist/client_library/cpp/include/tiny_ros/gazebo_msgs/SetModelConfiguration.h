#ifndef _TINYROS_SERVICE_SetModelConfiguration_h
#define _TINYROS_SERVICE_SetModelConfiguration_h
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

static const char SETMODELCONFIGURATION[] = "gazebo_msgs/SetModelConfiguration";

  class SetModelConfigurationRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef std::string _model_name_type;
      _model_name_type model_name;
      typedef std::string _urdf_param_name_type;
      _urdf_param_name_type urdf_param_name;
      typedef std::string _joint_names_type;
      std::vector<_joint_names_type> joint_names;
      typedef double _joint_positions_type;
      std::vector<_joint_positions_type> joint_positions;

    SetModelConfigurationRequest():
      model_name(""),
      urdf_param_name(""),
      joint_names(0),
      joint_positions(0)
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
      uint32_t length_urdf_param_name = this->urdf_param_name.size();
      varToArr(outbuffer + offset, length_urdf_param_name);
      offset += 4;
      memcpy(outbuffer + offset, this->urdf_param_name.c_str(), length_urdf_param_name);
      offset += length_urdf_param_name;
      uint32_t joint_names_length = this->joint_names.size();
      *(outbuffer + offset + 0) = (joint_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (joint_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (joint_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (joint_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_joint_namesi = this->joint_names[i].size();
        varToArr(outbuffer + offset, length_joint_namesi);
        offset += 4;
        memcpy(outbuffer + offset, this->joint_names[i].c_str(), length_joint_namesi);
        offset += length_joint_namesi;
      }
      uint32_t joint_positions_length = this->joint_positions.size();
      *(outbuffer + offset + 0) = (joint_positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (joint_positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (joint_positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (joint_positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(joint_positions_length);
      for( uint32_t i = 0; i < joint_positions_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_joint_positionsi;
        u_joint_positionsi.real = this->joint_positions[i];
        *(outbuffer + offset + 0) = (u_joint_positionsi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_joint_positionsi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_joint_positionsi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_joint_positionsi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_joint_positionsi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_joint_positionsi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_joint_positionsi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_joint_positionsi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->joint_positions[i]);
      }
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
      uint32_t length_urdf_param_name;
      arrToVar(length_urdf_param_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_urdf_param_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_urdf_param_name-1]=0;
      this->urdf_param_name = (char *)(inbuffer + offset-1);
      offset += length_urdf_param_name;
      uint32_t joint_names_length = ((uint32_t) (*(inbuffer + offset))); 
      joint_names_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_names_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_names_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->joint_names.resize(joint_names_length); 
      offset += sizeof(joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_joint_namesi;
        arrToVar(length_joint_namesi, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_joint_namesi; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_joint_namesi-1]=0;
        this->joint_names[i] = (char *)(inbuffer + offset-1);
        offset += length_joint_namesi;
      }
      uint32_t joint_positions_length = ((uint32_t) (*(inbuffer + offset))); 
      joint_positions_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_positions_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_positions_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->joint_positions.resize(joint_positions_length); 
      offset += sizeof(joint_positions_length);
      for( uint32_t i = 0; i < joint_positions_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_joint_positionsi;
        u_joint_positionsi.base = 0;
        u_joint_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_joint_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_joint_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_joint_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_joint_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_joint_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_joint_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_joint_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->joint_positions[i] = u_joint_positionsi.real;
        offset += sizeof(this->joint_positions[i]);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_model_name = this->model_name.size();
      length += 4;
      length += length_model_name;
      uint32_t length_urdf_param_name = this->urdf_param_name.size();
      length += 4;
      length += length_urdf_param_name;
      uint32_t joint_names_length = this->joint_names.size();
      length += sizeof(joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_joint_namesi = this->joint_names[i].size();
        length += 4;
        length += length_joint_namesi;
      }
      uint32_t joint_positions_length = this->joint_positions.size();
      length += sizeof(joint_positions_length);
      for( uint32_t i = 0; i < joint_positions_length; i++) {
        length += sizeof(this->joint_positions[i]);
      }
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
      string_echo += "\",";
      std::size_t urdf_param_name_pos = urdf_param_name.find("\"");
      while(urdf_param_name_pos != std::string::npos){
        urdf_param_name.replace(urdf_param_name_pos, 1,"\\\"");
        urdf_param_name_pos = urdf_param_name.find("\"", urdf_param_name_pos+2);
      }
      string_echo += "\"urdf_param_name\":\"";
      string_echo += urdf_param_name;
      string_echo += "\",";
      uint32_t joint_names_length = this->joint_names.size();
      string_echo += "joint_names:[";
      for( uint32_t i = 0; i < joint_names_length; i++) {
        if( i == (joint_names_length - 1)) {
          std::stringstream ss_joint_namesi; ss_joint_namesi << "\"";
          string_echo += ss_joint_namesi.str();
          std::size_t joint_namesi_pos = joint_names[i].find("\"");
          while(joint_namesi_pos != std::string::npos){
            joint_names[i].replace(joint_namesi_pos, 1,"\\\"");
            joint_namesi_pos = joint_names[i].find("\"", joint_namesi_pos+2);
          }
          string_echo += joint_names[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_joint_namesi; ss_joint_namesi << "\"";
          string_echo += ss_joint_namesi.str();
          std::size_t joint_namesi_pos = joint_names[i].find("\"");
          while(joint_namesi_pos != std::string::npos){
            joint_names[i].replace(joint_namesi_pos, 1,"\\\"");
            joint_namesi_pos = joint_names[i].find("\"", joint_namesi_pos+2);
          }
          string_echo += joint_names[i];
          string_echo += "\",";
        }
      }
      string_echo += "],";
      uint32_t joint_positions_length = this->joint_positions.size();
      string_echo += "joint_positions:[";
      for( uint32_t i = 0; i < joint_positions_length; i++) {
        if( i == (joint_positions_length - 1)) {
          std::stringstream ss_joint_positionsi; ss_joint_positionsi << joint_positions[i] <<"";
          string_echo += ss_joint_positionsi.str();
        } else {
          std::stringstream ss_joint_positionsi; ss_joint_positionsi << joint_positions[i] <<",";
          string_echo += ss_joint_positionsi.str();
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return SETMODELCONFIGURATION; }
    static std::string getTypeStatic(){ return SETMODELCONFIGURATION; }
    virtual std::string getMD5(){ return "74db6184ae83468b540d4c02d244ada7"; }
    static std::string getMD5Static(){ return "74db6184ae83468b540d4c02d244ada7"; }
    virtual std::string getDefinition(){ return "string model_name\nstring urdf_param_name\nstring[] joint_names\nfloat64[] joint_positions\n"; }
    static std::string getDefinitionStatic(){ return "string model_name\nstring urdf_param_name\nstring[] joint_names\nfloat64[] joint_positions\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::SetModelConfigurationRequest> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::SetModelConfigurationRequest const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::SetModelConfigurationRequest> SetModelConfigurationRequestPtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::SetModelConfigurationRequest const> SetModelConfigurationRequestConstPtr;

  class SetModelConfigurationResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef bool _success_type;
      _success_type success;
      typedef std::string _status_message_type;
      _status_message_type status_message;

    SetModelConfigurationResponse():
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

    virtual std::string getType(){ return SETMODELCONFIGURATION; }
    static std::string getTypeStatic(){ return SETMODELCONFIGURATION; }
    virtual std::string getMD5(){ return "6f12aefa315c8b37040d5d47471e39ee"; }
    static std::string getMD5Static(){ return "6f12aefa315c8b37040d5d47471e39ee"; }
    virtual std::string getDefinition(){ return "bool success\nstring status_message\n"; }
    static std::string getDefinitionStatic(){ return "bool success\nstring status_message\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::SetModelConfigurationResponse> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::SetModelConfigurationResponse const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::SetModelConfigurationResponse> SetModelConfigurationResponsePtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::SetModelConfigurationResponse const> SetModelConfigurationResponseConstPtr;

  class SetModelConfiguration {
    public:
    typedef SetModelConfigurationRequest Request;
    typedef SetModelConfigurationResponse Response;
  };

}
}
#endif
