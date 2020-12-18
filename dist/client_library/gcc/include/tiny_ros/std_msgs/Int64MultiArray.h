#ifndef _TINYROS_std_msgs_Int64MultiArray_h
#define _TINYROS_std_msgs_Int64MultiArray_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/MultiArrayLayout.h"

namespace tinyros
{
namespace std_msgs
{

  class Int64MultiArray : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::MultiArrayLayout _layout_type;
      _layout_type layout;
      uint32_t data_length;
      typedef int64_t _data_type;
      _data_type st_data;
      _data_type * data;

    Int64MultiArray():
      layout(),
      data_length(0), data(NULL)
    {
    }

    ~Int64MultiArray()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(this->data != NULL)
      {
        delete[] this->data;
      }
      this->data = NULL;
      this->data_length = 0;
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
          int64_t real;
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
      if(!this->data || data_lengthT > this->data_length) {
        this->deconstructor();
        this->data = new int64_t[data_lengthT];
      }
      this->data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++) {
        union {
          int64_t real;
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
        this->data[i] = this->st_data;
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

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"layout\":";
      string_echo += this->layout.echo();
      string_echo += ",";
      string_echo += "data:[";
      for( uint32_t i = 0; i < data_length; i++) {
        if( i == (data_length - 1)) {
          std::stringstream ss_datai; ss_datai << data[i] <<"";
          string_echo += ss_datai.str();
        } else {
          std::stringstream ss_datai; ss_datai << data[i] <<",";
          string_echo += ss_datai.str();
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "std_msgs/Int64MultiArray"; }
    static std::string getTypeStatic(){ return "std_msgs/Int64MultiArray"; }
    virtual std::string getMD5(){ return "c06d166bcec6ac0d57a5122b314c9f5c"; }
    static std::string getMD5Static(){ return "c06d166bcec6ac0d57a5122b314c9f5c"; }
    virtual std::string getDefinition(){ return "MultiArrayLayout  layout        \nint64[]           data          \n"; }
    static std::string getDefinitionStatic(){ return "MultiArrayLayout  layout        \nint64[]           data          \n"; }
    static bool hasHeader(){ return false; }
  };

typedef std::shared_ptr<tinyros::std_msgs::Int64MultiArray> Int64MultiArrayPtr;
typedef std::shared_ptr<tinyros::std_msgs::Int64MultiArray const> Int64MultiArrayConstPtr;

}
}
#endif
