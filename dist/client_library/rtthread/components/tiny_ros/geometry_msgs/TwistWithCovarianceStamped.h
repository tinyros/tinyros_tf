#ifndef _TINYROS_geometry_msgs_TwistWithCovarianceStamped_h
#define _TINYROS_geometry_msgs_TwistWithCovarianceStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/TwistWithCovariance.h"

namespace tinyros
{
namespace geometry_msgs
{

  class TwistWithCovarianceStamped : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::TwistWithCovariance _twist_type;
      _twist_type twist;

    TwistWithCovarianceStamped():
      header(),
      twist()
    {
    }

    ~TwistWithCovarianceStamped()
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

    virtual tinyros::string getType(){ return "geometry_msgs/TwistWithCovarianceStamped"; }
    static tinyros::string getTypeStatic(){ return "geometry_msgs/TwistWithCovarianceStamped"; }
    virtual tinyros::string getMD5(){ return "2cbcab62cac39de1d1d01785b99ba778"; }
    static tinyros::string getMD5Static(){ return "2cbcab62cac39de1d1d01785b99ba778"; }
    virtual tinyros::string getDefinition(){ return "Header header\nTwistWithCovariance twist\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\nTwistWithCovariance twist\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
