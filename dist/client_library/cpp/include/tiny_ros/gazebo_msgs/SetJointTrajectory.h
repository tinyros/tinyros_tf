#ifndef _TINYROS_SERVICE_SetJointTrajectory_h
#define _TINYROS_SERVICE_SetJointTrajectory_h
#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/trajectory_msgs/JointTrajectory.h"
#include "tiny_ros/geometry_msgs/Pose.h"

namespace tinyros
{
namespace gazebo_msgs
{

static const char SETJOINTTRAJECTORY[] = "gazebo_msgs/SetJointTrajectory";

  class SetJointTrajectoryRequest : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef std::string _model_name_type;
      _model_name_type model_name;
      typedef tinyros::trajectory_msgs::JointTrajectory _joint_trajectory_type;
      _joint_trajectory_type joint_trajectory;
      typedef tinyros::geometry_msgs::Pose _model_pose_type;
      _model_pose_type model_pose;
      typedef bool _set_model_pose_type;
      _set_model_pose_type set_model_pose;
      typedef bool _disable_physics_updates_type;
      _disable_physics_updates_type disable_physics_updates;

    SetJointTrajectoryRequest():
      model_name(""),
      joint_trajectory(),
      model_pose(),
      set_model_pose(0),
      disable_physics_updates(0)
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
      offset += this->joint_trajectory.serialize(outbuffer + offset);
      offset += this->model_pose.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_set_model_pose;
      u_set_model_pose.real = this->set_model_pose;
      *(outbuffer + offset + 0) = (u_set_model_pose.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->set_model_pose);
      union {
        bool real;
        uint8_t base;
      } u_disable_physics_updates;
      u_disable_physics_updates.real = this->disable_physics_updates;
      *(outbuffer + offset + 0) = (u_disable_physics_updates.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->disable_physics_updates);
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
      offset += this->joint_trajectory.deserialize(inbuffer + offset);
      offset += this->model_pose.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_set_model_pose;
      u_set_model_pose.base = 0;
      u_set_model_pose.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->set_model_pose = u_set_model_pose.real;
      offset += sizeof(this->set_model_pose);
      union {
        bool real;
        uint8_t base;
      } u_disable_physics_updates;
      u_disable_physics_updates.base = 0;
      u_disable_physics_updates.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->disable_physics_updates = u_disable_physics_updates.real;
      offset += sizeof(this->disable_physics_updates);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_model_name = this->model_name.size();
      length += 4;
      length += length_model_name;
      length += this->joint_trajectory.serializedLength();
      length += this->model_pose.serializedLength();
      length += sizeof(this->set_model_pose);
      length += sizeof(this->disable_physics_updates);
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
      string_echo += "\"joint_trajectory\":";
      string_echo += this->joint_trajectory.echo();
      string_echo += ",";
      string_echo += "\"model_pose\":";
      string_echo += this->model_pose.echo();
      string_echo += ",";
      std::stringstream ss_set_model_pose; ss_set_model_pose << "\"set_model_pose\":" << set_model_pose <<",";
      string_echo += ss_set_model_pose.str();
      std::stringstream ss_disable_physics_updates; ss_disable_physics_updates << "\"disable_physics_updates\":" << disable_physics_updates <<"";
      string_echo += ss_disable_physics_updates.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return SETJOINTTRAJECTORY; }
    static std::string getTypeStatic(){ return SETJOINTTRAJECTORY; }
    virtual std::string getMD5(){ return "8230e1fcc0295d8d21fbd5df0ccb0af3"; }
    static std::string getMD5Static(){ return "8230e1fcc0295d8d21fbd5df0ccb0af3"; }
    virtual std::string getDefinition(){ return "string model_name\ntrajectory_msgs/JointTrajectory joint_trajectory\ngeometry_msgs/Pose model_pose\nbool set_model_pose\nbool disable_physics_updates\n"; }
    static std::string getDefinitionStatic(){ return "string model_name\ntrajectory_msgs/JointTrajectory joint_trajectory\ngeometry_msgs/Pose model_pose\nbool set_model_pose\nbool disable_physics_updates\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::SetJointTrajectoryRequest> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::SetJointTrajectoryRequest const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::SetJointTrajectoryRequest> SetJointTrajectoryRequestPtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::SetJointTrajectoryRequest const> SetJointTrajectoryRequestConstPtr;

  class SetJointTrajectoryResponse : public tinyros::Msg
  {
    private:
      typedef uint32_t ___id___type;
      ___id___type __id__;

    public:
      typedef bool _success_type;
      _success_type success;
      typedef std::string _status_message_type;
      _status_message_type status_message;

    SetJointTrajectoryResponse():
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

    virtual std::string getType(){ return SETJOINTTRAJECTORY; }
    static std::string getTypeStatic(){ return SETJOINTTRAJECTORY; }
    virtual std::string getMD5(){ return "2f5fe47400272efd54556969ffe63e7e"; }
    static std::string getMD5Static(){ return "2f5fe47400272efd54556969ffe63e7e"; }
    virtual std::string getDefinition(){ return "bool success\nstring status_message\n"; }
    static std::string getDefinitionStatic(){ return "bool success\nstring status_message\n"; }
    static bool hasHeader(){ return false; }
    uint32_t getID() const { return this->__id__; }
    void setID(uint32_t id){ this->__id__ = id; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::SetJointTrajectoryResponse> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::SetJointTrajectoryResponse const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::SetJointTrajectoryResponse> SetJointTrajectoryResponsePtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::SetJointTrajectoryResponse const> SetJointTrajectoryResponseConstPtr;

  class SetJointTrajectory {
    public:
    typedef SetJointTrajectoryRequest Request;
    typedef SetJointTrajectoryResponse Response;
  };

}
}
#endif
