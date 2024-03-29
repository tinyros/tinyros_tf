#ifndef _TINYROS_geometry_msgs_Twist_h
#define _TINYROS_geometry_msgs_Twist_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/geometry_msgs/Vector3.h"

namespace tinyros
{
namespace geometry_msgs
{

  class Twist : public tinyros::Msg
  {
    public:
      typedef tinyros::geometry_msgs::Vector3 _linear_type;
      _linear_type linear;
      typedef tinyros::geometry_msgs::Vector3 _angular_type;
      _angular_type angular;

    Twist():
      linear(),
      angular()
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

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"linear\":";
      string_echo += this->linear.echo();
      string_echo += ",";
      string_echo += "\"angular\":";
      string_echo += this->angular.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "geometry_msgs/Twist"; }
    static std::string getTypeStatic(){ return "geometry_msgs/Twist"; }
    virtual std::string getMD5(){ return "29e7e4839b73f684ad08b19dc12c9c70"; }
    static std::string getMD5Static(){ return "29e7e4839b73f684ad08b19dc12c9c70"; }
    virtual std::string getDefinition(){ return "Vector3  linear\nVector3  angular\n"; }
    static std::string getDefinitionStatic(){ return "Vector3  linear\nVector3  angular\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::geometry_msgs::Twist> Ptr;
    typedef std::shared_ptr<tinyros::geometry_msgs::Twist const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::geometry_msgs::Twist> TwistPtr;
typedef std::shared_ptr<tinyros::geometry_msgs::Twist const> TwistConstPtr;

}
}
#endif
