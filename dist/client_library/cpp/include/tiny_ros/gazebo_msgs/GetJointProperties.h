#ifndef _TINYROS_SERVICE_GetJointProperties_h
#define _TINYROS_SERVICE_GetJointProperties_h
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

static const char GETJOINTPROPERTIES[] = "gazebo_msgs/GetJointProperties";

  class GetJointPropertiesRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef std::string _joint_name_type;
      _joint_name_type joint_name;

    GetJointPropertiesRequest():
      joint_name("")
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
      uint32_t length_joint_name = this->joint_name.size();
      varToArr(outbuffer + offset, length_joint_name);
      offset += 4;
      memcpy(outbuffer + offset, this->joint_name.c_str(), length_joint_name);
      offset += length_joint_name;
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
      uint32_t length_joint_name;
      arrToVar(length_joint_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_joint_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_joint_name-1]=0;
      this->joint_name = (char *)(inbuffer + offset-1);
      offset += length_joint_name;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_joint_name = this->joint_name.size();
      length += 4;
      length += length_joint_name;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::size_t joint_name_pos = joint_name.find("\"");
      while(joint_name_pos != std::string::npos){
        joint_name.replace(joint_name_pos, 1,"\\\"");
        joint_name_pos = joint_name.find("\"", joint_name_pos+2);
      }
      string_echo += "\"joint_name\":\"";
      string_echo += joint_name;
      string_echo += "\"";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return GETJOINTPROPERTIES; }
    static std::string getTypeStatic(){ return GETJOINTPROPERTIES; }
    virtual std::string getMD5(){ return "b07a3ce5fb5aba1cfc56577c9cb3ecc6"; }
    static std::string getMD5Static(){ return "b07a3ce5fb5aba1cfc56577c9cb3ecc6"; }
    virtual std::string getDefinition(){ return "string joint_name\n"; }
    static std::string getDefinitionStatic(){ return "string joint_name\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
  };

typedef std::shared_ptr<tinyros::gazebo_msgs::GetJointPropertiesRequest> GetJointPropertiesRequestPtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::GetJointPropertiesRequest const> GetJointPropertiesRequestConstPtr;

  class GetJointPropertiesResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef uint8_t _type_type;
      _type_type type;
      typedef double _damping_type;
      std::vector<_damping_type> damping;
      typedef double _position_type;
      std::vector<_position_type> position;
      typedef double _rate_type;
      std::vector<_rate_type> rate;
      typedef bool _success_type;
      _success_type success;
      typedef std::string _status_message_type;
      _status_message_type status_message;
      enum { REVOLUTE =  0                 };
      enum { CONTINUOUS =  1                 };
      enum { PRISMATIC =  2                 };
      enum { FIXED =  3                 };
      enum { BALL =  4                 };
      enum { UNIVERSAL =  5                 };

    GetJointPropertiesResponse():
      type(0),
      damping(0),
      position(0),
      rate(0),
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
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t damping_length = this->damping.size();
      *(outbuffer + offset + 0) = (damping_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (damping_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (damping_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (damping_length >> (8 * 3)) & 0xFF;
      offset += sizeof(damping_length);
      for( uint32_t i = 0; i < damping_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_dampingi;
        u_dampingi.real = this->damping[i];
        *(outbuffer + offset + 0) = (u_dampingi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_dampingi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_dampingi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_dampingi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_dampingi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_dampingi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_dampingi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_dampingi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->damping[i]);
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
      uint32_t rate_length = this->rate.size();
      *(outbuffer + offset + 0) = (rate_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (rate_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (rate_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (rate_length >> (8 * 3)) & 0xFF;
      offset += sizeof(rate_length);
      for( uint32_t i = 0; i < rate_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_ratei;
        u_ratei.real = this->rate[i];
        *(outbuffer + offset + 0) = (u_ratei.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_ratei.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_ratei.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_ratei.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_ratei.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_ratei.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_ratei.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_ratei.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->rate[i]);
      }
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
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      uint32_t damping_length = ((uint32_t) (*(inbuffer + offset))); 
      damping_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      damping_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      damping_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->damping.resize(damping_length); 
      offset += sizeof(damping_length);
      for( uint32_t i = 0; i < damping_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_dampingi;
        u_dampingi.base = 0;
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->damping[i] = u_dampingi.real;
        offset += sizeof(this->damping[i]);
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
      uint32_t rate_length = ((uint32_t) (*(inbuffer + offset))); 
      rate_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      rate_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      rate_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->rate.resize(rate_length); 
      offset += sizeof(rate_length);
      for( uint32_t i = 0; i < rate_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_ratei;
        u_ratei.base = 0;
        u_ratei.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_ratei.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_ratei.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_ratei.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_ratei.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_ratei.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_ratei.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_ratei.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->rate[i] = u_ratei.real;
        offset += sizeof(this->rate[i]);
      }
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
      length += sizeof(this->type);
      uint32_t damping_length = this->damping.size();
      length += sizeof(damping_length);
      for( uint32_t i = 0; i < damping_length; i++) {
        length += sizeof(this->damping[i]);
      }
      uint32_t position_length = this->position.size();
      length += sizeof(position_length);
      for( uint32_t i = 0; i < position_length; i++) {
        length += sizeof(this->position[i]);
      }
      uint32_t rate_length = this->rate.size();
      length += sizeof(rate_length);
      for( uint32_t i = 0; i < rate_length; i++) {
        length += sizeof(this->rate[i]);
      }
      length += sizeof(this->success);
      uint32_t length_status_message = this->status_message.size();
      length += 4;
      length += length_status_message;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::stringstream ss_type; ss_type << "\"type\":" << (uint16_t)type <<",";
      string_echo += ss_type.str();
      uint32_t damping_length = this->damping.size();
      string_echo += "damping:[";
      for( uint32_t i = 0; i < damping_length; i++) {
        if( i == (damping_length - 1)) {
          std::stringstream ss_dampingi; ss_dampingi << damping[i] <<"";
          string_echo += ss_dampingi.str();
        } else {
          std::stringstream ss_dampingi; ss_dampingi << damping[i] <<",";
          string_echo += ss_dampingi.str();
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
      uint32_t rate_length = this->rate.size();
      string_echo += "rate:[";
      for( uint32_t i = 0; i < rate_length; i++) {
        if( i == (rate_length - 1)) {
          std::stringstream ss_ratei; ss_ratei << rate[i] <<"";
          string_echo += ss_ratei.str();
        } else {
          std::stringstream ss_ratei; ss_ratei << rate[i] <<",";
          string_echo += ss_ratei.str();
        }
      }
      string_echo += "],";
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

    virtual std::string getType(){ return GETJOINTPROPERTIES; }
    static std::string getTypeStatic(){ return GETJOINTPROPERTIES; }
    virtual std::string getMD5(){ return "a60fbf691ac539e1355c979ca09b4573"; }
    static std::string getMD5Static(){ return "a60fbf691ac539e1355c979ca09b4573"; }
    virtual std::string getDefinition(){ return "uint8 type\nfloat64[] damping\nfloat64[] position\nfloat64[] rate\nbool success\nstring status_message\n"; }
    static std::string getDefinitionStatic(){ return "uint8 type\nfloat64[] damping\nfloat64[] position\nfloat64[] rate\nbool success\nstring status_message\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
  };

typedef std::shared_ptr<tinyros::gazebo_msgs::GetJointPropertiesResponse> GetJointPropertiesResponsePtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::GetJointPropertiesResponse const> GetJointPropertiesResponseConstPtr;

  class GetJointProperties {
    public:
    typedef GetJointPropertiesRequest Request;
    typedef GetJointPropertiesResponse Response;
  };

}
}
#endif
