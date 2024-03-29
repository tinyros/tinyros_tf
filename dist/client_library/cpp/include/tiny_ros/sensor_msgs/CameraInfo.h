#ifndef _TINYROS_sensor_msgs_CameraInfo_h
#define _TINYROS_sensor_msgs_CameraInfo_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/sensor_msgs/RegionOfInterest.h"

namespace tinyros
{
namespace sensor_msgs
{

  class CameraInfo : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _height_type;
      _height_type height;
      typedef uint32_t _width_type;
      _width_type width;
      typedef std::string _distortion_model_type;
      _distortion_model_type distortion_model;
      typedef double _D_type;
      std::vector<_D_type> D;
      typedef double _K_type;
      std::vector<_K_type> K;
      typedef double _R_type;
      std::vector<_R_type> R;
      typedef double _P_type;
      std::vector<_P_type> P;
      typedef uint32_t _binning_x_type;
      _binning_x_type binning_x;
      typedef uint32_t _binning_y_type;
      _binning_y_type binning_y;
      typedef tinyros::sensor_msgs::RegionOfInterest _roi_type;
      _roi_type roi;

    CameraInfo():
      header(),
      height(0),
      width(0),
      distortion_model(""),
      D(0),
      K(9),
      R(9),
      P(12),
      binning_x(0),
      binning_y(0),
      roi()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      uint32_t length_distortion_model = this->distortion_model.size();
      varToArr(outbuffer + offset, length_distortion_model);
      offset += 4;
      memcpy(outbuffer + offset, this->distortion_model.c_str(), length_distortion_model);
      offset += length_distortion_model;
      uint32_t D_length = this->D.size();
      *(outbuffer + offset + 0) = (D_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (D_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (D_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (D_length >> (8 * 3)) & 0xFF;
      offset += sizeof(D_length);
      for( uint32_t i = 0; i < D_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_Di;
        u_Di.real = this->D[i];
        *(outbuffer + offset + 0) = (u_Di.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_Di.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_Di.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_Di.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_Di.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_Di.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_Di.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_Di.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->D[i]);
      }
      for( uint32_t i = 0; i < 9; i++) {
        union {
          double real;
          uint64_t base;
        } u_Ki;
        u_Ki.real = this->K[i];
        *(outbuffer + offset + 0) = (u_Ki.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_Ki.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_Ki.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_Ki.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_Ki.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_Ki.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_Ki.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_Ki.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->K[i]);
      }
      for( uint32_t i = 0; i < 9; i++) {
        union {
          double real;
          uint64_t base;
        } u_Ri;
        u_Ri.real = this->R[i];
        *(outbuffer + offset + 0) = (u_Ri.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_Ri.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_Ri.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_Ri.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_Ri.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_Ri.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_Ri.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_Ri.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->R[i]);
      }
      for( uint32_t i = 0; i < 12; i++) {
        union {
          double real;
          uint64_t base;
        } u_Pi;
        u_Pi.real = this->P[i];
        *(outbuffer + offset + 0) = (u_Pi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_Pi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_Pi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_Pi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_Pi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_Pi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_Pi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_Pi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->P[i]);
      }
      *(outbuffer + offset + 0) = (this->binning_x >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->binning_x >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->binning_x >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->binning_x >> (8 * 3)) & 0xFF;
      offset += sizeof(this->binning_x);
      *(outbuffer + offset + 0) = (this->binning_y >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->binning_y >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->binning_y >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->binning_y >> (8 * 3)) & 0xFF;
      offset += sizeof(this->binning_y);
      offset += this->roi.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->height =  ((uint32_t) (*(inbuffer + offset)));
      this->height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->height);
      this->width =  ((uint32_t) (*(inbuffer + offset)));
      this->width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->width);
      uint32_t length_distortion_model;
      arrToVar(length_distortion_model, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_distortion_model; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_distortion_model-1]=0;
      this->distortion_model = (char *)(inbuffer + offset-1);
      offset += length_distortion_model;
      uint32_t D_length = ((uint32_t) (*(inbuffer + offset))); 
      D_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      D_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      D_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->D.resize(D_length); 
      offset += sizeof(D_length);
      for( uint32_t i = 0; i < D_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_Di;
        u_Di.base = 0;
        u_Di.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_Di.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_Di.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_Di.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_Di.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_Di.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_Di.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_Di.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->D[i] = u_Di.real;
        offset += sizeof(this->D[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
        union {
          double real;
          uint64_t base;
        } u_Ki;
        u_Ki.base = 0;
        u_Ki.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_Ki.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_Ki.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_Ki.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_Ki.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_Ki.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_Ki.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_Ki.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->K[i] = u_Ki.real;
        offset += sizeof(this->K[i]);
      }
      for( uint32_t i = 0; i < 9; i++){
        union {
          double real;
          uint64_t base;
        } u_Ri;
        u_Ri.base = 0;
        u_Ri.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_Ri.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_Ri.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_Ri.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_Ri.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_Ri.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_Ri.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_Ri.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->R[i] = u_Ri.real;
        offset += sizeof(this->R[i]);
      }
      for( uint32_t i = 0; i < 12; i++){
        union {
          double real;
          uint64_t base;
        } u_Pi;
        u_Pi.base = 0;
        u_Pi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_Pi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_Pi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_Pi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_Pi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_Pi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_Pi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_Pi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->P[i] = u_Pi.real;
        offset += sizeof(this->P[i]);
      }
      this->binning_x =  ((uint32_t) (*(inbuffer + offset)));
      this->binning_x |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->binning_x |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->binning_x |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->binning_x);
      this->binning_y =  ((uint32_t) (*(inbuffer + offset)));
      this->binning_y |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->binning_y |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->binning_y |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->binning_y);
      offset += this->roi.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += sizeof(this->height);
      length += sizeof(this->width);
      uint32_t length_distortion_model = this->distortion_model.size();
      length += 4;
      length += length_distortion_model;
      uint32_t D_length = this->D.size();
      length += sizeof(D_length);
      for( uint32_t i = 0; i < D_length; i++) {
        length += sizeof(this->D[i]);
      }
      for( uint32_t i = 0; i < 9; i++) {
        length += sizeof(this->K[i]);
      }
      for( uint32_t i = 0; i < 9; i++) {
        length += sizeof(this->R[i]);
      }
      for( uint32_t i = 0; i < 12; i++) {
        length += sizeof(this->P[i]);
      }
      length += sizeof(this->binning_x);
      length += sizeof(this->binning_y);
      length += this->roi.serializedLength();
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      std::stringstream ss_height; ss_height << "\"height\":" << height <<",";
      string_echo += ss_height.str();
      std::stringstream ss_width; ss_width << "\"width\":" << width <<",";
      string_echo += ss_width.str();
      std::size_t distortion_model_pos = distortion_model.find("\"");
      while(distortion_model_pos != std::string::npos){
        distortion_model.replace(distortion_model_pos, 1,"\\\"");
        distortion_model_pos = distortion_model.find("\"", distortion_model_pos+2);
      }
      string_echo += "\"distortion_model\":\"";
      string_echo += distortion_model;
      string_echo += "\",";
      uint32_t D_length = this->D.size();
      string_echo += "D:[";
      for( uint32_t i = 0; i < D_length; i++) {
        if( i == (D_length - 1)) {
          std::stringstream ss_Di; ss_Di << D[i] <<"";
          string_echo += ss_Di.str();
        } else {
          std::stringstream ss_Di; ss_Di << D[i] <<",";
          string_echo += ss_Di.str();
        }
      }
      string_echo += "],";
      string_echo += "K:[";
      for( uint32_t i = 0; i < 9; i++) {
        if( i == (9 - 1)) {
          std::stringstream ss_Ki; ss_Ki << K[i] <<"";
          string_echo += ss_Ki.str();
        } else {
          std::stringstream ss_Ki; ss_Ki << K[i] <<",";
          string_echo += ss_Ki.str();
        }
      }
      string_echo += "],";
      string_echo += "R:[";
      for( uint32_t i = 0; i < 9; i++) {
        if( i == (9 - 1)) {
          std::stringstream ss_Ri; ss_Ri << R[i] <<"";
          string_echo += ss_Ri.str();
        } else {
          std::stringstream ss_Ri; ss_Ri << R[i] <<",";
          string_echo += ss_Ri.str();
        }
      }
      string_echo += "],";
      string_echo += "P:[";
      for( uint32_t i = 0; i < 12; i++) {
        if( i == (12 - 1)) {
          std::stringstream ss_Pi; ss_Pi << P[i] <<"";
          string_echo += ss_Pi.str();
        } else {
          std::stringstream ss_Pi; ss_Pi << P[i] <<",";
          string_echo += ss_Pi.str();
        }
      }
      string_echo += "],";
      std::stringstream ss_binning_x; ss_binning_x << "\"binning_x\":" << binning_x <<",";
      string_echo += ss_binning_x.str();
      std::stringstream ss_binning_y; ss_binning_y << "\"binning_y\":" << binning_y <<",";
      string_echo += ss_binning_y.str();
      string_echo += "\"roi\":";
      string_echo += this->roi.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "sensor_msgs/CameraInfo"; }
    static std::string getTypeStatic(){ return "sensor_msgs/CameraInfo"; }
    virtual std::string getMD5(){ return "57d2553deec0a7842f00837f40032798"; }
    static std::string getMD5Static(){ return "57d2553deec0a7842f00837f40032798"; }
    virtual std::string getDefinition(){ return "Header header\nuint32 height\nuint32 width\nstring distortion_model\nfloat64[] D\nfloat64[9]  K\nfloat64[9]  R\nfloat64[12] P\nuint32 binning_x\nuint32 binning_y\nRegionOfInterest roi\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nuint32 height\nuint32 width\nstring distortion_model\nfloat64[] D\nfloat64[9]  K\nfloat64[9]  R\nfloat64[12] P\nuint32 binning_x\nuint32 binning_y\nRegionOfInterest roi\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::sensor_msgs::CameraInfo> Ptr;
    typedef std::shared_ptr<tinyros::sensor_msgs::CameraInfo const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::sensor_msgs::CameraInfo> CameraInfoPtr;
typedef std::shared_ptr<tinyros::sensor_msgs::CameraInfo const> CameraInfoConstPtr;

}
}
#endif
