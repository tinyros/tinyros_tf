#ifndef _TINYROS_std_msgs_Float64MultiArray_h
#define _TINYROS_std_msgs_Float64MultiArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/MultiArrayLayout.h"

namespace tinyros
{
namespace std_msgs
{

  class Float64MultiArray : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::MultiArrayLayout _layout_type;
      _layout_type layout;
      uint32_t data_length;
      typedef double _data_type;
      _data_type st_data;
      _data_type * data;

    Float64MultiArray():
      layout(),
      data_length(0), data(NULL)
    {
    }

    ~Float64MultiArray()
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
          double real;
          uint64_t base;
        } u_datai;
        u_datai.real = this->data[i];
        *(outbuffer + offset + 0) = (u_datai.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_datai.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_datai.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_datai.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_datai.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_datai.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_datai.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_datai.base >> (8 * 7)) & 0xFF;
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
        this->data = (double*)realloc(this->data, data_lengthT * sizeof(double));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_data;
        u_st_data.base = 0;
        u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_data.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_data = u_st_data.real;
        offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(double));
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

    virtual tinyros::string getType(){ return "std_msgs/Float64MultiArray"; }
    static tinyros::string getTypeStatic(){ return "std_msgs/Float64MultiArray"; }
    virtual tinyros::string getMD5(){ return "e3061da26924f3790a70f9dbf06fc1a5"; }
    static tinyros::string getMD5Static(){ return "e3061da26924f3790a70f9dbf06fc1a5"; }
    virtual tinyros::string getDefinition(){ return "MultiArrayLayout  layout        \nfloat64[]         data          \n"; }
    static tinyros::string getDefinitionStatic(){ return "MultiArrayLayout  layout        \nfloat64[]         data          \n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
