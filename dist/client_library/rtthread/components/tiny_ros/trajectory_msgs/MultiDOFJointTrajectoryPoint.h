#ifndef _TINYROS_trajectory_msgs_MultiDOFJointTrajectoryPoint_h
#define _TINYROS_trajectory_msgs_MultiDOFJointTrajectoryPoint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/geometry_msgs/Transform.h"
#include "tiny_ros/geometry_msgs/Twist.h"
#include "tiny_ros/ros/duration.h"

namespace tinyros
{
namespace trajectory_msgs
{

  class MultiDOFJointTrajectoryPoint : public tinyros::Msg
  {
    public:
      uint32_t transforms_length;
      typedef tinyros::geometry_msgs::Transform _transforms_type;
      _transforms_type st_transforms;
      _transforms_type * transforms;
      uint32_t velocities_length;
      typedef tinyros::geometry_msgs::Twist _velocities_type;
      _velocities_type st_velocities;
      _velocities_type * velocities;
      uint32_t accelerations_length;
      typedef tinyros::geometry_msgs::Twist _accelerations_type;
      _accelerations_type st_accelerations;
      _accelerations_type * accelerations;
      typedef tinyros::Duration _time_from_start_type;
      _time_from_start_type time_from_start;

    MultiDOFJointTrajectoryPoint():
      transforms_length(0), transforms(NULL),
      velocities_length(0), velocities(NULL),
      accelerations_length(0), accelerations(NULL),
      time_from_start()
    {
    }

    ~MultiDOFJointTrajectoryPoint()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(transforms != NULL)
      {
        for( uint32_t i = 0; i < transforms_length; i++){
          transforms[i].deconstructor();
        }
        free(transforms);
      }
      transforms = NULL;
      transforms_length = 0;
      if(velocities != NULL)
      {
        for( uint32_t i = 0; i < velocities_length; i++){
          velocities[i].deconstructor();
        }
        free(velocities);
      }
      velocities = NULL;
      velocities_length = 0;
      if(accelerations != NULL)
      {
        for( uint32_t i = 0; i < accelerations_length; i++){
          accelerations[i].deconstructor();
        }
        free(accelerations);
      }
      accelerations = NULL;
      accelerations_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->transforms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->transforms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->transforms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->transforms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++) {
        offset += this->transforms[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->velocities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocities_length);
      for( uint32_t i = 0; i < velocities_length; i++) {
        offset += this->velocities[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->accelerations_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->accelerations_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->accelerations_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->accelerations_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accelerations_length);
      for( uint32_t i = 0; i < accelerations_length; i++) {
        offset += this->accelerations[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->time_from_start.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.sec);
      *(outbuffer + offset + 0) = (this->time_from_start.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_from_start.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_from_start.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_from_start.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_from_start.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t transforms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->transforms_length);
      if(transforms_lengthT > transforms_length)
        this->transforms = (tinyros::geometry_msgs::Transform*)realloc(this->transforms, transforms_lengthT * sizeof(tinyros::geometry_msgs::Transform));
      transforms_length = transforms_lengthT;
      for( uint32_t i = 0; i < transforms_length; i++) {
        offset += this->st_transforms.deserialize(inbuffer + offset);
        memcpy( &(this->transforms[i]), &(this->st_transforms), sizeof(tinyros::geometry_msgs::Transform));
      }
      uint32_t velocities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->velocities_length);
      if(velocities_lengthT > velocities_length)
        this->velocities = (tinyros::geometry_msgs::Twist*)realloc(this->velocities, velocities_lengthT * sizeof(tinyros::geometry_msgs::Twist));
      velocities_length = velocities_lengthT;
      for( uint32_t i = 0; i < velocities_length; i++) {
        offset += this->st_velocities.deserialize(inbuffer + offset);
        memcpy( &(this->velocities[i]), &(this->st_velocities), sizeof(tinyros::geometry_msgs::Twist));
      }
      uint32_t accelerations_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->accelerations_length);
      if(accelerations_lengthT > accelerations_length)
        this->accelerations = (tinyros::geometry_msgs::Twist*)realloc(this->accelerations, accelerations_lengthT * sizeof(tinyros::geometry_msgs::Twist));
      accelerations_length = accelerations_lengthT;
      for( uint32_t i = 0; i < accelerations_length; i++) {
        offset += this->st_accelerations.deserialize(inbuffer + offset);
        memcpy( &(this->accelerations[i]), &(this->st_accelerations), sizeof(tinyros::geometry_msgs::Twist));
      }
      this->time_from_start.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.sec);
      this->time_from_start.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_from_start.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_from_start.nsec);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->transforms_length);
      for( uint32_t i = 0; i < transforms_length; i++) {
        length += this->transforms[i].serializedLength();
      }
      length += sizeof(this->velocities_length);
      for( uint32_t i = 0; i < velocities_length; i++) {
        length += this->velocities[i].serializedLength();
      }
      length += sizeof(this->accelerations_length);
      for( uint32_t i = 0; i < accelerations_length; i++) {
        length += this->accelerations[i].serializedLength();
      }
      length += sizeof(this->time_from_start.sec);
      length += sizeof(this->time_from_start.nsec);
      return length;
    }

    virtual tinyros::string getType(){ return "trajectory_msgs/MultiDOFJointTrajectoryPoint"; }
    static tinyros::string getTypeStatic(){ return "trajectory_msgs/MultiDOFJointTrajectoryPoint"; }
    virtual tinyros::string getMD5(){ return "f8b4a74b416279b5c5d565029308ff08"; }
    static tinyros::string getMD5Static(){ return "f8b4a74b416279b5c5d565029308ff08"; }
    virtual tinyros::string getDefinition(){ return "geometry_msgs/Transform[] transforms\ngeometry_msgs/Twist[] velocities\ngeometry_msgs/Twist[] accelerations\nduration time_from_start\n"; }
    static tinyros::string getDefinitionStatic(){ return "geometry_msgs/Transform[] transforms\ngeometry_msgs/Twist[] velocities\ngeometry_msgs/Twist[] accelerations\nduration time_from_start\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
