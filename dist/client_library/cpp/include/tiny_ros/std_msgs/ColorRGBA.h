#ifndef _TINYROS_std_msgs_ColorRGBA_h
#define _TINYROS_std_msgs_ColorRGBA_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace std_msgs
{

  class ColorRGBA : public tinyros::Msg
  {
    public:
      typedef float _r_type;
      _r_type r;
      typedef float _g_type;
      _g_type g;
      typedef float _b_type;
      _b_type b;
      typedef float _a_type;
      _a_type a;

    ColorRGBA():
      r(0),
      g(0),
      b(0),
      a(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_r;
      u_r.real = this->r;
      *(outbuffer + offset + 0) = (u_r.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_r.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_r.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_r.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->r);
      union {
        float real;
        uint32_t base;
      } u_g;
      u_g.real = this->g;
      *(outbuffer + offset + 0) = (u_g.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_g.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_g.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_g.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->g);
      union {
        float real;
        uint32_t base;
      } u_b;
      u_b.real = this->b;
      *(outbuffer + offset + 0) = (u_b.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_b.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_b.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_b.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->b);
      union {
        float real;
        uint32_t base;
      } u_a;
      u_a.real = this->a;
      *(outbuffer + offset + 0) = (u_a.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_a.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_a.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_a.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->a);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_r;
      u_r.base = 0;
      u_r.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_r.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_r.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_r.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->r = u_r.real;
      offset += sizeof(this->r);
      union {
        float real;
        uint32_t base;
      } u_g;
      u_g.base = 0;
      u_g.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_g.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_g.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_g.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->g = u_g.real;
      offset += sizeof(this->g);
      union {
        float real;
        uint32_t base;
      } u_b;
      u_b.base = 0;
      u_b.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_b.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_b.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_b.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->b = u_b.real;
      offset += sizeof(this->b);
      union {
        float real;
        uint32_t base;
      } u_a;
      u_a.base = 0;
      u_a.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_a.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_a.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_a.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->a = u_a.real;
      offset += sizeof(this->a);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->r);
      length += sizeof(this->g);
      length += sizeof(this->b);
      length += sizeof(this->a);
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::stringstream ss_r; ss_r << "\"r\":" << r <<",";
      string_echo += ss_r.str();
      std::stringstream ss_g; ss_g << "\"g\":" << g <<",";
      string_echo += ss_g.str();
      std::stringstream ss_b; ss_b << "\"b\":" << b <<",";
      string_echo += ss_b.str();
      std::stringstream ss_a; ss_a << "\"a\":" << a <<"";
      string_echo += ss_a.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "std_msgs/ColorRGBA"; }
    static std::string getTypeStatic(){ return "std_msgs/ColorRGBA"; }
    virtual std::string getMD5(){ return "3c740aa311a337bfa4133c69405e0aed"; }
    static std::string getMD5Static(){ return "3c740aa311a337bfa4133c69405e0aed"; }
    virtual std::string getDefinition(){ return "float32 r\nfloat32 g\nfloat32 b\nfloat32 a\n"; }
    static std::string getDefinitionStatic(){ return "float32 r\nfloat32 g\nfloat32 b\nfloat32 a\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::std_msgs::ColorRGBA> Ptr;
    typedef std::shared_ptr<tinyros::std_msgs::ColorRGBA const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::std_msgs::ColorRGBA> ColorRGBAPtr;
typedef std::shared_ptr<tinyros::std_msgs::ColorRGBA const> ColorRGBAConstPtr;

}
}
#endif
