#ifndef _TINYROS_smach_msgs_SmachContainerInitialStatusCmd_h
#define _TINYROS_smach_msgs_SmachContainerInitialStatusCmd_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace smach_msgs
{

  class SmachContainerInitialStatusCmd : public tinyros::Msg
  {
    public:
      typedef std::string _path_type;
      _path_type path;
      typedef std::string _initial_states_type;
      std::vector<_initial_states_type> initial_states;
      typedef std::string _local_data_type;
      _local_data_type local_data;

    SmachContainerInitialStatusCmd():
      path(""),
      initial_states(0),
      local_data("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
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
      uint32_t length_local_data = this->local_data.size();
      varToArr(outbuffer + offset, length_local_data);
      offset += 4;
      memcpy(outbuffer + offset, this->local_data.c_str(), length_local_data);
      offset += length_local_data;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
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
      uint32_t length_local_data;
      arrToVar(length_local_data, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_local_data; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_local_data-1]=0;
      this->local_data = (char *)(inbuffer + offset-1);
      offset += length_local_data;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
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
      uint32_t length_local_data = this->local_data.size();
      length += 4;
      length += length_local_data;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
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
      std::size_t local_data_pos = local_data.find("\"");
      while(local_data_pos != std::string::npos){
        local_data.replace(local_data_pos, 1,"\\\"");
        local_data_pos = local_data.find("\"", local_data_pos+2);
      }
      string_echo += "\"local_data\":\"";
      string_echo += local_data;
      string_echo += "\"";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "smach_msgs/SmachContainerInitialStatusCmd"; }
    static std::string getTypeStatic(){ return "smach_msgs/SmachContainerInitialStatusCmd"; }
    virtual std::string getMD5(){ return "b7c8a2bbd4d7c89f80561645ea1f4f13"; }
    static std::string getMD5Static(){ return "b7c8a2bbd4d7c89f80561645ea1f4f13"; }
    virtual std::string getDefinition(){ return "string path\nstring[] initial_states\nstring local_data\n"; }
    static std::string getDefinitionStatic(){ return "string path\nstring[] initial_states\nstring local_data\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::smach_msgs::SmachContainerInitialStatusCmd> Ptr;
    typedef std::shared_ptr<tinyros::smach_msgs::SmachContainerInitialStatusCmd const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::smach_msgs::SmachContainerInitialStatusCmd> SmachContainerInitialStatusCmdPtr;
typedef std::shared_ptr<tinyros::smach_msgs::SmachContainerInitialStatusCmd const> SmachContainerInitialStatusCmdConstPtr;

}
}
#endif
