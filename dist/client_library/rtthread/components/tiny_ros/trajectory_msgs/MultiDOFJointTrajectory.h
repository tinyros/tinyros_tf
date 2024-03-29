#ifndef _TINYROS_trajectory_msgs_MultiDOFJointTrajectory_h
#define _TINYROS_trajectory_msgs_MultiDOFJointTrajectory_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/trajectory_msgs/MultiDOFJointTrajectoryPoint.h"

namespace tinyros
{
namespace trajectory_msgs
{

  class MultiDOFJointTrajectory : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      uint32_t joint_names_length;
      typedef tinyros::string _joint_names_type;
      _joint_names_type st_joint_names;
      _joint_names_type * joint_names;
      uint32_t points_length;
      typedef tinyros::trajectory_msgs::MultiDOFJointTrajectoryPoint _points_type;
      _points_type st_points;
      _points_type * points;

    MultiDOFJointTrajectory():
      header(),
      joint_names_length(0), joint_names(NULL),
      points_length(0), points(NULL)
    {
    }

    ~MultiDOFJointTrajectory()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(joint_names != NULL)
      {
        free(joint_names);
      }
      joint_names = NULL;
      joint_names_length = 0;
      if(points != NULL)
      {
        for( uint32_t i = 0; i < points_length; i++){
          points[i].deconstructor();
        }
        free(points);
      }
      points = NULL;
      points_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->joint_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_joint_namesi = this->joint_names[i].size();
        varToArr(outbuffer + offset, length_joint_namesi);
        offset += 4;
        memcpy(outbuffer + offset, this->joint_names[i].c_str(), length_joint_namesi);
        offset += length_joint_namesi;
      }
      *(outbuffer + offset + 0) = (this->points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        offset += this->points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t joint_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->joint_names_length);
      if(joint_names_lengthT > joint_names_length)
        this->joint_names = (tinyros::string*)realloc(this->joint_names, joint_names_lengthT * sizeof(tinyros::string));
      joint_names_length = joint_names_lengthT;
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_st_joint_names;
        arrToVar(length_st_joint_names, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_st_joint_names; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_st_joint_names-1]=0;
        this->st_joint_names = (char *)(inbuffer + offset-1);
        offset += length_st_joint_names;
        memcpy( &(this->joint_names[i]), &(this->st_joint_names), sizeof(tinyros::string));
      }
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (tinyros::trajectory_msgs::MultiDOFJointTrajectoryPoint*)realloc(this->points, points_lengthT * sizeof(tinyros::trajectory_msgs::MultiDOFJointTrajectoryPoint));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++) {
        offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(tinyros::trajectory_msgs::MultiDOFJointTrajectoryPoint));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += sizeof(this->joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++) {
        uint32_t length_joint_namesi = this->joint_names[i].size();
        length += 4;
        length += length_joint_namesi;
      }
      length += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++) {
        length += this->points[i].serializedLength();
      }
      return length;
    }

    virtual tinyros::string getType(){ return "trajectory_msgs/MultiDOFJointTrajectory"; }
    static tinyros::string getTypeStatic(){ return "trajectory_msgs/MultiDOFJointTrajectory"; }
    virtual tinyros::string getMD5(){ return "19f97d4cdcae9d0ef55126c1495f6c91"; }
    static tinyros::string getMD5Static(){ return "19f97d4cdcae9d0ef55126c1495f6c91"; }
    virtual tinyros::string getDefinition(){ return "Header header\nstring[] joint_names\nMultiDOFJointTrajectoryPoint[] points\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\nstring[] joint_names\nMultiDOFJointTrajectoryPoint[] points\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
