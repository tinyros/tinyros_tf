#ifndef _TINYROS_shape_msgs_Mesh_h
#define _TINYROS_shape_msgs_Mesh_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/shape_msgs/MeshTriangle.h"
#include "tiny_ros/geometry_msgs/Point.h"

namespace tinyros
{
namespace shape_msgs
{

  class Mesh : public tinyros::Msg
  {
    public:
      typedef tinyros::shape_msgs::MeshTriangle _triangles_type;
      std::vector<_triangles_type> triangles;
      typedef tinyros::geometry_msgs::Point _vertices_type;
      std::vector<_vertices_type> vertices;

    Mesh():
      triangles(0),
      vertices(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t triangles_length = this->triangles.size();
      *(outbuffer + offset + 0) = (triangles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (triangles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (triangles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (triangles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(triangles_length);
      for( uint32_t i = 0; i < triangles_length; i++) {
        offset += this->triangles[i].serialize(outbuffer + offset);
      }
      uint32_t vertices_length = this->vertices.size();
      *(outbuffer + offset + 0) = (vertices_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (vertices_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (vertices_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (vertices_length >> (8 * 3)) & 0xFF;
      offset += sizeof(vertices_length);
      for( uint32_t i = 0; i < vertices_length; i++) {
        offset += this->vertices[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t triangles_length = ((uint32_t) (*(inbuffer + offset))); 
      triangles_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      triangles_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      triangles_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->triangles.resize(triangles_length); 
      offset += sizeof(triangles_length);
      for( uint32_t i = 0; i < triangles_length; i++) {
        offset += this->triangles[i].deserialize(inbuffer + offset);
      }
      uint32_t vertices_length = ((uint32_t) (*(inbuffer + offset))); 
      vertices_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vertices_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vertices_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->vertices.resize(vertices_length); 
      offset += sizeof(vertices_length);
      for( uint32_t i = 0; i < vertices_length; i++) {
        offset += this->vertices[i].deserialize(inbuffer + offset);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t triangles_length = this->triangles.size();
      length += sizeof(triangles_length);
      for( uint32_t i = 0; i < triangles_length; i++) {
        length += this->triangles[i].serializedLength();
      }
      uint32_t vertices_length = this->vertices.size();
      length += sizeof(vertices_length);
      for( uint32_t i = 0; i < vertices_length; i++) {
        length += this->vertices[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      uint32_t triangles_length = this->triangles.size();
      string_echo += "triangles:[";
      for( uint32_t i = 0; i < triangles_length; i++) {
        if( i == (triangles_length - 1)) {
          string_echo += this->triangles[i].echo();
          string_echo += "";
        } else {
          string_echo += this->triangles[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "],";
      uint32_t vertices_length = this->vertices.size();
      string_echo += "vertices:[";
      for( uint32_t i = 0; i < vertices_length; i++) {
        if( i == (vertices_length - 1)) {
          string_echo += this->vertices[i].echo();
          string_echo += "";
        } else {
          string_echo += this->vertices[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "shape_msgs/Mesh"; }
    static std::string getTypeStatic(){ return "shape_msgs/Mesh"; }
    virtual std::string getMD5(){ return "1579670b316f622b47d6700cd4f7e18d"; }
    static std::string getMD5Static(){ return "1579670b316f622b47d6700cd4f7e18d"; }
    virtual std::string getDefinition(){ return "MeshTriangle[] triangles\ngeometry_msgs/Point[] vertices\n"; }
    static std::string getDefinitionStatic(){ return "MeshTriangle[] triangles\ngeometry_msgs/Point[] vertices\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::shape_msgs::Mesh> Ptr;
    typedef std::shared_ptr<tinyros::shape_msgs::Mesh const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::shape_msgs::Mesh> MeshPtr;
typedef std::shared_ptr<tinyros::shape_msgs::Mesh const> MeshConstPtr;

}
}
#endif
