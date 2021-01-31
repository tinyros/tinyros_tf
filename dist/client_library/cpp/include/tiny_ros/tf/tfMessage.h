#ifndef _TINYROS_tf_tfMessage_h
#define _TINYROS_tf_tfMessage_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/geometry_msgs/TransformStamped.h"

namespace tinyros
{
namespace tf
{

  class tfMessage : public tinyros::Msg
  {
    public:
      typedef tinyros::geometry_msgs::TransformStamped _transforms_type;
      std::vector<_transforms_type> transforms;

    tfMessage():
      transforms(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t transforms_length = this->transforms.size();
      *(outbuffer + offset + 0) = (transforms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (transforms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (transforms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (transforms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++) {
        offset += this->transforms[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t transforms_length = ((uint32_t) (*(inbuffer + offset))); 
      transforms_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      transforms_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      transforms_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->transforms.resize(transforms_length); 
      offset += sizeof(transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++) {
        offset += this->transforms[i].deserialize(inbuffer + offset);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t transforms_length = this->transforms.size();
      length += sizeof(transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++) {
        length += this->transforms[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      uint32_t transforms_length = this->transforms.size();
      string_echo += "transforms:[";
      for( uint32_t i = 0; i < transforms_length; i++) {
        if( i == (transforms_length - 1)) {
          string_echo += this->transforms[i].echo();
          string_echo += "";
        } else {
          string_echo += this->transforms[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "tf/tfMessage"; }
    static std::string getTypeStatic(){ return "tf/tfMessage"; }
    virtual std::string getMD5(){ return "0401e4f6583aa665321e471e02ec671b"; }
    static std::string getMD5Static(){ return "0401e4f6583aa665321e471e02ec671b"; }
    virtual std::string getDefinition(){ return "geometry_msgs/TransformStamped[] transforms\n"; }
    static std::string getDefinitionStatic(){ return "geometry_msgs/TransformStamped[] transforms\n"; }
    static bool hasHeader(){ return false; }
  };

typedef std::shared_ptr<tinyros::tf::tfMessage> tfMessagePtr;
typedef std::shared_ptr<tinyros::tf::tfMessage const> tfMessageConstPtr;

}
}
#endif
