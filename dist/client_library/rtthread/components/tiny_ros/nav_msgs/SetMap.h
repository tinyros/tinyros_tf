#ifndef _TINYROS_SERVICE_SetMap_h
#define _TINYROS_SERVICE_SetMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/nav_msgs/OccupancyGrid.h"
#include "tiny_ros/geometry_msgs/PoseWithCovarianceStamped.h"

namespace tinyros
{
namespace nav_msgs
{

static const char SETMAP[] = "nav_msgs/SetMap";

  class SetMapRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef tinyros::nav_msgs::OccupancyGrid _map_type;
      _map_type map;
      typedef tinyros::geometry_msgs::PoseWithCovarianceStamped _initial_pose_type;
      _initial_pose_type initial_pose;

    SetMapRequest():
      map(),
      initial_pose()
    {
      this->__id__ = 0;
    }

    ~SetMapRequest()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->__id__ >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->__id__ >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->__id__ >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->__id__ >> (8 * 3)) & 0xFF;
      offset += sizeof(this->__id__);
      offset += this->map.serialize(outbuffer + offset);
      offset += this->initial_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->__id__ =  ((uint32_t) (*(inbuffer + offset)));
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->__id__);
      offset += this->map.deserialize(inbuffer + offset);
      offset += this->initial_pose.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->map.serializedLength();
      length += this->initial_pose.serializedLength();
      return length;
    }

    virtual tinyros::string getType(){ return SETMAP; }
    static tinyros::string getTypeStatic(){ return SETMAP; }
    virtual tinyros::string getMD5(){ return "946e1bd68c9db117a530a571e33d9e49"; }
    static tinyros::string getMD5Static(){ return "946e1bd68c9db117a530a571e33d9e49"; }
    virtual tinyros::string getDefinition(){ return "nav_msgs/OccupancyGrid map\ngeometry_msgs/PoseWithCovarianceStamped initial_pose\n"; }
    static tinyros::string getDefinitionStatic(){ return "nav_msgs/OccupancyGrid map\ngeometry_msgs/PoseWithCovarianceStamped initial_pose\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }

  };

  class SetMapResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef bool _success_type;
      _success_type success;

    SetMapResponse():
      success(0)
    {
      this->__id__ = 0;
    }

    ~SetMapResponse()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->__id__ >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->__id__ >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->__id__ >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->__id__ >> (8 * 3)) & 0xFF;
      offset += sizeof(this->__id__);
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->__id__ =  ((uint32_t) (*(inbuffer + offset)));
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->__id__);
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->success);
      return length;
    }

    virtual tinyros::string getType(){ return SETMAP; }
    static tinyros::string getTypeStatic(){ return SETMAP; }
    virtual tinyros::string getMD5(){ return "1e32607e79013262dafbbac9044e9cda"; }
    static tinyros::string getMD5Static(){ return "1e32607e79013262dafbbac9044e9cda"; }
    virtual tinyros::string getDefinition(){ return "bool success\n"; }
    static tinyros::string getDefinitionStatic(){ return "bool success\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }

  };

  class SetMap {
    public:
    typedef SetMapRequest Request;
    typedef SetMapResponse Response;
  };

}
}
#endif
