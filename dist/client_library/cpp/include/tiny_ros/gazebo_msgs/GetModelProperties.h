#ifndef _TINYROS_SERVICE_GetModelProperties_h
#define _TINYROS_SERVICE_GetModelProperties_h
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

static const char GETMODELPROPERTIES[] = "gazebo_msgs/GetModelProperties";

  class GetModelPropertiesRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef std::string _model_name_type;
      _model_name_type model_name;

    GetModelPropertiesRequest():
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

    virtual std::string getType(){ return GETMODELPROPERTIES; }
    static std::string getTypeStatic(){ return GETMODELPROPERTIES; }
    virtual std::string getMD5(){ return "fe0194bf75c917c89b820b09c12fe6c1"; }
    static std::string getMD5Static(){ return "fe0194bf75c917c89b820b09c12fe6c1"; }
    virtual std::string getDefinition(){ return "string model_name\n"; }
    static std::string getDefinitionStatic(){ return "string model_name\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::GetModelPropertiesRequest> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::GetModelPropertiesRequest const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::GetModelPropertiesRequest> GetModelPropertiesRequestPtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::GetModelPropertiesRequest const> GetModelPropertiesRequestConstPtr;

  class GetModelPropertiesResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef std::string _parent_model_name_type;
      _parent_model_name_type parent_model_name;
      typedef std::string _canonical_body_name_type;
      _canonical_body_name_type canonical_body_name;
      typedef std::string _body_names_type;
      std::vector<_body_names_type> body_names;
      typedef std::string _geom_names_type;
      std::vector<_geom_names_type> geom_names;
      typedef std::string _joint_names_type;
      std::vector<_joint_names_type> joint_names;
      typedef std::string _child_model_names_type;
      std::vector<_child_model_names_type> child_model_names;
      typedef bool _is_static_type;
      _is_static_type is_static;
      typedef bool _success_type;
      _success_type success;
      typedef std::string _status_message_type;
      _status_message_type status_message;

    GetModelPropertiesResponse():
      parent_model_name(""),
      canonical_body_name(""),
      body_names(0),
      geom_names(0),
      joint_names(0),
      child_model_names(0),
      is_static(0),
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
      uint32_t length_parent_model_name = this->parent_model_name.size();
      varToArr(outbuffer + offset, length_parent_model_name);
      offset += 4;
      memcpy(outbuffer + offset, this->parent_model_name.c_str(), length_parent_model_name);
      offset += length_parent_model_name;
      uint32_t length_canonical_body_name = this->canonical_body_name.size();
      varToArr(outbuffer + offset, length_canonical_body_name);
      offset += 4;
      memcpy(outbuffer + offset, this->canonical_body_name.c_str(), length_canonical_body_name);
      offset += length_canonical_body_name;
      uint32_t body_names_length = this->body_names.size();
      *(outbuffer + offset + 0) = (body_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (body_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (body_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (body_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(body_names_length);
      for( uint32_t i = 0; i < body_names_length; i++) {
        uint32_t length_body_namesi = this->body_names[i].size();
        varToArr(outbuffer + offset, length_body_namesi);
        offset += 4;
        memcpy(outbuffer + offset, this->body_names[i].c_str(), length_body_namesi);
        offset += length_body_namesi;
      }
      uint32_t geom_names_length = this->geom_names.size();
      *(outbuffer + offset + 0) = (geom_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (geom_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (geom_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (geom_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(geom_names_length);
      for( uint32_t i = 0; i < geom_names_length; i++) {
        uint32_t length_geom_namesi = this->geom_names[i].size();
        varToArr(outbuffer + offset, length_geom_namesi);
        offset += 4;
        memcpy(outbuffer + offset, this->geom_names[i].c_str(), length_geom_namesi);
        offset += length_geom_namesi;
      }
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
      uint32_t child_model_names_length = this->child_model_names.size();
      *(outbuffer + offset + 0) = (child_model_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (child_model_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (child_model_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (child_model_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(child_model_names_length);
      for( uint32_t i = 0; i < child_model_names_length; i++) {
        uint32_t length_child_model_namesi = this->child_model_names[i].size();
        varToArr(outbuffer + offset, length_child_model_namesi);
        offset += 4;
        memcpy(outbuffer + offset, this->child_model_names[i].c_str(), length_child_model_namesi);
        offset += length_child_model_namesi;
      }
      union {
        bool real;
        uint8_t base;
      } u_is_static;
      u_is_static.real = this->is_static;
      *(outbuffer + offset + 0) = (u_is_static.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_static);
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
      uint32_t length_parent_model_name;
      arrToVar(length_parent_model_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parent_model_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parent_model_name-1]=0;
      this->parent_model_name = (char *)(inbuffer + offset-1);
      offset += length_parent_model_name;
      uint32_t length_canonical_body_name;
      arrToVar(length_canonical_body_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_canonical_body_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_canonical_body_name-1]=0;
      this->canonical_body_name = (char *)(inbuffer + offset-1);
      offset += length_canonical_body_name;
      uint32_t body_names_length = ((uint32_t) (*(inbuffer + offset))); 
      body_names_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      body_names_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      body_names_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->body_names.resize(body_names_length); 
      offset += sizeof(body_names_length);
      for( uint32_t i = 0; i < body_names_length; i++) {
        uint32_t length_body_namesi;
        arrToVar(length_body_namesi, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_body_namesi; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_body_namesi-1]=0;
        this->body_names[i] = (char *)(inbuffer + offset-1);
        offset += length_body_namesi;
      }
      uint32_t geom_names_length = ((uint32_t) (*(inbuffer + offset))); 
      geom_names_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      geom_names_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      geom_names_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->geom_names.resize(geom_names_length); 
      offset += sizeof(geom_names_length);
      for( uint32_t i = 0; i < geom_names_length; i++) {
        uint32_t length_geom_namesi;
        arrToVar(length_geom_namesi, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_geom_namesi; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_geom_namesi-1]=0;
        this->geom_names[i] = (char *)(inbuffer + offset-1);
        offset += length_geom_namesi;
      }
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
      uint32_t child_model_names_length = ((uint32_t) (*(inbuffer + offset))); 
      child_model_names_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      child_model_names_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      child_model_names_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->child_model_names.resize(child_model_names_length); 
      offset += sizeof(child_model_names_length);
      for( uint32_t i = 0; i < child_model_names_length; i++) {
        uint32_t length_child_model_namesi;
        arrToVar(length_child_model_namesi, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_child_model_namesi; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_child_model_namesi-1]=0;
        this->child_model_names[i] = (char *)(inbuffer + offset-1);
        offset += length_child_model_namesi;
      }
      union {
        bool real;
        uint8_t base;
      } u_is_static;
      u_is_static.base = 0;
      u_is_static.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_static = u_is_static.real;
      offset += sizeof(this->is_static);
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
      uint32_t length_parent_model_name = this->parent_model_name.size();
      length += 4;
      length += length_parent_model_name;
      uint32_t length_canonical_body_name = this->canonical_body_name.size();
      length += 4;
      length += length_canonical_body_name;
      uint32_t body_names_length = this->body_names.size();
      length += sizeof(body_names_length);
      for( uint32_t i = 0; i < body_names_length; i++) {
        uint32_t length_body_namesi = this->body_names[i].size();
        length += 4;
        length += length_body_namesi;
      }
      uint32_t geom_names_length = this->geom_names.size();
      length += sizeof(geom_names_length);
      for( uint32_t i = 0; i < geom_names_length; i++) {
        uint32_t length_geom_namesi = this->geom_names[i].size();
        length += 4;
        length += length_geom_namesi;
      }
      uint32_t joint_names_length = this->joint_names.size();
      length += sizeof(joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_joint_namesi = this->joint_names[i].size();
        length += 4;
        length += length_joint_namesi;
      }
      uint32_t child_model_names_length = this->child_model_names.size();
      length += sizeof(child_model_names_length);
      for( uint32_t i = 0; i < child_model_names_length; i++) {
        uint32_t length_child_model_namesi = this->child_model_names[i].size();
        length += 4;
        length += length_child_model_namesi;
      }
      length += sizeof(this->is_static);
      length += sizeof(this->success);
      uint32_t length_status_message = this->status_message.size();
      length += 4;
      length += length_status_message;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::size_t parent_model_name_pos = parent_model_name.find("\"");
      while(parent_model_name_pos != std::string::npos){
        parent_model_name.replace(parent_model_name_pos, 1,"\\\"");
        parent_model_name_pos = parent_model_name.find("\"", parent_model_name_pos+2);
      }
      string_echo += "\"parent_model_name\":\"";
      string_echo += parent_model_name;
      string_echo += "\",";
      std::size_t canonical_body_name_pos = canonical_body_name.find("\"");
      while(canonical_body_name_pos != std::string::npos){
        canonical_body_name.replace(canonical_body_name_pos, 1,"\\\"");
        canonical_body_name_pos = canonical_body_name.find("\"", canonical_body_name_pos+2);
      }
      string_echo += "\"canonical_body_name\":\"";
      string_echo += canonical_body_name;
      string_echo += "\",";
      uint32_t body_names_length = this->body_names.size();
      string_echo += "body_names:[";
      for( uint32_t i = 0; i < body_names_length; i++) {
        if( i == (body_names_length - 1)) {
          std::stringstream ss_body_namesi; ss_body_namesi << "\"";
          string_echo += ss_body_namesi.str();
          std::size_t body_namesi_pos = body_names[i].find("\"");
          while(body_namesi_pos != std::string::npos){
            body_names[i].replace(body_namesi_pos, 1,"\\\"");
            body_namesi_pos = body_names[i].find("\"", body_namesi_pos+2);
          }
          string_echo += body_names[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_body_namesi; ss_body_namesi << "\"";
          string_echo += ss_body_namesi.str();
          std::size_t body_namesi_pos = body_names[i].find("\"");
          while(body_namesi_pos != std::string::npos){
            body_names[i].replace(body_namesi_pos, 1,"\\\"");
            body_namesi_pos = body_names[i].find("\"", body_namesi_pos+2);
          }
          string_echo += body_names[i];
          string_echo += "\",";
        }
      }
      string_echo += "],";
      uint32_t geom_names_length = this->geom_names.size();
      string_echo += "geom_names:[";
      for( uint32_t i = 0; i < geom_names_length; i++) {
        if( i == (geom_names_length - 1)) {
          std::stringstream ss_geom_namesi; ss_geom_namesi << "\"";
          string_echo += ss_geom_namesi.str();
          std::size_t geom_namesi_pos = geom_names[i].find("\"");
          while(geom_namesi_pos != std::string::npos){
            geom_names[i].replace(geom_namesi_pos, 1,"\\\"");
            geom_namesi_pos = geom_names[i].find("\"", geom_namesi_pos+2);
          }
          string_echo += geom_names[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_geom_namesi; ss_geom_namesi << "\"";
          string_echo += ss_geom_namesi.str();
          std::size_t geom_namesi_pos = geom_names[i].find("\"");
          while(geom_namesi_pos != std::string::npos){
            geom_names[i].replace(geom_namesi_pos, 1,"\\\"");
            geom_namesi_pos = geom_names[i].find("\"", geom_namesi_pos+2);
          }
          string_echo += geom_names[i];
          string_echo += "\",";
        }
      }
      string_echo += "],";
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
      uint32_t child_model_names_length = this->child_model_names.size();
      string_echo += "child_model_names:[";
      for( uint32_t i = 0; i < child_model_names_length; i++) {
        if( i == (child_model_names_length - 1)) {
          std::stringstream ss_child_model_namesi; ss_child_model_namesi << "\"";
          string_echo += ss_child_model_namesi.str();
          std::size_t child_model_namesi_pos = child_model_names[i].find("\"");
          while(child_model_namesi_pos != std::string::npos){
            child_model_names[i].replace(child_model_namesi_pos, 1,"\\\"");
            child_model_namesi_pos = child_model_names[i].find("\"", child_model_namesi_pos+2);
          }
          string_echo += child_model_names[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_child_model_namesi; ss_child_model_namesi << "\"";
          string_echo += ss_child_model_namesi.str();
          std::size_t child_model_namesi_pos = child_model_names[i].find("\"");
          while(child_model_namesi_pos != std::string::npos){
            child_model_names[i].replace(child_model_namesi_pos, 1,"\\\"");
            child_model_namesi_pos = child_model_names[i].find("\"", child_model_namesi_pos+2);
          }
          string_echo += child_model_names[i];
          string_echo += "\",";
        }
      }
      string_echo += "],";
      std::stringstream ss_is_static; ss_is_static << "\"is_static\":" << is_static <<",";
      string_echo += ss_is_static.str();
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

    virtual std::string getType(){ return GETMODELPROPERTIES; }
    static std::string getTypeStatic(){ return GETMODELPROPERTIES; }
    virtual std::string getMD5(){ return "d8f16b08abaf0220a551cf9025748602"; }
    static std::string getMD5Static(){ return "d8f16b08abaf0220a551cf9025748602"; }
    virtual std::string getDefinition(){ return "string parent_model_name\nstring canonical_body_name\nstring[] body_names\nstring[] geom_names\nstring[] joint_names\nstring[] child_model_names\nbool is_static\nbool success\nstring status_message\n"; }
    static std::string getDefinitionStatic(){ return "string parent_model_name\nstring canonical_body_name\nstring[] body_names\nstring[] geom_names\nstring[] joint_names\nstring[] child_model_names\nbool is_static\nbool success\nstring status_message\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::GetModelPropertiesResponse> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::GetModelPropertiesResponse const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::GetModelPropertiesResponse> GetModelPropertiesResponsePtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::GetModelPropertiesResponse const> GetModelPropertiesResponseConstPtr;

  class GetModelProperties {
    public:
    typedef GetModelPropertiesRequest Request;
    typedef GetModelPropertiesResponse Response;
  };

}
}
#endif
