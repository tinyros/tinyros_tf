#ifndef _TINYROS_geometry_msgs_WrenchStamped_h
#define _TINYROS_geometry_msgs_WrenchStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Wrench.h"

namespace tinyros
{
namespace geometry_msgs
{

  class WrenchStamped : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Wrench _wrench_type;
      _wrench_type wrench;

    WrenchStamped():
      header(),
      wrench()
    {
    }

    ~WrenchStamped()
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
      offset += this->wrench.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->wrench.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->wrench.serializedLength();
      return length;
    }

    virtual tinyros::string getType(){ return "geometry_msgs/WrenchStamped"; }
    static tinyros::string getTypeStatic(){ return "geometry_msgs/WrenchStamped"; }
    virtual tinyros::string getMD5(){ return "cf53874aa63609de4155ec8e9cf2c540"; }
    static tinyros::string getMD5Static(){ return "cf53874aa63609de4155ec8e9cf2c540"; }
    virtual tinyros::string getDefinition(){ return "Header header\nWrench wrench\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\nWrench wrench\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
