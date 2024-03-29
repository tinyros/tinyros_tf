#ifndef _TINYROS_sensor_msgs_JoyFeedback_h
#define _TINYROS_sensor_msgs_JoyFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace sensor_msgs
{

  class JoyFeedback : public tinyros::Msg
  {
    public:
      typedef uint8_t _type_type;
      _type_type type;
      typedef uint8_t _id_type;
      _id_type id;
      typedef float _intensity_type;
      _intensity_type intensity;
      enum { TYPE_LED =  0 };
      enum { TYPE_RUMBLE =  1 };
      enum { TYPE_BUZZER =  2 };

    JoyFeedback():
      type(0),
      id(0),
      intensity(0)
    {
    }

    ~JoyFeedback()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      union {
        float real;
        uint32_t base;
      } u_intensity;
      u_intensity.real = this->intensity;
      *(outbuffer + offset + 0) = (u_intensity.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_intensity.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_intensity.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_intensity.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->intensity);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
      union {
        float real;
        uint32_t base;
      } u_intensity;
      u_intensity.base = 0;
      u_intensity.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_intensity.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_intensity.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_intensity.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->intensity = u_intensity.real;
      offset += sizeof(this->intensity);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->type);
      length += sizeof(this->id);
      length += sizeof(this->intensity);
      return length;
    }

    virtual tinyros::string getType(){ return "sensor_msgs/JoyFeedback"; }
    static tinyros::string getTypeStatic(){ return "sensor_msgs/JoyFeedback"; }
    virtual tinyros::string getMD5(){ return "206b65e86c8b195f816ccbe40b3568a2"; }
    static tinyros::string getMD5Static(){ return "206b65e86c8b195f816ccbe40b3568a2"; }
    virtual tinyros::string getDefinition(){ return "uint8 type\nuint8 id\nfloat32 intensity\n"; }
    static tinyros::string getDefinitionStatic(){ return "uint8 type\nuint8 id\nfloat32 intensity\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
