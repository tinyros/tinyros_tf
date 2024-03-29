#ifndef _TINYROS_SERVICE_SaveMap_h
#define _TINYROS_SERVICE_SaveMap_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/String.h"

namespace tinyros
{
namespace map_msgs
{

static const char SAVEMAP[] = "map_msgs/SaveMap";

  class SaveMapRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef tinyros::std_msgs::String _filename_type;
      _filename_type filename;

    SaveMapRequest():
      filename()
    {
      this->__id__ = 0;
    }

    ~SaveMapRequest()
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
      offset += this->filename.serialize(outbuffer + offset);
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
      offset += this->filename.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->filename.serializedLength();
      return length;
    }

    virtual tinyros::string getType(){ return SAVEMAP; }
    static tinyros::string getTypeStatic(){ return SAVEMAP; }
    virtual tinyros::string getMD5(){ return "6643d8ede81a23998690e6a3ff657316"; }
    static tinyros::string getMD5Static(){ return "6643d8ede81a23998690e6a3ff657316"; }
    virtual tinyros::string getDefinition(){ return "std_msgs/String filename\n"; }
    static tinyros::string getDefinitionStatic(){ return "std_msgs/String filename\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }

  };

  class SaveMapResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:

    SaveMapResponse()
    {
      this->__id__ = 0;
    }

    ~SaveMapResponse()
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

    virtual tinyros::string getType(){ return SAVEMAP; }
    static tinyros::string getTypeStatic(){ return SAVEMAP; }
    virtual tinyros::string getMD5(){ return "9cd07446fa1bd59b4758dadf19f196e9"; }
    static tinyros::string getMD5Static(){ return "9cd07446fa1bd59b4758dadf19f196e9"; }
    virtual tinyros::string getDefinition(){ return ""; }
    static tinyros::string getDefinitionStatic(){ return ""; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }

  };

  class SaveMap {
    public:
    typedef SaveMapRequest Request;
    typedef SaveMapResponse Response;
  };

}
}
#endif
