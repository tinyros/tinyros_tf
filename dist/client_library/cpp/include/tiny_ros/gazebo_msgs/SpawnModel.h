#ifndef _TINYROS_SERVICE_SpawnModel_h
#define _TINYROS_SERVICE_SpawnModel_h
#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/geometry_msgs/Pose.h"

namespace tinyros
{
namespace gazebo_msgs
{

static const char SPAWNMODEL[] = "gazebo_msgs/SpawnModel";

  class SpawnModelRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef std::string _model_name_type;
      _model_name_type model_name;
      typedef std::string _model_xml_type;
      _model_xml_type model_xml;
      typedef std::string _robot_namespace_type;
      _robot_namespace_type robot_namespace;
      typedef tinyros::geometry_msgs::Pose _initial_pose_type;
      _initial_pose_type initial_pose;
      typedef std::string _reference_frame_type;
      _reference_frame_type reference_frame;

    SpawnModelRequest():
      model_name(""),
      model_xml(""),
      robot_namespace(""),
      initial_pose(),
      reference_frame("")
    {
      this->__id__ = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->__id__ >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->__id__ >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->__id__ >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->__id__ >> (8 * 3)) & 0xFF;
      offset += sizeof(this->__id__);
      uint32_t length_model_name = this->model_name.size();
      varToArr(outbuffer + offset, length_model_name);
      offset += 4;
      memcpy(outbuffer + offset, this->model_name.c_str(), length_model_name);
      offset += length_model_name;
      uint32_t length_model_xml = this->model_xml.size();
      varToArr(outbuffer + offset, length_model_xml);
      offset += 4;
      memcpy(outbuffer + offset, this->model_xml.c_str(), length_model_xml);
      offset += length_model_xml;
      uint32_t length_robot_namespace = this->robot_namespace.size();
      varToArr(outbuffer + offset, length_robot_namespace);
      offset += 4;
      memcpy(outbuffer + offset, this->robot_namespace.c_str(), length_robot_namespace);
      offset += length_robot_namespace;
      offset += this->initial_pose.serialize(outbuffer + offset);
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
      this->__id__ =  ((uint32_t) (*(inbuffer + offset)));
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->__id__);
      uint32_t length_model_name;
      arrToVar(length_model_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model_name-1]=0;
      this->model_name = (char *)(inbuffer + offset-1);
      offset += length_model_name;
      uint32_t length_model_xml;
      arrToVar(length_model_xml, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model_xml; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model_xml-1]=0;
      this->model_xml = (char *)(inbuffer + offset-1);
      offset += length_model_xml;
      uint32_t length_robot_namespace;
      arrToVar(length_robot_namespace, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot_namespace; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot_namespace-1]=0;
      this->robot_namespace = (char *)(inbuffer + offset-1);
      offset += length_robot_namespace;
      offset += this->initial_pose.deserialize(inbuffer + offset);
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
      uint32_t length_model_xml = this->model_xml.size();
      length += 4;
      length += length_model_xml;
      uint32_t length_robot_namespace = this->robot_namespace.size();
      length += 4;
      length += length_robot_namespace;
      length += this->initial_pose.serializedLength();
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
      std::size_t model_xml_pos = model_xml.find("\"");
      while(model_xml_pos != std::string::npos){
        model_xml.replace(model_xml_pos, 1,"\\\"");
        model_xml_pos = model_xml.find("\"", model_xml_pos+2);
      }
      string_echo += "\"model_xml\":\"";
      string_echo += model_xml;
      string_echo += "\",";
      std::size_t robot_namespace_pos = robot_namespace.find("\"");
      while(robot_namespace_pos != std::string::npos){
        robot_namespace.replace(robot_namespace_pos, 1,"\\\"");
        robot_namespace_pos = robot_namespace.find("\"", robot_namespace_pos+2);
      }
      string_echo += "\"robot_namespace\":\"";
      string_echo += robot_namespace;
      string_echo += "\",";
      string_echo += "\"initial_pose\":";
      string_echo += this->initial_pose.echo();
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

    virtual std::string getType(){ return SPAWNMODEL; }
    static std::string getTypeStatic(){ return SPAWNMODEL; }
    virtual std::string getMD5(){ return "da34e61c8813e52ac159e5f31fbf55be"; }
    static std::string getMD5Static(){ return "da34e61c8813e52ac159e5f31fbf55be"; }
    virtual std::string getDefinition(){ return "string model_name\nstring model_xml\nstring robot_namespace\ngeometry_msgs/Pose initial_pose\nstring reference_frame\n"; }
    static std::string getDefinitionStatic(){ return "string model_name\nstring model_xml\nstring robot_namespace\ngeometry_msgs/Pose initial_pose\nstring reference_frame\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::SpawnModelRequest> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::SpawnModelRequest const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::SpawnModelRequest> SpawnModelRequestPtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::SpawnModelRequest const> SpawnModelRequestConstPtr;

  class SpawnModelResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef bool _success_type;
      _success_type success;
      typedef std::string _status_message_type;
      _status_message_type status_message;

    SpawnModelResponse():
      success(0),
      status_message("")
    {
      this->__id__ = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->__id__ >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->__id__ >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->__id__ >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->__id__ >> (8 * 3)) & 0xFF;
      offset += sizeof(this->__id__);
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_status_message = this->status_message.size();
      varToArr(outbuffer + offset, length_status_message);
      offset += 4;
      memcpy(outbuffer + offset, this->status_message.c_str(), length_status_message);
      offset += length_status_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->__id__ =  ((uint32_t) (*(inbuffer + offset)));
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->__id__ |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->__id__);
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_status_message;
      arrToVar(length_status_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status_message; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status_message-1]=0;
      this->status_message = (char *)(inbuffer + offset-1);
      offset += length_status_message;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->success);
      uint32_t length_status_message = this->status_message.size();
      length += 4;
      length += length_status_message;
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::stringstream ss_success; ss_success << "\"success\":" << success <<",";
      string_echo += ss_success.str();
      std::size_t status_message_pos = status_message.find("\"");
      while(status_message_pos != std::string::npos){
        status_message.replace(status_message_pos, 1,"\\\"");
        status_message_pos = status_message.find("\"", status_message_pos+2);
      }
      string_echo += "\"status_message\":\"";
      string_echo += status_message;
      string_echo += "\"";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return SPAWNMODEL; }
    static std::string getTypeStatic(){ return SPAWNMODEL; }
    virtual std::string getMD5(){ return "d59d46cc4e5a64f978a429dd7c306d30"; }
    static std::string getMD5Static(){ return "d59d46cc4e5a64f978a429dd7c306d30"; }
    virtual std::string getDefinition(){ return "bool success\nstring status_message\n"; }
    static std::string getDefinitionStatic(){ return "bool success\nstring status_message\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::SpawnModelResponse> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::SpawnModelResponse const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::SpawnModelResponse> SpawnModelResponsePtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::SpawnModelResponse const> SpawnModelResponseConstPtr;

  class SpawnModel {
    public:
    typedef SpawnModelRequest Request;
    typedef SpawnModelResponse Response;
  };

}
}
#endif
