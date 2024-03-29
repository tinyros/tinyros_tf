#ifndef _TINYROS_sensor_msgs_Temperature_h
#define _TINYROS_sensor_msgs_Temperature_h

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

  class Temperature : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef double _temperature_type;
      _temperature_type temperature;
      typedef double _variance_type;
      _variance_type variance;

    Temperature():
      header(),
      temperature(0),
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
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_temperature.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_temperature.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_temperature.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_temperature.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->temperature);
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
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_temperature.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
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
      length += sizeof(this->temperature);
      length += sizeof(this->variance);
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      std::stringstream ss_temperature; ss_temperature << "\"temperature\":" << temperature <<",";
      string_echo += ss_temperature.str();
      std::stringstream ss_variance; ss_variance << "\"variance\":" << variance <<"";
      string_echo += ss_variance.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "sensor_msgs/Temperature"; }
    static std::string getTypeStatic(){ return "sensor_msgs/Temperature"; }
    virtual std::string getMD5(){ return "898a0e5950c8e4073c0c3cf2d7e7bf26"; }
    static std::string getMD5Static(){ return "898a0e5950c8e4073c0c3cf2d7e7bf26"; }
    virtual std::string getDefinition(){ return "Header header\nfloat64 temperature\nfloat64 variance\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nfloat64 temperature\nfloat64 variance\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::sensor_msgs::Temperature> Ptr;
    typedef std::shared_ptr<tinyros::sensor_msgs::Temperature const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::sensor_msgs::Temperature> TemperaturePtr;
typedef std::shared_ptr<tinyros::sensor_msgs::Temperature const> TemperatureConstPtr;

}
}
#endif
