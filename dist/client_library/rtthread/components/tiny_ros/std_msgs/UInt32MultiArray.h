#ifndef _TINYROS_std_msgs_UInt32MultiArray_h
#define _TINYROS_std_msgs_UInt32MultiArray_h

#include <stdint.h>
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
      uint32_t data_length;
      typedef uint32_t _data_type;
      _data_type st_data;
      _data_type * data;

    UInt32MultiArray():
      layout(),
      data_length(0), data(NULL)
    {
    }

    ~UInt32MultiArray()
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
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (uint32_t*)realloc(this->data, data_lengthT * sizeof(uint32_t));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++) {
        this->st_data =  ((uint32_t) (*(inbuffer + offset)));
        this->st_data |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
        this->st_data |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
        this->st_data |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
        offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(uint32_t));
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

    virtual tinyros::string getType(){ return "std_msgs/UInt32MultiArray"; }
    static tinyros::string getTypeStatic(){ return "std_msgs/UInt32MultiArray"; }
    virtual tinyros::string getMD5(){ return "eb9320ab0c1ae5878d7ab30676e3083f"; }
    static tinyros::string getMD5Static(){ return "eb9320ab0c1ae5878d7ab30676e3083f"; }
    virtual tinyros::string getDefinition(){ return "MultiArrayLayout  layout        \nuint32[]          data          \n"; }
    static tinyros::string getDefinitionStatic(){ return "MultiArrayLayout  layout        \nuint32[]          data          \n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
