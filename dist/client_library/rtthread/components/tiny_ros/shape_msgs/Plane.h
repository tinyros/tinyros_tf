#ifndef _TINYROS_shape_msgs_Plane_h
#define _TINYROS_shape_msgs_Plane_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace shape_msgs
{

  class Plane : public tinyros::Msg
  {
    public:
      double coef[4];

    Plane():
      coef()
    {
    }

    ~Plane()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++) {
        union {
          double real;
          uint64_t base;
        } u_coefi;
        u_coefi.real = this->coef[i];
        *(outbuffer + offset + 0) = (u_coefi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_coefi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_coefi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_coefi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_coefi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_coefi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_coefi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_coefi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->coef[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 4; i++){
        union {
          double real;
          uint64_t base;
        } u_coefi;
        u_coefi.base = 0;
        u_coefi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_coefi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_coefi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_coefi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_coefi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_coefi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_coefi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_coefi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->coef[i] = u_coefi.real;
        offset += sizeof(this->coef[i]);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      for( uint32_t i = 0; i < 4; i++) {
        length += sizeof(this->coef[i]);
      }
      return length;
    }

    virtual tinyros::string getType(){ return "shape_msgs/Plane"; }
    static tinyros::string getTypeStatic(){ return "shape_msgs/Plane"; }
    virtual tinyros::string getMD5(){ return "770421286b7c90effe8aac9f1c37eac0"; }
    static tinyros::string getMD5Static(){ return "770421286b7c90effe8aac9f1c37eac0"; }
    virtual tinyros::string getDefinition(){ return "float64[4] coef\n"; }
    static tinyros::string getDefinitionStatic(){ return "float64[4] coef\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
