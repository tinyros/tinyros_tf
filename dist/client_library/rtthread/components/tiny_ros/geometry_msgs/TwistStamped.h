#ifndef _TINYROS_geometry_msgs_TwistStamped_h
#define _TINYROS_geometry_msgs_TwistStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Twist.h"

namespace tinyros
{
namespace geometry_msgs
{

  class TwistStamped : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Twist _twist_type;
      _twist_type twist;

    TwistStamped():
      header(),
      twist()
    {
    }

    ~TwistStamped()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->twist.serializedLength();
      return length;
    }

    virtual tinyros::string getType(){ return "geometry_msgs/TwistStamped"; }
    static tinyros::string getTypeStatic(){ return "geometry_msgs/TwistStamped"; }
    virtual tinyros::string getMD5(){ return "2e3e0a57a69306091cb5c65e92d048e1"; }
    static tinyros::string getMD5Static(){ return "2e3e0a57a69306091cb5c65e92d048e1"; }
    virtual tinyros::string getDefinition(){ return "Header header\nTwist twist\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\nTwist twist\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
