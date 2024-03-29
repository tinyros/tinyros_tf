#ifndef _TINYROS_SERVICE_SetModelConfiguration_h
#define _TINYROS_SERVICE_SetModelConfiguration_h
#include <stdint.h>
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
      typedef tinyros::string _model_name_type;
      _model_name_type model_name;
      typedef tinyros::string _urdf_param_name_type;
      _urdf_param_name_type urdf_param_name;
      uint32_t joint_names_length;
      typedef tinyros::string _joint_names_type;
      _joint_names_type st_joint_names;
      _joint_names_type * joint_names;
      uint32_t joint_positions_length;
      typedef double _joint_positions_type;
      _joint_positions_type st_joint_positions;
      _joint_positions_type * joint_positions;

    SetModelConfigurationRequest():
      model_name(""),
      urdf_param_name(""),
      joint_names_length(0), joint_names(NULL),
      joint_positions_length(0), joint_positions(NULL)
    {
      this->__id__ = 0;
    }

    ~SetModelConfigurationRequest()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(joint_names != NULL)
      {
        free(joint_names);
      }
      joint_names = NULL;
      joint_names_length = 0;
      if(joint_positions != NULL)
      {
        free(joint_positions);
      }
      joint_positions = NULL;
      joint_positions_length = 0;
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
      *(outbuffer + offset + 0) = (this->joint_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_joint_namesi = this->joint_names[i].size();
        varToArr(outbuffer + offset, length_joint_namesi);
        offset += 4;
        memcpy(outbuffer + offset, this->joint_names[i].c_str(), length_joint_namesi);
        offset += length_joint_namesi;
      }
      *(outbuffer + offset + 0) = (this->joint_positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joint_positions_length);
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
      uint32_t joint_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->joint_names_length);
      if(joint_names_lengthT > joint_names_length)
        this->joint_names = (tinyros::string*)realloc(this->joint_names, joint_names_lengthT * sizeof(tinyros::string));
      joint_names_length = joint_names_lengthT;
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_st_joint_names;
        arrToVar(length_st_joint_names, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_st_joint_names; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_st_joint_names-1]=0;
        this->st_joint_names = (char *)(inbuffer + offset-1);
        offset += length_st_joint_names;
        memcpy( &(this->joint_names[i]), &(this->st_joint_names), sizeof(tinyros::string));
      }
      uint32_t joint_positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->joint_positions_length);
      if(joint_positions_lengthT > joint_positions_length)
        this->joint_positions = (double*)realloc(this->joint_positions, joint_positions_lengthT * sizeof(double));
      joint_positions_length = joint_positions_lengthT;
      for( uint32_t i = 0; i < joint_positions_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_joint_positions;
        u_st_joint_positions.base = 0;
        u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_joint_positions.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_joint_positions = u_st_joint_positions.real;
        offset += sizeof(this->st_joint_positions);
        memcpy( &(this->joint_positions[i]), &(this->st_joint_positions), sizeof(double));
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
      length += sizeof(this->joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_joint_namesi = this->joint_names[i].size();
        length += 4;
        length += length_joint_namesi;
      }
      length += sizeof(this->joint_positions_length);
      for( uint32_t i = 0; i < joint_positions_length; i++) {
        length += sizeof(this->joint_positions[i]);
      }
      return length;
    }

    virtual tinyros::string getType(){ return SETMODELCONFIGURATION; }
    static tinyros::string getTypeStatic(){ return SETMODELCONFIGURATION; }
    virtual tinyros::string getMD5(){ return "74db6184ae83468b540d4c02d244ada7"; }
    static tinyros::string getMD5Static(){ return "74db6184ae83468b540d4c02d244ada7"; }
    virtual tinyros::string getDefinition(){ return "string model_name           \nstring urdf_param_name      \nstring[] joint_names        \nfloat64[] joint_positions   \n"; }
    static tinyros::string getDefinitionStatic(){ return "string model_name           \nstring urdf_param_name      \nstring[] joint_names        \nfloat64[] joint_positions   \n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }

  };

  class SetModelConfigurationResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef bool _success_type;
      _success_type success;
      typedef tinyros::string _status_message_type;
      _status_message_type status_message;

    SetModelConfigurationResponse():
      success(0),
      status_message("")
    {
      this->__id__ = 0;
    }

    ~SetModelConfigurationResponse()
    {
      deconstructor();
    }

    void deconstructor()
    {
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

    virtual tinyros::string getType(){ return SETMODELCONFIGURATION; }
    static tinyros::string getTypeStatic(){ return SETMODELCONFIGURATION; }
    virtual tinyros::string getMD5(){ return "6f12aefa315c8b37040d5d47471e39ee"; }
    static tinyros::string getMD5Static(){ return "6f12aefa315c8b37040d5d47471e39ee"; }
    virtual tinyros::string getDefinition(){ return "bool success                \nstring status_message       \n"; }
    static tinyros::string getDefinitionStatic(){ return "bool success                \nstring status_message       \n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }

  };

  class SetModelConfiguration {
    public:
    typedef SetModelConfigurationRequest Request;
    typedef SetModelConfigurationResponse Response;
  };

}
}
#endif
