#ifndef _TINYROS_geometry_msgs_Pose_h
#define _TINYROS_geometry_msgs_Pose_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/geometry_msgs/Point.h"
#include "tiny_ros/geometry_msgs/Quaternion.h"

namespace tinyros
{
namespace geometry_msgs
{

  class Pose : public tinyros::Msg
  {
    public:
      typedef tinyros::geometry_msgs::Point _position_type;
      _position_type position;
      typedef tinyros::geometry_msgs::Quaternion _orientation_type;
      _orientation_type orientation;

    Pose():
      position(),
      orientation()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->position.serialize(outbuffer + offset);
      offset += this->orientation.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->orientation.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->position.serializedLength();
      length += this->orientation.serializedLength();
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"position\":";
      string_echo += this->position.echo();
      string_echo += ",";
      string_echo += "\"orientation\":";
      string_echo += this->orientation.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "geometry_msgs/Pose"; }
    static std::string getTypeStatic(){ return "geometry_msgs/Pose"; }
    virtual std::string getMD5(){ return "0b42fb88be8cac0efa6e446e13befcae"; }
    static std::string getMD5Static(){ return "0b42fb88be8cac0efa6e446e13befcae"; }
    virtual std::string getDefinition(){ return "Point position\nQuaternion orientation\n"; }
    static std::string getDefinitionStatic(){ return "Point position\nQuaternion orientation\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::geometry_msgs::Pose> Ptr;
    typedef std::shared_ptr<tinyros::geometry_msgs::Pose const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::geometry_msgs::Pose> PosePtr;
typedef std::shared_ptr<tinyros::geometry_msgs::Pose const> PoseConstPtr;

}
}
#endif
