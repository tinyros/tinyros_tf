#ifndef _TINYROS_gazebo_msgs_ODEJointProperties_h
#define _TINYROS_gazebo_msgs_ODEJointProperties_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace gazebo_msgs
{

  class ODEJointProperties : public tinyros::Msg
  {
    public:
      typedef double _damping_type;
      std::vector<_damping_type> damping;
      typedef double _hiStop_type;
      std::vector<_hiStop_type> hiStop;
      typedef double _loStop_type;
      std::vector<_loStop_type> loStop;
      typedef double _erp_type;
      std::vector<_erp_type> erp;
      typedef double _cfm_type;
      std::vector<_cfm_type> cfm;
      typedef double _stop_erp_type;
      std::vector<_stop_erp_type> stop_erp;
      typedef double _stop_cfm_type;
      std::vector<_stop_cfm_type> stop_cfm;
      typedef double _fudge_factor_type;
      std::vector<_fudge_factor_type> fudge_factor;
      typedef double _fmax_type;
      std::vector<_fmax_type> fmax;
      typedef double _vel_type;
      std::vector<_vel_type> vel;

    ODEJointProperties():
      damping(0),
      hiStop(0),
      loStop(0),
      erp(0),
      cfm(0),
      stop_erp(0),
      stop_cfm(0),
      fudge_factor(0),
      fmax(0),
      vel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t damping_length = this->damping.size();
      *(outbuffer + offset + 0) = (damping_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (damping_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (damping_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (damping_length >> (8 * 3)) & 0xFF;
      offset += sizeof(damping_length);
      for( uint32_t i = 0; i < damping_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_dampingi;
        u_dampingi.real = this->damping[i];
        *(outbuffer + offset + 0) = (u_dampingi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_dampingi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_dampingi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_dampingi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_dampingi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_dampingi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_dampingi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_dampingi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->damping[i]);
      }
      uint32_t hiStop_length = this->hiStop.size();
      *(outbuffer + offset + 0) = (hiStop_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (hiStop_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (hiStop_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (hiStop_length >> (8 * 3)) & 0xFF;
      offset += sizeof(hiStop_length);
      for( uint32_t i = 0; i < hiStop_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_hiStopi;
        u_hiStopi.real = this->hiStop[i];
        *(outbuffer + offset + 0) = (u_hiStopi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_hiStopi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_hiStopi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_hiStopi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_hiStopi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_hiStopi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_hiStopi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_hiStopi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->hiStop[i]);
      }
      uint32_t loStop_length = this->loStop.size();
      *(outbuffer + offset + 0) = (loStop_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (loStop_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (loStop_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (loStop_length >> (8 * 3)) & 0xFF;
      offset += sizeof(loStop_length);
      for( uint32_t i = 0; i < loStop_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_loStopi;
        u_loStopi.real = this->loStop[i];
        *(outbuffer + offset + 0) = (u_loStopi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_loStopi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_loStopi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_loStopi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_loStopi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_loStopi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_loStopi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_loStopi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->loStop[i]);
      }
      uint32_t erp_length = this->erp.size();
      *(outbuffer + offset + 0) = (erp_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (erp_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (erp_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (erp_length >> (8 * 3)) & 0xFF;
      offset += sizeof(erp_length);
      for( uint32_t i = 0; i < erp_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_erpi;
        u_erpi.real = this->erp[i];
        *(outbuffer + offset + 0) = (u_erpi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_erpi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_erpi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_erpi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_erpi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_erpi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_erpi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_erpi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->erp[i]);
      }
      uint32_t cfm_length = this->cfm.size();
      *(outbuffer + offset + 0) = (cfm_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (cfm_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (cfm_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (cfm_length >> (8 * 3)) & 0xFF;
      offset += sizeof(cfm_length);
      for( uint32_t i = 0; i < cfm_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_cfmi;
        u_cfmi.real = this->cfm[i];
        *(outbuffer + offset + 0) = (u_cfmi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_cfmi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_cfmi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_cfmi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_cfmi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_cfmi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_cfmi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_cfmi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->cfm[i]);
      }
      uint32_t stop_erp_length = this->stop_erp.size();
      *(outbuffer + offset + 0) = (stop_erp_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (stop_erp_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (stop_erp_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (stop_erp_length >> (8 * 3)) & 0xFF;
      offset += sizeof(stop_erp_length);
      for( uint32_t i = 0; i < stop_erp_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_stop_erpi;
        u_stop_erpi.real = this->stop_erp[i];
        *(outbuffer + offset + 0) = (u_stop_erpi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_stop_erpi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_stop_erpi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_stop_erpi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_stop_erpi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_stop_erpi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_stop_erpi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_stop_erpi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->stop_erp[i]);
      }
      uint32_t stop_cfm_length = this->stop_cfm.size();
      *(outbuffer + offset + 0) = (stop_cfm_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (stop_cfm_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (stop_cfm_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (stop_cfm_length >> (8 * 3)) & 0xFF;
      offset += sizeof(stop_cfm_length);
      for( uint32_t i = 0; i < stop_cfm_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_stop_cfmi;
        u_stop_cfmi.real = this->stop_cfm[i];
        *(outbuffer + offset + 0) = (u_stop_cfmi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_stop_cfmi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_stop_cfmi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_stop_cfmi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_stop_cfmi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_stop_cfmi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_stop_cfmi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_stop_cfmi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->stop_cfm[i]);
      }
      uint32_t fudge_factor_length = this->fudge_factor.size();
      *(outbuffer + offset + 0) = (fudge_factor_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (fudge_factor_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (fudge_factor_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (fudge_factor_length >> (8 * 3)) & 0xFF;
      offset += sizeof(fudge_factor_length);
      for( uint32_t i = 0; i < fudge_factor_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_fudge_factori;
        u_fudge_factori.real = this->fudge_factor[i];
        *(outbuffer + offset + 0) = (u_fudge_factori.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_fudge_factori.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_fudge_factori.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_fudge_factori.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_fudge_factori.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_fudge_factori.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_fudge_factori.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_fudge_factori.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->fudge_factor[i]);
      }
      uint32_t fmax_length = this->fmax.size();
      *(outbuffer + offset + 0) = (fmax_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (fmax_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (fmax_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (fmax_length >> (8 * 3)) & 0xFF;
      offset += sizeof(fmax_length);
      for( uint32_t i = 0; i < fmax_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_fmaxi;
        u_fmaxi.real = this->fmax[i];
        *(outbuffer + offset + 0) = (u_fmaxi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_fmaxi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_fmaxi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_fmaxi.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_fmaxi.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_fmaxi.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_fmaxi.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_fmaxi.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->fmax[i]);
      }
      uint32_t vel_length = this->vel.size();
      *(outbuffer + offset + 0) = (vel_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (vel_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (vel_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (vel_length >> (8 * 3)) & 0xFF;
      offset += sizeof(vel_length);
      for( uint32_t i = 0; i < vel_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_veli;
        u_veli.real = this->vel[i];
        *(outbuffer + offset + 0) = (u_veli.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_veli.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_veli.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_veli.base >> (8 * 3)) & 0xFF;
        *(outbuffer + offset + 4) = (u_veli.base >> (8 * 4)) & 0xFF;
        *(outbuffer + offset + 5) = (u_veli.base >> (8 * 5)) & 0xFF;
        *(outbuffer + offset + 6) = (u_veli.base >> (8 * 6)) & 0xFF;
        *(outbuffer + offset + 7) = (u_veli.base >> (8 * 7)) & 0xFF;
        offset += sizeof(this->vel[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t damping_length = ((uint32_t) (*(inbuffer + offset))); 
      damping_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      damping_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      damping_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->damping.resize(damping_length); 
      offset += sizeof(damping_length);
      for( uint32_t i = 0; i < damping_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_dampingi;
        u_dampingi.base = 0;
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_dampingi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->damping[i] = u_dampingi.real;
        offset += sizeof(this->damping[i]);
      }
      uint32_t hiStop_length = ((uint32_t) (*(inbuffer + offset))); 
      hiStop_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      hiStop_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      hiStop_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->hiStop.resize(hiStop_length); 
      offset += sizeof(hiStop_length);
      for( uint32_t i = 0; i < hiStop_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_hiStopi;
        u_hiStopi.base = 0;
        u_hiStopi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_hiStopi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_hiStopi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_hiStopi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_hiStopi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_hiStopi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_hiStopi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_hiStopi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->hiStop[i] = u_hiStopi.real;
        offset += sizeof(this->hiStop[i]);
      }
      uint32_t loStop_length = ((uint32_t) (*(inbuffer + offset))); 
      loStop_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      loStop_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      loStop_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->loStop.resize(loStop_length); 
      offset += sizeof(loStop_length);
      for( uint32_t i = 0; i < loStop_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_loStopi;
        u_loStopi.base = 0;
        u_loStopi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_loStopi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_loStopi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_loStopi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_loStopi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_loStopi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_loStopi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_loStopi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->loStop[i] = u_loStopi.real;
        offset += sizeof(this->loStop[i]);
      }
      uint32_t erp_length = ((uint32_t) (*(inbuffer + offset))); 
      erp_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      erp_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      erp_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->erp.resize(erp_length); 
      offset += sizeof(erp_length);
      for( uint32_t i = 0; i < erp_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_erpi;
        u_erpi.base = 0;
        u_erpi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_erpi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_erpi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_erpi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_erpi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_erpi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_erpi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_erpi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->erp[i] = u_erpi.real;
        offset += sizeof(this->erp[i]);
      }
      uint32_t cfm_length = ((uint32_t) (*(inbuffer + offset))); 
      cfm_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cfm_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cfm_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->cfm.resize(cfm_length); 
      offset += sizeof(cfm_length);
      for( uint32_t i = 0; i < cfm_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_cfmi;
        u_cfmi.base = 0;
        u_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->cfm[i] = u_cfmi.real;
        offset += sizeof(this->cfm[i]);
      }
      uint32_t stop_erp_length = ((uint32_t) (*(inbuffer + offset))); 
      stop_erp_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stop_erp_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stop_erp_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->stop_erp.resize(stop_erp_length); 
      offset += sizeof(stop_erp_length);
      for( uint32_t i = 0; i < stop_erp_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_stop_erpi;
        u_stop_erpi.base = 0;
        u_stop_erpi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_stop_erpi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_stop_erpi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_stop_erpi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_stop_erpi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_stop_erpi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_stop_erpi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_stop_erpi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->stop_erp[i] = u_stop_erpi.real;
        offset += sizeof(this->stop_erp[i]);
      }
      uint32_t stop_cfm_length = ((uint32_t) (*(inbuffer + offset))); 
      stop_cfm_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stop_cfm_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stop_cfm_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->stop_cfm.resize(stop_cfm_length); 
      offset += sizeof(stop_cfm_length);
      for( uint32_t i = 0; i < stop_cfm_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_stop_cfmi;
        u_stop_cfmi.base = 0;
        u_stop_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_stop_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_stop_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_stop_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_stop_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_stop_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_stop_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_stop_cfmi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->stop_cfm[i] = u_stop_cfmi.real;
        offset += sizeof(this->stop_cfm[i]);
      }
      uint32_t fudge_factor_length = ((uint32_t) (*(inbuffer + offset))); 
      fudge_factor_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fudge_factor_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fudge_factor_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->fudge_factor.resize(fudge_factor_length); 
      offset += sizeof(fudge_factor_length);
      for( uint32_t i = 0; i < fudge_factor_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_fudge_factori;
        u_fudge_factori.base = 0;
        u_fudge_factori.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_fudge_factori.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_fudge_factori.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_fudge_factori.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_fudge_factori.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_fudge_factori.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_fudge_factori.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_fudge_factori.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->fudge_factor[i] = u_fudge_factori.real;
        offset += sizeof(this->fudge_factor[i]);
      }
      uint32_t fmax_length = ((uint32_t) (*(inbuffer + offset))); 
      fmax_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fmax_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fmax_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->fmax.resize(fmax_length); 
      offset += sizeof(fmax_length);
      for( uint32_t i = 0; i < fmax_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_fmaxi;
        u_fmaxi.base = 0;
        u_fmaxi.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_fmaxi.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_fmaxi.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_fmaxi.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_fmaxi.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_fmaxi.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_fmaxi.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_fmaxi.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->fmax[i] = u_fmaxi.real;
        offset += sizeof(this->fmax[i]);
      }
      uint32_t vel_length = ((uint32_t) (*(inbuffer + offset))); 
      vel_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vel_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vel_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->vel.resize(vel_length); 
      offset += sizeof(vel_length);
      for( uint32_t i = 0; i < vel_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_veli;
        u_veli.base = 0;
        u_veli.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_veli.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_veli.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_veli.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_veli.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_veli.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_veli.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_veli.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->vel[i] = u_veli.real;
        offset += sizeof(this->vel[i]);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t damping_length = this->damping.size();
      length += sizeof(damping_length);
      for( uint32_t i = 0; i < damping_length; i++) {
        length += sizeof(this->damping[i]);
      }
      uint32_t hiStop_length = this->hiStop.size();
      length += sizeof(hiStop_length);
      for( uint32_t i = 0; i < hiStop_length; i++) {
        length += sizeof(this->hiStop[i]);
      }
      uint32_t loStop_length = this->loStop.size();
      length += sizeof(loStop_length);
      for( uint32_t i = 0; i < loStop_length; i++) {
        length += sizeof(this->loStop[i]);
      }
      uint32_t erp_length = this->erp.size();
      length += sizeof(erp_length);
      for( uint32_t i = 0; i < erp_length; i++) {
        length += sizeof(this->erp[i]);
      }
      uint32_t cfm_length = this->cfm.size();
      length += sizeof(cfm_length);
      for( uint32_t i = 0; i < cfm_length; i++) {
        length += sizeof(this->cfm[i]);
      }
      uint32_t stop_erp_length = this->stop_erp.size();
      length += sizeof(stop_erp_length);
      for( uint32_t i = 0; i < stop_erp_length; i++) {
        length += sizeof(this->stop_erp[i]);
      }
      uint32_t stop_cfm_length = this->stop_cfm.size();
      length += sizeof(stop_cfm_length);
      for( uint32_t i = 0; i < stop_cfm_length; i++) {
        length += sizeof(this->stop_cfm[i]);
      }
      uint32_t fudge_factor_length = this->fudge_factor.size();
      length += sizeof(fudge_factor_length);
      for( uint32_t i = 0; i < fudge_factor_length; i++) {
        length += sizeof(this->fudge_factor[i]);
      }
      uint32_t fmax_length = this->fmax.size();
      length += sizeof(fmax_length);
      for( uint32_t i = 0; i < fmax_length; i++) {
        length += sizeof(this->fmax[i]);
      }
      uint32_t vel_length = this->vel.size();
      length += sizeof(vel_length);
      for( uint32_t i = 0; i < vel_length; i++) {
        length += sizeof(this->vel[i]);
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      uint32_t damping_length = this->damping.size();
      string_echo += "damping:[";
      for( uint32_t i = 0; i < damping_length; i++) {
        if( i == (damping_length - 1)) {
          std::stringstream ss_dampingi; ss_dampingi << damping[i] <<"";
          string_echo += ss_dampingi.str();
        } else {
          std::stringstream ss_dampingi; ss_dampingi << damping[i] <<",";
          string_echo += ss_dampingi.str();
        }
      }
      string_echo += "],";
      uint32_t hiStop_length = this->hiStop.size();
      string_echo += "hiStop:[";
      for( uint32_t i = 0; i < hiStop_length; i++) {
        if( i == (hiStop_length - 1)) {
          std::stringstream ss_hiStopi; ss_hiStopi << hiStop[i] <<"";
          string_echo += ss_hiStopi.str();
        } else {
          std::stringstream ss_hiStopi; ss_hiStopi << hiStop[i] <<",";
          string_echo += ss_hiStopi.str();
        }
      }
      string_echo += "],";
      uint32_t loStop_length = this->loStop.size();
      string_echo += "loStop:[";
      for( uint32_t i = 0; i < loStop_length; i++) {
        if( i == (loStop_length - 1)) {
          std::stringstream ss_loStopi; ss_loStopi << loStop[i] <<"";
          string_echo += ss_loStopi.str();
        } else {
          std::stringstream ss_loStopi; ss_loStopi << loStop[i] <<",";
          string_echo += ss_loStopi.str();
        }
      }
      string_echo += "],";
      uint32_t erp_length = this->erp.size();
      string_echo += "erp:[";
      for( uint32_t i = 0; i < erp_length; i++) {
        if( i == (erp_length - 1)) {
          std::stringstream ss_erpi; ss_erpi << erp[i] <<"";
          string_echo += ss_erpi.str();
        } else {
          std::stringstream ss_erpi; ss_erpi << erp[i] <<",";
          string_echo += ss_erpi.str();
        }
      }
      string_echo += "],";
      uint32_t cfm_length = this->cfm.size();
      string_echo += "cfm:[";
      for( uint32_t i = 0; i < cfm_length; i++) {
        if( i == (cfm_length - 1)) {
          std::stringstream ss_cfmi; ss_cfmi << cfm[i] <<"";
          string_echo += ss_cfmi.str();
        } else {
          std::stringstream ss_cfmi; ss_cfmi << cfm[i] <<",";
          string_echo += ss_cfmi.str();
        }
      }
      string_echo += "],";
      uint32_t stop_erp_length = this->stop_erp.size();
      string_echo += "stop_erp:[";
      for( uint32_t i = 0; i < stop_erp_length; i++) {
        if( i == (stop_erp_length - 1)) {
          std::stringstream ss_stop_erpi; ss_stop_erpi << stop_erp[i] <<"";
          string_echo += ss_stop_erpi.str();
        } else {
          std::stringstream ss_stop_erpi; ss_stop_erpi << stop_erp[i] <<",";
          string_echo += ss_stop_erpi.str();
        }
      }
      string_echo += "],";
      uint32_t stop_cfm_length = this->stop_cfm.size();
      string_echo += "stop_cfm:[";
      for( uint32_t i = 0; i < stop_cfm_length; i++) {
        if( i == (stop_cfm_length - 1)) {
          std::stringstream ss_stop_cfmi; ss_stop_cfmi << stop_cfm[i] <<"";
          string_echo += ss_stop_cfmi.str();
        } else {
          std::stringstream ss_stop_cfmi; ss_stop_cfmi << stop_cfm[i] <<",";
          string_echo += ss_stop_cfmi.str();
        }
      }
      string_echo += "],";
      uint32_t fudge_factor_length = this->fudge_factor.size();
      string_echo += "fudge_factor:[";
      for( uint32_t i = 0; i < fudge_factor_length; i++) {
        if( i == (fudge_factor_length - 1)) {
          std::stringstream ss_fudge_factori; ss_fudge_factori << fudge_factor[i] <<"";
          string_echo += ss_fudge_factori.str();
        } else {
          std::stringstream ss_fudge_factori; ss_fudge_factori << fudge_factor[i] <<",";
          string_echo += ss_fudge_factori.str();
        }
      }
      string_echo += "],";
      uint32_t fmax_length = this->fmax.size();
      string_echo += "fmax:[";
      for( uint32_t i = 0; i < fmax_length; i++) {
        if( i == (fmax_length - 1)) {
          std::stringstream ss_fmaxi; ss_fmaxi << fmax[i] <<"";
          string_echo += ss_fmaxi.str();
        } else {
          std::stringstream ss_fmaxi; ss_fmaxi << fmax[i] <<",";
          string_echo += ss_fmaxi.str();
        }
      }
      string_echo += "],";
      uint32_t vel_length = this->vel.size();
      string_echo += "vel:[";
      for( uint32_t i = 0; i < vel_length; i++) {
        if( i == (vel_length - 1)) {
          std::stringstream ss_veli; ss_veli << vel[i] <<"";
          string_echo += ss_veli.str();
        } else {
          std::stringstream ss_veli; ss_veli << vel[i] <<",";
          string_echo += ss_veli.str();
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "gazebo_msgs/ODEJointProperties"; }
    static std::string getTypeStatic(){ return "gazebo_msgs/ODEJointProperties"; }
    virtual std::string getMD5(){ return "a9e264dbf3eff8e202d2bebecf081639"; }
    static std::string getMD5Static(){ return "a9e264dbf3eff8e202d2bebecf081639"; }
    virtual std::string getDefinition(){ return "float64[] damping\nfloat64[] hiStop\nfloat64[] loStop\nfloat64[] erp\nfloat64[] cfm\nfloat64[] stop_erp\nfloat64[] stop_cfm\nfloat64[] fudge_factor\nfloat64[] fmax\nfloat64[] vel\n"; }
    static std::string getDefinitionStatic(){ return "float64[] damping\nfloat64[] hiStop\nfloat64[] loStop\nfloat64[] erp\nfloat64[] cfm\nfloat64[] stop_erp\nfloat64[] stop_cfm\nfloat64[] fudge_factor\nfloat64[] fmax\nfloat64[] vel\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::ODEJointProperties> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::ODEJointProperties const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::ODEJointProperties> ODEJointPropertiesPtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::ODEJointProperties const> ODEJointPropertiesConstPtr;

}
}
#endif
