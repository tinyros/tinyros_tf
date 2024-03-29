#ifndef _TINYROS_geometry_msgs_Accel_h
#define _TINYROS_geometry_msgs_Accel_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/geometry_msgs/Vector3.h"

namespace tinyros
{
namespace geometry_msgs
{

  class Accel : public tinyros::Msg
  {
    public:
      typedef tinyros::geometry_msgs::Vector3 _linear_type;
      _linear_type linear;
      typedef tinyros::geometry_msgs::Vector3 _angular_type;
      _angular_type angular;

    Accel():
      linear(),
      angular()
    {
    }

    ~Accel()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->linear.serialize(outbuffer + offset);
      offset += this->angular.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->linear.deserialize(inbuffer + offset);
      offset += this->angular.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->linear.serializedLength();
      length += this->angular.serializedLength();
      return length;
    }

    virtual tinyros::string getType(){ return "geometry_msgs/Accel"; }
    static tinyros::string getTypeStatic(){ return "geometry_msgs/Accel"; }
    virtual tinyros::string getMD5(){ return "580cbad5f3bd2e9f0ca71e14b7ab1b0f"; }
    static tinyros::string getMD5Static(){ return "580cbad5f3bd2e9f0ca71e14b7ab1b0f"; }
    virtual tinyros::string getDefinition(){ return "Vector3  linear\nVector3  angular\n"; }
    static tinyros::string getDefinitionStatic(){ return "Vector3  linear\nVector3  angular\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
