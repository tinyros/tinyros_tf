#ifndef _TINYROS_visualization_msgs_Marker_h
#define _TINYROS_visualization_msgs_Marker_h

#include <stdint.h>
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
      typedef tinyros::string _ns_type;
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
      uint32_t points_length;
      typedef tinyros::geometry_msgs::Point _points_type;
      _points_type st_points;
      _points_type * points;
      uint32_t colors_length;
      typedef tinyros::std_msgs::ColorRGBA _colors_type;
      _colors_type st_colors;
      _colors_type * colors;
      typedef tinyros::string _text_type;
      _text_type text;
      typedef tinyros::string _mesh_resource_type;
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
      points_length(0), points(NULL),
      colors_length(0), colors(NULL),
      text(""),
      mesh_resource(""),
      mesh_use_embedded_materials(0)
    {
    }

    ~Marker()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(points != NULL)
      {
        for( uint32_t i = 0; i < points_length; i++){
          points[i].deconstructor();
        }
        free(points);
      }
      points = NULL;
      points_length = 0;
      if(colors != NULL)
      {
        for( uint32_t i = 0; i < colors_length; i++){
          colors[i].deconstructor();
        }
        free(colors);
      }
      colors = NULL;
      colors_length = 0;
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
      *(outbuffer + offset + 0) = (this->points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        offset += this->points[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->colors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->colors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->colors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->colors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->colors_length);
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
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (tinyros::geometry_msgs::Point*)realloc(this->points, points_lengthT * sizeof(tinyros::geometry_msgs::Point));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++) {
        offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(tinyros::geometry_msgs::Point));
      }
      uint32_t colors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->colors_length);
      if(colors_lengthT > colors_length)
        this->colors = (tinyros::std_msgs::ColorRGBA*)realloc(this->colors, colors_lengthT * sizeof(tinyros::std_msgs::ColorRGBA));
      colors_length = colors_lengthT;
      for( uint32_t i = 0; i < colors_length; i++) {
        offset += this->st_colors.deserialize(inbuffer + offset);
        memcpy( &(this->colors[i]), &(this->st_colors), sizeof(tinyros::std_msgs::ColorRGBA));
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
      length += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        length += this->points[i].serializedLength();
      }
      length += sizeof(this->colors_length);
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

    virtual tinyros::string getType(){ return "visualization_msgs/Marker"; }
    static tinyros::string getTypeStatic(){ return "visualization_msgs/Marker"; }
    virtual tinyros::string getMD5(){ return "666484e5c1e264d98a42c3b7c44c0ac3"; }
    static tinyros::string getMD5Static(){ return "666484e5c1e264d98a42c3b7c44c0ac3"; }
    virtual tinyros::string getDefinition(){ return "Header header                        \nstring ns                            \nint32 id                            \nint32 type                          \nint32 action                         \ngeometry_msgs/Pose pose                 \ngeometry_msgs/Vector3 scale             \nstd_msgs/ColorRGBA color             \nduration lifetime                    \nbool frame_locked                    \ngeometry_msgs/Point[] points\nstd_msgs/ColorRGBA[] colors\nstring text\nstring mesh_resource\nbool mesh_use_embedded_materials\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header                        \nstring ns                            \nint32 id                            \nint32 type                          \nint32 action                         \ngeometry_msgs/Pose pose                 \ngeometry_msgs/Vector3 scale             \nstd_msgs/ColorRGBA color             \nduration lifetime                    \nbool frame_locked                    \ngeometry_msgs/Point[] points\nstd_msgs/ColorRGBA[] colors\nstring text\nstring mesh_resource\nbool mesh_use_embedded_materials\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
