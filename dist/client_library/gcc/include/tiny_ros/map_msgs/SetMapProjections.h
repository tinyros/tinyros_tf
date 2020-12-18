#ifndef _TINYROS_SERVICE_SetMapProjections_h
#define _TINYROS_SERVICE_SetMapProjections_h
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

static const char SETMAPPROJECTIONS[] = "map_msgs/SetMapProjections";

  class SetMapProjectionsRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:

    SetMapProjectionsRequest()
    {
      this->__id__ = 0;
    }

    ~SetMapProjectionsRequest()
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

    virtual std::string getType(){ return SETMAPPROJECTIONS; }
    static std::string getTypeStatic(){ return SETMAPPROJECTIONS; }
    virtual std::string getMD5(){ return "26dbba584adf9695d68b8667830be463"; }
    static std::string getMD5Static(){ return "26dbba584adf9695d68b8667830be463"; }
    virtual std::string getDefinition(){ return ""; }
    static std::string getDefinitionStatic(){ return ""; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
  };

typedef std::shared_ptr<tinyros::map_msgs::SetMapProjectionsRequest> SetMapProjectionsRequestPtr;
typedef std::shared_ptr<tinyros::map_msgs::SetMapProjectionsRequest const> SetMapProjectionsRequestConstPtr;

  class SetMapProjectionsResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      uint32_t projected_maps_info_length;
      typedef tinyros::map_msgs::ProjectedMapInfo _projected_maps_info_type;
      _projected_maps_info_type st_projected_maps_info;
      _projected_maps_info_type * projected_maps_info;

    SetMapProjectionsResponse():
      projected_maps_info_length(0), projected_maps_info(NULL)
    {
      this->__id__ = 0;
    }

    ~SetMapProjectionsResponse()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(this->projected_maps_info != NULL)
      {
        for( uint32_t i = 0; i < this->projected_maps_info_length; i++){
          this->projected_maps_info[i].deconstructor();
        }
        delete[] this->projected_maps_info;
      }
      this->projected_maps_info = NULL;
      this->projected_maps_info_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->__id__ >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->__id__ >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->__id__ >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->__id__ >> (8 * 3)) & 0xFF;
      offset += sizeof(this->__id__);
      *(outbuffer + offset + 0) = (this->projected_maps_info_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->projected_maps_info_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->projected_maps_info_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->projected_maps_info_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->projected_maps_info_length);
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
      uint32_t projected_maps_info_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      projected_maps_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      projected_maps_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      projected_maps_info_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->projected_maps_info_length);
      if(!this->projected_maps_info || projected_maps_info_lengthT > this->projected_maps_info_length) {
        this->deconstructor();
        this->projected_maps_info = new tinyros::map_msgs::ProjectedMapInfo[projected_maps_info_lengthT];
      }
      this->projected_maps_info_length = projected_maps_info_lengthT;
      for( uint32_t i = 0; i < projected_maps_info_length; i++) {
        offset += this->st_projected_maps_info.deserialize(inbuffer + offset);
        this->projected_maps_info[i] = this->st_projected_maps_info;
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->projected_maps_info_length);
      for( uint32_t i = 0; i < projected_maps_info_length; i++) {
        length += this->projected_maps_info[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
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

    virtual std::string getType(){ return SETMAPPROJECTIONS; }
    static std::string getTypeStatic(){ return SETMAPPROJECTIONS; }
    virtual std::string getMD5(){ return "47b7931263dc316e5b0f0264428853e9"; }
    static std::string getMD5Static(){ return "47b7931263dc316e5b0f0264428853e9"; }
    virtual std::string getDefinition(){ return "map_msgs/ProjectedMapInfo[] projected_maps_info\n"; }
    static std::string getDefinitionStatic(){ return "map_msgs/ProjectedMapInfo[] projected_maps_info\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
  };

typedef std::shared_ptr<tinyros::map_msgs::SetMapProjectionsResponse> SetMapProjectionsResponsePtr;
typedef std::shared_ptr<tinyros::map_msgs::SetMapProjectionsResponse const> SetMapProjectionsResponseConstPtr;

  class SetMapProjections {
    public:
    typedef SetMapProjectionsRequest Request;
    typedef SetMapProjectionsResponse Response;
  };

}
}
#endif
