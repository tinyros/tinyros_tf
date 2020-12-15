#ifndef _TINYROS_SERVICE_BodyRequest_h
#define _TINYROS_SERVICE_BodyRequest_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace gazebo_msgs
{

static const char BODYREQUEST[] = "gazebo_msgs/BodyRequest";

  class BodyRequestRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef tinyros::string _body_name_type;
      _body_name_type body_name;

    BodyRequestRequest():
      body_name("")
    {
      this->__id__ = 0;
    }

    ~BodyRequestRequest()
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
      uint32_t length_body_name = this->body_name.size();
      varToArr(outbuffer + offset, length_body_name);
      offset += 4;
      memcpy(outbuffer + offset, this->body_name.c_str(), length_body_name);
      offset += length_body_name;
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
      uint32_t length_body_name;
      arrToVar(length_body_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_body_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_body_name-1]=0;
      this->body_name = (char *)(inbuffer + offset-1);
      offset += length_body_name;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_body_name = this->body_name.size();
      length += 4;
      length += length_body_name;
      return length;
    }

    virtual tinyros::string getType(){ return BODYREQUEST; }
    static tinyros::string getTypeStatic(){ return BODYREQUEST; }
    virtual tinyros::string getMD5(){ return "d1c66fbceb0ee1b51e3b09ac030dedec"; }
    static tinyros::string getMD5Static(){ return "d1c66fbceb0ee1b51e3b09ac030dedec"; }
    virtual tinyros::string getDefinition(){ return "string body_name   \n"; }
    static tinyros::string getDefinitionStatic(){ return "string body_name   \n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }

  };

  class BodyRequestResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:

    BodyRequestResponse()
    {
      this->__id__ = 0;
    }

    ~BodyRequestResponse()
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

    virtual tinyros::string getType(){ return BODYREQUEST; }
    static tinyros::string getTypeStatic(){ return BODYREQUEST; }
    virtual tinyros::string getMD5(){ return "e0caf2eb9951542b962f95924c6eeb34"; }
    static tinyros::string getMD5Static(){ return "e0caf2eb9951542b962f95924c6eeb34"; }
    virtual tinyros::string getDefinition(){ return ""; }
    static tinyros::string getDefinitionStatic(){ return ""; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }

  };

  class BodyRequest {
    public:
    typedef BodyRequestRequest Request;
    typedef BodyRequestResponse Response;
  };

}
}
#endif
