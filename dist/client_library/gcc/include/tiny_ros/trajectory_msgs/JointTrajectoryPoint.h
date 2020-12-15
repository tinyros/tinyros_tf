#ifndef _TINYROS_trajectory_msgs_JointTrajectoryPoint_h
#define _TINYROS_trajectory_msgs_JointTrajectoryPoint_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/ros/duration.h"

namespace tinyros
{
namespace trajectory_msgs
{

  class JointTrajectoryPoint : public tinyros::Msg
  {
    public:
      uint32_t positions_length;
      typedef double _positions_type;
      _positions_type st_positions;
      _positions_type * positions;
      uint32_t velocities_length;
      typedef double _velocities_type;
      _velocities_type st_velocities;
      _velocities_type * velocities;
      uint32_t accelerations_length;
      typedef double _accelerations_type;
      _accelerations_type st_accelerations;
      _accelerations_type * accelerations;
      uint32_t effort_length;
      typedef double _effort_type;
      _effort_type st_effort;
      _effort_type * effort;
      typedef tinyros::Duration _time_from_start_type;
      _time_from_start_type time_from_start;

    JointTrajectoryPoint():
      positions_length(0), positions(NULL),
      velocities_length(0), velocities(NULL),
      accelerations_length(0), accelerations(NULL),
      effort_length(0), effort(NULL),
      time_from_start()
    {
    }

    ~JointTrajectoryPoint()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(positions != NULL)
      {
        free(positions);
      }
      positions = NULL;
      positions_length = 0;
      if(velocities != NULL)
      {
        free(velocities);
      }
      velocities = NULL;
      velocities_length = 0;
      if(accelerations != NULL)
      {
        free(accelerations);
      }
      accelerations = NULL;
      accelerations_length = 0;
      if(effort != NULL)
      {
        free(effort);
      }
      effort = NULL;
      effort_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->positions_length);
      for( uint32_t i = 0; i < positions_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_positionsi;
        u_positionsi.real = this->positions[i];
        *(outbuffer + offset + 0) = (u_positionsi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_positionsi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_positionsi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_positionsi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_positionsi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_positionsi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_positionsi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_positionsi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->positions[i]);
      }
      *(outbuffer + offset + 0) = (this->velocities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->velocities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->velocities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->velocities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->velocities_length);
      for( uint32_t i = 0; i < velocities_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_velocitiesi;
        u_velocitiesi.real = this->velocities[i];
        *(outbuffer + offset + 0) = (u_velocitiesi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_velocitiesi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_velocitiesi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_velocitiesi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_velocitiesi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_velocitiesi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_velocitiesi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_velocitiesi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->velocities[i]);
      }
      *(outbuffer + offset + 0) = (this->accelerations_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->accelerations_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->accelerations_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->accelerations_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accelerations_length);
      for( uint32_t i = 0; i < accelerations_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_accelerationsi;
        u_accelerationsi.real = this->accelerations[i];
        *(outbuffer + offset + 0) = (u_accelerationsi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_accelerationsi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_accelerationsi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_accelerationsi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_accelerationsi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_accelerationsi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_accelerationsi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_accelerationsi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->accelerations[i]);
      }
      *(outbuffer + offset + 0) = (this->effort_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->effort_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->effort_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->effort_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->effort_length);
      for( uint32_t i = 0; i < effort_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_efforti;
        u_efforti.real = this->effort[i];
        *(outbuffer + offset + 0) = (u_efforti.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_efforti.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_efforti.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_efforti.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_efforti.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_efforti.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_efforti.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_efforti.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->effort[i]);
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
      uint32_t positions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      positions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->positions_length);
      if(positions_lengthT > positions_length)
        this->positions = (double*)realloc(this->positions, positions_lengthT * sizeof(double));
      positions_length = positions_lengthT;
      for( uint32_t i = 0; i < positions_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_positions;
        u_st_positions.base = 0;
        u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_positions.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_positions = u_st_positions.real;
        offset += sizeof(this->st_positions);
        memcpy( &(this->positions[i]), &(this->st_positions), sizeof(double));
      }
      uint32_t velocities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->velocities_length);
      if(velocities_lengthT > velocities_length)
        this->velocities = (double*)realloc(this->velocities, velocities_lengthT * sizeof(double));
      velocities_length = velocities_lengthT;
      for( uint32_t i = 0; i < velocities_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_velocities;
        u_st_velocities.base = 0;
        u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_velocities.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_velocities = u_st_velocities.real;
        offset += sizeof(this->st_velocities);
        memcpy( &(this->velocities[i]), &(this->st_velocities), sizeof(double));
      }
      uint32_t accelerations_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      accelerations_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->accelerations_length);
      if(accelerations_lengthT > accelerations_length)
        this->accelerations = (double*)realloc(this->accelerations, accelerations_lengthT * sizeof(double));
      accelerations_length = accelerations_lengthT;
      for( uint32_t i = 0; i < accelerations_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_accelerations;
        u_st_accelerations.base = 0;
        u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_accelerations.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_accelerations = u_st_accelerations.real;
        offset += sizeof(this->st_accelerations);
        memcpy( &(this->accelerations[i]), &(this->st_accelerations), sizeof(double));
      }
      uint32_t effort_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      effort_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->effort_length);
      if(effort_lengthT > effort_length)
        this->effort = (double*)realloc(this->effort, effort_lengthT * sizeof(double));
      effort_length = effort_lengthT;
      for( uint32_t i = 0; i < effort_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_effort;
        u_st_effort.base = 0;
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_effort.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_effort = u_st_effort.real;
        offset += sizeof(this->st_effort);
        memcpy( &(this->effort[i]), &(this->st_effort), sizeof(double));
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
      length += sizeof(this->positions_length);
      for( uint32_t i = 0; i < positions_length; i++) {
        length += sizeof(this->positions[i]);
      }
      length += sizeof(this->velocities_length);
      for( uint32_t i = 0; i < velocities_length; i++) {
        length += sizeof(this->velocities[i]);
      }
      length += sizeof(this->accelerations_length);
      for( uint32_t i = 0; i < accelerations_length; i++) {
        length += sizeof(this->accelerations[i]);
      }
      length += sizeof(this->effort_length);
      for( uint32_t i = 0; i < effort_length; i++) {
        length += sizeof(this->effort[i]);
      }
      length += sizeof(this->time_from_start.sec);
      length += sizeof(this->time_from_start.nsec);
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "positions:[";
      for( uint32_t i = 0; i < positions_length; i++) {
        if( i == (positions_length - 1)) {
          std::stringstream ss_positionsi; ss_positionsi << positions[i] <<"";
          string_echo += ss_positionsi.str();
        } else {
          std::stringstream ss_positionsi; ss_positionsi << positions[i] <<",";
          string_echo += ss_positionsi.str();
        }
      }
      string_echo += "],";
      string_echo += "velocities:[";
      for( uint32_t i = 0; i < velocities_length; i++) {
        if( i == (velocities_length - 1)) {
          std::stringstream ss_velocitiesi; ss_velocitiesi << velocities[i] <<"";
          string_echo += ss_velocitiesi.str();
        } else {
          std::stringstream ss_velocitiesi; ss_velocitiesi << velocities[i] <<",";
          string_echo += ss_velocitiesi.str();
        }
      }
      string_echo += "],";
      string_echo += "accelerations:[";
      for( uint32_t i = 0; i < accelerations_length; i++) {
        if( i == (accelerations_length - 1)) {
          std::stringstream ss_accelerationsi; ss_accelerationsi << accelerations[i] <<"";
          string_echo += ss_accelerationsi.str();
        } else {
          std::stringstream ss_accelerationsi; ss_accelerationsi << accelerations[i] <<",";
          string_echo += ss_accelerationsi.str();
        }
      }
      string_echo += "],";
      string_echo += "effort:[";
      for( uint32_t i = 0; i < effort_length; i++) {
        if( i == (effort_length - 1)) {
          std::stringstream ss_efforti; ss_efforti << effort[i] <<"";
          string_echo += ss_efforti.str();
        } else {
          std::stringstream ss_efforti; ss_efforti << effort[i] <<",";
          string_echo += ss_efforti.str();
        }
      }
      string_echo += "],";
      std::stringstream ss_time_from_start;
      ss_time_from_start << "\"time_from_start\":{\"sec\":" << time_from_start.sec;
      ss_time_from_start << ",\"nsec\":" << time_from_start.nsec << "}";
      string_echo += ss_time_from_start.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "trajectory_msgs/JointTrajectoryPoint"; }
    static std::string getTypeStatic(){ return "trajectory_msgs/JointTrajectoryPoint"; }
    virtual std::string getMD5(){ return "38679319321341510f6fde7d7f745eb0"; }
    static std::string getMD5Static(){ return "38679319321341510f6fde7d7f745eb0"; }
    virtual std::string getDefinition(){ return "float64[] positions\nfloat64[] velocities\nfloat64[] accelerations\nfloat64[] effort\nduration time_from_start\n"; }
    static std::string getDefinitionStatic(){ return "float64[] positions\nfloat64[] velocities\nfloat64[] accelerations\nfloat64[] effort\nduration time_from_start\n"; }
    static bool hasHeader(){ return false; }


    typedef std::shared_ptr<tinyros::trajectory_msgs::JointTrajectoryPoint> Ptr;
    typedef std::shared_ptr<tinyros::trajectory_msgs::JointTrajectoryPoint const> ConstPtr;
  };

}
}
#endif