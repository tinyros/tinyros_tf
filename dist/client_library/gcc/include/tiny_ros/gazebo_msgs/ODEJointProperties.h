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
      uint32_t damping_length;
      typedef double _damping_type;
      _damping_type st_damping;
      _damping_type * damping;
      uint32_t hiStop_length;
      typedef double _hiStop_type;
      _hiStop_type st_hiStop;
      _hiStop_type * hiStop;
      uint32_t loStop_length;
      typedef double _loStop_type;
      _loStop_type st_loStop;
      _loStop_type * loStop;
      uint32_t erp_length;
      typedef double _erp_type;
      _erp_type st_erp;
      _erp_type * erp;
      uint32_t cfm_length;
      typedef double _cfm_type;
      _cfm_type st_cfm;
      _cfm_type * cfm;
      uint32_t stop_erp_length;
      typedef double _stop_erp_type;
      _stop_erp_type st_stop_erp;
      _stop_erp_type * stop_erp;
      uint32_t stop_cfm_length;
      typedef double _stop_cfm_type;
      _stop_cfm_type st_stop_cfm;
      _stop_cfm_type * stop_cfm;
      uint32_t fudge_factor_length;
      typedef double _fudge_factor_type;
      _fudge_factor_type st_fudge_factor;
      _fudge_factor_type * fudge_factor;
      uint32_t fmax_length;
      typedef double _fmax_type;
      _fmax_type st_fmax;
      _fmax_type * fmax;
      uint32_t vel_length;
      typedef double _vel_type;
      _vel_type st_vel;
      _vel_type * vel;

    ODEJointProperties():
      damping_length(0), damping(NULL),
      hiStop_length(0), hiStop(NULL),
      loStop_length(0), loStop(NULL),
      erp_length(0), erp(NULL),
      cfm_length(0), cfm(NULL),
      stop_erp_length(0), stop_erp(NULL),
      stop_cfm_length(0), stop_cfm(NULL),
      fudge_factor_length(0), fudge_factor(NULL),
      fmax_length(0), fmax(NULL),
      vel_length(0), vel(NULL)
    {
    }

    ~ODEJointProperties()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(this->damping != NULL)
      {
        delete[] this->damping;
      }
      this->damping = NULL;
      this->damping_length = 0;
      if(this->hiStop != NULL)
      {
        delete[] this->hiStop;
      }
      this->hiStop = NULL;
      this->hiStop_length = 0;
      if(this->loStop != NULL)
      {
        delete[] this->loStop;
      }
      this->loStop = NULL;
      this->loStop_length = 0;
      if(this->erp != NULL)
      {
        delete[] this->erp;
      }
      this->erp = NULL;
      this->erp_length = 0;
      if(this->cfm != NULL)
      {
        delete[] this->cfm;
      }
      this->cfm = NULL;
      this->cfm_length = 0;
      if(this->stop_erp != NULL)
      {
        delete[] this->stop_erp;
      }
      this->stop_erp = NULL;
      this->stop_erp_length = 0;
      if(this->stop_cfm != NULL)
      {
        delete[] this->stop_cfm;
      }
      this->stop_cfm = NULL;
      this->stop_cfm_length = 0;
      if(this->fudge_factor != NULL)
      {
        delete[] this->fudge_factor;
      }
      this->fudge_factor = NULL;
      this->fudge_factor_length = 0;
      if(this->fmax != NULL)
      {
        delete[] this->fmax;
      }
      this->fmax = NULL;
      this->fmax_length = 0;
      if(this->vel != NULL)
      {
        delete[] this->vel;
      }
      this->vel = NULL;
      this->vel_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->damping_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->damping_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->damping_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->damping_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->damping_length);
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
      *(outbuffer + offset + 0) = (this->hiStop_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hiStop_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hiStop_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hiStop_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hiStop_length);
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
      *(outbuffer + offset + 0) = (this->loStop_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->loStop_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->loStop_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->loStop_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->loStop_length);
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
      *(outbuffer + offset + 0) = (this->erp_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->erp_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->erp_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->erp_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->erp_length);
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
      *(outbuffer + offset + 0) = (this->cfm_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->cfm_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->cfm_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->cfm_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cfm_length);
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
      *(outbuffer + offset + 0) = (this->stop_erp_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stop_erp_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stop_erp_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stop_erp_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stop_erp_length);
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
      *(outbuffer + offset + 0) = (this->stop_cfm_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stop_cfm_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stop_cfm_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stop_cfm_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stop_cfm_length);
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
      *(outbuffer + offset + 0) = (this->fudge_factor_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fudge_factor_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fudge_factor_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fudge_factor_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fudge_factor_length);
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
      *(outbuffer + offset + 0) = (this->fmax_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fmax_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fmax_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fmax_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fmax_length);
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
      *(outbuffer + offset + 0) = (this->vel_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vel_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vel_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vel_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel_length);
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
      uint32_t damping_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      damping_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      damping_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      damping_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->damping_length);
      if(!this->damping || damping_lengthT > this->damping_length) {
        this->deconstructor();
        this->damping = new double[damping_lengthT];
      }
      this->damping_length = damping_lengthT;
      for( uint32_t i = 0; i < damping_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_damping;
        u_st_damping.base = 0;
        u_st_damping.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_damping.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_damping.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_damping.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_damping.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_damping.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_damping.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_damping.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_damping = u_st_damping.real;
        offset += sizeof(this->st_damping);
        this->damping[i] = this->st_damping;
      }
      uint32_t hiStop_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      hiStop_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      hiStop_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      hiStop_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->hiStop_length);
      if(!this->hiStop || hiStop_lengthT > this->hiStop_length) {
        this->deconstructor();
        this->hiStop = new double[hiStop_lengthT];
      }
      this->hiStop_length = hiStop_lengthT;
      for( uint32_t i = 0; i < hiStop_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_hiStop;
        u_st_hiStop.base = 0;
        u_st_hiStop.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_hiStop.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_hiStop.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_hiStop.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_hiStop.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_hiStop.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_hiStop.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_hiStop.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_hiStop = u_st_hiStop.real;
        offset += sizeof(this->st_hiStop);
        this->hiStop[i] = this->st_hiStop;
      }
      uint32_t loStop_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      loStop_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      loStop_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      loStop_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->loStop_length);
      if(!this->loStop || loStop_lengthT > this->loStop_length) {
        this->deconstructor();
        this->loStop = new double[loStop_lengthT];
      }
      this->loStop_length = loStop_lengthT;
      for( uint32_t i = 0; i < loStop_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_loStop;
        u_st_loStop.base = 0;
        u_st_loStop.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_loStop.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_loStop.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_loStop.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_loStop.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_loStop.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_loStop.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_loStop.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_loStop = u_st_loStop.real;
        offset += sizeof(this->st_loStop);
        this->loStop[i] = this->st_loStop;
      }
      uint32_t erp_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      erp_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      erp_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      erp_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->erp_length);
      if(!this->erp || erp_lengthT > this->erp_length) {
        this->deconstructor();
        this->erp = new double[erp_lengthT];
      }
      this->erp_length = erp_lengthT;
      for( uint32_t i = 0; i < erp_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_erp;
        u_st_erp.base = 0;
        u_st_erp.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_erp.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_erp.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_erp.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_erp.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_erp.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_erp.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_erp.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_erp = u_st_erp.real;
        offset += sizeof(this->st_erp);
        this->erp[i] = this->st_erp;
      }
      uint32_t cfm_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      cfm_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cfm_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cfm_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->cfm_length);
      if(!this->cfm || cfm_lengthT > this->cfm_length) {
        this->deconstructor();
        this->cfm = new double[cfm_lengthT];
      }
      this->cfm_length = cfm_lengthT;
      for( uint32_t i = 0; i < cfm_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_cfm;
        u_st_cfm.base = 0;
        u_st_cfm.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_cfm.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_cfm.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_cfm.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_cfm.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_cfm.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_cfm.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_cfm.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_cfm = u_st_cfm.real;
        offset += sizeof(this->st_cfm);
        this->cfm[i] = this->st_cfm;
      }
      uint32_t stop_erp_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stop_erp_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stop_erp_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stop_erp_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stop_erp_length);
      if(!this->stop_erp || stop_erp_lengthT > this->stop_erp_length) {
        this->deconstructor();
        this->stop_erp = new double[stop_erp_lengthT];
      }
      this->stop_erp_length = stop_erp_lengthT;
      for( uint32_t i = 0; i < stop_erp_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_stop_erp;
        u_st_stop_erp.base = 0;
        u_st_stop_erp.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_stop_erp.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_stop_erp.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_stop_erp.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_stop_erp.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_stop_erp.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_stop_erp.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_stop_erp.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_stop_erp = u_st_stop_erp.real;
        offset += sizeof(this->st_stop_erp);
        this->stop_erp[i] = this->st_stop_erp;
      }
      uint32_t stop_cfm_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stop_cfm_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stop_cfm_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stop_cfm_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stop_cfm_length);
      if(!this->stop_cfm || stop_cfm_lengthT > this->stop_cfm_length) {
        this->deconstructor();
        this->stop_cfm = new double[stop_cfm_lengthT];
      }
      this->stop_cfm_length = stop_cfm_lengthT;
      for( uint32_t i = 0; i < stop_cfm_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_stop_cfm;
        u_st_stop_cfm.base = 0;
        u_st_stop_cfm.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_stop_cfm.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_stop_cfm.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_stop_cfm.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_stop_cfm.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_stop_cfm.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_stop_cfm.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_stop_cfm.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_stop_cfm = u_st_stop_cfm.real;
        offset += sizeof(this->st_stop_cfm);
        this->stop_cfm[i] = this->st_stop_cfm;
      }
      uint32_t fudge_factor_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fudge_factor_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fudge_factor_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fudge_factor_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fudge_factor_length);
      if(!this->fudge_factor || fudge_factor_lengthT > this->fudge_factor_length) {
        this->deconstructor();
        this->fudge_factor = new double[fudge_factor_lengthT];
      }
      this->fudge_factor_length = fudge_factor_lengthT;
      for( uint32_t i = 0; i < fudge_factor_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_fudge_factor;
        u_st_fudge_factor.base = 0;
        u_st_fudge_factor.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_fudge_factor.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_fudge_factor.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_fudge_factor.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_fudge_factor.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_fudge_factor.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_fudge_factor.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_fudge_factor.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_fudge_factor = u_st_fudge_factor.real;
        offset += sizeof(this->st_fudge_factor);
        this->fudge_factor[i] = this->st_fudge_factor;
      }
      uint32_t fmax_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fmax_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fmax_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fmax_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fmax_length);
      if(!this->fmax || fmax_lengthT > this->fmax_length) {
        this->deconstructor();
        this->fmax = new double[fmax_lengthT];
      }
      this->fmax_length = fmax_lengthT;
      for( uint32_t i = 0; i < fmax_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_fmax;
        u_st_fmax.base = 0;
        u_st_fmax.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_fmax.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_fmax.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_fmax.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_fmax.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_fmax.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_fmax.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_fmax.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_fmax = u_st_fmax.real;
        offset += sizeof(this->st_fmax);
        this->fmax[i] = this->st_fmax;
      }
      uint32_t vel_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vel_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vel_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vel_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vel_length);
      if(!this->vel || vel_lengthT > this->vel_length) {
        this->deconstructor();
        this->vel = new double[vel_lengthT];
      }
      this->vel_length = vel_lengthT;
      for( uint32_t i = 0; i < vel_length; i++) {
        union {
          double real;
          uint64_t base;
        } u_st_vel;
        u_st_vel.base = 0;
        u_st_vel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_vel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_vel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_vel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
        u_st_vel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
        u_st_vel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
        u_st_vel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
        u_st_vel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
        this->st_vel = u_st_vel.real;
        offset += sizeof(this->st_vel);
        this->vel[i] = this->st_vel;
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->damping_length);
      for( uint32_t i = 0; i < damping_length; i++) {
        length += sizeof(this->damping[i]);
      }
      length += sizeof(this->hiStop_length);
      for( uint32_t i = 0; i < hiStop_length; i++) {
        length += sizeof(this->hiStop[i]);
      }
      length += sizeof(this->loStop_length);
      for( uint32_t i = 0; i < loStop_length; i++) {
        length += sizeof(this->loStop[i]);
      }
      length += sizeof(this->erp_length);
      for( uint32_t i = 0; i < erp_length; i++) {
        length += sizeof(this->erp[i]);
      }
      length += sizeof(this->cfm_length);
      for( uint32_t i = 0; i < cfm_length; i++) {
        length += sizeof(this->cfm[i]);
      }
      length += sizeof(this->stop_erp_length);
      for( uint32_t i = 0; i < stop_erp_length; i++) {
        length += sizeof(this->stop_erp[i]);
      }
      length += sizeof(this->stop_cfm_length);
      for( uint32_t i = 0; i < stop_cfm_length; i++) {
        length += sizeof(this->stop_cfm[i]);
      }
      length += sizeof(this->fudge_factor_length);
      for( uint32_t i = 0; i < fudge_factor_length; i++) {
        length += sizeof(this->fudge_factor[i]);
      }
      length += sizeof(this->fmax_length);
      for( uint32_t i = 0; i < fmax_length; i++) {
        length += sizeof(this->fmax[i]);
      }
      length += sizeof(this->vel_length);
      for( uint32_t i = 0; i < vel_length; i++) {
        length += sizeof(this->vel[i]);
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
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
    virtual std::string getDefinition(){ return "float64[] damping             \nfloat64[] hiStop              \nfloat64[] loStop              \nfloat64[] erp                 \nfloat64[] cfm                 \nfloat64[] stop_erp            \nfloat64[] stop_cfm            \nfloat64[] fudge_factor        \nfloat64[] fmax                \nfloat64[] vel                 \n"; }
    static std::string getDefinitionStatic(){ return "float64[] damping             \nfloat64[] hiStop              \nfloat64[] loStop              \nfloat64[] erp                 \nfloat64[] cfm                 \nfloat64[] stop_erp            \nfloat64[] stop_cfm            \nfloat64[] fudge_factor        \nfloat64[] fmax                \nfloat64[] vel                 \n"; }
    static bool hasHeader(){ return false; }
  };

typedef std::shared_ptr<tinyros::gazebo_msgs::ODEJointProperties> ODEJointPropertiesPtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::ODEJointProperties const> ODEJointPropertiesConstPtr;

}
}
#endif
