#ifndef _TINYROS_SERVICE_GetPointMap_h
#define _TINYROS_SERVICE_GetPointMap_h
#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/sensor_msgs/PointCloud2.h"

namespace tinyros
{
namespace map_msgs
{

static const char GETPOINTMAP[] = "map_msgs/GetPointMap";

  class GetPointMapRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:

    GetPointMapRequest()
    {
      this->__id__ = 0;
    }

    ~GetPointMapRequest()
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

    virtual std::string getType(){ return GETPOINTMAP; }
    static std::string getTypeStatic(){ return GETPOINTMAP; }
    virtual std::string getMD5(){ return "418d4ee8c9d758b7ef1aab3e068c7568"; }
    static std::string getMD5Static(){ return "418d4ee8c9d758b7ef1aab3e068c7568"; }
    virtual std::string getDefinition(){ return ""; }
    static std::string getDefinitionStatic(){ return ""; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }


    typedef std::shared_ptr<tinyros::map_msgs::GetPointMapRequest> Ptr;
    typedef std::shared_ptr<tinyros::map_msgs::GetPointMapRequest const> ConstPtr;
  };

  class GetPointMapResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef tinyros::sensor_msgs::PointCloud2 _map_type;
      _map_type map;

    GetPointMapResponse():
      map()
    {
      this->__id__ = 0;
    }

    ~GetPointMapResponse()
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

    virtual std::string getType(){ return GETPOINTMAP; }
    static std::string getTypeStatic(){ return GETPOINTMAP; }
    virtual std::string getMD5(){ return "abc97e6c5b25f536248da280bdf271d7"; }
    static std::string getMD5Static(){ return "abc97e6c5b25f536248da280bdf271d7"; }
    virtual std::string getDefinition(){ return "sensor_msgs/PointCloud2 map\n"; }
    static std::string getDefinitionStatic(){ return "sensor_msgs/PointCloud2 map\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }


    typedef std::shared_ptr<tinyros::map_msgs::GetPointMapResponse> Ptr;
    typedef std::shared_ptr<tinyros::map_msgs::GetPointMapResponse const> ConstPtr;
  };

  class GetPointMap {
    public:
    typedef GetPointMapRequest Request;
    typedef GetPointMapResponse Response;
  };

}
}
#endif
