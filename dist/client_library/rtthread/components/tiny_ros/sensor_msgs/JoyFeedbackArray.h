#ifndef _TINYROS_sensor_msgs_JoyFeedbackArray_h
#define _TINYROS_sensor_msgs_JoyFeedbackArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/sensor_msgs/JoyFeedback.h"

namespace tinyros
{
namespace sensor_msgs
{

  class JoyFeedbackArray : public tinyros::Msg
  {
    public:
      uint32_t array_length;
      typedef tinyros::sensor_msgs::JoyFeedback _array_type;
      _array_type st_array;
      _array_type * array;

    JoyFeedbackArray():
      array_length(0), array(NULL)
    {
    }

    ~JoyFeedbackArray()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(array != NULL)
      {
        for( uint32_t i = 0; i < array_length; i++){
          array[i].deconstructor();
        }
        free(array);
      }
      array = NULL;
      array_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->array_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->array_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->array_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->array_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->array_length);
      for( uint32_t i = 0; i < array_length; i++) {
        offset += this->array[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t array_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      array_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      array_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      array_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->array_length);
      if(array_lengthT > array_length)
        this->array = (tinyros::sensor_msgs::JoyFeedback*)realloc(this->array, array_lengthT * sizeof(tinyros::sensor_msgs::JoyFeedback));
      array_length = array_lengthT;
      for( uint32_t i = 0; i < array_length; i++) {
        offset += this->st_array.deserialize(inbuffer + offset);
        memcpy( &(this->array[i]), &(this->st_array), sizeof(tinyros::sensor_msgs::JoyFeedback));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->array_length);
      for( uint32_t i = 0; i < array_length; i++) {
        length += this->array[i].serializedLength();
      }
      return length;
    }

    virtual tinyros::string getType(){ return "sensor_msgs/JoyFeedbackArray"; }
    static tinyros::string getTypeStatic(){ return "sensor_msgs/JoyFeedbackArray"; }
    virtual tinyros::string getMD5(){ return "45361e458d526d5670706a9f083819b6"; }
    static tinyros::string getMD5Static(){ return "45361e458d526d5670706a9f083819b6"; }
    virtual tinyros::string getDefinition(){ return "JoyFeedback[] array\n"; }
    static tinyros::string getDefinitionStatic(){ return "JoyFeedback[] array\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
