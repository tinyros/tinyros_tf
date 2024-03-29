#ifndef _TINYROS_sensor_msgs_FluidPressure_h
#define _TINYROS_sensor_msgs_FluidPressure_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"

namespace tinyros
{
namespace sensor_msgs
{

  class FluidPressure : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef double _fluid_pressure_type;
      _fluid_pressure_type fluid_pressure;
      typedef double _variance_type;
      _variance_type variance;

    FluidPressure():
      header(),
      fluid_pressure(0),
      variance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_fluid_pressure;
      u_fluid_pressure.real = this->fluid_pressure;
      *(outbuffer + offset + 0) = (u_fluid_pressure.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fluid_pressure.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fluid_pressure.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fluid_pressure.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_fluid_pressure.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_fluid_pressure.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_fluid_pressure.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_fluid_pressure.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->fluid_pressure);
      union {
        double real;
        uint64_t base;
      } u_variance;
      u_variance.real = this->variance;
      *(outbuffer + offset + 0) = (u_variance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_variance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_variance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_variance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_variance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_variance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_variance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_variance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->variance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_fluid_pressure;
      u_fluid_pressure.base = 0;
      u_fluid_pressure.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fluid_pressure.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fluid_pressure.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fluid_pressure.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_fluid_pressure.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_fluid_pressure.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_fluid_pressure.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_fluid_pressure.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->fluid_pressure = u_fluid_pressure.real;
      offset += sizeof(this->fluid_pressure);
      union {
        double real;
        uint64_t base;
      } u_variance;
      u_variance.base = 0;
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_variance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->variance = u_variance.real;
      offset += sizeof(this->variance);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += sizeof(this->fluid_pressure);
      length += sizeof(this->variance);
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      std::stringstream ss_fluid_pressure; ss_fluid_pressure << "\"fluid_pressure\":" << fluid_pressure <<",";
      string_echo += ss_fluid_pressure.str();
      std::stringstream ss_variance; ss_variance << "\"variance\":" << variance <<"";
      string_echo += ss_variance.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "sensor_msgs/FluidPressure"; }
    static std::string getTypeStatic(){ return "sensor_msgs/FluidPressure"; }
    virtual std::string getMD5(){ return "0fdea137019d78ebf8c2cb91c31a458a"; }
    static std::string getMD5Static(){ return "0fdea137019d78ebf8c2cb91c31a458a"; }
    virtual std::string getDefinition(){ return "Header header\nfloat64 fluid_pressure\nfloat64 variance\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nfloat64 fluid_pressure\nfloat64 variance\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::sensor_msgs::FluidPressure> Ptr;
    typedef std::shared_ptr<tinyros::sensor_msgs::FluidPressure const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::sensor_msgs::FluidPressure> FluidPressurePtr;
typedef std::shared_ptr<tinyros::sensor_msgs::FluidPressure const> FluidPressureConstPtr;

}
}
#endif
