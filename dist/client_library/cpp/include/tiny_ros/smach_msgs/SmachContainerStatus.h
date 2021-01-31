#ifndef _TINYROS_smach_msgs_SmachContainerStatus_h
#define _TINYROS_smach_msgs_SmachContainerStatus_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"

namespace tinyros
{
namespace smach_msgs
{

  class SmachContainerStatus : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef std::string _path_type;
      _path_type path;
      typedef std::string _initial_states_type;
      std::vector<_initial_states_type> initial_states;
      typedef std::string _active_states_type;
      std::vector<_active_states_type> active_states;
      typedef std::string _local_data_type;
      _local_data_type local_data;
      typedef std::string _info_type;
      _info_type info;

    SmachContainerStatus():
      header(),
      path(""),
      initial_states(0),
      active_states(0),
      local_data(""),
      info("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_path = this->path.size();
      varToArr(outbuffer + offset, length_path);
      offset += 4;
      memcpy(outbuffer + offset, this->path.c_str(), length_path);
      offset += length_path;
      uint32_t initial_states_length = this->initial_states.size();
      *(outbuffer + offset + 0) = (initial_states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (initial_states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (initial_states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (initial_states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(initial_states_length);
      for( uint32_t i = 0; i < initial_states_length; i++) {
        uint32_t length_initial_statesi = this->initial_states[i].size();
        varToArr(outbuffer + offset, length_initial_statesi);
        offset += 4;
        memcpy(outbuffer + offset, this->initial_states[i].c_str(), length_initial_statesi);
        offset += length_initial_statesi;
      }
      uint32_t active_states_length = this->active_states.size();
      *(outbuffer + offset + 0) = (active_states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (active_states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (active_states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (active_states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(active_states_length);
      for( uint32_t i = 0; i < active_states_length; i++) {
        uint32_t length_active_statesi = this->active_states[i].size();
        varToArr(outbuffer + offset, length_active_statesi);
        offset += 4;
        memcpy(outbuffer + offset, this->active_states[i].c_str(), length_active_statesi);
        offset += length_active_statesi;
      }
      uint32_t length_local_data = this->local_data.size();
      varToArr(outbuffer + offset, length_local_data);
      offset += 4;
      memcpy(outbuffer + offset, this->local_data.c_str(), length_local_data);
      offset += length_local_data;
      uint32_t length_info = this->info.size();
      varToArr(outbuffer + offset, length_info);
      offset += 4;
      memcpy(outbuffer + offset, this->info.c_str(), length_info);
      offset += length_info;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_path;
      arrToVar(length_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_path; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_path-1]=0;
      this->path = (char *)(inbuffer + offset-1);
      offset += length_path;
      uint32_t initial_states_length = ((uint32_t) (*(inbuffer + offset))); 
      initial_states_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      initial_states_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      initial_states_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->initial_states.resize(initial_states_length); 
      offset += sizeof(initial_states_length);
      for( uint32_t i = 0; i < initial_states_length; i++) {
        uint32_t length_initial_statesi;
        arrToVar(length_initial_statesi, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_initial_statesi; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_initial_statesi-1]=0;
        this->initial_states[i] = (char *)(inbuffer + offset-1);
        offset += length_initial_statesi;
      }
      uint32_t active_states_length = ((uint32_t) (*(inbuffer + offset))); 
      active_states_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      active_states_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      active_states_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->active_states.resize(active_states_length); 
      offset += sizeof(active_states_length);
      for( uint32_t i = 0; i < active_states_length; i++) {
        uint32_t length_active_statesi;
        arrToVar(length_active_statesi, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_active_statesi; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_active_statesi-1]=0;
        this->active_states[i] = (char *)(inbuffer + offset-1);
        offset += length_active_statesi;
      }
      uint32_t length_local_data;
      arrToVar(length_local_data, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_local_data; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_local_data-1]=0;
      this->local_data = (char *)(inbuffer + offset-1);
      offset += length_local_data;
      uint32_t length_info;
      arrToVar(length_info, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_info; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_info-1]=0;
      this->info = (char *)(inbuffer + offset-1);
      offset += length_info;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      uint32_t length_path = this->path.size();
      length += 4;
      length += length_path;
      uint32_t initial_states_length = this->initial_states.size();
      length += sizeof(initial_states_length);
      for( uint32_t i = 0; i < initial_states_length; i++) {
        uint32_t length_initial_statesi = this->initial_states[i].size();
        length += 4;
        length += length_initial_statesi;
      }
      uint32_t active_states_length = this->active_states.size();
      length += sizeof(active_states_length);
      for( uint32_t i = 0; i < active_states_length; i++) {
        uint32_t length_active_statesi = this->active_states[i].size();
        length += 4;
        length += length_active_statesi;
      }
      uint32_t length_local_data = this->local_data.size();
      length += 4;
      length += length_local_data;
      uint32_t length_info = this->info.size();
      length += 4;
      length += length_info;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      std::size_t path_pos = path.find("\"");
      while(path_pos != std::string::npos){
        path.replace(path_pos, 1,"\\\"");
        path_pos = path.find("\"", path_pos+2);
      }
      string_echo += "\"path\":\"";
      string_echo += path;
      string_echo += "\",";
      uint32_t initial_states_length = this->initial_states.size();
      string_echo += "initial_states:[";
      for( uint32_t i = 0; i < initial_states_length; i++) {
        if( i == (initial_states_length - 1)) {
          std::stringstream ss_initial_statesi; ss_initial_statesi << "\"";
          string_echo += ss_initial_statesi.str();
          std::size_t initial_statesi_pos = initial_states[i].find("\"");
          while(initial_statesi_pos != std::string::npos){
            initial_states[i].replace(initial_statesi_pos, 1,"\\\"");
            initial_statesi_pos = initial_states[i].find("\"", initial_statesi_pos+2);
          }
          string_echo += initial_states[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_initial_statesi; ss_initial_statesi << "\"";
          string_echo += ss_initial_statesi.str();
          std::size_t initial_statesi_pos = initial_states[i].find("\"");
          while(initial_statesi_pos != std::string::npos){
            initial_states[i].replace(initial_statesi_pos, 1,"\\\"");
            initial_statesi_pos = initial_states[i].find("\"", initial_statesi_pos+2);
          }
          string_echo += initial_states[i];
          string_echo += "\",";
        }
      }
      string_echo += "],";
      uint32_t active_states_length = this->active_states.size();
      string_echo += "active_states:[";
      for( uint32_t i = 0; i < active_states_length; i++) {
        if( i == (active_states_length - 1)) {
          std::stringstream ss_active_statesi; ss_active_statesi << "\"";
          string_echo += ss_active_statesi.str();
          std::size_t active_statesi_pos = active_states[i].find("\"");
          while(active_statesi_pos != std::string::npos){
            active_states[i].replace(active_statesi_pos, 1,"\\\"");
            active_statesi_pos = active_states[i].find("\"", active_statesi_pos+2);
          }
          string_echo += active_states[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_active_statesi; ss_active_statesi << "\"";
          string_echo += ss_active_statesi.str();
          std::size_t active_statesi_pos = active_states[i].find("\"");
          while(active_statesi_pos != std::string::npos){
            active_states[i].replace(active_statesi_pos, 1,"\\\"");
            active_statesi_pos = active_states[i].find("\"", active_statesi_pos+2);
          }
          string_echo += active_states[i];
          string_echo += "\",";
        }
      }
      string_echo += "],";
      std::size_t local_data_pos = local_data.find("\"");
      while(local_data_pos != std::string::npos){
        local_data.replace(local_data_pos, 1,"\\\"");
        local_data_pos = local_data.find("\"", local_data_pos+2);
      }
      string_echo += "\"local_data\":\"";
      string_echo += local_data;
      string_echo += "\",";
      std::size_t info_pos = info.find("\"");
      while(info_pos != std::string::npos){
        info.replace(info_pos, 1,"\\\"");
        info_pos = info.find("\"", info_pos+2);
      }
      string_echo += "\"info\":\"";
      string_echo += info;
      string_echo += "\"";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "smach_msgs/SmachContainerStatus"; }
    static std::string getTypeStatic(){ return "smach_msgs/SmachContainerStatus"; }
    virtual std::string getMD5(){ return "3e74cf72da18311be27e7a5970ea6415"; }
    static std::string getMD5Static(){ return "3e74cf72da18311be27e7a5970ea6415"; }
    virtual std::string getDefinition(){ return "Header header\nstring path\nstring[] initial_states\nstring[] active_states\nstring local_data\nstring info\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nstring path\nstring[] initial_states\nstring[] active_states\nstring local_data\nstring info\n"; }
    static bool hasHeader(){ return true; }
  };

typedef std::shared_ptr<tinyros::smach_msgs::SmachContainerStatus> SmachContainerStatusPtr;
typedef std::shared_ptr<tinyros::smach_msgs::SmachContainerStatus const> SmachContainerStatusConstPtr;

}
}
#endif
