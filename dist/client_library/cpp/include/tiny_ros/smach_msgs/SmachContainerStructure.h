#ifndef _TINYROS_smach_msgs_SmachContainerStructure_h
#define _TINYROS_smach_msgs_SmachContainerStructure_h

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

  class SmachContainerStructure : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef std::string _path_type;
      _path_type path;
      typedef std::string _children_type;
      std::vector<_children_type> children;
      typedef std::string _internal_outcomes_type;
      std::vector<_internal_outcomes_type> internal_outcomes;
      typedef std::string _outcomes_from_type;
      std::vector<_outcomes_from_type> outcomes_from;
      typedef std::string _outcomes_to_type;
      std::vector<_outcomes_to_type> outcomes_to;
      typedef std::string _container_outcomes_type;
      std::vector<_container_outcomes_type> container_outcomes;

    SmachContainerStructure():
      header(),
      path(""),
      children(0),
      internal_outcomes(0),
      outcomes_from(0),
      outcomes_to(0),
      container_outcomes(0)
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
      uint32_t children_length = this->children.size();
      *(outbuffer + offset + 0) = (children_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (children_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (children_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (children_length >> (8 * 3)) & 0xFF;
      offset += sizeof(children_length);
      for( uint32_t i = 0; i < children_length; i++) {
        uint32_t length_childreni = this->children[i].size();
        varToArr(outbuffer + offset, length_childreni);
        offset += 4;
        memcpy(outbuffer + offset, this->children[i].c_str(), length_childreni);
        offset += length_childreni;
      }
      uint32_t internal_outcomes_length = this->internal_outcomes.size();
      *(outbuffer + offset + 0) = (internal_outcomes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (internal_outcomes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (internal_outcomes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (internal_outcomes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(internal_outcomes_length);
      for( uint32_t i = 0; i < internal_outcomes_length; i++) {
        uint32_t length_internal_outcomesi = this->internal_outcomes[i].size();
        varToArr(outbuffer + offset, length_internal_outcomesi);
        offset += 4;
        memcpy(outbuffer + offset, this->internal_outcomes[i].c_str(), length_internal_outcomesi);
        offset += length_internal_outcomesi;
      }
      uint32_t outcomes_from_length = this->outcomes_from.size();
      *(outbuffer + offset + 0) = (outcomes_from_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (outcomes_from_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (outcomes_from_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (outcomes_from_length >> (8 * 3)) & 0xFF;
      offset += sizeof(outcomes_from_length);
      for( uint32_t i = 0; i < outcomes_from_length; i++) {
        uint32_t length_outcomes_fromi = this->outcomes_from[i].size();
        varToArr(outbuffer + offset, length_outcomes_fromi);
        offset += 4;
        memcpy(outbuffer + offset, this->outcomes_from[i].c_str(), length_outcomes_fromi);
        offset += length_outcomes_fromi;
      }
      uint32_t outcomes_to_length = this->outcomes_to.size();
      *(outbuffer + offset + 0) = (outcomes_to_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (outcomes_to_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (outcomes_to_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (outcomes_to_length >> (8 * 3)) & 0xFF;
      offset += sizeof(outcomes_to_length);
      for( uint32_t i = 0; i < outcomes_to_length; i++) {
        uint32_t length_outcomes_toi = this->outcomes_to[i].size();
        varToArr(outbuffer + offset, length_outcomes_toi);
        offset += 4;
        memcpy(outbuffer + offset, this->outcomes_to[i].c_str(), length_outcomes_toi);
        offset += length_outcomes_toi;
      }
      uint32_t container_outcomes_length = this->container_outcomes.size();
      *(outbuffer + offset + 0) = (container_outcomes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (container_outcomes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (container_outcomes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (container_outcomes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(container_outcomes_length);
      for( uint32_t i = 0; i < container_outcomes_length; i++) {
        uint32_t length_container_outcomesi = this->container_outcomes[i].size();
        varToArr(outbuffer + offset, length_container_outcomesi);
        offset += 4;
        memcpy(outbuffer + offset, this->container_outcomes[i].c_str(), length_container_outcomesi);
        offset += length_container_outcomesi;
      }
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
      uint32_t children_length = ((uint32_t) (*(inbuffer + offset))); 
      children_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      children_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      children_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->children.resize(children_length); 
      offset += sizeof(children_length);
      for( uint32_t i = 0; i < children_length; i++) {
        uint32_t length_childreni;
        arrToVar(length_childreni, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_childreni; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_childreni-1]=0;
        this->children[i] = (char *)(inbuffer + offset-1);
        offset += length_childreni;
      }
      uint32_t internal_outcomes_length = ((uint32_t) (*(inbuffer + offset))); 
      internal_outcomes_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      internal_outcomes_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      internal_outcomes_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->internal_outcomes.resize(internal_outcomes_length); 
      offset += sizeof(internal_outcomes_length);
      for( uint32_t i = 0; i < internal_outcomes_length; i++) {
        uint32_t length_internal_outcomesi;
        arrToVar(length_internal_outcomesi, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_internal_outcomesi; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_internal_outcomesi-1]=0;
        this->internal_outcomes[i] = (char *)(inbuffer + offset-1);
        offset += length_internal_outcomesi;
      }
      uint32_t outcomes_from_length = ((uint32_t) (*(inbuffer + offset))); 
      outcomes_from_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      outcomes_from_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      outcomes_from_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->outcomes_from.resize(outcomes_from_length); 
      offset += sizeof(outcomes_from_length);
      for( uint32_t i = 0; i < outcomes_from_length; i++) {
        uint32_t length_outcomes_fromi;
        arrToVar(length_outcomes_fromi, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_outcomes_fromi; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_outcomes_fromi-1]=0;
        this->outcomes_from[i] = (char *)(inbuffer + offset-1);
        offset += length_outcomes_fromi;
      }
      uint32_t outcomes_to_length = ((uint32_t) (*(inbuffer + offset))); 
      outcomes_to_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      outcomes_to_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      outcomes_to_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->outcomes_to.resize(outcomes_to_length); 
      offset += sizeof(outcomes_to_length);
      for( uint32_t i = 0; i < outcomes_to_length; i++) {
        uint32_t length_outcomes_toi;
        arrToVar(length_outcomes_toi, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_outcomes_toi; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_outcomes_toi-1]=0;
        this->outcomes_to[i] = (char *)(inbuffer + offset-1);
        offset += length_outcomes_toi;
      }
      uint32_t container_outcomes_length = ((uint32_t) (*(inbuffer + offset))); 
      container_outcomes_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      container_outcomes_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      container_outcomes_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->container_outcomes.resize(container_outcomes_length); 
      offset += sizeof(container_outcomes_length);
      for( uint32_t i = 0; i < container_outcomes_length; i++) {
        uint32_t length_container_outcomesi;
        arrToVar(length_container_outcomesi, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_container_outcomesi; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_container_outcomesi-1]=0;
        this->container_outcomes[i] = (char *)(inbuffer + offset-1);
        offset += length_container_outcomesi;
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      uint32_t length_path = this->path.size();
      length += 4;
      length += length_path;
      uint32_t children_length = this->children.size();
      length += sizeof(children_length);
      for( uint32_t i = 0; i < children_length; i++) {
        uint32_t length_childreni = this->children[i].size();
        length += 4;
        length += length_childreni;
      }
      uint32_t internal_outcomes_length = this->internal_outcomes.size();
      length += sizeof(internal_outcomes_length);
      for( uint32_t i = 0; i < internal_outcomes_length; i++) {
        uint32_t length_internal_outcomesi = this->internal_outcomes[i].size();
        length += 4;
        length += length_internal_outcomesi;
      }
      uint32_t outcomes_from_length = this->outcomes_from.size();
      length += sizeof(outcomes_from_length);
      for( uint32_t i = 0; i < outcomes_from_length; i++) {
        uint32_t length_outcomes_fromi = this->outcomes_from[i].size();
        length += 4;
        length += length_outcomes_fromi;
      }
      uint32_t outcomes_to_length = this->outcomes_to.size();
      length += sizeof(outcomes_to_length);
      for( uint32_t i = 0; i < outcomes_to_length; i++) {
        uint32_t length_outcomes_toi = this->outcomes_to[i].size();
        length += 4;
        length += length_outcomes_toi;
      }
      uint32_t container_outcomes_length = this->container_outcomes.size();
      length += sizeof(container_outcomes_length);
      for( uint32_t i = 0; i < container_outcomes_length; i++) {
        uint32_t length_container_outcomesi = this->container_outcomes[i].size();
        length += 4;
        length += length_container_outcomesi;
      }
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
      uint32_t children_length = this->children.size();
      string_echo += "children:[";
      for( uint32_t i = 0; i < children_length; i++) {
        if( i == (children_length - 1)) {
          std::stringstream ss_childreni; ss_childreni << "\"";
          string_echo += ss_childreni.str();
          std::size_t childreni_pos = children[i].find("\"");
          while(childreni_pos != std::string::npos){
            children[i].replace(childreni_pos, 1,"\\\"");
            childreni_pos = children[i].find("\"", childreni_pos+2);
          }
          string_echo += children[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_childreni; ss_childreni << "\"";
          string_echo += ss_childreni.str();
          std::size_t childreni_pos = children[i].find("\"");
          while(childreni_pos != std::string::npos){
            children[i].replace(childreni_pos, 1,"\\\"");
            childreni_pos = children[i].find("\"", childreni_pos+2);
          }
          string_echo += children[i];
          string_echo += "\",";
        }
      }
      string_echo += "],";
      uint32_t internal_outcomes_length = this->internal_outcomes.size();
      string_echo += "internal_outcomes:[";
      for( uint32_t i = 0; i < internal_outcomes_length; i++) {
        if( i == (internal_outcomes_length - 1)) {
          std::stringstream ss_internal_outcomesi; ss_internal_outcomesi << "\"";
          string_echo += ss_internal_outcomesi.str();
          std::size_t internal_outcomesi_pos = internal_outcomes[i].find("\"");
          while(internal_outcomesi_pos != std::string::npos){
            internal_outcomes[i].replace(internal_outcomesi_pos, 1,"\\\"");
            internal_outcomesi_pos = internal_outcomes[i].find("\"", internal_outcomesi_pos+2);
          }
          string_echo += internal_outcomes[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_internal_outcomesi; ss_internal_outcomesi << "\"";
          string_echo += ss_internal_outcomesi.str();
          std::size_t internal_outcomesi_pos = internal_outcomes[i].find("\"");
          while(internal_outcomesi_pos != std::string::npos){
            internal_outcomes[i].replace(internal_outcomesi_pos, 1,"\\\"");
            internal_outcomesi_pos = internal_outcomes[i].find("\"", internal_outcomesi_pos+2);
          }
          string_echo += internal_outcomes[i];
          string_echo += "\",";
        }
      }
      string_echo += "],";
      uint32_t outcomes_from_length = this->outcomes_from.size();
      string_echo += "outcomes_from:[";
      for( uint32_t i = 0; i < outcomes_from_length; i++) {
        if( i == (outcomes_from_length - 1)) {
          std::stringstream ss_outcomes_fromi; ss_outcomes_fromi << "\"";
          string_echo += ss_outcomes_fromi.str();
          std::size_t outcomes_fromi_pos = outcomes_from[i].find("\"");
          while(outcomes_fromi_pos != std::string::npos){
            outcomes_from[i].replace(outcomes_fromi_pos, 1,"\\\"");
            outcomes_fromi_pos = outcomes_from[i].find("\"", outcomes_fromi_pos+2);
          }
          string_echo += outcomes_from[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_outcomes_fromi; ss_outcomes_fromi << "\"";
          string_echo += ss_outcomes_fromi.str();
          std::size_t outcomes_fromi_pos = outcomes_from[i].find("\"");
          while(outcomes_fromi_pos != std::string::npos){
            outcomes_from[i].replace(outcomes_fromi_pos, 1,"\\\"");
            outcomes_fromi_pos = outcomes_from[i].find("\"", outcomes_fromi_pos+2);
          }
          string_echo += outcomes_from[i];
          string_echo += "\",";
        }
      }
      string_echo += "],";
      uint32_t outcomes_to_length = this->outcomes_to.size();
      string_echo += "outcomes_to:[";
      for( uint32_t i = 0; i < outcomes_to_length; i++) {
        if( i == (outcomes_to_length - 1)) {
          std::stringstream ss_outcomes_toi; ss_outcomes_toi << "\"";
          string_echo += ss_outcomes_toi.str();
          std::size_t outcomes_toi_pos = outcomes_to[i].find("\"");
          while(outcomes_toi_pos != std::string::npos){
            outcomes_to[i].replace(outcomes_toi_pos, 1,"\\\"");
            outcomes_toi_pos = outcomes_to[i].find("\"", outcomes_toi_pos+2);
          }
          string_echo += outcomes_to[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_outcomes_toi; ss_outcomes_toi << "\"";
          string_echo += ss_outcomes_toi.str();
          std::size_t outcomes_toi_pos = outcomes_to[i].find("\"");
          while(outcomes_toi_pos != std::string::npos){
            outcomes_to[i].replace(outcomes_toi_pos, 1,"\\\"");
            outcomes_toi_pos = outcomes_to[i].find("\"", outcomes_toi_pos+2);
          }
          string_echo += outcomes_to[i];
          string_echo += "\",";
        }
      }
      string_echo += "],";
      uint32_t container_outcomes_length = this->container_outcomes.size();
      string_echo += "container_outcomes:[";
      for( uint32_t i = 0; i < container_outcomes_length; i++) {
        if( i == (container_outcomes_length - 1)) {
          std::stringstream ss_container_outcomesi; ss_container_outcomesi << "\"";
          string_echo += ss_container_outcomesi.str();
          std::size_t container_outcomesi_pos = container_outcomes[i].find("\"");
          while(container_outcomesi_pos != std::string::npos){
            container_outcomes[i].replace(container_outcomesi_pos, 1,"\\\"");
            container_outcomesi_pos = container_outcomes[i].find("\"", container_outcomesi_pos+2);
          }
          string_echo += container_outcomes[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_container_outcomesi; ss_container_outcomesi << "\"";
          string_echo += ss_container_outcomesi.str();
          std::size_t container_outcomesi_pos = container_outcomes[i].find("\"");
          while(container_outcomesi_pos != std::string::npos){
            container_outcomes[i].replace(container_outcomesi_pos, 1,"\\\"");
            container_outcomesi_pos = container_outcomes[i].find("\"", container_outcomesi_pos+2);
          }
          string_echo += container_outcomes[i];
          string_echo += "\",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "smach_msgs/SmachContainerStructure"; }
    static std::string getTypeStatic(){ return "smach_msgs/SmachContainerStructure"; }
    virtual std::string getMD5(){ return "0209663ab13753a56b6ac1d094d07fbe"; }
    static std::string getMD5Static(){ return "0209663ab13753a56b6ac1d094d07fbe"; }
    virtual std::string getDefinition(){ return "Header header\nstring path\nstring[] children\nstring[] internal_outcomes\nstring[] outcomes_from\nstring[] outcomes_to\nstring[] container_outcomes\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nstring path\nstring[] children\nstring[] internal_outcomes\nstring[] outcomes_from\nstring[] outcomes_to\nstring[] container_outcomes\n"; }
    static bool hasHeader(){ return true; }
  };

typedef std::shared_ptr<tinyros::smach_msgs::SmachContainerStructure> SmachContainerStructurePtr;
typedef std::shared_ptr<tinyros::smach_msgs::SmachContainerStructure const> SmachContainerStructureConstPtr;

}
}
#endif
