#ifndef _TINYROS_stereo_msgs_DisparityImage_h
#define _TINYROS_stereo_msgs_DisparityImage_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/sensor_msgs/Image.h"
#include "tiny_ros/sensor_msgs/RegionOfInterest.h"

namespace tinyros
{
namespace stereo_msgs
{

  class DisparityImage : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::sensor_msgs::Image _image_type;
      _image_type image;
      typedef float _f_type;
      _f_type f;
      typedef float _T_type;
      _T_type T;
      typedef tinyros::sensor_msgs::RegionOfInterest _valid_window_type;
      _valid_window_type valid_window;
      typedef float _min_disparity_type;
      _min_disparity_type min_disparity;
      typedef float _max_disparity_type;
      _max_disparity_type max_disparity;
      typedef float _delta_d_type;
      _delta_d_type delta_d;

    DisparityImage():
      header(),
      image(),
      f(0),
      T(0),
      valid_window(),
      min_disparity(0),
      max_disparity(0),
      delta_d(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->image.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_f;
      u_f.real = this->f;
      *(outbuffer + offset + 0) = (u_f.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_f.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_f.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_f.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->f);
      union {
        float real;
        uint32_t base;
      } u_T;
      u_T.real = this->T;
      *(outbuffer + offset + 0) = (u_T.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_T.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_T.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_T.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->T);
      offset += this->valid_window.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_min_disparity;
      u_min_disparity.real = this->min_disparity;
      *(outbuffer + offset + 0) = (u_min_disparity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_min_disparity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_min_disparity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_min_disparity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->min_disparity);
      union {
        float real;
        uint32_t base;
      } u_max_disparity;
      u_max_disparity.real = this->max_disparity;
      *(outbuffer + offset + 0) = (u_max_disparity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_max_disparity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_max_disparity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_max_disparity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_disparity);
      union {
        float real;
        uint32_t base;
      } u_delta_d;
      u_delta_d.real = this->delta_d;
      *(outbuffer + offset + 0) = (u_delta_d.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_delta_d.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_delta_d.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_delta_d.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delta_d);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->image.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_f;
      u_f.base = 0;
      u_f.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_f.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_f.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_f.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->f = u_f.real;
      offset += sizeof(this->f);
      union {
        float real;
        uint32_t base;
      } u_T;
      u_T.base = 0;
      u_T.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_T.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_T.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_T.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->T = u_T.real;
      offset += sizeof(this->T);
      offset += this->valid_window.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_min_disparity;
      u_min_disparity.base = 0;
      u_min_disparity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_min_disparity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_min_disparity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_min_disparity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->min_disparity = u_min_disparity.real;
      offset += sizeof(this->min_disparity);
      union {
        float real;
        uint32_t base;
      } u_max_disparity;
      u_max_disparity.base = 0;
      u_max_disparity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_max_disparity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_max_disparity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_max_disparity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->max_disparity = u_max_disparity.real;
      offset += sizeof(this->max_disparity);
      union {
        float real;
        uint32_t base;
      } u_delta_d;
      u_delta_d.base = 0;
      u_delta_d.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_delta_d.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_delta_d.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_delta_d.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->delta_d = u_delta_d.real;
      offset += sizeof(this->delta_d);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->image.serializedLength();
      length += sizeof(this->f);
      length += sizeof(this->T);
      length += this->valid_window.serializedLength();
      length += sizeof(this->min_disparity);
      length += sizeof(this->max_disparity);
      length += sizeof(this->delta_d);
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      string_echo += "\"image\":";
      string_echo += this->image.echo();
      string_echo += ",";
      std::stringstream ss_f; ss_f << "\"f\":" << f <<",";
      string_echo += ss_f.str();
      std::stringstream ss_T; ss_T << "\"T\":" << T <<",";
      string_echo += ss_T.str();
      string_echo += "\"valid_window\":";
      string_echo += this->valid_window.echo();
      string_echo += ",";
      std::stringstream ss_min_disparity; ss_min_disparity << "\"min_disparity\":" << min_disparity <<",";
      string_echo += ss_min_disparity.str();
      std::stringstream ss_max_disparity; ss_max_disparity << "\"max_disparity\":" << max_disparity <<",";
      string_echo += ss_max_disparity.str();
      std::stringstream ss_delta_d; ss_delta_d << "\"delta_d\":" << delta_d <<"";
      string_echo += ss_delta_d.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "stereo_msgs/DisparityImage"; }
    static std::string getTypeStatic(){ return "stereo_msgs/DisparityImage"; }
    virtual std::string getMD5(){ return "03545cef8df8d20bea21fdbbf9482b4b"; }
    static std::string getMD5Static(){ return "03545cef8df8d20bea21fdbbf9482b4b"; }
    virtual std::string getDefinition(){ return "Header header\nsensor_msgs/Image image\nfloat32 f\nfloat32 T\nsensor_msgs/RegionOfInterest valid_window\nfloat32 min_disparity\nfloat32 max_disparity\nfloat32 delta_d\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nsensor_msgs/Image image\nfloat32 f\nfloat32 T\nsensor_msgs/RegionOfInterest valid_window\nfloat32 min_disparity\nfloat32 max_disparity\nfloat32 delta_d\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::stereo_msgs::DisparityImage> Ptr;
    typedef std::shared_ptr<tinyros::stereo_msgs::DisparityImage const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::stereo_msgs::DisparityImage> DisparityImagePtr;
typedef std::shared_ptr<tinyros::stereo_msgs::DisparityImage const> DisparityImageConstPtr;

}
}
#endif
