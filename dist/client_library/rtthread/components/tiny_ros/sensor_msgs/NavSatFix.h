#ifndef _TINYROS_sensor_msgs_NavSatFix_h
#define _TINYROS_sensor_msgs_NavSatFix_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/sensor_msgs/NavSatStatus.h"

namespace tinyros
{
namespace sensor_msgs
{

  class NavSatFix : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::sensor_msgs::NavSatStatus _status_type;
      _status_type status;
      typedef double _latitude_type;
      _latitude_type latitude;
      typedef double _longitude_type;
      _longitude_type longitude;
      typedef double _altitude_type;
      _altitude_type altitude;
      double position_covariance[9];
      typedef uint8_t _position_covariance_type_type;
      _position_covariance_type_type position_covariance_type;
      enum { COVARIANCE_TYPE_UNKNOWN =  0 };
      enum { COVARIANCE_TYPE_APPROXIMATED =  1 };
      enum { COVARIANCE_TYPE_DIAGONAL_KNOWN =  2 };
      enum { COVARIANCE_TYPE_KNOWN =  3 };

    NavSatFix():
      header(),
      status(),
      latitude(0),
      longitude(0),
      altitude(0),
      position_covariance(),
      position_covariance_type(0)
    {
    }

    ~NavSatFix()
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
      offset += this->status.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_latitude;
      u_latitude.real = this->latitude;
      *(outbuffer + offset + 0) = (u_latitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_latitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_latitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_latitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_latitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->latitude);
      union {
        double real;
        uint64_t base;
      } u_longitude;
      u_longitude.real = this->longitude;
      *(outbuffer + offset + 0) = (u_longitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_longitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_longitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_longitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_longitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->longitude);
      union {
        double real;
        uint64_t base;
      } u_altitude;
      u_altitude.real = this->altitude;
      *(outbuffer + offset + 0) = (u_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_altitude.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_altitude.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_altitude.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_altitude.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->altitude);
      for( uint32_t i = 0; i < 9; i++) {
        union {
          double real;
          uint64_t base;
        } u_position_covariancei;
        u_position_covariancei.real = this->position_covariance[i];
        *(outbuffer + offset + 0) = (u_position_covariancei.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_position_covariancei.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_position_covariancei.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_position_covariancei.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_position_covariancei.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_position_covariancei.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_position_covariancei.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_position_covariancei.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->position_covariance[i]);
      }
      *(outbuffer + offset + 0) = (this->position_covariance_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->position_covariance_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_latitude;
      u_latitude.base = 0;
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_latitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->latitude = u_latitude.real;
      offset += sizeof(this->latitude);
      union {
        double real;
        uint64_t base;
      } u_longitude;
      u_longitude.base = 0;
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_longitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->longitude = u_longitude.real;
      offset += sizeof(this->longitude);
      union {
        double real;
        uint64_t base;
      } u_altitude;
      u_altitude.base = 0;
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_altitude.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->altitude = u_altitude.real;
      offset += sizeof(this->altitude);
      for( uint32_t i = 0; i < 9; i++){
        union {
          double real;
          uint64_t base;
        } u_position_covariancei;
        u_position_covariancei.base = 0;
        u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_position_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->position_covariance[i] = u_position_covariancei.real;
        offset += sizeof(this->position_covariance[i]);
      }
      this->position_covariance_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->position_covariance_type);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->status.serializedLength();
      length += sizeof(this->latitude);
      length += sizeof(this->longitude);
      length += sizeof(this->altitude);
      for( uint32_t i = 0; i < 9; i++) {
        length += sizeof(this->position_covariance[i]);
      }
      length += sizeof(this->position_covariance_type);
      return length;
    }

    virtual tinyros::string getType(){ return "sensor_msgs/NavSatFix"; }
    static tinyros::string getTypeStatic(){ return "sensor_msgs/NavSatFix"; }
    virtual tinyros::string getMD5(){ return "adc27ca9d8634ed087021b82f3c43576"; }
    static tinyros::string getMD5Static(){ return "adc27ca9d8634ed087021b82f3c43576"; }
    virtual tinyros::string getDefinition(){ return "Header header\nNavSatStatus status\nfloat64 latitude\nfloat64 longitude\nfloat64 altitude\nfloat64[9] position_covariance\nuint8 position_covariance_type\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\nNavSatStatus status\nfloat64 latitude\nfloat64 longitude\nfloat64 altitude\nfloat64[9] position_covariance\nuint8 position_covariance_type\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
