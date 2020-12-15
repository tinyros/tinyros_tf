#ifndef _TINYROS_sensor_msgs_MagneticField_h
#define _TINYROS_sensor_msgs_MagneticField_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Vector3.h"

namespace tinyros
{
namespace sensor_msgs
{

  class MagneticField : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Vector3 _magnetic_field_type;
      _magnetic_field_type magnetic_field;
      double magnetic_field_covariance[9];

    MagneticField():
      header(),
      magnetic_field(),
      magnetic_field_covariance()
    {
    }

    ~MagneticField()
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
      offset += this->magnetic_field.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 9; i++) {
        union {
          double real;
          uint64_t base;
        } u_magnetic_field_covariancei;
        u_magnetic_field_covariancei.real = this->magnetic_field_covariance[i];
        *(outbuffer + offset + 0) = (u_magnetic_field_covariancei.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_magnetic_field_covariancei.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_magnetic_field_covariancei.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_magnetic_field_covariancei.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_magnetic_field_covariancei.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_magnetic_field_covariancei.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_magnetic_field_covariancei.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_magnetic_field_covariancei.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->magnetic_field_covariance[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->magnetic_field.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 9; i++){
        union {
          double real;
          uint64_t base;
        } u_magnetic_field_covariancei;
        u_magnetic_field_covariancei.base = 0;
        u_magnetic_field_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_magnetic_field_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_magnetic_field_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_magnetic_field_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_magnetic_field_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_magnetic_field_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_magnetic_field_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_magnetic_field_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->magnetic_field_covariance[i] = u_magnetic_field_covariancei.real;
        offset += sizeof(this->magnetic_field_covariance[i]);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->magnetic_field.serializedLength();
      for( uint32_t i = 0; i < 9; i++) {
        length += sizeof(this->magnetic_field_covariance[i]);
      }
      return length;
    }

    virtual tinyros::string getType(){ return "sensor_msgs/MagneticField"; }
    static tinyros::string getTypeStatic(){ return "sensor_msgs/MagneticField"; }
    virtual tinyros::string getMD5(){ return "f8e051d776de1349146122759c66db92"; }
    static tinyros::string getMD5Static(){ return "f8e051d776de1349146122759c66db92"; }
    virtual tinyros::string getDefinition(){ return "Header header                        \ngeometry_msgs/Vector3 magnetic_field \nfloat64[9] magnetic_field_covariance \n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header                        \ngeometry_msgs/Vector3 magnetic_field \nfloat64[9] magnetic_field_covariance \n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif