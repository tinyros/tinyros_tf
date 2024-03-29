#ifndef _TINYROS_shape_msgs_MeshTriangle_h
#define _TINYROS_shape_msgs_MeshTriangle_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace shape_msgs
{

  class MeshTriangle : public tinyros::Msg
  {
    public:
      typedef uint32_t _vertex_indices_type;
      std::vector<_vertex_indices_type> vertex_indices;

    MeshTriangle():
      vertex_indices(3)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++) {
        *(outbuffer + offset + 0) = (this->vertex_indices[i] >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (this->vertex_indices[i] >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (this->vertex_indices[i] >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (this->vertex_indices[i] >> (8 * 3)) & 0xFF;
        offset += sizeof(this->vertex_indices[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
        this->vertex_indices[i] =  ((uint32_t) (*(inbuffer + offset)));
        this->vertex_indices[i] |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
        this->vertex_indices[i] |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
        this->vertex_indices[i] |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
        offset += sizeof(this->vertex_indices[i]);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      for( uint32_t i = 0; i < 3; i++) {
        length += sizeof(this->vertex_indices[i]);
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "vertex_indices:[";
      for( uint32_t i = 0; i < 3; i++) {
        if( i == (3 - 1)) {
          std::stringstream ss_vertex_indicesi; ss_vertex_indicesi << vertex_indices[i] <<"";
          string_echo += ss_vertex_indicesi.str();
        } else {
          std::stringstream ss_vertex_indicesi; ss_vertex_indicesi << vertex_indices[i] <<",";
          string_echo += ss_vertex_indicesi.str();
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "shape_msgs/MeshTriangle"; }
    static std::string getTypeStatic(){ return "shape_msgs/MeshTriangle"; }
    virtual std::string getMD5(){ return "01020cfeb9ad7679dd18bbd7149962ba"; }
    static std::string getMD5Static(){ return "01020cfeb9ad7679dd18bbd7149962ba"; }
    virtual std::string getDefinition(){ return "uint32[3] vertex_indices\n"; }
    static std::string getDefinitionStatic(){ return "uint32[3] vertex_indices\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::shape_msgs::MeshTriangle> Ptr;
    typedef std::shared_ptr<tinyros::shape_msgs::MeshTriangle const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::shape_msgs::MeshTriangle> MeshTrianglePtr;
typedef std::shared_ptr<tinyros::shape_msgs::MeshTriangle const> MeshTriangleConstPtr;

}
}
#endif
