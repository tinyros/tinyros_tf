#ifndef _TINYROS_sensor_msgs_PointField_h
#define _TINYROS_sensor_msgs_PointField_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace sensor_msgs
{

  class PointField : public tinyros::Msg
  {
    public:
      typedef tinyros::string _name_type;
      _name_type name;
      typedef uint32_t _offset_type;
      _offset_type offset;
      typedef uint8_t _datatype_type;
      _datatype_type datatype;
      typedef uint32_t _count_type;
      _count_type count;
      enum { INT8 =  1 };
      enum { UINT8 =  2 };
      enum { INT16 =  3 };
      enum { UINT16 =  4 };
      enum { INT32 =  5 };
      enum { UINT32 =  6 };
      enum { FLOAT32 =  7 };
      enum { FLOAT64 =  8 };

    PointField():
      name(""),
      offset(0),
      datatype(0),
      count(0)
    {
    }

    ~PointField()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = this->name.size();
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name.c_str(), length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->offset >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->offset >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->offset >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->offset >> (8 * 3)) & 0xFF;
      offset += sizeof(this->offset);
      *(outbuffer + offset + 0) = (this->datatype >> (8 * 0)) & 0xFF;
      offset += sizeof(this->datatype);
      *(outbuffer + offset + 0) = (this->count >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->count >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->count >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->count >> (8 * 3)) & 0xFF;
      offset += sizeof(this->count);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      this->offset =  ((uint32_t) (*(inbuffer + offset)));
      this->offset |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->offset |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->offset |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->offset);
      this->datatype =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->datatype);
      this->count =  ((uint32_t) (*(inbuffer + offset)));
      this->count |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->count |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->count |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->count);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_name = this->name.size();
      length += 4;
      length += length_name;
      length += sizeof(this->offset);
      length += sizeof(this->datatype);
      length += sizeof(this->count);
      return length;
    }

    virtual tinyros::string getType(){ return "sensor_msgs/PointField"; }
    static tinyros::string getTypeStatic(){ return "sensor_msgs/PointField"; }
    virtual tinyros::string getMD5(){ return "039974f05fdf0470d9dc865fd01dcc3e"; }
    static tinyros::string getMD5Static(){ return "039974f05fdf0470d9dc865fd01dcc3e"; }
    virtual tinyros::string getDefinition(){ return "string name      \nuint32 offset    \nuint8  datatype  \nuint32 count     \n"; }
    static tinyros::string getDefinitionStatic(){ return "string name      \nuint32 offset    \nuint8  datatype  \nuint32 count     \n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
