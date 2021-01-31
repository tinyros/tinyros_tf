#ifndef _TINYROS_shape_msgs_SolidPrimitive_h
#define _TINYROS_shape_msgs_SolidPrimitive_h

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

  class SolidPrimitive : public tinyros::Msg
  {
    public:
      typedef uint8_t _type_type;
      _type_type type;
      typedef double _dimensions_type;
      std::vector<_dimensions_type> dimensions;
      enum { BOX = 1 };
      enum { SPHERE = 2 };
      enum { CYLINDER = 3 };
      enum { CONE = 4 };
      enum { BOX_X = 0 };
      enum { BOX_Y = 1 };
      enum { BOX_Z = 2 };
      enum { SPHERE_RADIUS = 0 };
      enum { CYLINDER_HEIGHT = 0 };
      enum { CYLINDER_RADIUS = 1 };
      enum { CONE_HEIGHT = 0 };
      enum { CONE_RADIUS = 1 };

    SolidPrimitive():
      type(0),
      dimensions(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t dimensions_length = this->dimensions.size();
      *(outbuffer + offset + 0) = (dimensions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (dimensions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (dimensions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (dimensions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(dimensions_length);
      for( uint32_t i = 0; i < dimensions_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_dimensionsi;
        u_dimensionsi.real = this->dimensions[i];
        *(outbuffer + offset + 0) = (u_dimensionsi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_dimensionsi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_dimensionsi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_dimensionsi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_dimensionsi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_dimensionsi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_dimensionsi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_dimensionsi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->dimensions[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      uint32_t dimensions_length = ((uint32_t) (*(inbuffer + offset))); 
      dimensions_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      dimensions_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      dimensions_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->dimensions.resize(dimensions_length); 
      offset += sizeof(dimensions_length);
      for( uint32_t i = 0; i < dimensions_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_dimensionsi;
        u_dimensionsi.base = 0;
        u_dimensionsi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_dimensionsi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_dimensionsi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_dimensionsi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_dimensionsi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_dimensionsi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_dimensionsi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_dimensionsi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->dimensions[i] = u_dimensionsi.real;
        offset += sizeof(this->dimensions[i]);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->type);
      uint32_t dimensions_length = this->dimensions.size();
      length += sizeof(dimensions_length);
      for( uint32_t i = 0; i < dimensions_length; i++) {
        length += sizeof(this->dimensions[i]);
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::stringstream ss_type; ss_type << "\"type\":" << (uint16_t)type <<",";
      string_echo += ss_type.str();
      uint32_t dimensions_length = this->dimensions.size();
      string_echo += "dimensions:[";
      for( uint32_t i = 0; i < dimensions_length; i++) {
        if( i == (dimensions_length - 1)) {
          std::stringstream ss_dimensionsi; ss_dimensionsi << dimensions[i] <<"";
          string_echo += ss_dimensionsi.str();
        } else {
          std::stringstream ss_dimensionsi; ss_dimensionsi << dimensions[i] <<",";
          string_echo += ss_dimensionsi.str();
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "shape_msgs/SolidPrimitive"; }
    static std::string getTypeStatic(){ return "shape_msgs/SolidPrimitive"; }
    virtual std::string getMD5(){ return "f40805922065416be24909fd8fd751b5"; }
    static std::string getMD5Static(){ return "f40805922065416be24909fd8fd751b5"; }
    virtual std::string getDefinition(){ return "uint8 type\nfloat64[] dimensions\n"; }
    static std::string getDefinitionStatic(){ return "uint8 type\nfloat64[] dimensions\n"; }
    static bool hasHeader(){ return false; }
  };

typedef std::shared_ptr<tinyros::shape_msgs::SolidPrimitive> SolidPrimitivePtr;
typedef std::shared_ptr<tinyros::shape_msgs::SolidPrimitive const> SolidPrimitiveConstPtr;

}
}
#endif
