#ifndef _TINYROS_visualization_msgs_InteractiveMarker_h
#define _TINYROS_visualization_msgs_InteractiveMarker_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Pose.h"
#include "tiny_ros/visualization_msgs/MenuEntry.h"
#include "tiny_ros/visualization_msgs/InteractiveMarkerControl.h"

namespace tinyros
{
namespace visualization_msgs
{

  class InteractiveMarker : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef tinyros::string _name_type;
      _name_type name;
      typedef tinyros::string _description_type;
      _description_type description;
      typedef float _scale_type;
      _scale_type scale;
      uint32_t menu_entries_length;
      typedef tinyros::visualization_msgs::MenuEntry _menu_entries_type;
      _menu_entries_type st_menu_entries;
      _menu_entries_type * menu_entries;
      uint32_t controls_length;
      typedef tinyros::visualization_msgs::InteractiveMarkerControl _controls_type;
      _controls_type st_controls;
      _controls_type * controls;

    InteractiveMarker():
      header(),
      pose(),
      name(""),
      description(""),
      scale(0),
      menu_entries_length(0), menu_entries(NULL),
      controls_length(0), controls(NULL)
    {
    }

    ~InteractiveMarker()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(menu_entries != NULL)
      {
        for( uint32_t i = 0; i < menu_entries_length; i++){
          menu_entries[i].deconstructor();
        }
        free(menu_entries);
      }
      menu_entries = NULL;
      menu_entries_length = 0;
      if(controls != NULL)
      {
        for( uint32_t i = 0; i < controls_length; i++){
          controls[i].deconstructor();
        }
        free(controls);
      }
      controls = NULL;
      controls_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      uint32_t length_name = this->name.size();
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name.c_str(), length_name);
      offset += length_name;
      uint32_t length_description = this->description.size();
      varToArr(outbuffer + offset, length_description);
      offset += 4;
      memcpy(outbuffer + offset, this->description.c_str(), length_description);
      offset += length_description;
      union {
        float real;
        uint32_t base;
      } u_scale;
      u_scale.real = this->scale;
      *(outbuffer + offset + 0) = (u_scale.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scale.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scale.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scale.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scale);
      *(outbuffer + offset + 0) = (this->menu_entries_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->menu_entries_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->menu_entries_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->menu_entries_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->menu_entries_length);
      for( uint32_t i = 0; i < menu_entries_length; i++) {
        offset += this->menu_entries[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->controls_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->controls_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->controls_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->controls_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->controls_length);
      for( uint32_t i = 0; i < controls_length; i++) {
        offset += this->controls[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_description;
      arrToVar(length_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      union {
        float real;
        uint32_t base;
      } u_scale;
      u_scale.base = 0;
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_scale.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->scale = u_scale.real;
      offset += sizeof(this->scale);
      uint32_t menu_entries_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      menu_entries_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      menu_entries_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      menu_entries_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->menu_entries_length);
      if(menu_entries_lengthT > menu_entries_length)
        this->menu_entries = (tinyros::visualization_msgs::MenuEntry*)realloc(this->menu_entries, menu_entries_lengthT * sizeof(tinyros::visualization_msgs::MenuEntry));
      menu_entries_length = menu_entries_lengthT;
      for( uint32_t i = 0; i < menu_entries_length; i++) {
        offset += this->st_menu_entries.deserialize(inbuffer + offset);
        memcpy( &(this->menu_entries[i]), &(this->st_menu_entries), sizeof(tinyros::visualization_msgs::MenuEntry));
      }
      uint32_t controls_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      controls_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      controls_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      controls_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->controls_length);
      if(controls_lengthT > controls_length)
        this->controls = (tinyros::visualization_msgs::InteractiveMarkerControl*)realloc(this->controls, controls_lengthT * sizeof(tinyros::visualization_msgs::InteractiveMarkerControl));
      controls_length = controls_lengthT;
      for( uint32_t i = 0; i < controls_length; i++) {
        offset += this->st_controls.deserialize(inbuffer + offset);
        memcpy( &(this->controls[i]), &(this->st_controls), sizeof(tinyros::visualization_msgs::InteractiveMarkerControl));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->pose.serializedLength();
      uint32_t length_name = this->name.size();
      length += 4;
      length += length_name;
      uint32_t length_description = this->description.size();
      length += 4;
      length += length_description;
      length += sizeof(this->scale);
      length += sizeof(this->menu_entries_length);
      for( uint32_t i = 0; i < menu_entries_length; i++) {
        length += this->menu_entries[i].serializedLength();
      }
      length += sizeof(this->controls_length);
      for( uint32_t i = 0; i < controls_length; i++) {
        length += this->controls[i].serializedLength();
      }
      return length;
    }

    virtual tinyros::string getType(){ return "visualization_msgs/InteractiveMarker"; }
    static tinyros::string getTypeStatic(){ return "visualization_msgs/InteractiveMarker"; }
    virtual tinyros::string getMD5(){ return "9ebcf376fedf5708487702be1923ba61"; }
    static tinyros::string getMD5Static(){ return "9ebcf376fedf5708487702be1923ba61"; }
    virtual tinyros::string getDefinition(){ return "Header header\ngeometry_msgs/Pose pose\nstring name\nstring description\nfloat32 scale\nMenuEntry[] menu_entries\nInteractiveMarkerControl[] controls\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\ngeometry_msgs/Pose pose\nstring name\nstring description\nfloat32 scale\nMenuEntry[] menu_entries\nInteractiveMarkerControl[] controls\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
