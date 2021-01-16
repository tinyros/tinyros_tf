#ifndef _TINYROS_sensor_msgs_JointState_h
#define _TINYROS_sensor_msgs_JointState_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"

namespace tinyros
{
namespace sensor_msgs
{

  class JointState : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef std::string _name_type;
      std::vector<_name_type> name;
      typedef double _position_type;
      std::vector<_position_type> position;
      typedef double _velocity_type;
      std::vector<_velocity_type> velocity;
      typedef double _effort_type;
      std::vector<_effort_type> effort;

    JointState():
      header(),
      name(0),
      position(0),
      velocity(0),
      effort(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t name_length = this->name.size();
      *(outbuffer + offset + 0) = (name_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (name_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (name_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (name_length >> (8 * 3)) & 0xFF;
      offset += sizeof(name_length);
      for( uint32_t i = 0; i < name_length; i++) {
        uint32_t length_namei = this->name[i].size();
        varToArr(outbuffer + offset, length_namei);
        offset += 4;
        memcpy(outbuffer + offset, this->name[i].c_str(), length_namei);
        offset += length_namei;
      }
      uint32_t position_length = this->position.size();
      *(outbuffer + offset + 0) = (position_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (position_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (position_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (position_length >> (8 * 3)) & 0xFF;
      offset += sizeof(position_length);
      for( uint32_t i = 0; i < position_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_positioni;
        u_positioni.real = this->position[i];
        *(outbuffer + offset + 0) = (u_positioni.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_positioni.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_positioni.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_positioni.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_positioni.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_positioni.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_positioni.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_positioni.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->position[i]);
      }
      uint32_t velocity_length = this->velocity.size();
      *(outbuffer + offset + 0) = (velocity_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (velocity_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (velocity_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (velocity_length >> (8 * 3)) & 0xFF;
      offset += sizeof(velocity_length);
      for( uint32_t i = 0; i < velocity_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_velocityi;
        u_velocityi.real = this->velocity[i];
        *(outbuffer + offset + 0) = (u_velocityi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_velocityi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_velocityi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_velocityi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_velocityi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_velocityi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_velocityi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_velocityi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->velocity[i]);
      }
      uint32_t effort_length = this->effort.size();
      *(outbuffer + offset + 0) = (effort_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (effort_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (effort_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (effort_length >> (8 * 3)) & 0xFF;
      offset += sizeof(effort_length);
      for( uint32_t i = 0; i < effort_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_efforti;
        u_efforti.real = this->effort[i];
        *(outbuffer + offset + 0) = (u_efforti.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_efforti.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_efforti.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_efforti.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_efforti.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_efforti.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_efforti.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_efforti.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->effort[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t name_length = ((uint32_t) (*(inbuffer + offset))); 
      name_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      name_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      name_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->name.resize(name_length); 
      offset += sizeof(name_length);
      for( uint32_t i = 0; i < name_length; i++) {
        uint32_t length_namei;
        arrToVar(length_namei, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_namei; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_namei-1]=0;
        this->name[i] = (char *)(inbuffer + offset-1);
        offset += length_namei;
      }
      uint32_t position_length = ((uint32_t) (*(inbuffer + offset))); 
      position_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      position_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      position_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->position.resize(position_length); 
      offset += sizeof(position_length);
      for( uint32_t i = 0; i < position_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_positioni;
        u_positioni.base = 0;
        u_positioni.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_positioni.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_positioni.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_positioni.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_positioni.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_positioni.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_positioni.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_positioni.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->position[i] = u_positioni.real;
        offset += sizeof(this->position[i]);
      }
      uint32_t velocity_length = ((uint32_t) (*(inbuffer + offset))); 
      velocity_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocity_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocity_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->velocity.resize(velocity_length); 
      offset += sizeof(velocity_length);
      for( uint32_t i = 0; i < velocity_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_velocityi;
        u_velocityi.base = 0;
        u_velocityi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_velocityi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_velocityi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_velocityi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_velocityi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_velocityi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_velocityi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_velocityi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->velocity[i] = u_velocityi.real;
        offset += sizeof(this->velocity[i]);
      }
      uint32_t effort_length = ((uint32_t) (*(inbuffer + offset))); 
      effort_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      effort_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      effort_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->effort.resize(effort_length); 
      offset += sizeof(effort_length);
      for( uint32_t i = 0; i < effort_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_efforti;
        u_efforti.base = 0;
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->effort[i] = u_efforti.real;
        offset += sizeof(this->effort[i]);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      uint32_t name_length = this->name.size();
      length += sizeof(name_length);
      for( uint32_t i = 0; i < name_length; i++) {
        uint32_t length_namei = this->name[i].size();
        length += 4;
        length += length_namei;
      }
      uint32_t position_length = this->position.size();
      length += sizeof(position_length);
      for( uint32_t i = 0; i < position_length; i++) {
        length += sizeof(this->position[i]);
      }
      uint32_t velocity_length = this->velocity.size();
      length += sizeof(velocity_length);
      for( uint32_t i = 0; i < velocity_length; i++) {
        length += sizeof(this->velocity[i]);
      }
      uint32_t effort_length = this->effort.size();
      length += sizeof(effort_length);
      for( uint32_t i = 0; i < effort_length; i++) {
        length += sizeof(this->effort[i]);
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      uint32_t name_length = this->name.size();
      string_echo += "name:[";
      for( uint32_t i = 0; i < name_length; i++) {
        if( i == (name_length - 1)) {
          std::stringstream ss_namei; ss_namei << "\"";
          string_echo += ss_namei.str();
          std::size_t namei_pos = name[i].find("\"");
          while(namei_pos != std::string::npos){
            name[i].replace(namei_pos, 1,"\\\"");
            namei_pos = name[i].find("\"", namei_pos+2);
          }
          string_echo += name[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_namei; ss_namei << "\"";
          string_echo += ss_namei.str();
          std::size_t namei_pos = name[i].find("\"");
          while(namei_pos != std::string::npos){
            name[i].replace(namei_pos, 1,"\\\"");
            namei_pos = name[i].find("\"", namei_pos+2);
          }
          string_echo += name[i];
          string_echo += "\",";
        }
      }
      string_echo += "],";
      uint32_t position_length = this->position.size();
      string_echo += "position:[";
      for( uint32_t i = 0; i < position_length; i++) {
        if( i == (position_length - 1)) {
          std::stringstream ss_positioni; ss_positioni << position[i] <<"";
          string_echo += ss_positioni.str();
        } else {
          std::stringstream ss_positioni; ss_positioni << position[i] <<",";
          string_echo += ss_positioni.str();
        }
      }
      string_echo += "],";
      uint32_t velocity_length = this->velocity.size();
      string_echo += "velocity:[";
      for( uint32_t i = 0; i < velocity_length; i++) {
        if( i == (velocity_length - 1)) {
          std::stringstream ss_velocityi; ss_velocityi << velocity[i] <<"";
          string_echo += ss_velocityi.str();
        } else {
          std::stringstream ss_velocityi; ss_velocityi << velocity[i] <<",";
          string_echo += ss_velocityi.str();
        }
      }
      string_echo += "],";
      uint32_t effort_length = this->effort.size();
      string_echo += "effort:[";
      for( uint32_t i = 0; i < effort_length; i++) {
        if( i == (effort_length - 1)) {
          std::stringstream ss_efforti; ss_efforti << effort[i] <<"";
          string_echo += ss_efforti.str();
        } else {
          std::stringstream ss_efforti; ss_efforti << effort[i] <<",";
          string_echo += ss_efforti.str();
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "sensor_msgs/JointState"; }
    static std::string getTypeStatic(){ return "sensor_msgs/JointState"; }
    virtual std::string getMD5(){ return "6df7130a6d6a4c2f2037ce4a6e061fb9"; }
    static std::string getMD5Static(){ return "6df7130a6d6a4c2f2037ce4a6e061fb9"; }
    virtual std::string getDefinition(){ return "Header header\nstring[] name\nfloat64[] position\nfloat64[] velocity\nfloat64[] effort\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nstring[] name\nfloat64[] position\nfloat64[] velocity\nfloat64[] effort\n"; }
    static bool hasHeader(){ return true; }
  };

typedef std::shared_ptr<tinyros::sensor_msgs::JointState> JointStatePtr;
typedef std::shared_ptr<tinyros::sensor_msgs::JointState const> JointStateConstPtr;

}
}
#endif
