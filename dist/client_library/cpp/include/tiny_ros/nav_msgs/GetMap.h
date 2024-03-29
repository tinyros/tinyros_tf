#ifndef _TINYROS_SERVICE_GetMap_h
#define _TINYROS_SERVICE_GetMap_h
#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/nav_msgs/OccupancyGrid.h"

namespace tinyros
{
namespace nav_msgs
{

static const char GETMAP[] = "nav_msgs/GetMap";

  class GetMapRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:

    GetMapRequest()
    {
      this->__id__ = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->__id__ >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->__id__ >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->__id__ >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->__id__ >> (8 * 3)) & 0xFF;
      offset += sizeof(this->__id__);
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
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return GETMAP; }
    static std::string getTypeStatic(){ return GETMAP; }
    virtual std::string getMD5(){ return "8ea512c109a0b3a9eca8de407dd02d2a"; }
    static std::string getMD5Static(){ return "8ea512c109a0b3a9eca8de407dd02d2a"; }
    virtual std::string getDefinition(){ return ""; }
    static std::string getDefinitionStatic(){ return ""; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::nav_msgs::GetMapRequest> Ptr;
    typedef std::shared_ptr<tinyros::nav_msgs::GetMapRequest const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::nav_msgs::GetMapRequest> GetMapRequestPtr;
typedef std::shared_ptr<tinyros::nav_msgs::GetMapRequest const> GetMapRequestConstPtr;

  class GetMapResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef tinyros::nav_msgs::OccupancyGrid _map_type;
      _map_type map;

    GetMapResponse():
      map()
    {
      this->__id__ = 0;
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
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->map.serializedLength();
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"map\":";
      string_echo += this->map.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return GETMAP; }
    static std::string getTypeStatic(){ return GETMAP; }
    virtual std::string getMD5(){ return "5bf895a6cdaff312c69ca1cef20fed64"; }
    static std::string getMD5Static(){ return "5bf895a6cdaff312c69ca1cef20fed64"; }
    virtual std::string getDefinition(){ return "nav_msgs/OccupancyGrid map\n"; }
    static std::string getDefinitionStatic(){ return "nav_msgs/OccupancyGrid map\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::nav_msgs::GetMapResponse> Ptr;
    typedef std::shared_ptr<tinyros::nav_msgs::GetMapResponse const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::nav_msgs::GetMapResponse> GetMapResponsePtr;
typedef std::shared_ptr<tinyros::nav_msgs::GetMapResponse const> GetMapResponseConstPtr;

  class GetMap {
    public:
    typedef GetMapRequest Request;
    typedef GetMapResponse Response;
  };

}
}
#endif
