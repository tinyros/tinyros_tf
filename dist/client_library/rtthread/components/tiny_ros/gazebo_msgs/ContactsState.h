#ifndef _TINYROS_gazebo_msgs_ContactsState_h
#define _TINYROS_gazebo_msgs_ContactsState_h

#include <stdint.h>
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
      uint32_t states_length;
      typedef tinyros::gazebo_msgs::ContactState _states_type;
      _states_type st_states;
      _states_type * states;

    ContactsState():
      header(),
      states_length(0), states(NULL)
    {
    }

    ~ContactsState()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(states != NULL)
      {
        for( uint32_t i = 0; i < states_length; i++){
          states[i].deconstructor();
        }
        free(states);
      }
      states = NULL;
      states_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->states_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->states_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->states_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->states_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->states_length);
      for( uint32_t i = 0; i < states_length; i++) {
        offset += this->states[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t states_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      states_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->states_length);
      if(states_lengthT > states_length)
        this->states = (tinyros::gazebo_msgs::ContactState*)realloc(this->states, states_lengthT * sizeof(tinyros::gazebo_msgs::ContactState));
      states_length = states_lengthT;
      for( uint32_t i = 0; i < states_length; i++) {
        offset += this->st_states.deserialize(inbuffer + offset);
        memcpy( &(this->states[i]), &(this->st_states), sizeof(tinyros::gazebo_msgs::ContactState));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += sizeof(this->states_length);
      for( uint32_t i = 0; i < states_length; i++) {
        length += this->states[i].serializedLength();
      }
      return length;
    }

    virtual tinyros::string getType(){ return "gazebo_msgs/ContactsState"; }
    static tinyros::string getTypeStatic(){ return "gazebo_msgs/ContactsState"; }
    virtual tinyros::string getMD5(){ return "d19cd2a086cbd43da4252eb8d5cc64f5"; }
    static tinyros::string getMD5Static(){ return "d19cd2a086cbd43da4252eb8d5cc64f5"; }
    virtual tinyros::string getDefinition(){ return "Header header                                   \ngazebo_msgs/ContactState[] states            \n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header                                   \ngazebo_msgs/ContactState[] states            \n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
