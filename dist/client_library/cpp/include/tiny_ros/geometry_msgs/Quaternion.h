#ifndef _TINYROS_geometry_msgs_Quaternion_h
#define _TINYROS_geometry_msgs_Quaternion_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace geometry_msgs
{

  class Quaternion : public tinyros::Msg
  {
    public:
      typedef double _x_type;
      _x_type x;
      typedef double _y_type;
      _y_type y;
      typedef double _z_type;
      _z_type z;
      typedef double _w_type;
      _w_type w;

    Quaternion():
      x(0),
      y(0),
      z(0),
      w(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_z.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_z.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_z.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_z.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->z);
      union {
        double real;
        uint64_t base;
      } u_w;
      u_w.real = this->w;
      *(outbuffer + offset + 0) = (u_w.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_w.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_w.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_w.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_w.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_w.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_w.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_w.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->w);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        double real;
        uint64_t base;
      } u_w;
      u_w.base = 0;
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_w.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->w = u_w.real;
      offset += sizeof(this->w);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->x);
      length += sizeof(this->y);
      length += sizeof(this->z);
      length += sizeof(this->w);
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::stringstream ss_x; ss_x << "\"x\":" << x <<",";
      string_echo += ss_x.str();
      std::stringstream ss_y; ss_y << "\"y\":" << y <<",";
      string_echo += ss_y.str();
      std::stringstream ss_z; ss_z << "\"z\":" << z <<",";
      string_echo += ss_z.str();
      std::stringstream ss_w; ss_w << "\"w\":" << w <<"";
      string_echo += ss_w.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "geometry_msgs/Quaternion"; }
    static std::string getTypeStatic(){ return "geometry_msgs/Quaternion"; }
    virtual std::string getMD5(){ return "175c1571887d10ebed42ba6c042ddd88"; }
    static std::string getMD5Static(){ return "175c1571887d10ebed42ba6c042ddd88"; }
    virtual std::string getDefinition(){ return "float64 x\nfloat64 y\nfloat64 z\nfloat64 w\n"; }
    static std::string getDefinitionStatic(){ return "float64 x\nfloat64 y\nfloat64 z\nfloat64 w\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::geometry_msgs::Quaternion> Ptr;
    typedef std::shared_ptr<tinyros::geometry_msgs::Quaternion const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::geometry_msgs::Quaternion> QuaternionPtr;
typedef std::shared_ptr<tinyros::geometry_msgs::Quaternion const> QuaternionConstPtr;

}
}
#endif
