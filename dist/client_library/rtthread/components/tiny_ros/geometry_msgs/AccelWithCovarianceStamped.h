#ifndef _TINYROS_geometry_msgs_AccelWithCovarianceStamped_h
#define _TINYROS_geometry_msgs_AccelWithCovarianceStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/AccelWithCovariance.h"

namespace tinyros
{
namespace geometry_msgs
{

  class AccelWithCovarianceStamped : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::AccelWithCovariance _accel_type;
      _accel_type accel;

    AccelWithCovarianceStamped():
      header(),
      accel()
    {
    }

    ~AccelWithCovarianceStamped()
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
      offset += this->accel.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->accel.deserialize(inbuffer + offset);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->accel.serializedLength();
      return length;
    }

    virtual tinyros::string getType(){ return "geometry_msgs/AccelWithCovarianceStamped"; }
    static tinyros::string getTypeStatic(){ return "geometry_msgs/AccelWithCovarianceStamped"; }
    virtual tinyros::string getMD5(){ return "efd9e7d0b5ca262cc8b05aa8e97c984f"; }
    static tinyros::string getMD5Static(){ return "efd9e7d0b5ca262cc8b05aa8e97c984f"; }
    virtual tinyros::string getDefinition(){ return "Header header\nAccelWithCovariance accel\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\nAccelWithCovariance accel\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
