#ifndef _TINYROS_sensor_msgs_Illuminance_h
#define _TINYROS_sensor_msgs_Illuminance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"

namespace tinyros
{
namespace sensor_msgs
{

  class Illuminance : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef double _illuminance_type;
      _illuminance_type illuminance;
      typedef double _variance_type;
      _variance_type variance;

    Illuminance():
      header(),
      illuminance(0),
      variance(0)
    {
    }

    ~Illuminance()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_illuminance;
      u_illuminance.real = this->illuminance;
      *(outbuffer + offset + 0) = (u_illuminance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_illuminance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_illuminance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_illuminance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_illuminance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_illuminance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_illuminance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_illuminance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->illuminance);
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
      } u_illuminance;
      u_illuminance.base = 0;
      u_illuminance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_illuminance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_illuminance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_illuminance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_illuminance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_illuminance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_illuminance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_illuminance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->illuminance = u_illuminance.real;
      offset += sizeof(this->illuminance);
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
      length += sizeof(this->illuminance);
      length += sizeof(this->variance);
      return length;
    }

    virtual tinyros::string getType(){ return "sensor_msgs/Illuminance"; }
    static tinyros::string getTypeStatic(){ return "sensor_msgs/Illuminance"; }
    virtual tinyros::string getMD5(){ return "08ab9e71fcfbed30d5e337886c3f07f2"; }
    static tinyros::string getMD5Static(){ return "08ab9e71fcfbed30d5e337886c3f07f2"; }
    virtual tinyros::string getDefinition(){ return "Header header           \nfloat64 illuminance     \nfloat64 variance        \n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header           \nfloat64 illuminance     \nfloat64 variance        \n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
