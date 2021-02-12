#ifndef _TINYROS_gazebo_msgs_ContactsState_h
#define _TINYROS_gazebo_msgs_ContactsState_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/gazebo_msgs/ContactState.h"

namespace tinyros
{
namespace gazebo_msgs
{

  class ContactsState : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::gazebo_msgs::ContactState _states_type;
      std::vector<_states_type> states;

    ContactsState():
      header(),
      states(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t states_length = this->states.size();
      *(outbuffer + offset + 0) = (states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(states_length);
      for( uint32_t i = 0; i < states_length; i++) {
        offset += this->states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t states_length = ((uint32_t) (*(inbuffer + offset))); 
      states_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      states_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      states_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->states.resize(states_length); 
      offset += sizeof(states_length);
      for( uint32_t i = 0; i < states_length; i++) {
        offset += this->states[i].deserialize(inbuffer + offset);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      uint32_t states_length = this->states.size();
      length += sizeof(states_length);
      for( uint32_t i = 0; i < states_length; i++) {
        length += this->states[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      uint32_t states_length = this->states.size();
      string_echo += "states:[";
      for( uint32_t i = 0; i < states_length; i++) {
        if( i == (states_length - 1)) {
          string_echo += this->states[i].echo();
          string_echo += "";
        } else {
          string_echo += this->states[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "gazebo_msgs/ContactsState"; }
    static std::string getTypeStatic(){ return "gazebo_msgs/ContactsState"; }
    virtual std::string getMD5(){ return "d19cd2a086cbd43da4252eb8d5cc64f5"; }
    static std::string getMD5Static(){ return "d19cd2a086cbd43da4252eb8d5cc64f5"; }
    virtual std::string getDefinition(){ return "Header header\ngazebo_msgs/ContactState[] states\n"; }
    static std::string getDefinitionStatic(){ return "Header header\ngazebo_msgs/ContactState[] states\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::ContactsState> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::ContactsState const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::ContactsState> ContactsStatePtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::ContactsState const> ContactsStateConstPtr;

}
}
#endif
