#ifndef _TINYROS_std_msgs_UInt32MultiArray_h
#define _TINYROS_std_msgs_UInt32MultiArray_h

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

  class UInt32MultiArray : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::MultiArrayLayout _layout_type;
      _layout_type layout;
      typedef uint32_t _data_type;
      std::vector<_data_type> data;

    UInt32MultiArray():
      layout(),
      data(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->layout.serialize(outbuffer + offset);
      uint32_t data_length = this->data.size();
      *(outbuffer + offset + 0) = (data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(data_length);
      for( uint32_t i = 0; i < data_length; i++) {
        *(outbuffer + offset + 0) = (this->data[i] >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (this->data[i] >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (this->data[i] >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (this->data[i] >> (8 * 3)) & 0xFF;
        offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->layout.deserialize(inbuffer + offset);
      uint32_t data_length = ((uint32_t) (*(inbuffer + offset))); 
      data_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->data.resize(data_length); 
      offset += sizeof(data_length);
      for( uint32_t i = 0; i < data_length; i++) {
        this->data[i] =  ((uint32_t) (*(inbuffer + offset)));
        this->data[i] |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
        this->data[i] |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
        this->data[i] |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
        offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->layout.serializedLength();
      uint32_t data_length = this->data.size();
      length += sizeof(data_length);
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
      uint32_t data_length = this->data.size();
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

    virtual std::string getType(){ return "std_msgs/UInt32MultiArray"; }
    static std::string getTypeStatic(){ return "std_msgs/UInt32MultiArray"; }
    virtual std::string getMD5(){ return "eb9320ab0c1ae5878d7ab30676e3083f"; }
    static std::string getMD5Static(){ return "eb9320ab0c1ae5878d7ab30676e3083f"; }
    virtual std::string getDefinition(){ return "MultiArrayLayout  layout\nuint32[]          data\n"; }
    static std::string getDefinitionStatic(){ return "MultiArrayLayout  layout\nuint32[]          data\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::std_msgs::UInt32MultiArray> Ptr;
    typedef std::shared_ptr<tinyros::std_msgs::UInt32MultiArray const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::std_msgs::UInt32MultiArray> UInt32MultiArrayPtr;
typedef std::shared_ptr<tinyros::std_msgs::UInt32MultiArray const> UInt32MultiArrayConstPtr;

}
}
#endif
