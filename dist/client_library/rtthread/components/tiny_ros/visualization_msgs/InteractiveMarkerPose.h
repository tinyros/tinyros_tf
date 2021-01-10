#ifndef _TINYROS_visualization_msgs_InteractiveMarkerPose_h
#define _TINYROS_visualization_msgs_InteractiveMarkerPose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Pose.h"

namespace tinyros
{
namespace visualization_msgs
{

  class InteractiveMarkerPose : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef tinyros::string _name_type;
      _name_type name;

    InteractiveMarkerPose():
      header(),
      pose(),
      name("")
    {
    }

    ~InteractiveMarkerPose()
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
      offset += this->pose.serialize(outbuffer + offset);
      uint32_t length_name = this->name.size();
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name.c_str(), length_name);
      offset += length_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += this->pose.serializedLength();
      uint32_t length_name = this->name.size();
      length += 4;
      length += length_name;
      return length;
    }

    virtual tinyros::string getType(){ return "visualization_msgs/InteractiveMarkerPose"; }
    static tinyros::string getTypeStatic(){ return "visualization_msgs/InteractiveMarkerPose"; }
    virtual tinyros::string getMD5(){ return "d719f99881759f7a03f9f5411bdb7074"; }
    static tinyros::string getMD5Static(){ return "d719f99881759f7a03f9f5411bdb7074"; }
    virtual tinyros::string getDefinition(){ return "Header header\ngeometry_msgs/Pose pose\nstring name\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\ngeometry_msgs/Pose pose\nstring name\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
