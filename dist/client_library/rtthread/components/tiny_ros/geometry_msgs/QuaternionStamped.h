#ifndef _TINYROS_geometry_msgs_QuaternionStamped_h
#define _TINYROS_geometry_msgs_QuaternionStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Quaternion.h"

namespace tinyros
{
namespace geometry_msgs
{

  class QuaternionStamped : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Quaternion _quaternion_type;
      _quaternion_type quaternion;

    QuaternionStamped():
      header(),
      quaternion()
    {
    }

    ~QuaternionStamped()
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
      offset += this->quaternion.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->quaternion.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->quaternion.serializedLength();
      return length;
    }

    virtual tinyros::string getType(){ return "geometry_msgs/QuaternionStamped"; }
    static tinyros::string getTypeStatic(){ return "geometry_msgs/QuaternionStamped"; }
    virtual tinyros::string getMD5(){ return "69e39922feb9ec6eaf93755f93fce2cf"; }
    static tinyros::string getMD5Static(){ return "69e39922feb9ec6eaf93755f93fce2cf"; }
    virtual tinyros::string getDefinition(){ return "Header header\nQuaternion quaternion\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\nQuaternion quaternion\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
