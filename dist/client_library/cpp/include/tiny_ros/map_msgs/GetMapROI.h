#ifndef _TINYROS_SERVICE_GetMapROI_h
#define _TINYROS_SERVICE_GetMapROI_h
#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/nav_msgs/OccupancyGrid.h"

namespace tinyros
{
namespace map_msgs
{

static const char GETMAPROI[] = "map_msgs/GetMapROI";

  class GetMapROIRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef double _x_type;
      _x_type x;
      typedef double _y_type;
      _y_type y;
      typedef double _l_x_type;
      _l_x_type l_x;
      typedef double _l_y_type;
      _l_y_type l_y;

    GetMapROIRequest():
      x(0),
      y(0),
      l_x(0),
      l_y(0)
    {
      this->__id__ = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->__id__ >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->__id__ >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->__id__ >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->__id__ >> (8 * 3)) & 0xFF;
      offset += sizeof(this->__id__);
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
      } u_l_x;
      u_l_x.real = this->l_x;
      *(outbuffer + offset + 0) = (u_l_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_l_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_l_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_l_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_l_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_l_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_l_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_l_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->l_x);
      union {
        double real;
        uint64_t base;
      } u_l_y;
      u_l_y.real = this->l_y;
      *(outbuffer + offset + 0) = (u_l_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_l_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_l_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_l_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_l_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_l_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_l_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_l_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->l_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->__id__ =  ((uint32_t) (*(inbuffer + offset)));
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->__id__);
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
      } u_l_x;
      u_l_x.base = 0;
      u_l_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_l_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_l_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_l_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_l_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_l_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_l_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_l_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->l_x = u_l_x.real;
      offset += sizeof(this->l_x);
      union {
        double real;
        uint64_t base;
      } u_l_y;
      u_l_y.base = 0;
      u_l_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_l_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_l_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_l_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_l_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_l_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_l_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_l_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->l_y = u_l_y.real;
      offset += sizeof(this->l_y);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->x);
      length += sizeof(this->y);
      length += sizeof(this->l_x);
      length += sizeof(this->l_y);
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::stringstream ss_x; ss_x << "\"x\":" << x <<",";
      string_echo += ss_x.str();
      std::stringstream ss_y; ss_y << "\"y\":" << y <<",";
      string_echo += ss_y.str();
      std::stringstream ss_l_x; ss_l_x << "\"l_x\":" << l_x <<",";
      string_echo += ss_l_x.str();
      std::stringstream ss_l_y; ss_l_y << "\"l_y\":" << l_y <<"";
      string_echo += ss_l_y.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return GETMAPROI; }
    static std::string getTypeStatic(){ return GETMAPROI; }
    virtual std::string getMD5(){ return "f74ea8c8dc9b857aae7ea10033520d28"; }
    static std::string getMD5Static(){ return "f74ea8c8dc9b857aae7ea10033520d28"; }
    virtual std::string getDefinition(){ return "float64 x\nfloat64 y\nfloat64 l_x\nfloat64 l_y\n"; }
    static std::string getDefinitionStatic(){ return "float64 x\nfloat64 y\nfloat64 l_x\nfloat64 l_y\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::map_msgs::GetMapROIRequest> Ptr;
    typedef std::shared_ptr<tinyros::map_msgs::GetMapROIRequest const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::map_msgs::GetMapROIRequest> GetMapROIRequestPtr;
typedef std::shared_ptr<tinyros::map_msgs::GetMapROIRequest const> GetMapROIRequestConstPtr;

  class GetMapROIResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef tinyros::nav_msgs::OccupancyGrid _sub_map_type;
      _sub_map_type sub_map;

    GetMapROIResponse():
      sub_map()
    {
      this->__id__ = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->__id__ >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->__id__ >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->__id__ >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->__id__ >> (8 * 3)) & 0xFF;
      offset += sizeof(this->__id__);
      offset += this->sub_map.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->__id__ =  ((uint32_t) (*(inbuffer + offset)));
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->__id__);
      offset += this->sub_map.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->sub_map.serializedLength();
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"sub_map\":";
      string_echo += this->sub_map.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return GETMAPROI; }
    static std::string getTypeStatic(){ return GETMAPROI; }
    virtual std::string getMD5(){ return "a178ec520c3d0d99d9d85c70ed4b535a"; }
    static std::string getMD5Static(){ return "a178ec520c3d0d99d9d85c70ed4b535a"; }
    virtual std::string getDefinition(){ return "nav_msgs/OccupancyGrid sub_map\n"; }
    static std::string getDefinitionStatic(){ return "nav_msgs/OccupancyGrid sub_map\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::map_msgs::GetMapROIResponse> Ptr;
    typedef std::shared_ptr<tinyros::map_msgs::GetMapROIResponse const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::map_msgs::GetMapROIResponse> GetMapROIResponsePtr;
typedef std::shared_ptr<tinyros::map_msgs::GetMapROIResponse const> GetMapROIResponseConstPtr;

  class GetMapROI {
    public:
    typedef GetMapROIRequest Request;
    typedef GetMapROIResponse Response;
  };

}
}
#endif
