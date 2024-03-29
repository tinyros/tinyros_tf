#ifndef _TINYROS_geometry_msgs_PoseArray_h
#define _TINYROS_geometry_msgs_PoseArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Pose.h"

namespace tinyros
{
namespace geometry_msgs
{

  class PoseArray : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      uint32_t poses_length;
      typedef tinyros::geometry_msgs::Pose _poses_type;
      _poses_type st_poses;
      _poses_type * poses;

    PoseArray():
      header(),
      poses_length(0), poses(NULL)
    {
    }

    ~PoseArray()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(poses != NULL)
      {
        for( uint32_t i = 0; i < poses_length; i++){
          poses[i].deconstructor();
        }
        free(poses);
      }
      poses = NULL;
      poses_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->poses_length);
      for( uint32_t i = 0; i < poses_length; i++) {
        offset += this->poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->poses_length);
      if(poses_lengthT > poses_length)
        this->poses = (tinyros::geometry_msgs::Pose*)realloc(this->poses, poses_lengthT * sizeof(tinyros::geometry_msgs::Pose));
      poses_length = poses_lengthT;
      for( uint32_t i = 0; i < poses_length; i++) {
        offset += this->st_poses.deserialize(inbuffer + offset);
        memcpy( &(this->poses[i]), &(this->st_poses), sizeof(tinyros::geometry_msgs::Pose));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += sizeof(this->poses_length);
      for( uint32_t i = 0; i < poses_length; i++) {
        length += this->poses[i].serializedLength();
      }
      return length;
    }

    virtual tinyros::string getType(){ return "geometry_msgs/PoseArray"; }
    static tinyros::string getTypeStatic(){ return "geometry_msgs/PoseArray"; }
    virtual tinyros::string getMD5(){ return "184f43246f3bc9cb5d0613694e6641a6"; }
    static tinyros::string getMD5Static(){ return "184f43246f3bc9cb5d0613694e6641a6"; }
    virtual tinyros::string getDefinition(){ return "Header header\nPose[] poses\n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\nPose[] poses\n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
