#ifndef _TINYROS_geometry_msgs_TwistWithCovarianceStamped_h
#define _TINYROS_geometry_msgs_TwistWithCovarianceStamped_h

#include <stdint.h>
#include <string>
#include <stdio.h>
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

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      string_echo += "\"twist\":";
      string_echo += this->twist.echo();
      string_echo += "";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "geometry_msgs/TwistWithCovarianceStamped"; }
    static std::string getTypeStatic(){ return "geometry_msgs/TwistWithCovarianceStamped"; }
    virtual std::string getMD5(){ return "2cbcab62cac39de1d1d01785b99ba778"; }
    static std::string getMD5Static(){ return "2cbcab62cac39de1d1d01785b99ba778"; }
    virtual std::string getDefinition(){ return "Header header\nTwistWithCovariance twist\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nTwistWithCovariance twist\n"; }
    static bool hasHeader(){ return true; }
  };

typedef std::shared_ptr<tinyros::geometry_msgs::TwistWithCovarianceStamped> TwistWithCovarianceStampedPtr;
typedef std::shared_ptr<tinyros::geometry_msgs::TwistWithCovarianceStamped const> TwistWithCovarianceStampedConstPtr;

}
}
#endif
