#ifndef _TINYROS_std_msgs_Float32MultiArray_h
#define _TINYROS_std_msgs_Float32MultiArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/MultiArrayLayout.h"

namespace tinyros
{
namespace std_msgs
{

  class Float32MultiArray : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::MultiArrayLayout _layout_type;
      _layout_type layout;
      uint32_t data_length;
      typedef float _data_type;
      _data_type st_data;
      _data_type * data;

    Float32MultiArray():
      layout(),
      data_length(0), data(NULL)
    {
    }

    ~Float32MultiArray()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(data != NULL)
      {
        free(data);
      }
      data = NULL;
      data_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->layout.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++) {
        union {
          float real;
          uint32_t base;
        } u_datai;
        u_datai.real = this->data[i];
        *(outbuffer + offset + 0) = (u_datai.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_datai.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_datai.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_datai.base >> (8 * 3)) & 0xFF;
        offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->layout.deserialize(inbuffer + offset);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (float*)realloc(this->data, data_lengthT * sizeof(float));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++) {
        union {
          float real;
          uint32_t base;
        } u_st_data;
        u_st_data.base = 0;
        u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_data.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
        this->st_data = u_st_data.real;
        offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(float));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->layout.serializedLength();
      length += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++) {
        length += sizeof(this->data[i]);
      }
      return length;
    }

    virtual tinyros::string getType(){ return "std_msgs/Float32MultiArray"; }
    static tinyros::string getTypeStatic(){ return "std_msgs/Float32MultiArray"; }
    virtual tinyros::string getMD5(){ return "224f9a21761656b5f5da2b311973577f"; }
    static tinyros::string getMD5Static(){ return "224f9a21761656b5f5da2b311973577f"; }
    virtual tinyros::string getDefinition(){ return "MultiArrayLayout  layout        \nfloat32[]         data          \n"; }
    static tinyros::string getDefinitionStatic(){ return "MultiArrayLayout  layout        \nfloat32[]         data          \n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
