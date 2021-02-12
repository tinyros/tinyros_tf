#ifndef _TINYROS_std_msgs_MultiArrayLayout_h
#define _TINYROS_std_msgs_MultiArrayLayout_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/MultiArrayDimension.h"

namespace tinyros
{
namespace std_msgs
{

  class MultiArrayLayout : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::MultiArrayDimension _dim_type;
      std::vector<_dim_type> dim;
      typedef uint32_t _data_offset_type;
      _data_offset_type data_offset;

    MultiArrayLayout():
      dim(0),
      data_offset(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t dim_length = this->dim.size();
      *(outbuffer + offset + 0) = (dim_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (dim_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (dim_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (dim_length >> (8 * 3)) & 0xFF;
      offset += sizeof(dim_length);
      for( uint32_t i = 0; i < dim_length; i++) {
        offset += this->dim[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->data_offset >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_offset >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_offset >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_offset >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t dim_length = ((uint32_t) (*(inbuffer + offset))); 
      dim_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      dim_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      dim_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->dim.resize(dim_length); 
      offset += sizeof(dim_length);
      for( uint32_t i = 0; i < dim_length; i++) {
        offset += this->dim[i].deserialize(inbuffer + offset);
      }
      this->data_offset =  ((uint32_t) (*(inbuffer + offset)));
      this->data_offset |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data_offset |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->data_offset |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->data_offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t dim_length = this->dim.size();
      length += sizeof(dim_length);
      for( uint32_t i = 0; i < dim_length; i++) {
        length += this->dim[i].serializedLength();
      }
      length += sizeof(this->data_offset);
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      uint32_t dim_length = this->dim.size();
      string_echo += "dim:[";
      for( uint32_t i = 0; i < dim_length; i++) {
        if( i == (dim_length - 1)) {
          string_echo += this->dim[i].echo();
          string_echo += "";
        } else {
          string_echo += this->dim[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "],";
      std::stringstream ss_data_offset; ss_data_offset << "\"data_offset\":" << data_offset <<"";
      string_echo += ss_data_offset.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "std_msgs/MultiArrayLayout"; }
    static std::string getTypeStatic(){ return "std_msgs/MultiArrayLayout"; }
    virtual std::string getMD5(){ return "f40f0b5b285a93ca167c98c1012a989a"; }
    static std::string getMD5Static(){ return "f40f0b5b285a93ca167c98c1012a989a"; }
    virtual std::string getDefinition(){ return "MultiArrayDimension[] dim\nuint32 data_offset\n"; }
    static std::string getDefinitionStatic(){ return "MultiArrayDimension[] dim\nuint32 data_offset\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::std_msgs::MultiArrayLayout> Ptr;
    typedef std::shared_ptr<tinyros::std_msgs::MultiArrayLayout const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::std_msgs::MultiArrayLayout> MultiArrayLayoutPtr;
typedef std::shared_ptr<tinyros::std_msgs::MultiArrayLayout const> MultiArrayLayoutConstPtr;

}
}
#endif
