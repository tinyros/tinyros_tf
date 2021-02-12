#ifndef _TINYROS_gazebo_msgs_ContactState_h
#define _TINYROS_gazebo_msgs_ContactState_h

#include <stdint.h>
#include <string>
#include <stdio.h>
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
      typedef std::string _info_type;
      _info_type info;
      typedef std::string _collision1_name_type;
      _collision1_name_type collision1_name;
      typedef std::string _collision2_name_type;
      _collision2_name_type collision2_name;
      typedef tinyros::geometry_msgs::Wrench _wrenches_type;
      std::vector<_wrenches_type> wrenches;
      typedef tinyros::geometry_msgs::Wrench _total_wrench_type;
      _total_wrench_type total_wrench;
      typedef tinyros::geometry_msgs::Vector3 _contact_positions_type;
      std::vector<_contact_positions_type> contact_positions;
      typedef tinyros::geometry_msgs::Vector3 _contact_normals_type;
      std::vector<_contact_normals_type> contact_normals;
      typedef double _depths_type;
      std::vector<_depths_type> depths;

    ContactState():
      info(""),
      collision1_name(""),
      collision2_name(""),
      wrenches(0),
      total_wrench(),
      contact_positions(0),
      contact_normals(0),
      depths(0)
    {
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
      uint32_t wrenches_length = this->wrenches.size();
      *(outbuffer + offset + 0) = (wrenches_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (wrenches_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (wrenches_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (wrenches_length >> (8 * 3)) & 0xFF;
      offset += sizeof(wrenches_length);
      for( uint32_t i = 0; i < wrenches_length; i++) {
        offset += this->wrenches[i].serialize(outbuffer + offset);
      }
      offset += this->total_wrench.serialize(outbuffer + offset);
      uint32_t contact_positions_length = this->contact_positions.size();
      *(outbuffer + offset + 0) = (contact_positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (contact_positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (contact_positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (contact_positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(contact_positions_length);
      for( uint32_t i = 0; i < contact_positions_length; i++) {
        offset += this->contact_positions[i].serialize(outbuffer + offset);
      }
      uint32_t contact_normals_length = this->contact_normals.size();
      *(outbuffer + offset + 0) = (contact_normals_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (contact_normals_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (contact_normals_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (contact_normals_length >> (8 * 3)) & 0xFF;
      offset += sizeof(contact_normals_length);
      for( uint32_t i = 0; i < contact_normals_length; i++) {
        offset += this->contact_normals[i].serialize(outbuffer + offset);
      }
      uint32_t depths_length = this->depths.size();
      *(outbuffer + offset + 0) = (depths_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (depths_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (depths_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (depths_length >> (8 * 3)) & 0xFF;
      offset += sizeof(depths_length);
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
      uint32_t wrenches_length = ((uint32_t) (*(inbuffer + offset))); 
      wrenches_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      wrenches_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      wrenches_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->wrenches.resize(wrenches_length); 
      offset += sizeof(wrenches_length);
      for( uint32_t i = 0; i < wrenches_length; i++) {
        offset += this->wrenches[i].deserialize(inbuffer + offset);
      }
      offset += this->total_wrench.deserialize(inbuffer + offset);
      uint32_t contact_positions_length = ((uint32_t) (*(inbuffer + offset))); 
      contact_positions_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      contact_positions_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      contact_positions_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->contact_positions.resize(contact_positions_length); 
      offset += sizeof(contact_positions_length);
      for( uint32_t i = 0; i < contact_positions_length; i++) {
        offset += this->contact_positions[i].deserialize(inbuffer + offset);
      }
      uint32_t contact_normals_length = ((uint32_t) (*(inbuffer + offset))); 
      contact_normals_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      contact_normals_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      contact_normals_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->contact_normals.resize(contact_normals_length); 
      offset += sizeof(contact_normals_length);
      for( uint32_t i = 0; i < contact_normals_length; i++) {
        offset += this->contact_normals[i].deserialize(inbuffer + offset);
      }
      uint32_t depths_length = ((uint32_t) (*(inbuffer + offset))); 
      depths_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      depths_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      depths_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->depths.resize(depths_length); 
      offset += sizeof(depths_length);
      for( uint32_t i = 0; i < depths_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_depthsi;
        u_depthsi.base = 0;
        u_depthsi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_depthsi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_depthsi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_depthsi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_depthsi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_depthsi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_depthsi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_depthsi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->depths[i] = u_depthsi.real;
        offset += sizeof(this->depths[i]);
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
      uint32_t wrenches_length = this->wrenches.size();
      length += sizeof(wrenches_length);
      for( uint32_t i = 0; i < wrenches_length; i++) {
        length += this->wrenches[i].serializedLength();
      }
      length += this->total_wrench.serializedLength();
      uint32_t contact_positions_length = this->contact_positions.size();
      length += sizeof(contact_positions_length);
      for( uint32_t i = 0; i < contact_positions_length; i++) {
        length += this->contact_positions[i].serializedLength();
      }
      uint32_t contact_normals_length = this->contact_normals.size();
      length += sizeof(contact_normals_length);
      for( uint32_t i = 0; i < contact_normals_length; i++) {
        length += this->contact_normals[i].serializedLength();
      }
      uint32_t depths_length = this->depths.size();
      length += sizeof(depths_length);
      for( uint32_t i = 0; i < depths_length; i++) {
        length += sizeof(this->depths[i]);
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::size_t info_pos = info.find("\"");
      while(info_pos != std::string::npos){
        info.replace(info_pos, 1,"\\\"");
        info_pos = info.find("\"", info_pos+2);
      }
      string_echo += "\"info\":\"";
      string_echo += info;
      string_echo += "\",";
      std::size_t collision1_name_pos = collision1_name.find("\"");
      while(collision1_name_pos != std::string::npos){
        collision1_name.replace(collision1_name_pos, 1,"\\\"");
        collision1_name_pos = collision1_name.find("\"", collision1_name_pos+2);
      }
      string_echo += "\"collision1_name\":\"";
      string_echo += collision1_name;
      string_echo += "\",";
      std::size_t collision2_name_pos = collision2_name.find("\"");
      while(collision2_name_pos != std::string::npos){
        collision2_name.replace(collision2_name_pos, 1,"\\\"");
        collision2_name_pos = collision2_name.find("\"", collision2_name_pos+2);
      }
      string_echo += "\"collision2_name\":\"";
      string_echo += collision2_name;
      string_echo += "\",";
      uint32_t wrenches_length = this->wrenches.size();
      string_echo += "wrenches:[";
      for( uint32_t i = 0; i < wrenches_length; i++) {
        if( i == (wrenches_length - 1)) {
          string_echo += this->wrenches[i].echo();
          string_echo += "";
        } else {
          string_echo += this->wrenches[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "],";
      string_echo += "\"total_wrench\":";
      string_echo += this->total_wrench.echo();
      string_echo += ",";
      uint32_t contact_positions_length = this->contact_positions.size();
      string_echo += "contact_positions:[";
      for( uint32_t i = 0; i < contact_positions_length; i++) {
        if( i == (contact_positions_length - 1)) {
          string_echo += this->contact_positions[i].echo();
          string_echo += "";
        } else {
          string_echo += this->contact_positions[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "],";
      uint32_t contact_normals_length = this->contact_normals.size();
      string_echo += "contact_normals:[";
      for( uint32_t i = 0; i < contact_normals_length; i++) {
        if( i == (contact_normals_length - 1)) {
          string_echo += this->contact_normals[i].echo();
          string_echo += "";
        } else {
          string_echo += this->contact_normals[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "],";
      uint32_t depths_length = this->depths.size();
      string_echo += "depths:[";
      for( uint32_t i = 0; i < depths_length; i++) {
        if( i == (depths_length - 1)) {
          std::stringstream ss_depthsi; ss_depthsi << depths[i] <<"";
          string_echo += ss_depthsi.str();
        } else {
          std::stringstream ss_depthsi; ss_depthsi << depths[i] <<",";
          string_echo += ss_depthsi.str();
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "gazebo_msgs/ContactState"; }
    static std::string getTypeStatic(){ return "gazebo_msgs/ContactState"; }
    virtual std::string getMD5(){ return "d82d0f0cae88aebf6b2cc86caea33a2b"; }
    static std::string getMD5Static(){ return "d82d0f0cae88aebf6b2cc86caea33a2b"; }
    virtual std::string getDefinition(){ return "string info\nstring collision1_name\nstring collision2_name\ngeometry_msgs/Wrench[] wrenches\ngeometry_msgs/Wrench total_wrench\ngeometry_msgs/Vector3[] contact_positions\ngeometry_msgs/Vector3[] contact_normals\nfloat64[] depths\n"; }
    static std::string getDefinitionStatic(){ return "string info\nstring collision1_name\nstring collision2_name\ngeometry_msgs/Wrench[] wrenches\ngeometry_msgs/Wrench total_wrench\ngeometry_msgs/Vector3[] contact_positions\ngeometry_msgs/Vector3[] contact_normals\nfloat64[] depths\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::ContactState> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::ContactState const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::ContactState> ContactStatePtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::ContactState const> ContactStateConstPtr;

}
}
#endif
