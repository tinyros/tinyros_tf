#ifndef _TINYROS_nav_msgs_MapMetaData_h
#define _TINYROS_nav_msgs_MapMetaData_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/ros/time.h"
#include "tiny_ros/geometry_msgs/Pose.h"

namespace tinyros
{
namespace nav_msgs
{

  class MapMetaData : public tinyros::Msg
  {
    public:
      typedef tinyros::Time _map_load_time_type;
      _map_load_time_type map_load_time;
      typedef float _resolution_type;
      _resolution_type resolution;
      typedef uint32_t _width_type;
      _width_type width;
      typedef uint32_t _height_type;
      _height_type height;
      typedef tinyros::geometry_msgs::Pose _origin_type;
      _origin_type origin;

    MapMetaData():
      map_load_time(),
      resolution(0),
      width(0),
      height(0),
      origin()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->map_load_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->map_load_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->map_load_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->map_load_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->map_load_time.sec);
      *(outbuffer + offset + 0) = (this->map_load_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->map_load_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->map_load_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->map_load_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->map_load_time.nsec);
      union {
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.real = this->resolution;
      *(outbuffer + offset + 0) = (u_resolution.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_resolution.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_resolution.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_resolution.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->resolution);
      *(outbuffer + offset + 0) = (this->width >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->width >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->width >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->width >> (8 * 3)) & 0xFF;
      offset += sizeof(this->width);
      *(outbuffer + offset + 0) = (this->height >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->height >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->height >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->height >> (8 * 3)) & 0xFF;
      offset += sizeof(this->height);
      offset += this->origin.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->map_load_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->map_load_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->map_load_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->map_load_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->map_load_time.sec);
      this->map_load_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->map_load_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->map_load_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->map_load_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->map_load_time.nsec);
      union {
        float real;
        uint32_t base;
      } u_resolution;
      u_resolution.base = 0;
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_resolution.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->resolution = u_resolution.real;
      offset += sizeof(this->resolution);
      this->width =  ((uint32_t) (*(inbuffer + offset)));
      this->width |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->width |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->width |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->width);
      this->height =  ((uint32_t) (*(inbuffer + offset)));
      this->height |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->height |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->height |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->height);
      offset += this->origin.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->map_load_time.sec);
      length += sizeof(this->map_load_time.nsec);
      length += sizeof(this->resolution);
      length += sizeof(this->width);
      length += sizeof(this->height);
      length += this->origin.serializedLength();
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::stringstream ss_map_load_time;
      ss_map_load_time << "\"map_load_time\":{\"sec\":" << map_load_time.sec;
      ss_map_load_time << ",\"nsec\":" << map_load_time.nsec << "},";
      string_echo += ss_map_load_time.str();
      std::stringstream ss_resolution; ss_resolution << "\"resolution\":" << resolution <<",";
      string_echo += ss_resolution.str();
      std::stringstream ss_width; ss_width << "\"width\":" << width <<",";
      string_echo += ss_width.str();
      std::stringstream ss_height; ss_height << "\"height\":" << height <<",";
      string_echo += ss_height.str();
      string_echo += "\"origin\":";
      string_echo += this->origin.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "nav_msgs/MapMetaData"; }
    static std::string getTypeStatic(){ return "nav_msgs/MapMetaData"; }
    virtual std::string getMD5(){ return "328f5a1f2242fff4676d48189bd8b309"; }
    static std::string getMD5Static(){ return "328f5a1f2242fff4676d48189bd8b309"; }
    virtual std::string getDefinition(){ return "time map_load_time\nfloat32 resolution\nuint32 width\nuint32 height\ngeometry_msgs/Pose origin\n"; }
    static std::string getDefinitionStatic(){ return "time map_load_time\nfloat32 resolution\nuint32 width\nuint32 height\ngeometry_msgs/Pose origin\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::nav_msgs::MapMetaData> Ptr;
    typedef std::shared_ptr<tinyros::nav_msgs::MapMetaData const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::nav_msgs::MapMetaData> MapMetaDataPtr;
typedef std::shared_ptr<tinyros::nav_msgs::MapMetaData const> MapMetaDataConstPtr;

}
}
#endif
