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
      typedef double _positions_type;
      std::vector<_positions_type> positions;
      typedef double _velocities_type;
      std::vector<_velocities_type> velocities;
      typedef double _accelerations_type;
      std::vector<_accelerations_type> accelerations;
      typedef double _effort_type;
      std::vector<_effort_type> effort;
      typedef tinyros::Duration _time_from_start_type;
      _time_from_start_type time_from_start;

    JointTrajectoryPoint():
      positions(0),
      velocities(0),
      accelerations(0),
      effort(0),
      time_from_start()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t positions_length = this->positions.size();
      *(outbuffer + offset + 0) = (positions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (positions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (positions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (positions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(positions_length);
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
      uint32_t velocities_length = this->velocities.size();
      *(outbuffer + offset + 0) = (velocities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (velocities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (velocities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (velocities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(velocities_length);
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
      uint32_t accelerations_length = this->accelerations.size();
      *(outbuffer + offset + 0) = (accelerations_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (accelerations_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (accelerations_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (accelerations_length >> (8 * 3)) & 0xFF;
      offset += sizeof(accelerations_length);
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
      uint32_t effort_length = this->effort.size();
      *(outbuffer + offset + 0) = (effort_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (effort_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (effort_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (effort_length >> (8 * 3)) & 0xFF;
      offset += sizeof(effort_length);
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
      uint32_t positions_length = ((uint32_t) (*(inbuffer + offset))); 
      positions_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      positions_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      positions_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->positions.resize(positions_length); 
      offset += sizeof(positions_length);
      for( uint32_t i = 0; i < positions_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_positionsi;
        u_positionsi.base = 0;
        u_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_positionsi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->positions[i] = u_positionsi.real;
        offset += sizeof(this->positions[i]);
      }
      uint32_t velocities_length = ((uint32_t) (*(inbuffer + offset))); 
      velocities_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      velocities_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      velocities_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->velocities.resize(velocities_length); 
      offset += sizeof(velocities_length);
      for( uint32_t i = 0; i < velocities_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_velocitiesi;
        u_velocitiesi.base = 0;
        u_velocitiesi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_velocitiesi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_velocitiesi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_velocitiesi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_velocitiesi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_velocitiesi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_velocitiesi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_velocitiesi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->velocities[i] = u_velocitiesi.real;
        offset += sizeof(this->velocities[i]);
      }
      uint32_t accelerations_length = ((uint32_t) (*(inbuffer + offset))); 
      accelerations_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      accelerations_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      accelerations_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->accelerations.resize(accelerations_length); 
      offset += sizeof(accelerations_length);
      for( uint32_t i = 0; i < accelerations_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_accelerationsi;
        u_accelerationsi.base = 0;
        u_accelerationsi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_accelerationsi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_accelerationsi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_accelerationsi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_accelerationsi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_accelerationsi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_accelerationsi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_accelerationsi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->accelerations[i] = u_accelerationsi.real;
        offset += sizeof(this->accelerations[i]);
      }
      uint32_t effort_length = ((uint32_t) (*(inbuffer + offset))); 
      effort_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      effort_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      effort_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->effort.resize(effort_length); 
      offset += sizeof(effort_length);
      for( uint32_t i = 0; i < effort_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_efforti;
        u_efforti.base = 0;
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_efforti.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->effort[i] = u_efforti.real;
        offset += sizeof(this->effort[i]);
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
      uint32_t positions_length = this->positions.size();
      length += sizeof(positions_length);
      for( uint32_t i = 0; i < positions_length; i++) {
        length += sizeof(this->positions[i]);
      }
      uint32_t velocities_length = this->velocities.size();
      length += sizeof(velocities_length);
      for( uint32_t i = 0; i < velocities_length; i++) {
        length += sizeof(this->velocities[i]);
      }
      uint32_t accelerations_length = this->accelerations.size();
      length += sizeof(accelerations_length);
      for( uint32_t i = 0; i < accelerations_length; i++) {
        length += sizeof(this->accelerations[i]);
      }
      uint32_t effort_length = this->effort.size();
      length += sizeof(effort_length);
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
      uint32_t positions_length = this->positions.size();
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
      uint32_t velocities_length = this->velocities.size();
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
      uint32_t accelerations_length = this->accelerations.size();
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
      uint32_t effort_length = this->effort.size();
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
typedef std::shared_ptr<tinyros::trajectory_msgs::JointTrajectoryPoint> JointTrajectoryPointPtr;
typedef std::shared_ptr<tinyros::trajectory_msgs::JointTrajectoryPoint const> JointTrajectoryPointConstPtr;

}
}
#endif
