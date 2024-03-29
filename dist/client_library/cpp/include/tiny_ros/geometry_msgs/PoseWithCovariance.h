#ifndef _TINYROS_geometry_msgs_PoseWithCovariance_h
#define _TINYROS_geometry_msgs_PoseWithCovariance_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/geometry_msgs/Pose.h"

namespace tinyros
{
namespace geometry_msgs
{

  class PoseWithCovariance : public tinyros::Msg
  {
    public:
      typedef tinyros::geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef double _covariance_type;
      std::vector<_covariance_type> covariance;

    PoseWithCovariance():
      pose(),
      covariance(36)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->pose.serialize(outbuffer + offset);
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
      offset += this->pose.deserialize(inbuffer + offset);
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
      length += this->pose.serializedLength();
      for( uint32_t i = 0; i < 36; i++) {
        length += sizeof(this->covariance[i]);
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"pose\":";
      string_echo += this->pose.echo();
      string_echo += ",";
      string_echo += "covariance:[";
      for( uint32_t i = 0; i < 36; i++) {
        if( i == (36 - 1)) {
          std::stringstream ss_covariancei; ss_covariancei << covariance[i] <<"";
          string_echo += ss_covariancei.str();
        } else {
          std::stringstream ss_covariancei; ss_covariancei << covariance[i] <<",";
          string_echo += ss_covariancei.str();
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "geometry_msgs/PoseWithCovariance"; }
    static std::string getTypeStatic(){ return "geometry_msgs/PoseWithCovariance"; }
    virtual std::string getMD5(){ return "054c6283d50e78f8d9358aaaee5f4c1b"; }
    static std::string getMD5Static(){ return "054c6283d50e78f8d9358aaaee5f4c1b"; }
    virtual std::string getDefinition(){ return "Pose pose\nfloat64[36] covariance\n"; }
    static std::string getDefinitionStatic(){ return "Pose pose\nfloat64[36] covariance\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::geometry_msgs::PoseWithCovariance> Ptr;
    typedef std::shared_ptr<tinyros::geometry_msgs::PoseWithCovariance const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::geometry_msgs::PoseWithCovariance> PoseWithCovariancePtr;
typedef std::shared_ptr<tinyros::geometry_msgs::PoseWithCovariance const> PoseWithCovarianceConstPtr;

}
}
#endif
