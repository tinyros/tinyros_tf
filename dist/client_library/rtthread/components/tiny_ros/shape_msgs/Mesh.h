#ifndef _TINYROS_shape_msgs_Mesh_h
#define _TINYROS_shape_msgs_Mesh_h

#include <stdint.h>
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
      uint32_t triangles_length;
      typedef tinyros::shape_msgs::MeshTriangle _triangles_type;
      _triangles_type st_triangles;
      _triangles_type * triangles;
      uint32_t vertices_length;
      typedef tinyros::geometry_msgs::Point _vertices_type;
      _vertices_type st_vertices;
      _vertices_type * vertices;

    Mesh():
      triangles_length(0), triangles(NULL),
      vertices_length(0), vertices(NULL)
    {
    }

    ~Mesh()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(triangles != NULL)
      {
        for( uint32_t i = 0; i < triangles_length; i++){
          triangles[i].deconstructor();
        }
        free(triangles);
      }
      triangles = NULL;
      triangles_length = 0;
      if(vertices != NULL)
      {
        for( uint32_t i = 0; i < vertices_length; i++){
          vertices[i].deconstructor();
        }
        free(vertices);
      }
      vertices = NULL;
      vertices_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->triangles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->triangles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->triangles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->triangles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->triangles_length);
      for( uint32_t i = 0; i < triangles_length; i++) {
        offset += this->triangles[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->vertices_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vertices_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vertices_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vertices_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vertices_length);
      for( uint32_t i = 0; i < vertices_length; i++) {
        offset += this->vertices[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t triangles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      triangles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      triangles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      triangles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->triangles_length);
      if(triangles_lengthT > triangles_length)
        this->triangles = (tinyros::shape_msgs::MeshTriangle*)realloc(this->triangles, triangles_lengthT * sizeof(tinyros::shape_msgs::MeshTriangle));
      triangles_length = triangles_lengthT;
      for( uint32_t i = 0; i < triangles_length; i++) {
        offset += this->st_triangles.deserialize(inbuffer + offset);
        memcpy( &(this->triangles[i]), &(this->st_triangles), sizeof(tinyros::shape_msgs::MeshTriangle));
      }
      uint32_t vertices_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vertices_length);
      if(vertices_lengthT > vertices_length)
        this->vertices = (tinyros::geometry_msgs::Point*)realloc(this->vertices, vertices_lengthT * sizeof(tinyros::geometry_msgs::Point));
      vertices_length = vertices_lengthT;
      for( uint32_t i = 0; i < vertices_length; i++) {
        offset += this->st_vertices.deserialize(inbuffer + offset);
        memcpy( &(this->vertices[i]), &(this->st_vertices), sizeof(tinyros::geometry_msgs::Point));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->triangles_length);
      for( uint32_t i = 0; i < triangles_length; i++) {
        length += this->triangles[i].serializedLength();
      }
      length += sizeof(this->vertices_length);
      for( uint32_t i = 0; i < vertices_length; i++) {
        length += this->vertices[i].serializedLength();
      }
      return length;
    }

    virtual tinyros::string getType(){ return "shape_msgs/Mesh"; }
    static tinyros::string getTypeStatic(){ return "shape_msgs/Mesh"; }
    virtual tinyros::string getMD5(){ return "1579670b316f622b47d6700cd4f7e18d"; }
    static tinyros::string getMD5Static(){ return "1579670b316f622b47d6700cd4f7e18d"; }
    virtual tinyros::string getDefinition(){ return "MeshTriangle[] triangles\ngeometry_msgs/Point[] vertices\n"; }
    static tinyros::string getDefinitionStatic(){ return "MeshTriangle[] triangles\ngeometry_msgs/Point[] vertices\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
