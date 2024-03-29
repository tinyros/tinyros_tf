#ifndef _TINYROS_tf_tfMessage_h
#define _TINYROS_tf_tfMessage_h

#include <stdint.h>
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
      uint32_t transforms_length;
      typedef tinyros::geometry_msgs::TransformStamped _transforms_type;
      _transforms_type st_transforms;
      _transforms_type * transforms;

    tfMessage():
      transforms_length(0), transforms(NULL)
    {
    }

    ~tfMessage()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(transforms != NULL)
      {
        for( uint32_t i = 0; i < transforms_length; i++){
          transforms[i].deconstructor();
        }
        free(transforms);
      }
      transforms = NULL;
      transforms_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->transforms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->transforms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->transforms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->transforms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++) {
        offset += this->transforms[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t transforms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->transforms_length);
      if(transforms_lengthT > transforms_length)
        this->transforms = (tinyros::geometry_msgs::TransformStamped*)realloc(this->transforms, transforms_lengthT * sizeof(tinyros::geometry_msgs::TransformStamped));
      transforms_length = transforms_lengthT;
      for( uint32_t i = 0; i < transforms_length; i++) {
        offset += this->st_transforms.deserialize(inbuffer + offset);
        memcpy( &(this->transforms[i]), &(this->st_transforms), sizeof(tinyros::geometry_msgs::TransformStamped));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++) {
        length += this->transforms[i].serializedLength();
      }
      return length;
    }

    virtual tinyros::string getType(){ return "tf/tfMessage"; }
    static tinyros::string getTypeStatic(){ return "tf/tfMessage"; }
    virtual tinyros::string getMD5(){ return "0401e4f6583aa665321e471e02ec671b"; }
    static tinyros::string getMD5Static(){ return "0401e4f6583aa665321e471e02ec671b"; }
    virtual tinyros::string getDefinition(){ return "geometry_msgs/TransformStamped[] transforms\n"; }
    static tinyros::string getDefinitionStatic(){ return "geometry_msgs/TransformStamped[] transforms\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
