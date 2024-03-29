#ifndef _TINYROS_sensor_msgs_Imu_h
#define _TINYROS_sensor_msgs_Imu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Quaternion.h"
#include "tiny_ros/geometry_msgs/Vector3.h"

namespace tinyros
{
namespace sensor_msgs
{

  class Imu : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Quaternion _orientation_type;
      _orientation_type orientation;
      double orientation_covariance[9];
      typedef tinyros::geometry_msgs::Vector3 _angular_velocity_type;
      _angular_velocity_type angular_velocity;
      double angular_velocity_covariance[9];
      typedef tinyros::geometry_msgs::Vector3 _linear_acceleration_type;
      _linear_acceleration_type linear_acceleration;
      double linear_acceleration_covariance[9];

    Imu():
      header(),
      orientation(),
      orientation_covariance(),
      angular_velocity(),
      angular_velocity_covariance(),
      linear_acceleration(),
      linear_acceleration_covariance()
    {
    }

    ~Imu()
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
      offset += this->orientation.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 9; i++) {
        union {
          double real;
          uint64_t base;
        } u_orientation_covariancei;
        u_orientation_covariancei.real = this->orientation_covariance[i];
        *(outbuffer + offset + 0) = (u_orientation_covariancei.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_orientation_covariancei.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_orientation_covariancei.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_orientation_covariancei.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_orientation_covariancei.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_orientation_covariancei.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_orientation_covariancei.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_orientation_covariancei.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->orientation_covariance[i]);
      }
      offset += this->angular_velocity.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 9; i++) {
        union {
          double real;
          uint64_t base;
        } u_angular_velocity_covariancei;
        u_angular_velocity_covariancei.real = this->angular_velocity_covariance[i];
        *(outbuffer + offset + 0) = (u_angular_velocity_covariancei.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_angular_velocity_covariancei.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_angular_velocity_covariancei.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_angular_velocity_covariancei.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_angular_velocity_covariancei.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_angular_velocity_covariancei.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_angular_velocity_covariancei.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_angular_velocity_covariancei.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->angular_velocity_covariance[i]);
      }
      offset += this->linear_acceleration.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 9; i++) {
        union {
          double real;
          uint64_t base;
        } u_linear_acceleration_covariancei;
        u_linear_acceleration_covariancei.real = this->linear_acceleration_covariance[i];
        *(outbuffer + offset + 0) = (u_linear_acceleration_covariancei.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_linear_acceleration_covariancei.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_linear_acceleration_covariancei.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_linear_acceleration_covariancei.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_linear_acceleration_covariancei.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_linear_acceleration_covariancei.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_linear_acceleration_covariancei.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_linear_acceleration_covariancei.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->linear_acceleration_covariance[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 9; i++){
        union {
          double real;
          uint64_t base;
        } u_orientation_covariancei;
        u_orientation_covariancei.base = 0;
        u_orientation_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_orientation_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_orientation_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_orientation_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_orientation_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_orientation_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_orientation_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_orientation_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->orientation_covariance[i] = u_orientation_covariancei.real;
        offset += sizeof(this->orientation_covariance[i]);
      }
      offset += this->angular_velocity.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 9; i++){
        union {
          double real;
          uint64_t base;
        } u_angular_velocity_covariancei;
        u_angular_velocity_covariancei.base = 0;
        u_angular_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_angular_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_angular_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_angular_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_angular_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_angular_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_angular_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_angular_velocity_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->angular_velocity_covariance[i] = u_angular_velocity_covariancei.real;
        offset += sizeof(this->angular_velocity_covariance[i]);
      }
      offset += this->linear_acceleration.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 9; i++){
        union {
          double real;
          uint64_t base;
        } u_linear_acceleration_covariancei;
        u_linear_acceleration_covariancei.base = 0;
        u_linear_acceleration_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_linear_acceleration_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_linear_acceleration_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_linear_acceleration_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_linear_acceleration_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_linear_acceleration_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_linear_acceleration_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_linear_acceleration_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->linear_acceleration_covariance[i] = u_linear_acceleration_covariancei.real;
        offset += sizeof(this->linear_acceleration_covariance[i]);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->orientation.serializedLength();
      for( uint32_t i = 0; i < 9; i++) {
        length += sizeof(this->orientation_covariance[i]);
      }
      length += this->angular_velocity.serializedLength();
      for( uint32_t i = 0; i < 9; i++) {
        length += sizeof(this->angular_velocity_covariance[i]);
      }
      length += this->linear_acceleration.serializedLength();
      for( uint32_t i = 0; i < 9; i++) {
        length += sizeof(this->linear_acceleration_covariance[i]);
      }
      return length;
    }

    virtual tinyros::string getType(){ return "sensor_msgs/Imu"; }
    static tinyros::string getTypeStatic(){ return "sensor_msgs/Imu"; }
    virtual tinyros::string getMD5(){ return "a42c1ab94665a5807834c0ea19a6d16a"; }
    static tinyros::string getMD5Static(){ return "a42c1ab94665a5807834c0ea19a6d16a"; }
    virtual tinyros::string getDefinition(){ return "Header header\ngeometry_msgs/Quaternion orientation\nfloat64[9] orientation_covariance \ngeometry_msgs/Vector3 angular_velocity\nfloat64[9] angular_velocity_covariance \ngeometry_msgs/Vector3 linear_acceleration\nfloat64[9] linear_acceleration_covariance \n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\ngeometry_msgs/Quaternion orientation\nfloat64[9] orientation_covariance \ngeometry_msgs/Vector3 angular_velocity\nfloat64[9] angular_velocity_covariance \ngeometry_msgs/Vector3 linear_acceleration\nfloat64[9] linear_acceleration_covariance \n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
