#ifndef _TINYROS_sensor_msgs_JointState_h
#define _TINYROS_sensor_msgs_JointState_h

#include <stdint.h>
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
      uint32_t name_length;
      typedef tinyros::string _name_type;
      _name_type st_name;
      _name_type * name;
      uint32_t position_length;
      typedef double _position_type;
      _position_type st_position;
      _position_type * position;
      uint32_t velocity_length;
      typedef double _velocity_type;
      _velocity_type st_velocity;
      _velocity_type * velocity;
      uint32_t effort_length;
      typedef double _effort_type;
      _effort_type st_effort;
      _effort_type * effort;

    JointState():
      header(),
      name_length(0), name(NULL),
      position_length(0), position(NULL),
      velocity_length(0), velocity(NULL),
      effort_length(0), effort(NULL)
    {
    }

    ~JointState()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(name != NULL)
      {
        free(name);
      }
      name = NULL;
      name_length = 0;
      if(position != NULL)
      {
        free(position);
      }
      position = NULL;
      position_length = 0;
      if(velocity != NULL)
      {
        free(velocity);
      }
      velocity = NULL;
      velocity_length = 0;
      if(effort != NULL)
      {
        free(effort);
      }
      effort = NULL;
      effort_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->name_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->name_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->name_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->name_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->name_length);
      for( uint32_t i = 0; i < name_length; i++) {
        uint32_t length_namei = this->name[i].size();
        varToArr(outbuffer + offset, length_namei);
        offset += 4;
        memcpy(outbuffer + offset, this->name[i].c_str(), length_namei);
        offset += length_namei;
      }
      *(outbuffer + offset + 0) = (this->position_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->position_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->position_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->position_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->position_length);
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
      *(outbuffer + offset + 0) = (this->velocity_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocity_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocity_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocity_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocity_length);
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
      *(outbuffer + offset + 0) = (this->effort_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->effort_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->effort_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->effort_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effort_length);
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
      uint32_t name_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->name_length);
      if(name_lengthT > name_length)
        this->name = (tinyros::string*)realloc(this->name, name_lengthT * sizeof(tinyros::string));
      name_length = name_lengthT;
      for( uint32_t i = 0; i < name_length; i++) {
        uint32_t length_st_name;
        arrToVar(length_st_name, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_st_name; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_st_name-1]=0;
        this->st_name = (char *)(inbuffer + offset-1);
        offset += length_st_name;
        memcpy( &(this->name[i]), &(this->st_name), sizeof(tinyros::string));
      }
      uint32_t position_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      position_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      position_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      position_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->position_length);
      if(position_lengthT > position_length)
        this->position = (double*)realloc(this->position, position_lengthT * sizeof(double));
      position_length = position_lengthT;
      for( uint32_t i = 0; i < position_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_position;
        u_st_position.base = 0;
        u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_position.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_position = u_st_position.real;
        offset += sizeof(this->st_position);
        memcpy( &(this->position[i]), &(this->st_position), sizeof(double));
      }
      uint32_t velocity_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->velocity_length);
      if(velocity_lengthT > velocity_length)
        this->velocity = (double*)realloc(this->velocity, velocity_lengthT * sizeof(double));
      velocity_length = velocity_lengthT;
      for( uint32_t i = 0; i < velocity_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_velocity;
        u_st_velocity.base = 0;
        u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_velocity.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_velocity = u_st_velocity.real;
        offset += sizeof(this->st_velocity);
        memcpy( &(this->velocity[i]), &(this->st_velocity), sizeof(double));
      }
      uint32_t effort_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->effort_length);
      if(effort_lengthT > effort_length)
        this->effort = (double*)realloc(this->effort, effort_lengthT * sizeof(double));
      effort_length = effort_lengthT;
      for( uint32_t i = 0; i < effort_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_effort;
        u_st_effort.base = 0;
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_effort = u_st_effort.real;
        offset += sizeof(this->st_effort);
        memcpy( &(this->effort[i]), &(this->st_effort), sizeof(double));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += sizeof(this->name_length);
      for( uint32_t i = 0; i < name_length; i++) {
        uint32_t length_namei = this->name[i].size();
        length += 4;
        length += length_namei;
      }
      length += sizeof(this->position_length);
      for( uint32_t i = 0; i < position_length; i++) {
        length += sizeof(this->position[i]);
      }
      length += sizeof(this->velocity_length);
      for( uint32_t i = 0; i < velocity_length; i++) {
        length += sizeof(this->velocity[i]);
      }
      length += sizeof(this->effort_length);
      for( uint32_t i = 0; i < effort_length; i++) {
        length += sizeof(this->effort[i]);
      }
      return length;
    }

    virtual tinyros::string getType(){ return "sensor_msgs/JointState"; }
    static tinyros::string getTypeStatic(){ return "sensor_msgs/JointState"; }
    virtual tinyros::string getMD5(){ return "6df7130a6d6a4c2f2037ce4a6e061fb9"; }
    static tinyros::string getMD5Static(){ return "6df7130a6d6a4c2f2037ce4a6e061fb9"; }
    virtual tinyros::string getDefinition(){ return "Header header\nstring[] name\nfloat64[] position\nfloat64[] velocity\nfloat64[] effort\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\nstring[] name\nfloat64[] position\nfloat64[] velocity\nfloat64[] effort\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
