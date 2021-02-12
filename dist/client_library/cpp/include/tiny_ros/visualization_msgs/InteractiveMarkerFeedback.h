#ifndef _TINYROS_visualization_msgs_InteractiveMarkerFeedback_h
#define _TINYROS_visualization_msgs_InteractiveMarkerFeedback_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Pose.h"
#include "tiny_ros/geometry_msgs/Point.h"

namespace tinyros
{
namespace visualization_msgs
{

  class InteractiveMarkerFeedback : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef std::string _client_id_type;
      _client_id_type client_id;
      typedef std::string _marker_name_type;
      _marker_name_type marker_name;
      typedef std::string _control_name_type;
      _control_name_type control_name;
      typedef uint8_t _event_type_type;
      _event_type_type event_type;
      typedef tinyros::geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef uint32_t _menu_entry_id_type;
      _menu_entry_id_type menu_entry_id;
      typedef tinyros::geometry_msgs::Point _mouse_point_type;
      _mouse_point_type mouse_point;
      typedef bool _mouse_point_valid_type;
      _mouse_point_valid_type mouse_point_valid;
      enum { KEEP_ALIVE =  0 };
      enum { POSE_UPDATE =  1 };
      enum { MENU_SELECT =  2 };
      enum { BUTTON_CLICK =  3 };
      enum { MOUSE_DOWN =  4 };
      enum { MOUSE_UP =  5 };

    InteractiveMarkerFeedback():
      header(),
      client_id(""),
      marker_name(""),
      control_name(""),
      event_type(0),
      pose(),
      menu_entry_id(0),
      mouse_point(),
      mouse_point_valid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_client_id = this->client_id.size();
      varToArr(outbuffer + offset, length_client_id);
      offset += 4;
      memcpy(outbuffer + offset, this->client_id.c_str(), length_client_id);
      offset += length_client_id;
      uint32_t length_marker_name = this->marker_name.size();
      varToArr(outbuffer + offset, length_marker_name);
      offset += 4;
      memcpy(outbuffer + offset, this->marker_name.c_str(), length_marker_name);
      offset += length_marker_name;
      uint32_t length_control_name = this->control_name.size();
      varToArr(outbuffer + offset, length_control_name);
      offset += 4;
      memcpy(outbuffer + offset, this->control_name.c_str(), length_control_name);
      offset += length_control_name;
      *(outbuffer + offset + 0) = (this->event_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->event_type);
      offset += this->pose.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->menu_entry_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->menu_entry_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->menu_entry_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->menu_entry_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->menu_entry_id);
      offset += this->mouse_point.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_mouse_point_valid;
      u_mouse_point_valid.real = this->mouse_point_valid;
      *(outbuffer + offset + 0) = (u_mouse_point_valid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mouse_point_valid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_client_id;
      arrToVar(length_client_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_client_id; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_client_id-1]=0;
      this->client_id = (char *)(inbuffer + offset-1);
      offset += length_client_id;
      uint32_t length_marker_name;
      arrToVar(length_marker_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_marker_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_marker_name-1]=0;
      this->marker_name = (char *)(inbuffer + offset-1);
      offset += length_marker_name;
      uint32_t length_control_name;
      arrToVar(length_control_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_control_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_control_name-1]=0;
      this->control_name = (char *)(inbuffer + offset-1);
      offset += length_control_name;
      this->event_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->event_type);
      offset += this->pose.deserialize(inbuffer + offset);
      this->menu_entry_id =  ((uint32_t) (*(inbuffer + offset)));
      this->menu_entry_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->menu_entry_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->menu_entry_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->menu_entry_id);
      offset += this->mouse_point.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_mouse_point_valid;
      u_mouse_point_valid.base = 0;
      u_mouse_point_valid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mouse_point_valid = u_mouse_point_valid.real;
      offset += sizeof(this->mouse_point_valid);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      uint32_t length_client_id = this->client_id.size();
      length += 4;
      length += length_client_id;
      uint32_t length_marker_name = this->marker_name.size();
      length += 4;
      length += length_marker_name;
      uint32_t length_control_name = this->control_name.size();
      length += 4;
      length += length_control_name;
      length += sizeof(this->event_type);
      length += this->pose.serializedLength();
      length += sizeof(this->menu_entry_id);
      length += this->mouse_point.serializedLength();
      length += sizeof(this->mouse_point_valid);
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      std::size_t client_id_pos = client_id.find("\"");
      while(client_id_pos != std::string::npos){
        client_id.replace(client_id_pos, 1,"\\\"");
        client_id_pos = client_id.find("\"", client_id_pos+2);
      }
      string_echo += "\"client_id\":\"";
      string_echo += client_id;
      string_echo += "\",";
      std::size_t marker_name_pos = marker_name.find("\"");
      while(marker_name_pos != std::string::npos){
        marker_name.replace(marker_name_pos, 1,"\\\"");
        marker_name_pos = marker_name.find("\"", marker_name_pos+2);
      }
      string_echo += "\"marker_name\":\"";
      string_echo += marker_name;
      string_echo += "\",";
      std::size_t control_name_pos = control_name.find("\"");
      while(control_name_pos != std::string::npos){
        control_name.replace(control_name_pos, 1,"\\\"");
        control_name_pos = control_name.find("\"", control_name_pos+2);
      }
      string_echo += "\"control_name\":\"";
      string_echo += control_name;
      string_echo += "\",";
      std::stringstream ss_event_type; ss_event_type << "\"event_type\":" << (uint16_t)event_type <<",";
      string_echo += ss_event_type.str();
      string_echo += "\"pose\":";
      string_echo += this->pose.echo();
      string_echo += ",";
      std::stringstream ss_menu_entry_id; ss_menu_entry_id << "\"menu_entry_id\":" << menu_entry_id <<",";
      string_echo += ss_menu_entry_id.str();
      string_echo += "\"mouse_point\":";
      string_echo += this->mouse_point.echo();
      string_echo += ",";
      std::stringstream ss_mouse_point_valid; ss_mouse_point_valid << "\"mouse_point_valid\":" << mouse_point_valid <<"";
      string_echo += ss_mouse_point_valid.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "visualization_msgs/InteractiveMarkerFeedback"; }
    static std::string getTypeStatic(){ return "visualization_msgs/InteractiveMarkerFeedback"; }
    virtual std::string getMD5(){ return "2b2c717ae73a04857e91f4992896e58f"; }
    static std::string getMD5Static(){ return "2b2c717ae73a04857e91f4992896e58f"; }
    virtual std::string getDefinition(){ return "Header header\nstring client_id\nstring marker_name\nstring control_name\nuint8 event_type\ngeometry_msgs/Pose pose\nuint32 menu_entry_id\ngeometry_msgs/Point mouse_point\nbool mouse_point_valid\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nstring client_id\nstring marker_name\nstring control_name\nuint8 event_type\ngeometry_msgs/Pose pose\nuint32 menu_entry_id\ngeometry_msgs/Point mouse_point\nbool mouse_point_valid\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::visualization_msgs::InteractiveMarkerFeedback> Ptr;
    typedef std::shared_ptr<tinyros::visualization_msgs::InteractiveMarkerFeedback const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::visualization_msgs::InteractiveMarkerFeedback> InteractiveMarkerFeedbackPtr;
typedef std::shared_ptr<tinyros::visualization_msgs::InteractiveMarkerFeedback const> InteractiveMarkerFeedbackConstPtr;

}
}
#endif
