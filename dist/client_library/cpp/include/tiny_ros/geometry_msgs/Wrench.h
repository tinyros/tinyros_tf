#ifndef _TINYROS_geometry_msgs_Wrench_h
#define _TINYROS_geometry_msgs_Wrench_h

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

  class Wrench : public tinyros::Msg
  {
    public:
      typedef tinyros::geometry_msgs::Vector3 _force_type;
      _force_type force;
      typedef tinyros::geometry_msgs::Vector3 _torque_type;
      _torque_type torque;

    Wrench():
      force(),
      torque()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->force.serialize(outbuffer + offset);
      offset += this->torque.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->force.deserialize(inbuffer + offset);
      offset += this->torque.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->force.serializedLength();
      length += this->torque.serializedLength();
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"force\":";
      string_echo += this->force.echo();
      string_echo += ",";
      string_echo += "\"torque\":";
      string_echo += this->torque.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "geometry_msgs/Wrench"; }
    static std::string getTypeStatic(){ return "geometry_msgs/Wrench"; }
    virtual std::string getMD5(){ return "02d01d4a8dc253c7b42d4c9866201aee"; }
    static std::string getMD5Static(){ return "02d01d4a8dc253c7b42d4c9866201aee"; }
    virtual std::string getDefinition(){ return "Vector3  force\nVector3  torque\n"; }
    static std::string getDefinitionStatic(){ return "Vector3  force\nVector3  torque\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::geometry_msgs::Wrench> Ptr;
    typedef std::shared_ptr<tinyros::geometry_msgs::Wrench const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::geometry_msgs::Wrench> WrenchPtr;
typedef std::shared_ptr<tinyros::geometry_msgs::Wrench const> WrenchConstPtr;

}
}
#endif
