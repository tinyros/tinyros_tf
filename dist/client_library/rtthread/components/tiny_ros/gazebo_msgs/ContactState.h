#ifndef _TINYROS_gazebo_msgs_ContactState_h
#define _TINYROS_gazebo_msgs_ContactState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/geometry_msgs/Wrench.h"
#include "tiny_ros/geometry_msgs/Vector3.h"

namespace tinyros
{
namespace gazebo_msgs
{

  class ContactState : public tinyros::Msg
  {
    public:
      typedef tinyros::string _info_type;
      _info_type info;
      typedef tinyros::string _collision1_name_type;
      _collision1_name_type collision1_name;
      typedef tinyros::string _collision2_name_type;
      _collision2_name_type collision2_name;
      uint32_t wrenches_length;
      typedef tinyros::geometry_msgs::Wrench _wrenches_type;
      _wrenches_type st_wrenches;
      _wrenches_type * wrenches;
      typedef tinyros::geometry_msgs::Wrench _total_wrench_type;
      _total_wrench_type total_wrench;
      uint32_t contact_positions_length;
      typedef tinyros::geometry_msgs::Vector3 _contact_positions_type;
      _contact_positions_type st_contact_positions;
      _contact_positions_type * contact_positions;
      uint32_t contact_normals_length;
      typedef tinyros::geometry_msgs::Vector3 _contact_normals_type;
      _contact_normals_type st_contact_normals;
      _contact_normals_type * contact_normals;
      uint32_t depths_length;
      typedef double _depths_type;
      _depths_type st_depths;
      _depths_type * depths;

    ContactState():
      info(""),
      collision1_name(""),
      collision2_name(""),
      wrenches_length(0), wrenches(NULL),
      total_wrench(),
      contact_positions_length(0), contact_positions(NULL),
      contact_normals_length(0), contact_normals(NULL),
      depths_length(0), depths(NULL)
    {
    }

    ~ContactState()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(wrenches != NULL)
      {
        for( uint32_t i = 0; i < wrenches_length; i++){
          wrenches[i].deconstructor();
        }
        free(wrenches);
      }
      wrenches = NULL;
      wrenches_length = 0;
      if(contact_positions != NULL)
      {
        for( uint32_t i = 0; i < contact_positions_length; i++){
          contact_positions[i].deconstructor();
        }
        free(contact_positions);
      }
      contact_positions = NULL;
      contact_positions_length = 0;
      if(contact_normals != NULL)
      {
        for( uint32_t i = 0; i < contact_normals_length; i++){
          contact_normals[i].deconstructor();
        }
        free(contact_normals);
      }
      contact_normals = NULL;
      contact_normals_length = 0;
      if(depths != NULL)
      {
        free(depths);
      }
      depths = NULL;
      depths_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_info = this->info.size();
      varToArr(outbuffer + offset, length_info);
      offset += 4;
      memcpy(outbuffer + offset, this->info.c_str(), length_info);
      offset += length_info;
      uint32_t length_collision1_name = this->collision1_name.size();
      varToArr(outbuffer + offset, length_collision1_name);
      offset += 4;
      memcpy(outbuffer + offset, this->collision1_name.c_str(), length_collision1_name);
      offset += length_collision1_name;
      uint32_t length_collision2_name = this->collision2_name.size();
      varToArr(outbuffer + offset, length_collision2_name);
      offset += 4;
      memcpy(outbuffer + offset, this->collision2_name.c_str(), length_collision2_name);
      offset += length_collision2_name;
      *(outbuffer + offset + 0) = (this->wrenches_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wrenches_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->wrenches_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->wrenches_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wrenches_length);
      for( uint32_t i = 0; i < wrenches_length; i++) {
        offset += this->wrenches[i].serialize(outbuffer + offset);
      }
      offset += this->total_wrench.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->contact_positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->contact_positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->contact_positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->contact_positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->contact_positions_length);
      for( uint32_t i = 0; i < contact_positions_length; i++) {
        offset += this->contact_positions[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->contact_normals_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->contact_normals_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->contact_normals_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->contact_normals_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->contact_normals_length);
      for( uint32_t i = 0; i < contact_normals_length; i++) {
        offset += this->contact_normals[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->depths_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->depths_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->depths_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->depths_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->depths_length);
      for( uint32_t i = 0; i < depths_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_depthsi;
        u_depthsi.real = this->depths[i];
        *(outbuffer + offset + 0) = (u_depthsi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_depthsi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_depthsi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_depthsi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_depthsi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_depthsi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_depthsi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_depthsi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->depths[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_info;
      arrToVar(length_info, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_info; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_info-1]=0;
      this->info = (char *)(inbuffer + offset-1);
      offset += length_info;
      uint32_t length_collision1_name;
      arrToVar(length_collision1_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_collision1_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_collision1_name-1]=0;
      this->collision1_name = (char *)(inbuffer + offset-1);
      offset += length_collision1_name;
      uint32_t length_collision2_name;
      arrToVar(length_collision2_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_collision2_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_collision2_name-1]=0;
      this->collision2_name = (char *)(inbuffer + offset-1);
      offset += length_collision2_name;
      uint32_t wrenches_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      wrenches_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      wrenches_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      wrenches_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->wrenches_length);
      if(wrenches_lengthT > wrenches_length)
        this->wrenches = (tinyros::geometry_msgs::Wrench*)realloc(this->wrenches, wrenches_lengthT * sizeof(tinyros::geometry_msgs::Wrench));
      wrenches_length = wrenches_lengthT;
      for( uint32_t i = 0; i < wrenches_length; i++) {
        offset += this->st_wrenches.deserialize(inbuffer + offset);
        memcpy( &(this->wrenches[i]), &(this->st_wrenches), sizeof(tinyros::geometry_msgs::Wrench));
      }
      offset += this->total_wrench.deserialize(inbuffer + offset);
      uint32_t contact_positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      contact_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      contact_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      contact_positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->contact_positions_length);
      if(contact_positions_lengthT > contact_positions_length)
        this->contact_positions = (tinyros::geometry_msgs::Vector3*)realloc(this->contact_positions, contact_positions_lengthT * sizeof(tinyros::geometry_msgs::Vector3));
      contact_positions_length = contact_positions_lengthT;
      for( uint32_t i = 0; i < contact_positions_length; i++) {
        offset += this->st_contact_positions.deserialize(inbuffer + offset);
        memcpy( &(this->contact_positions[i]), &(this->st_contact_positions), sizeof(tinyros::geometry_msgs::Vector3));
      }
      uint32_t contact_normals_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      contact_normals_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      contact_normals_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      contact_normals_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->contact_normals_length);
      if(contact_normals_lengthT > contact_normals_length)
        this->contact_normals = (tinyros::geometry_msgs::Vector3*)realloc(this->contact_normals, contact_normals_lengthT * sizeof(tinyros::geometry_msgs::Vector3));
      contact_normals_length = contact_normals_lengthT;
      for( uint32_t i = 0; i < contact_normals_length; i++) {
        offset += this->st_contact_normals.deserialize(inbuffer + offset);
        memcpy( &(this->contact_normals[i]), &(this->st_contact_normals), sizeof(tinyros::geometry_msgs::Vector3));
      }
      uint32_t depths_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      depths_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      depths_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      depths_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->depths_length);
      if(depths_lengthT > depths_length)
        this->depths = (double*)realloc(this->depths, depths_lengthT * sizeof(double));
      depths_length = depths_lengthT;
      for( uint32_t i = 0; i < depths_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_depths;
        u_st_depths.base = 0;
        u_st_depths.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_depths.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_depths.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_depths.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_depths.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_depths.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_depths.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_depths.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_depths = u_st_depths.real;
        offset += sizeof(this->st_depths);
        memcpy( &(this->depths[i]), &(this->st_depths), sizeof(double));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_info = this->info.size();
      length += 4;
      length += length_info;
      uint32_t length_collision1_name = this->collision1_name.size();
      length += 4;
      length += length_collision1_name;
      uint32_t length_collision2_name = this->collision2_name.size();
      length += 4;
      length += length_collision2_name;
      length += sizeof(this->wrenches_length);
      for( uint32_t i = 0; i < wrenches_length; i++) {
        length += this->wrenches[i].serializedLength();
      }
      length += this->total_wrench.serializedLength();
      length += sizeof(this->contact_positions_length);
      for( uint32_t i = 0; i < contact_positions_length; i++) {
        length += this->contact_positions[i].serializedLength();
      }
      length += sizeof(this->contact_normals_length);
      for( uint32_t i = 0; i < contact_normals_length; i++) {
        length += this->contact_normals[i].serializedLength();
      }
      length += sizeof(this->depths_length);
      for( uint32_t i = 0; i < depths_length; i++) {
        length += sizeof(this->depths[i]);
      }
      return length;
    }

    virtual tinyros::string getType(){ return "gazebo_msgs/ContactState"; }
    static tinyros::string getTypeStatic(){ return "gazebo_msgs/ContactState"; }
    virtual tinyros::string getMD5(){ return "d82d0f0cae88aebf6b2cc86caea33a2b"; }
    static tinyros::string getMD5Static(){ return "d82d0f0cae88aebf6b2cc86caea33a2b"; }
    virtual tinyros::string getDefinition(){ return "string info                                   \nstring collision1_name                        \nstring collision2_name                        \ngeometry_msgs/Wrench[] wrenches               \ngeometry_msgs/Wrench total_wrench             \ngeometry_msgs/Vector3[] contact_positions     \ngeometry_msgs/Vector3[] contact_normals       \nfloat64[] depths                              \n"; }
    static tinyros::string getDefinitionStatic(){ return "string info                                   \nstring collision1_name                        \nstring collision2_name                        \ngeometry_msgs/Wrench[] wrenches               \ngeometry_msgs/Wrench total_wrench             \ngeometry_msgs/Vector3[] contact_positions     \ngeometry_msgs/Vector3[] contact_normals       \nfloat64[] depths                              \n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
