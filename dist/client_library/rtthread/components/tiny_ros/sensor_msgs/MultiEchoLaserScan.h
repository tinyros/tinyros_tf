#ifndef _TINYROS_sensor_msgs_MultiEchoLaserScan_h
#define _TINYROS_sensor_msgs_MultiEchoLaserScan_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/sensor_msgs/LaserEcho.h"

namespace tinyros
{
namespace sensor_msgs
{

  class MultiEchoLaserScan : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef float _angle_min_type;
      _angle_min_type angle_min;
      typedef float _angle_max_type;
      _angle_max_type angle_max;
      typedef float _angle_increment_type;
      _angle_increment_type angle_increment;
      typedef float _time_increment_type;
      _time_increment_type time_increment;
      typedef float _scan_time_type;
      _scan_time_type scan_time;
      typedef float _range_min_type;
      _range_min_type range_min;
      typedef float _range_max_type;
      _range_max_type range_max;
      uint32_t ranges_length;
      typedef tinyros::sensor_msgs::LaserEcho _ranges_type;
      _ranges_type st_ranges;
      _ranges_type * ranges;
      uint32_t intensities_length;
      typedef tinyros::sensor_msgs::LaserEcho _intensities_type;
      _intensities_type st_intensities;
      _intensities_type * intensities;

    MultiEchoLaserScan():
      header(),
      angle_min(0),
      angle_max(0),
      angle_increment(0),
      time_increment(0),
      scan_time(0),
      range_min(0),
      range_max(0),
      ranges_length(0), ranges(NULL),
      intensities_length(0), intensities(NULL)
    {
    }

    ~MultiEchoLaserScan()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(ranges != NULL)
      {
        for( uint32_t i = 0; i < ranges_length; i++){
          ranges[i].deconstructor();
        }
        free(ranges);
      }
      ranges = NULL;
      ranges_length = 0;
      if(intensities != NULL)
      {
        for( uint32_t i = 0; i < intensities_length; i++){
          intensities[i].deconstructor();
        }
        free(intensities);
      }
      intensities = NULL;
      intensities_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_angle_min;
      u_angle_min.real = this->angle_min;
      *(outbuffer + offset + 0) = (u_angle_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_min.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_min);
      union {
        float real;
        uint32_t base;
      } u_angle_max;
      u_angle_max.real = this->angle_max;
      *(outbuffer + offset + 0) = (u_angle_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_max.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_max);
      union {
        float real;
        uint32_t base;
      } u_angle_increment;
      u_angle_increment.real = this->angle_increment;
      *(outbuffer + offset + 0) = (u_angle_increment.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle_increment.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle_increment.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle_increment.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle_increment);
      union {
        float real;
        uint32_t base;
      } u_time_increment;
      u_time_increment.real = this->time_increment;
      *(outbuffer + offset + 0) = (u_time_increment.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time_increment.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time_increment.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time_increment.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_increment);
      union {
        float real;
        uint32_t base;
      } u_scan_time;
      u_scan_time.real = this->scan_time;
      *(outbuffer + offset + 0) = (u_scan_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_scan_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_scan_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_scan_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->scan_time);
      union {
        float real;
        uint32_t base;
      } u_range_min;
      u_range_min.real = this->range_min;
      *(outbuffer + offset + 0) = (u_range_min.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range_min.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range_min.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range_min.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range_min);
      union {
        float real;
        uint32_t base;
      } u_range_max;
      u_range_max.real = this->range_max;
      *(outbuffer + offset + 0) = (u_range_max.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_range_max.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_range_max.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_range_max.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->range_max);
      *(outbuffer + offset + 0) = (this->ranges_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ranges_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ranges_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ranges_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ranges_length);
      for( uint32_t i = 0; i < ranges_length; i++) {
        offset += this->ranges[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->intensities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->intensities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->intensities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->intensities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->intensities_length);
      for( uint32_t i = 0; i < intensities_length; i++) {
        offset += this->intensities[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_angle_min;
      u_angle_min.base = 0;
      u_angle_min.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_min.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_min.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_min.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_min = u_angle_min.real;
      offset += sizeof(this->angle_min);
      union {
        float real;
        uint32_t base;
      } u_angle_max;
      u_angle_max.base = 0;
      u_angle_max.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_max.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_max.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_max.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_max = u_angle_max.real;
      offset += sizeof(this->angle_max);
      union {
        float real;
        uint32_t base;
      } u_angle_increment;
      u_angle_increment.base = 0;
      u_angle_increment.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle_increment.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle_increment.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle_increment.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle_increment = u_angle_increment.real;
      offset += sizeof(this->angle_increment);
      union {
        float real;
        uint32_t base;
      } u_time_increment;
      u_time_increment.base = 0;
      u_time_increment.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time_increment.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time_increment.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time_increment.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->time_increment = u_time_increment.real;
      offset += sizeof(this->time_increment);
      union {
        float real;
        uint32_t base;
      } u_scan_time;
      u_scan_time.base = 0;
      u_scan_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_scan_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_scan_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_scan_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->scan_time = u_scan_time.real;
      offset += sizeof(this->scan_time);
      union {
        float real;
        uint32_t base;
      } u_range_min;
      u_range_min.base = 0;
      u_range_min.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range_min.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range_min.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range_min.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range_min = u_range_min.real;
      offset += sizeof(this->range_min);
      union {
        float real;
        uint32_t base;
      } u_range_max;
      u_range_max.base = 0;
      u_range_max.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_range_max.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_range_max.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_range_max.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->range_max = u_range_max.real;
      offset += sizeof(this->range_max);
      uint32_t ranges_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      ranges_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      ranges_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      ranges_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->ranges_length);
      if(ranges_lengthT > ranges_length)
        this->ranges = (tinyros::sensor_msgs::LaserEcho*)realloc(this->ranges, ranges_lengthT * sizeof(tinyros::sensor_msgs::LaserEcho));
      ranges_length = ranges_lengthT;
      for( uint32_t i = 0; i < ranges_length; i++) {
        offset += this->st_ranges.deserialize(inbuffer + offset);
        memcpy( &(this->ranges[i]), &(this->st_ranges), sizeof(tinyros::sensor_msgs::LaserEcho));
      }
      uint32_t intensities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      intensities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      intensities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      intensities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->intensities_length);
      if(intensities_lengthT > intensities_length)
        this->intensities = (tinyros::sensor_msgs::LaserEcho*)realloc(this->intensities, intensities_lengthT * sizeof(tinyros::sensor_msgs::LaserEcho));
      intensities_length = intensities_lengthT;
      for( uint32_t i = 0; i < intensities_length; i++) {
        offset += this->st_intensities.deserialize(inbuffer + offset);
        memcpy( &(this->intensities[i]), &(this->st_intensities), sizeof(tinyros::sensor_msgs::LaserEcho));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += sizeof(this->angle_min);
      length += sizeof(this->angle_max);
      length += sizeof(this->angle_increment);
      length += sizeof(this->time_increment);
      length += sizeof(this->scan_time);
      length += sizeof(this->range_min);
      length += sizeof(this->range_max);
      length += sizeof(this->ranges_length);
      for( uint32_t i = 0; i < ranges_length; i++) {
        length += this->ranges[i].serializedLength();
      }
      length += sizeof(this->intensities_length);
      for( uint32_t i = 0; i < intensities_length; i++) {
        length += this->intensities[i].serializedLength();
      }
      return length;
    }

    virtual tinyros::string getType(){ return "sensor_msgs/MultiEchoLaserScan"; }
    static tinyros::string getTypeStatic(){ return "sensor_msgs/MultiEchoLaserScan"; }
    virtual tinyros::string getMD5(){ return "92f3933b4fa486e3889b461437899bf5"; }
    static tinyros::string getMD5Static(){ return "92f3933b4fa486e3889b461437899bf5"; }
    virtual tinyros::string getDefinition(){ return "Header header            \nfloat32 angle_min        \nfloat32 angle_max        \nfloat32 angle_increment  \nfloat32 time_increment   \nfloat32 scan_time        \nfloat32 range_min        \nfloat32 range_max        \nLaserEcho[] ranges       \nLaserEcho[] intensities  \n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header            \nfloat32 angle_min        \nfloat32 angle_max        \nfloat32 angle_increment  \nfloat32 time_increment   \nfloat32 scan_time        \nfloat32 range_min        \nfloat32 range_max        \nLaserEcho[] ranges       \nLaserEcho[] intensities  \n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
