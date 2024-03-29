#ifndef _TINYROS_geometry_msgs_Pose_h
#define _TINYROS_geometry_msgs_Pose_h

#include <stdint.h>
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

    ~Pose()
    {
      deconstructor();
    }

    void deconstructor()
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

    virtual tinyros::string getType(){ return "geometry_msgs/Pose"; }
    static tinyros::string getTypeStatic(){ return "geometry_msgs/Pose"; }
    virtual tinyros::string getMD5(){ return "0b42fb88be8cac0efa6e446e13befcae"; }
    static tinyros::string getMD5Static(){ return "0b42fb88be8cac0efa6e446e13befcae"; }
    virtual tinyros::string getDefinition(){ return "Point position\nQuaternion orientation\n"; }
    static tinyros::string getDefinitionStatic(){ return "Point position\nQuaternion orientation\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
