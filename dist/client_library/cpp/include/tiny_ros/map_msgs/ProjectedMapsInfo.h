#ifndef _TINYROS_SERVICE_ProjectedMapsInfo_h
#define _TINYROS_SERVICE_ProjectedMapsInfo_h
#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/map_msgs/ProjectedMapInfo.h"

namespace tinyros
{
namespace map_msgs
{

static const char PROJECTEDMAPSINFO[] = "map_msgs/ProjectedMapsInfo";

  class ProjectedMapsInfoRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef tinyros::map_msgs::ProjectedMapInfo _projected_maps_info_type;
      std::vector<_projected_maps_info_type> projected_maps_info;

    ProjectedMapsInfoRequest():
      projected_maps_info(0)
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
      uint32_t projected_maps_info_length = this->projected_maps_info.size();
      *(outbuffer + offset + 0) = (projected_maps_info_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (projected_maps_info_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (projected_maps_info_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (projected_maps_info_length >> (8 * 3)) & 0xFF;
      offset += sizeof(projected_maps_info_length);
      for( uint32_t i = 0; i < projected_maps_info_length; i++) {
        offset += this->projected_maps_info[i].serialize(outbuffer + offset);
      }
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
      uint32_t projected_maps_info_length = ((uint32_t) (*(inbuffer + offset))); 
      projected_maps_info_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      projected_maps_info_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      projected_maps_info_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->projected_maps_info.resize(projected_maps_info_length); 
      offset += sizeof(projected_maps_info_length);
      for( uint32_t i = 0; i < projected_maps_info_length; i++) {
        offset += this->projected_maps_info[i].deserialize(inbuffer + offset);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t projected_maps_info_length = this->projected_maps_info.size();
      length += sizeof(projected_maps_info_length);
      for( uint32_t i = 0; i < projected_maps_info_length; i++) {
        length += this->projected_maps_info[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      uint32_t projected_maps_info_length = this->projected_maps_info.size();
      string_echo += "projected_maps_info:[";
      for( uint32_t i = 0; i < projected_maps_info_length; i++) {
        if( i == (projected_maps_info_length - 1)) {
          string_echo += this->projected_maps_info[i].echo();
          string_echo += "";
        } else {
          string_echo += this->projected_maps_info[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return PROJECTEDMAPSINFO; }
    static std::string getTypeStatic(){ return PROJECTEDMAPSINFO; }
    virtual std::string getMD5(){ return "59778fc7286f314a408be52b4611a8b4"; }
    static std::string getMD5Static(){ return "59778fc7286f314a408be52b4611a8b4"; }
    virtual std::string getDefinition(){ return "map_msgs/ProjectedMapInfo[] projected_maps_info\n"; }
    static std::string getDefinitionStatic(){ return "map_msgs/ProjectedMapInfo[] projected_maps_info\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::map_msgs::ProjectedMapsInfoRequest> Ptr;
    typedef std::shared_ptr<tinyros::map_msgs::ProjectedMapsInfoRequest const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::map_msgs::ProjectedMapsInfoRequest> ProjectedMapsInfoRequestPtr;
typedef std::shared_ptr<tinyros::map_msgs::ProjectedMapsInfoRequest const> ProjectedMapsInfoRequestConstPtr;

  class ProjectedMapsInfoResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:

    ProjectedMapsInfoResponse()
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

    virtual std::string getType(){ return PROJECTEDMAPSINFO; }
    static std::string getTypeStatic(){ return PROJECTEDMAPSINFO; }
    virtual std::string getMD5(){ return "223a7c48f052c5181dd525823dcc67fc"; }
    static std::string getMD5Static(){ return "223a7c48f052c5181dd525823dcc67fc"; }
    virtual std::string getDefinition(){ return ""; }
    static std::string getDefinitionStatic(){ return ""; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::map_msgs::ProjectedMapsInfoResponse> Ptr;
    typedef std::shared_ptr<tinyros::map_msgs::ProjectedMapsInfoResponse const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::map_msgs::ProjectedMapsInfoResponse> ProjectedMapsInfoResponsePtr;
typedef std::shared_ptr<tinyros::map_msgs::ProjectedMapsInfoResponse const> ProjectedMapsInfoResponseConstPtr;

  class ProjectedMapsInfo {
    public:
    typedef ProjectedMapsInfoRequest Request;
    typedef ProjectedMapsInfoResponse Response;
  };

}
}
#endif
