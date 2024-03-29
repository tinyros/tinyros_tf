#ifndef _TINYROS_geometry_msgs_TwistWithCovariance_h
#define _TINYROS_geometry_msgs_TwistWithCovariance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/geometry_msgs/Twist.h"

namespace tinyros
{
namespace geometry_msgs
{

  class TwistWithCovariance : public tinyros::Msg
  {
    public:
      typedef tinyros::geometry_msgs::Twist _twist_type;
      _twist_type twist;
      double covariance[36];

    TwistWithCovariance():
      twist(),
      covariance()
    {
    }

    ~TwistWithCovariance()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->twist.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 36; i++) {
        union {
          double real;
          uint64_t base;
        } u_covariancei;
        u_covariancei.real = this->covariance[i];
        *(outbuffer + offset + 0) = (u_covariancei.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_covariancei.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_covariancei.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_covariancei.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_covariancei.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_covariancei.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_covariancei.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_covariancei.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->covariance[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->twist.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 36; i++){
        union {
          double real;
          uint64_t base;
        } u_covariancei;
        u_covariancei.base = 0;
        u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_covariancei.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->covariance[i] = u_covariancei.real;
        offset += sizeof(this->covariance[i]);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->twist.serializedLength();
      for( uint32_t i = 0; i < 36; i++) {
        length += sizeof(this->covariance[i]);
      }
      return length;
    }

    virtual tinyros::string getType(){ return "geometry_msgs/TwistWithCovariance"; }
    static tinyros::string getTypeStatic(){ return "geometry_msgs/TwistWithCovariance"; }
    virtual tinyros::string getMD5(){ return "0421bae691707888d99987e0bbcf4c55"; }
    static tinyros::string getMD5Static(){ return "0421bae691707888d99987e0bbcf4c55"; }
    virtual tinyros::string getDefinition(){ return "Twist twist\nfloat64[36] covariance\n"; }
    static tinyros::string getDefinitionStatic(){ return "Twist twist\nfloat64[36] covariance\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
