#ifndef _TINYROS_visualization_msgs_Marker_h
#define _TINYROS_visualization_msgs_Marker_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Pose.h"
#include "tiny_ros/geometry_msgs/Vector3.h"
#include "tiny_ros/std_msgs/ColorRGBA.h"
#include "tiny_ros/ros/duration.h"
#include "tiny_ros/geometry_msgs/Point.h"

namespace tinyros
{
namespace visualization_msgs
{

  class Marker : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef std::string _ns_type;
      _ns_type ns;
      typedef int32_t _id_type;
      _id_type id;
      typedef int32_t _type_type;
      _type_type type;
      typedef int32_t _action_type;
      _action_type action;
      typedef tinyros::geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef tinyros::geometry_msgs::Vector3 _scale_type;
      _scale_type scale;
      typedef tinyros::std_msgs::ColorRGBA _color_type;
      _color_type color;
      typedef tinyros::Duration _lifetime_type;
      _lifetime_type lifetime;
      typedef bool _frame_locked_type;
      _frame_locked_type frame_locked;
      typedef tinyros::geometry_msgs::Point _points_type;
      std::vector<_points_type> points;
      typedef tinyros::std_msgs::ColorRGBA _colors_type;
      std::vector<_colors_type> colors;
      typedef std::string _text_type;
      _text_type text;
      typedef std::string _mesh_resource_type;
      _mesh_resource_type mesh_resource;
      typedef bool _mesh_use_embedded_materials_type;
      _mesh_use_embedded_materials_type mesh_use_embedded_materials;
      enum { ARROW = 0 };
      enum { CUBE = 1 };
      enum { SPHERE = 2 };
      enum { CYLINDER = 3 };
      enum { LINE_STRIP = 4 };
      enum { LINE_LIST = 5 };
      enum { CUBE_LIST = 6 };
      enum { SPHERE_LIST = 7 };
      enum { POINTS = 8 };
      enum { TEXT_VIEW_FACING = 9 };
      enum { MESH_RESOURCE = 10 };
      enum { TRIANGLE_LIST = 11 };
      enum { ADD = 0 };
      enum { MODIFY = 0 };
      enum { DELETE = 2 };

    Marker():
      header(),
      ns(""),
      id(0),
      type(0),
      action(0),
      pose(),
      scale(),
      color(),
      lifetime(),
      frame_locked(0),
      points(0),
      colors(0),
      text(""),
      mesh_resource(""),
      mesh_use_embedded_materials(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_ns = this->ns.size();
      varToArr(outbuffer + offset, length_ns);
      offset += 4;
      memcpy(outbuffer + offset, this->ns.c_str(), length_ns);
      offset += length_ns;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_action;
      u_action.real = this->action;
      *(outbuffer + offset + 0) = (u_action.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_action.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_action.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_action.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->action);
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->scale.serialize(outbuffer + offset);
      offset += this->color.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->lifetime.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lifetime.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lifetime.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lifetime.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lifetime.sec);
      *(outbuffer + offset + 0) = (this->lifetime.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->lifetime.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->lifetime.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->lifetime.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->lifetime.nsec);
      union {
        bool real;
        uint8_t base;
      } u_frame_locked;
      u_frame_locked.real = this->frame_locked;
      *(outbuffer + offset + 0) = (u_frame_locked.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->frame_locked);
      uint32_t points_length = this->points.size();
      *(outbuffer + offset + 0) = (points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        offset += this->points[i].serialize(outbuffer + offset);
      }
      uint32_t colors_length = this->colors.size();
      *(outbuffer + offset + 0) = (colors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (colors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (colors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (colors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(colors_length);
      for( uint32_t i = 0; i < colors_length; i++) {
        offset += this->colors[i].serialize(outbuffer + offset);
      }
      uint32_t length_text = this->text.size();
      varToArr(outbuffer + offset, length_text);
      offset += 4;
      memcpy(outbuffer + offset, this->text.c_str(), length_text);
      offset += length_text;
      uint32_t length_mesh_resource = this->mesh_resource.size();
      varToArr(outbuffer + offset, length_mesh_resource);
      offset += 4;
      memcpy(outbuffer + offset, this->mesh_resource.c_str(), length_mesh_resource);
      offset += length_mesh_resource;
      union {
        bool real;
        uint8_t base;
      } u_mesh_use_embedded_materials;
      u_mesh_use_embedded_materials.real = this->mesh_use_embedded_materials;
      *(outbuffer + offset + 0) = (u_mesh_use_embedded_materials.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mesh_use_embedded_materials);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_ns;
      arrToVar(length_ns, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_ns; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_ns-1]=0;
      this->ns = (char *)(inbuffer + offset-1);
      offset += length_ns;
      union {
        int32_t real;
        uint32_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id = u_id.real;
      offset += sizeof(this->id);
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->type = u_type.real;
      offset += sizeof(this->type);
      union {
        int32_t real;
        uint32_t base;
      } u_action;
      u_action.base = 0;
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_action.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->action = u_action.real;
      offset += sizeof(this->action);
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->scale.deserialize(inbuffer + offset);
      offset += this->color.deserialize(inbuffer + offset);
      this->lifetime.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->lifetime.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lifetime.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->lifetime.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->lifetime.sec);
      this->lifetime.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->lifetime.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->lifetime.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->lifetime.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->lifetime.nsec);
      union {
        bool real;
        uint8_t base;
      } u_frame_locked;
      u_frame_locked.base = 0;
      u_frame_locked.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->frame_locked = u_frame_locked.real;
      offset += sizeof(this->frame_locked);
      uint32_t points_length = ((uint32_t) (*(inbuffer + offset))); 
      points_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->points.resize(points_length); 
      offset += sizeof(points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        offset += this->points[i].deserialize(inbuffer + offset);
      }
      uint32_t colors_length = ((uint32_t) (*(inbuffer + offset))); 
      colors_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      colors_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      colors_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->colors.resize(colors_length); 
      offset += sizeof(colors_length);
      for( uint32_t i = 0; i < colors_length; i++) {
        offset += this->colors[i].deserialize(inbuffer + offset);
      }
      uint32_t length_text;
      arrToVar(length_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
      uint32_t length_mesh_resource;
      arrToVar(length_mesh_resource, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mesh_resource; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mesh_resource-1]=0;
      this->mesh_resource = (char *)(inbuffer + offset-1);
      offset += length_mesh_resource;
      union {
        bool real;
        uint8_t base;
      } u_mesh_use_embedded_materials;
      u_mesh_use_embedded_materials.base = 0;
      u_mesh_use_embedded_materials.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mesh_use_embedded_materials = u_mesh_use_embedded_materials.real;
      offset += sizeof(this->mesh_use_embedded_materials);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      uint32_t length_ns = this->ns.size();
      length += 4;
      length += length_ns;
      length += sizeof(this->id);
      length += sizeof(this->type);
      length += sizeof(this->action);
      length += this->pose.serializedLength();
      length += this->scale.serializedLength();
      length += this->color.serializedLength();
      length += sizeof(this->lifetime.sec);
      length += sizeof(this->lifetime.nsec);
      length += sizeof(this->frame_locked);
      uint32_t points_length = this->points.size();
      length += sizeof(points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        length += this->points[i].serializedLength();
      }
      uint32_t colors_length = this->colors.size();
      length += sizeof(colors_length);
      for( uint32_t i = 0; i < colors_length; i++) {
        length += this->colors[i].serializedLength();
      }
      uint32_t length_text = this->text.size();
      length += 4;
      length += length_text;
      uint32_t length_mesh_resource = this->mesh_resource.size();
      length += 4;
      length += length_mesh_resource;
      length += sizeof(this->mesh_use_embedded_materials);
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      std::size_t ns_pos = ns.find("\"");
      while(ns_pos != std::string::npos){
        ns.replace(ns_pos, 1,"\\\"");
        ns_pos = ns.find("\"", ns_pos+2);
      }
      string_echo += "\"ns\":\"";
      string_echo += ns;
      string_echo += "\",";
      std::stringstream ss_id; ss_id << "\"id\":" << id <<",";
      string_echo += ss_id.str();
      std::stringstream ss_type; ss_type << "\"type\":" << type <<",";
      string_echo += ss_type.str();
      std::stringstream ss_action; ss_action << "\"action\":" << action <<",";
      string_echo += ss_action.str();
      string_echo += "\"pose\":";
      string_echo += this->pose.echo();
      string_echo += ",";
      string_echo += "\"scale\":";
      string_echo += this->scale.echo();
      string_echo += ",";
      string_echo += "\"color\":";
      string_echo += this->color.echo();
      string_echo += ",";
      std::stringstream ss_lifetime;
      ss_lifetime << "\"lifetime\":{\"sec\":" << lifetime.sec;
      ss_lifetime << ",\"nsec\":" << lifetime.nsec << "},";
      string_echo += ss_lifetime.str();
      std::stringstream ss_frame_locked; ss_frame_locked << "\"frame_locked\":" << frame_locked <<",";
      string_echo += ss_frame_locked.str();
      uint32_t points_length = this->points.size();
      string_echo += "points:[";
      for( uint32_t i = 0; i < points_length; i++) {
        if( i == (points_length - 1)) {
          string_echo += this->points[i].echo();
          string_echo += "";
        } else {
          string_echo += this->points[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "],";
      uint32_t colors_length = this->colors.size();
      string_echo += "colors:[";
      for( uint32_t i = 0; i < colors_length; i++) {
        if( i == (colors_length - 1)) {
          string_echo += this->colors[i].echo();
          string_echo += "";
        } else {
          string_echo += this->colors[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "],";
      std::size_t text_pos = text.find("\"");
      while(text_pos != std::string::npos){
        text.replace(text_pos, 1,"\\\"");
        text_pos = text.find("\"", text_pos+2);
      }
      string_echo += "\"text\":\"";
      string_echo += text;
      string_echo += "\",";
      std::size_t mesh_resource_pos = mesh_resource.find("\"");
      while(mesh_resource_pos != std::string::npos){
        mesh_resource.replace(mesh_resource_pos, 1,"\\\"");
        mesh_resource_pos = mesh_resource.find("\"", mesh_resource_pos+2);
      }
      string_echo += "\"mesh_resource\":\"";
      string_echo += mesh_resource;
      string_echo += "\",";
      std::stringstream ss_mesh_use_embedded_materials; ss_mesh_use_embedded_materials << "\"mesh_use_embedded_materials\":" << mesh_use_embedded_materials <<"";
      string_echo += ss_mesh_use_embedded_materials.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "visualization_msgs/Marker"; }
    static std::string getTypeStatic(){ return "visualization_msgs/Marker"; }
    virtual std::string getMD5(){ return "666484e5c1e264d98a42c3b7c44c0ac3"; }
    static std::string getMD5Static(){ return "666484e5c1e264d98a42c3b7c44c0ac3"; }
    virtual std::string getDefinition(){ return "Header header\nstring ns\nint32 id\nint32 type\nint32 action\ngeometry_msgs/Pose pose\ngeometry_msgs/Vector3 scale\nstd_msgs/ColorRGBA color\nduration lifetime\nbool frame_locked\ngeometry_msgs/Point[] points\nstd_msgs/ColorRGBA[] colors\nstring text\nstring mesh_resource\nbool mesh_use_embedded_materials\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nstring ns\nint32 id\nint32 type\nint32 action\ngeometry_msgs/Pose pose\ngeometry_msgs/Vector3 scale\nstd_msgs/ColorRGBA color\nduration lifetime\nbool frame_locked\ngeometry_msgs/Point[] points\nstd_msgs/ColorRGBA[] colors\nstring text\nstring mesh_resource\nbool mesh_use_embedded_materials\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::visualization_msgs::Marker> Ptr;
    typedef std::shared_ptr<tinyros::visualization_msgs::Marker const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::visualization_msgs::Marker> MarkerPtr;
typedef std::shared_ptr<tinyros::visualization_msgs::Marker const> MarkerConstPtr;

}
}
#endif
