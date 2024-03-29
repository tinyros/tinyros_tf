#ifndef _TINYROS_SERVICE_GetWorldProperties_h
#define _TINYROS_SERVICE_GetWorldProperties_h
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

static const char GETWORLDPROPERTIES[] = "gazebo_msgs/GetWorldProperties";

  class GetWorldPropertiesRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:

    GetWorldPropertiesRequest()
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

    virtual std::string getType(){ return GETWORLDPROPERTIES; }
    static std::string getTypeStatic(){ return GETWORLDPROPERTIES; }
    virtual std::string getMD5(){ return "3aa5de7106eec5dae41ad1c9ae681123"; }
    static std::string getMD5Static(){ return "3aa5de7106eec5dae41ad1c9ae681123"; }
    virtual std::string getDefinition(){ return ""; }
    static std::string getDefinitionStatic(){ return ""; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::GetWorldPropertiesRequest> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::GetWorldPropertiesRequest const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::GetWorldPropertiesRequest> GetWorldPropertiesRequestPtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::GetWorldPropertiesRequest const> GetWorldPropertiesRequestConstPtr;

  class GetWorldPropertiesResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef double _sim_time_type;
      _sim_time_type sim_time;
      typedef std::string _model_names_type;
      std::vector<_model_names_type> model_names;
      typedef bool _rendering_enabled_type;
      _rendering_enabled_type rendering_enabled;
      typedef bool _success_type;
      _success_type success;
      typedef std::string _status_message_type;
      _status_message_type status_message;

    GetWorldPropertiesResponse():
      sim_time(0),
      model_names(0),
      rendering_enabled(0),
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
        double real;
        uint64_t base;
      } u_sim_time;
      u_sim_time.real = this->sim_time;
      *(outbuffer + offset + 0) = (u_sim_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sim_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sim_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sim_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_sim_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_sim_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_sim_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_sim_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sim_time);
      uint32_t model_names_length = this->model_names.size();
      *(outbuffer + offset + 0) = (model_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (model_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (model_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (model_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(model_names_length);
      for( uint32_t i = 0; i < model_names_length; i++) {
        uint32_t length_model_namesi = this->model_names[i].size();
        varToArr(outbuffer + offset, length_model_namesi);
        offset += 4;
        memcpy(outbuffer + offset, this->model_names[i].c_str(), length_model_namesi);
        offset += length_model_namesi;
      }
      union {
        bool real;
        uint8_t base;
      } u_rendering_enabled;
      u_rendering_enabled.real = this->rendering_enabled;
      *(outbuffer + offset + 0) = (u_rendering_enabled.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->rendering_enabled);
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
        double real;
        uint64_t base;
      } u_sim_time;
      u_sim_time.base = 0;
      u_sim_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sim_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sim_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sim_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_sim_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_sim_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_sim_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_sim_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sim_time = u_sim_time.real;
      offset += sizeof(this->sim_time);
      uint32_t model_names_length = ((uint32_t) (*(inbuffer + offset))); 
      model_names_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      model_names_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      model_names_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->model_names.resize(model_names_length); 
      offset += sizeof(model_names_length);
      for( uint32_t i = 0; i < model_names_length; i++) {
        uint32_t length_model_namesi;
        arrToVar(length_model_namesi, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_model_namesi; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_model_namesi-1]=0;
        this->model_names[i] = (char *)(inbuffer + offset-1);
        offset += length_model_namesi;
      }
      union {
        bool real;
        uint8_t base;
      } u_rendering_enabled;
      u_rendering_enabled.base = 0;
      u_rendering_enabled.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->rendering_enabled = u_rendering_enabled.real;
      offset += sizeof(this->rendering_enabled);
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
      length += sizeof(this->sim_time);
      uint32_t model_names_length = this->model_names.size();
      length += sizeof(model_names_length);
      for( uint32_t i = 0; i < model_names_length; i++) {
        uint32_t length_model_namesi = this->model_names[i].size();
        length += 4;
        length += length_model_namesi;
      }
      length += sizeof(this->rendering_enabled);
      length += sizeof(this->success);
      uint32_t length_status_message = this->status_message.size();
      length += 4;
      length += length_status_message;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::stringstream ss_sim_time; ss_sim_time << "\"sim_time\":" << sim_time <<",";
      string_echo += ss_sim_time.str();
      uint32_t model_names_length = this->model_names.size();
      string_echo += "model_names:[";
      for( uint32_t i = 0; i < model_names_length; i++) {
        if( i == (model_names_length - 1)) {
          std::stringstream ss_model_namesi; ss_model_namesi << "\"";
          string_echo += ss_model_namesi.str();
          std::size_t model_namesi_pos = model_names[i].find("\"");
          while(model_namesi_pos != std::string::npos){
            model_names[i].replace(model_namesi_pos, 1,"\\\"");
            model_namesi_pos = model_names[i].find("\"", model_namesi_pos+2);
          }
          string_echo += model_names[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_model_namesi; ss_model_namesi << "\"";
          string_echo += ss_model_namesi.str();
          std::size_t model_namesi_pos = model_names[i].find("\"");
          while(model_namesi_pos != std::string::npos){
            model_names[i].replace(model_namesi_pos, 1,"\\\"");
            model_namesi_pos = model_names[i].find("\"", model_namesi_pos+2);
          }
          string_echo += model_names[i];
          string_echo += "\",";
        }
      }
      string_echo += "],";
      std::stringstream ss_rendering_enabled; ss_rendering_enabled << "\"rendering_enabled\":" << rendering_enabled <<",";
      string_echo += ss_rendering_enabled.str();
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

    virtual std::string getType(){ return GETWORLDPROPERTIES; }
    static std::string getTypeStatic(){ return GETWORLDPROPERTIES; }
    virtual std::string getMD5(){ return "fe944c1c210919291ad14bc43b6c10cf"; }
    static std::string getMD5Static(){ return "fe944c1c210919291ad14bc43b6c10cf"; }
    virtual std::string getDefinition(){ return "float64 sim_time\nstring[] model_names\nbool rendering_enabled\nbool success\nstring status_message\n"; }
    static std::string getDefinitionStatic(){ return "float64 sim_time\nstring[] model_names\nbool rendering_enabled\nbool success\nstring status_message\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::GetWorldPropertiesResponse> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::GetWorldPropertiesResponse const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::GetWorldPropertiesResponse> GetWorldPropertiesResponsePtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::GetWorldPropertiesResponse const> GetWorldPropertiesResponseConstPtr;

  class GetWorldProperties {
    public:
    typedef GetWorldPropertiesRequest Request;
    typedef GetWorldPropertiesResponse Response;
  };

}
}
#endif
