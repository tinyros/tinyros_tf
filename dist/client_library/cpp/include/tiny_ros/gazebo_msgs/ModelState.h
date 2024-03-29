#ifndef _TINYROS_gazebo_msgs_ModelState_h
#define _TINYROS_gazebo_msgs_ModelState_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/geometry_msgs/Pose.h"
#include "tiny_ros/geometry_msgs/Twist.h"

namespace tinyros
{
namespace gazebo_msgs
{

  class ModelState : public tinyros::Msg
  {
    public:
      typedef std::string _model_name_type;
      _model_name_type model_name;
      typedef tinyros::geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef tinyros::geometry_msgs::Twist _twist_type;
      _twist_type twist;
      typedef std::string _reference_frame_type;
      _reference_frame_type reference_frame;

    ModelState():
      model_name(""),
      pose(),
      twist(),
      reference_frame("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_model_name = this->model_name.size();
      varToArr(outbuffer + offset, length_model_name);
      offset += 4;
      memcpy(outbuffer + offset, this->model_name.c_str(), length_model_name);
      offset += length_model_name;
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
      uint32_t length_model_name;
      arrToVar(length_model_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model_name-1]=0;
      this->model_name = (char *)(inbuffer + offset-1);
      offset += length_model_name;
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
      uint32_t length_model_name = this->model_name.size();
      length += 4;
      length += length_model_name;
      length += this->pose.serializedLength();
      length += this->twist.serializedLength();
      uint32_t length_reference_frame = this->reference_frame.size();
      length += 4;
      length += length_reference_frame;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::size_t model_name_pos = model_name.find("\"");
      while(model_name_pos != std::string::npos){
        model_name.replace(model_name_pos, 1,"\\\"");
        model_name_pos = model_name.find("\"", model_name_pos+2);
      }
      string_echo += "\"model_name\":\"";
      string_echo += model_name;
      string_echo += "\",";
      string_echo += "\"pose\":";
      string_echo += this->pose.echo();
      string_echo += ",";
      string_echo += "\"twist\":";
      string_echo += this->twist.echo();
      string_echo += ",";
      std::size_t reference_frame_pos = reference_frame.find("\"");
      while(reference_frame_pos != std::string::npos){
        reference_frame.replace(reference_frame_pos, 1,"\\\"");
        reference_frame_pos = reference_frame.find("\"", reference_frame_pos+2);
      }
      string_echo += "\"reference_frame\":\"";
      string_echo += reference_frame;
      string_echo += "\"";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "gazebo_msgs/ModelState"; }
    static std::string getTypeStatic(){ return "gazebo_msgs/ModelState"; }
    virtual std::string getMD5(){ return "dee4d802363b4d6bd1ed61e20c2c4635"; }
    static std::string getMD5Static(){ return "dee4d802363b4d6bd1ed61e20c2c4635"; }
    virtual std::string getDefinition(){ return "string model_name\ngeometry_msgs/Pose pose\ngeometry_msgs/Twist twist\nstring reference_frame\n"; }
    static std::string getDefinitionStatic(){ return "string model_name\ngeometry_msgs/Pose pose\ngeometry_msgs/Twist twist\nstring reference_frame\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::ModelState> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::ModelState const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::ModelState> ModelStatePtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::ModelState const> ModelStateConstPtr;

}
}
#endif
