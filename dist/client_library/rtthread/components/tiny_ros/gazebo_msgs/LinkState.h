#ifndef _TINYROS_gazebo_msgs_LinkState_h
#define _TINYROS_gazebo_msgs_LinkState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/geometry_msgs/Pose.h"
#include "tiny_ros/geometry_msgs/Twist.h"

namespace tinyros
{
namespace gazebo_msgs
{

  class LinkState : public tinyros::Msg
  {
    public:
      typedef tinyros::string _link_name_type;
      _link_name_type link_name;
      typedef tinyros::geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef tinyros::geometry_msgs::Twist _twist_type;
      _twist_type twist;
      typedef tinyros::string _reference_frame_type;
      _reference_frame_type reference_frame;

    LinkState():
      link_name(""),
      pose(),
      twist(),
      reference_frame("")
    {
    }

    ~LinkState()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_link_name = this->link_name.size();
      varToArr(outbuffer + offset, length_link_name);
      offset += 4;
      memcpy(outbuffer + offset, this->link_name.c_str(), length_link_name);
      offset += length_link_name;
      offset += this->pose.serialize(outbuffer + offset);
      offset += this->twist.serialize(outbuffer + offset);
      uint32_t length_reference_frame = this->reference_frame.size();
      varToArr(outbuffer + offset, length_reference_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->reference_frame.c_str(), length_reference_frame);
      offset += length_reference_frame;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_link_name;
      arrToVar(length_link_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_name-1]=0;
      this->link_name = (char *)(inbuffer + offset-1);
      offset += length_link_name;
      offset += this->pose.deserialize(inbuffer + offset);
      offset += this->twist.deserialize(inbuffer + offset);
      uint32_t length_reference_frame;
      arrToVar(length_reference_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_reference_frame; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_reference_frame-1]=0;
      this->reference_frame = (char *)(inbuffer + offset-1);
      offset += length_reference_frame;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_link_name = this->link_name.size();
      length += 4;
      length += length_link_name;
      length += this->pose.serializedLength();
      length += this->twist.serializedLength();
      uint32_t length_reference_frame = this->reference_frame.size();
      length += 4;
      length += length_reference_frame;
      return length;
    }

    virtual tinyros::string getType(){ return "gazebo_msgs/LinkState"; }
    static tinyros::string getTypeStatic(){ return "gazebo_msgs/LinkState"; }
    virtual tinyros::string getMD5(){ return "eb3584856a5c068877b12eba5fc9372d"; }
    static tinyros::string getMD5Static(){ return "eb3584856a5c068877b12eba5fc9372d"; }
    virtual tinyros::string getDefinition(){ return "string link_name            \ngeometry_msgs/Pose pose     \ngeometry_msgs/Twist twist   \nstring reference_frame      \n"; }
    static tinyros::string getDefinitionStatic(){ return "string link_name            \ngeometry_msgs/Pose pose     \ngeometry_msgs/Twist twist   \nstring reference_frame      \n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
