#ifndef _TINYROS_visualization_msgs_InteractiveMarkerControl_h
#define _TINYROS_visualization_msgs_InteractiveMarkerControl_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/geometry_msgs/Quaternion.h"
#include "tiny_ros/visualization_msgs/Marker.h"

namespace tinyros
{
namespace visualization_msgs
{

  class InteractiveMarkerControl : public tinyros::Msg
  {
    public:
      typedef std::string _name_type;
      _name_type name;
      typedef tinyros::geometry_msgs::Quaternion _orientation_type;
      _orientation_type orientation;
      typedef uint8_t _orientation_mode_type;
      _orientation_mode_type orientation_mode;
      typedef uint8_t _interaction_mode_type;
      _interaction_mode_type interaction_mode;
      typedef bool _always_visible_type;
      _always_visible_type always_visible;
      uint32_t markers_length;
      typedef tinyros::visualization_msgs::Marker _markers_type;
      _markers_type st_markers;
      _markers_type * markers;
      typedef bool _independent_marker_orientation_type;
      _independent_marker_orientation_type independent_marker_orientation;
      typedef std::string _description_type;
      _description_type description;
      enum { INHERIT =  0 };
      enum { FIXED =  1 };
      enum { VIEW_FACING =  2 };
      enum { NONE =  0 };
      enum { MENU =  1 };
      enum { BUTTON =  2 };
      enum { MOVE_AXIS =  3 };
      enum { MOVE_PLANE =  4 };
      enum { ROTATE_AXIS =  5 };
      enum { MOVE_ROTATE =  6 };
      enum { MOVE_3D =  7 };
      enum { ROTATE_3D =  8 };
      enum { MOVE_ROTATE_3D =  9 };

    InteractiveMarkerControl():
      name(""),
      orientation(),
      orientation_mode(0),
      interaction_mode(0),
      always_visible(0),
      markers_length(0), markers(NULL),
      independent_marker_orientation(0),
      description("")
    {
    }

    ~InteractiveMarkerControl()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(this->markers != NULL)
      {
        for( uint32_t i = 0; i < this->markers_length; i++){
          this->markers[i].deconstructor();
        }
        delete[] this->markers;
      }
      this->markers = NULL;
      this->markers_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = this->name.size();
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name.c_str(), length_name);
      offset += length_name;
      offset += this->orientation.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->orientation_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->orientation_mode);
      *(outbuffer + offset + 0) = (this->interaction_mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->interaction_mode);
      union {
        bool real;
        uint8_t base;
      } u_always_visible;
      u_always_visible.real = this->always_visible;
      *(outbuffer + offset + 0) = (u_always_visible.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->always_visible);
      *(outbuffer + offset + 0) = (this->markers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->markers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->markers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->markers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->markers_length);
      for( uint32_t i = 0; i < markers_length; i++) {
        offset += this->markers[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_independent_marker_orientation;
      u_independent_marker_orientation.real = this->independent_marker_orientation;
      *(outbuffer + offset + 0) = (u_independent_marker_orientation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->independent_marker_orientation);
      uint32_t length_description = this->description.size();
      varToArr(outbuffer + offset, length_description);
      offset += 4;
      memcpy(outbuffer + offset, this->description.c_str(), length_description);
      offset += length_description;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += this->orientation.deserialize(inbuffer + offset);
      this->orientation_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->orientation_mode);
      this->interaction_mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->interaction_mode);
      union {
        bool real;
        uint8_t base;
      } u_always_visible;
      u_always_visible.base = 0;
      u_always_visible.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->always_visible = u_always_visible.real;
      offset += sizeof(this->always_visible);
      uint32_t markers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->markers_length);
      if(!this->markers || markers_lengthT > this->markers_length) {
        this->deconstructor();
        this->markers = new tinyros::visualization_msgs::Marker[markers_lengthT];
      }
      this->markers_length = markers_lengthT;
      for( uint32_t i = 0; i < markers_length; i++) {
        offset += this->st_markers.deserialize(inbuffer + offset);
        this->markers[i] = this->st_markers;
      }
      union {
        bool real;
        uint8_t base;
      } u_independent_marker_orientation;
      u_independent_marker_orientation.base = 0;
      u_independent_marker_orientation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->independent_marker_orientation = u_independent_marker_orientation.real;
      offset += sizeof(this->independent_marker_orientation);
      uint32_t length_description;
      arrToVar(length_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_name = this->name.size();
      length += 4;
      length += length_name;
      length += this->orientation.serializedLength();
      length += sizeof(this->orientation_mode);
      length += sizeof(this->interaction_mode);
      length += sizeof(this->always_visible);
      length += sizeof(this->markers_length);
      for( uint32_t i = 0; i < markers_length; i++) {
        length += this->markers[i].serializedLength();
      }
      length += sizeof(this->independent_marker_orientation);
      uint32_t length_description = this->description.size();
      length += 4;
      length += length_description;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::size_t name_pos = name.find("\"");
      while(name_pos != std::string::npos){
        name.replace(name_pos, 1,"\\\"");
        name_pos = name.find("\"", name_pos+2);
      }
      string_echo += "\"name\":\"";
      string_echo += name;
      string_echo += "\",";
      string_echo += "\"orientation\":";
      string_echo += this->orientation.echo();
      string_echo += ",";
      std::stringstream ss_orientation_mode; ss_orientation_mode << "\"orientation_mode\":" << (uint16_t)orientation_mode <<",";
      string_echo += ss_orientation_mode.str();
      std::stringstream ss_interaction_mode; ss_interaction_mode << "\"interaction_mode\":" << (uint16_t)interaction_mode <<",";
      string_echo += ss_interaction_mode.str();
      std::stringstream ss_always_visible; ss_always_visible << "\"always_visible\":" << always_visible <<",";
      string_echo += ss_always_visible.str();
      string_echo += "markers:[";
      for( uint32_t i = 0; i < markers_length; i++) {
        if( i == (markers_length - 1)) {
          string_echo += this->markers[i].echo();
          string_echo += "";
        } else {
          string_echo += this->markers[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "],";
      std::stringstream ss_independent_marker_orientation; ss_independent_marker_orientation << "\"independent_marker_orientation\":" << independent_marker_orientation <<",";
      string_echo += ss_independent_marker_orientation.str();
      std::size_t description_pos = description.find("\"");
      while(description_pos != std::string::npos){
        description.replace(description_pos, 1,"\\\"");
        description_pos = description.find("\"", description_pos+2);
      }
      string_echo += "\"description\":\"";
      string_echo += description;
      string_echo += "\"";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "visualization_msgs/InteractiveMarkerControl"; }
    static std::string getTypeStatic(){ return "visualization_msgs/InteractiveMarkerControl"; }
    virtual std::string getMD5(){ return "22b3d411f6992b5b98c859d9077512ba"; }
    static std::string getMD5Static(){ return "22b3d411f6992b5b98c859d9077512ba"; }
    virtual std::string getDefinition(){ return "string name\ngeometry_msgs/Quaternion orientation\nuint8 orientation_mode\nuint8 interaction_mode\nbool always_visible\nMarker[] markers\nbool independent_marker_orientation\nstring description\n"; }
    static std::string getDefinitionStatic(){ return "string name\ngeometry_msgs/Quaternion orientation\nuint8 orientation_mode\nuint8 interaction_mode\nbool always_visible\nMarker[] markers\nbool independent_marker_orientation\nstring description\n"; }
    static bool hasHeader(){ return false; }
  };

typedef std::shared_ptr<tinyros::visualization_msgs::InteractiveMarkerControl> InteractiveMarkerControlPtr;
typedef std::shared_ptr<tinyros::visualization_msgs::InteractiveMarkerControl const> InteractiveMarkerControlConstPtr;

}
}
#endif
