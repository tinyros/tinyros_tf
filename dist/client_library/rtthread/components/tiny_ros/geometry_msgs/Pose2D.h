#ifndef _TINYROS_geometry_msgs_Pose2D_h
#define _TINYROS_geometry_msgs_Pose2D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace geometry_msgs
{

  class Pose2D : public tinyros::Msg
  {
    public:
      typedef double _x_type;
      _x_type x;
      typedef double _y_type;
      _y_type y;
      typedef double _theta_type;
      _theta_type theta;

    Pose2D():
      x(0),
      y(0),
      theta(0)
    {
    }

    ~Pose2D()
    {
      deconstructor();
    }

    void deconstructor()
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
      } u_theta;
      u_theta.real = this->theta;
      *(outbuffer + offset + 0) = (u_theta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_theta.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_theta.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_theta.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_theta.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->theta);
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
      } u_theta;
      u_theta.base = 0;
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_theta.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->theta = u_theta.real;
      offset += sizeof(this->theta);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->x);
      length += sizeof(this->y);
      length += sizeof(this->theta);
      return length;
    }

    virtual tinyros::string getType(){ return "geometry_msgs/Pose2D"; }
    static tinyros::string getTypeStatic(){ return "geometry_msgs/Pose2D"; }
    virtual tinyros::string getMD5(){ return "509f362ff66c4d3df21020fa7c01f8c6"; }
    static tinyros::string getMD5Static(){ return "509f362ff66c4d3df21020fa7c01f8c6"; }
    virtual tinyros::string getDefinition(){ return "float64 x\nfloat64 y\nfloat64 theta\n"; }
    static tinyros::string getDefinitionStatic(){ return "float64 x\nfloat64 y\nfloat64 theta\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
