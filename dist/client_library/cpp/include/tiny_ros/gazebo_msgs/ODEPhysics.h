#ifndef _TINYROS_gazebo_msgs_ODEPhysics_h
#define _TINYROS_gazebo_msgs_ODEPhysics_h

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

  class ODEPhysics : public tinyros::Msg
  {
    public:
      typedef bool _auto_disable_bodies_type;
      _auto_disable_bodies_type auto_disable_bodies;
      typedef uint32_t _sor_pgs_precon_iters_type;
      _sor_pgs_precon_iters_type sor_pgs_precon_iters;
      typedef uint32_t _sor_pgs_iters_type;
      _sor_pgs_iters_type sor_pgs_iters;
      typedef double _sor_pgs_w_type;
      _sor_pgs_w_type sor_pgs_w;
      typedef double _sor_pgs_rms_error_tol_type;
      _sor_pgs_rms_error_tol_type sor_pgs_rms_error_tol;
      typedef double _contact_surface_layer_type;
      _contact_surface_layer_type contact_surface_layer;
      typedef double _contact_max_correcting_vel_type;
      _contact_max_correcting_vel_type contact_max_correcting_vel;
      typedef double _cfm_type;
      _cfm_type cfm;
      typedef double _erp_type;
      _erp_type erp;
      typedef uint32_t _max_contacts_type;
      _max_contacts_type max_contacts;

    ODEPhysics():
      auto_disable_bodies(0),
      sor_pgs_precon_iters(0),
      sor_pgs_iters(0),
      sor_pgs_w(0),
      sor_pgs_rms_error_tol(0),
      contact_surface_layer(0),
      contact_max_correcting_vel(0),
      cfm(0),
      erp(0),
      max_contacts(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_auto_disable_bodies;
      u_auto_disable_bodies.real = this->auto_disable_bodies;
      *(outbuffer + offset + 0) = (u_auto_disable_bodies.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->auto_disable_bodies);
      *(outbuffer + offset + 0) = (this->sor_pgs_precon_iters >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sor_pgs_precon_iters >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sor_pgs_precon_iters >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sor_pgs_precon_iters >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sor_pgs_precon_iters);
      *(outbuffer + offset + 0) = (this->sor_pgs_iters >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sor_pgs_iters >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sor_pgs_iters >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sor_pgs_iters >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sor_pgs_iters);
      union {
        double real;
        uint64_t base;
      } u_sor_pgs_w;
      u_sor_pgs_w.real = this->sor_pgs_w;
      *(outbuffer + offset + 0) = (u_sor_pgs_w.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sor_pgs_w.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sor_pgs_w.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sor_pgs_w.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_sor_pgs_w.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_sor_pgs_w.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_sor_pgs_w.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_sor_pgs_w.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sor_pgs_w);
      union {
        double real;
        uint64_t base;
      } u_sor_pgs_rms_error_tol;
      u_sor_pgs_rms_error_tol.real = this->sor_pgs_rms_error_tol;
      *(outbuffer + offset + 0) = (u_sor_pgs_rms_error_tol.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_sor_pgs_rms_error_tol.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_sor_pgs_rms_error_tol.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_sor_pgs_rms_error_tol.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_sor_pgs_rms_error_tol.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_sor_pgs_rms_error_tol.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_sor_pgs_rms_error_tol.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_sor_pgs_rms_error_tol.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sor_pgs_rms_error_tol);
      union {
        double real;
        uint64_t base;
      } u_contact_surface_layer;
      u_contact_surface_layer.real = this->contact_surface_layer;
      *(outbuffer + offset + 0) = (u_contact_surface_layer.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_contact_surface_layer.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_contact_surface_layer.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_contact_surface_layer.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_contact_surface_layer.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_contact_surface_layer.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_contact_surface_layer.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_contact_surface_layer.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->contact_surface_layer);
      union {
        double real;
        uint64_t base;
      } u_contact_max_correcting_vel;
      u_contact_max_correcting_vel.real = this->contact_max_correcting_vel;
      *(outbuffer + offset + 0) = (u_contact_max_correcting_vel.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_contact_max_correcting_vel.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_contact_max_correcting_vel.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_contact_max_correcting_vel.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_contact_max_correcting_vel.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_contact_max_correcting_vel.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_contact_max_correcting_vel.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_contact_max_correcting_vel.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->contact_max_correcting_vel);
      union {
        double real;
        uint64_t base;
      } u_cfm;
      u_cfm.real = this->cfm;
      *(outbuffer + offset + 0) = (u_cfm.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cfm.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cfm.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cfm.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_cfm.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_cfm.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_cfm.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_cfm.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->cfm);
      union {
        double real;
        uint64_t base;
      } u_erp;
      u_erp.real = this->erp;
      *(outbuffer + offset + 0) = (u_erp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_erp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_erp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_erp.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_erp.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_erp.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_erp.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_erp.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->erp);
      *(outbuffer + offset + 0) = (this->max_contacts >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->max_contacts >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->max_contacts >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->max_contacts >> (8 * 3)) & 0xFF;
      offset += sizeof(this->max_contacts);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_auto_disable_bodies;
      u_auto_disable_bodies.base = 0;
      u_auto_disable_bodies.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->auto_disable_bodies = u_auto_disable_bodies.real;
      offset += sizeof(this->auto_disable_bodies);
      this->sor_pgs_precon_iters =  ((uint32_t) (*(inbuffer + offset)));
      this->sor_pgs_precon_iters |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sor_pgs_precon_iters |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sor_pgs_precon_iters |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sor_pgs_precon_iters);
      this->sor_pgs_iters =  ((uint32_t) (*(inbuffer + offset)));
      this->sor_pgs_iters |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sor_pgs_iters |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sor_pgs_iters |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->sor_pgs_iters);
      union {
        double real;
        uint64_t base;
      } u_sor_pgs_w;
      u_sor_pgs_w.base = 0;
      u_sor_pgs_w.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sor_pgs_w.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sor_pgs_w.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sor_pgs_w.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_sor_pgs_w.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_sor_pgs_w.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_sor_pgs_w.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_sor_pgs_w.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sor_pgs_w = u_sor_pgs_w.real;
      offset += sizeof(this->sor_pgs_w);
      union {
        double real;
        uint64_t base;
      } u_sor_pgs_rms_error_tol;
      u_sor_pgs_rms_error_tol.base = 0;
      u_sor_pgs_rms_error_tol.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_sor_pgs_rms_error_tol.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_sor_pgs_rms_error_tol.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_sor_pgs_rms_error_tol.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_sor_pgs_rms_error_tol.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_sor_pgs_rms_error_tol.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_sor_pgs_rms_error_tol.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_sor_pgs_rms_error_tol.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->sor_pgs_rms_error_tol = u_sor_pgs_rms_error_tol.real;
      offset += sizeof(this->sor_pgs_rms_error_tol);
      union {
        double real;
        uint64_t base;
      } u_contact_surface_layer;
      u_contact_surface_layer.base = 0;
      u_contact_surface_layer.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_contact_surface_layer.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_contact_surface_layer.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_contact_surface_layer.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_contact_surface_layer.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_contact_surface_layer.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_contact_surface_layer.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_contact_surface_layer.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->contact_surface_layer = u_contact_surface_layer.real;
      offset += sizeof(this->contact_surface_layer);
      union {
        double real;
        uint64_t base;
      } u_contact_max_correcting_vel;
      u_contact_max_correcting_vel.base = 0;
      u_contact_max_correcting_vel.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_contact_max_correcting_vel.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_contact_max_correcting_vel.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_contact_max_correcting_vel.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_contact_max_correcting_vel.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_contact_max_correcting_vel.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_contact_max_correcting_vel.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_contact_max_correcting_vel.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->contact_max_correcting_vel = u_contact_max_correcting_vel.real;
      offset += sizeof(this->contact_max_correcting_vel);
      union {
        double real;
        uint64_t base;
      } u_cfm;
      u_cfm.base = 0;
      u_cfm.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cfm.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cfm.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cfm.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_cfm.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_cfm.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_cfm.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_cfm.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->cfm = u_cfm.real;
      offset += sizeof(this->cfm);
      union {
        double real;
        uint64_t base;
      } u_erp;
      u_erp.base = 0;
      u_erp.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_erp.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_erp.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_erp.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_erp.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_erp.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_erp.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_erp.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->erp = u_erp.real;
      offset += sizeof(this->erp);
      this->max_contacts =  ((uint32_t) (*(inbuffer + offset)));
      this->max_contacts |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->max_contacts |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->max_contacts |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->max_contacts);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->auto_disable_bodies);
      length += sizeof(this->sor_pgs_precon_iters);
      length += sizeof(this->sor_pgs_iters);
      length += sizeof(this->sor_pgs_w);
      length += sizeof(this->sor_pgs_rms_error_tol);
      length += sizeof(this->contact_surface_layer);
      length += sizeof(this->contact_max_correcting_vel);
      length += sizeof(this->cfm);
      length += sizeof(this->erp);
      length += sizeof(this->max_contacts);
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::stringstream ss_auto_disable_bodies; ss_auto_disable_bodies << "\"auto_disable_bodies\":" << auto_disable_bodies <<",";
      string_echo += ss_auto_disable_bodies.str();
      std::stringstream ss_sor_pgs_precon_iters; ss_sor_pgs_precon_iters << "\"sor_pgs_precon_iters\":" << sor_pgs_precon_iters <<",";
      string_echo += ss_sor_pgs_precon_iters.str();
      std::stringstream ss_sor_pgs_iters; ss_sor_pgs_iters << "\"sor_pgs_iters\":" << sor_pgs_iters <<",";
      string_echo += ss_sor_pgs_iters.str();
      std::stringstream ss_sor_pgs_w; ss_sor_pgs_w << "\"sor_pgs_w\":" << sor_pgs_w <<",";
      string_echo += ss_sor_pgs_w.str();
      std::stringstream ss_sor_pgs_rms_error_tol; ss_sor_pgs_rms_error_tol << "\"sor_pgs_rms_error_tol\":" << sor_pgs_rms_error_tol <<",";
      string_echo += ss_sor_pgs_rms_error_tol.str();
      std::stringstream ss_contact_surface_layer; ss_contact_surface_layer << "\"contact_surface_layer\":" << contact_surface_layer <<",";
      string_echo += ss_contact_surface_layer.str();
      std::stringstream ss_contact_max_correcting_vel; ss_contact_max_correcting_vel << "\"contact_max_correcting_vel\":" << contact_max_correcting_vel <<",";
      string_echo += ss_contact_max_correcting_vel.str();
      std::stringstream ss_cfm; ss_cfm << "\"cfm\":" << cfm <<",";
      string_echo += ss_cfm.str();
      std::stringstream ss_erp; ss_erp << "\"erp\":" << erp <<",";
      string_echo += ss_erp.str();
      std::stringstream ss_max_contacts; ss_max_contacts << "\"max_contacts\":" << max_contacts <<"";
      string_echo += ss_max_contacts.str();
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "gazebo_msgs/ODEPhysics"; }
    static std::string getTypeStatic(){ return "gazebo_msgs/ODEPhysics"; }
    virtual std::string getMD5(){ return "67a077e58362b50f63dc189c25d01418"; }
    static std::string getMD5Static(){ return "67a077e58362b50f63dc189c25d01418"; }
    virtual std::string getDefinition(){ return "bool auto_disable_bodies\nuint32 sor_pgs_precon_iters\nuint32 sor_pgs_iters\nfloat64 sor_pgs_w\nfloat64 sor_pgs_rms_error_tol\nfloat64 contact_surface_layer\nfloat64 contact_max_correcting_vel\nfloat64 cfm\nfloat64 erp\nuint32 max_contacts\n"; }
    static std::string getDefinitionStatic(){ return "bool auto_disable_bodies\nuint32 sor_pgs_precon_iters\nuint32 sor_pgs_iters\nfloat64 sor_pgs_w\nfloat64 sor_pgs_rms_error_tol\nfloat64 contact_surface_layer\nfloat64 contact_max_correcting_vel\nfloat64 cfm\nfloat64 erp\nuint32 max_contacts\n"; }
    static bool hasHeader(){ return false; }
    typedef std::shared_ptr<tinyros::gazebo_msgs::ODEPhysics> Ptr;
    typedef std::shared_ptr<tinyros::gazebo_msgs::ODEPhysics const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::gazebo_msgs::ODEPhysics> ODEPhysicsPtr;
typedef std::shared_ptr<tinyros::gazebo_msgs::ODEPhysics const> ODEPhysicsConstPtr;

}
}
#endif
