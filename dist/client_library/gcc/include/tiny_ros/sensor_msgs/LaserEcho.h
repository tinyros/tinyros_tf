#ifndef _TINYROS_sensor_msgs_LaserEcho_h
#define _TINYROS_sensor_msgs_LaserEcho_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace sensor_msgs
{

  class LaserEcho : public tinyros::Msg
  {
    public:
      uint32_t echoes_length;
      typedef float _echoes_type;
      _echoes_type st_echoes;
      _echoes_type * echoes;

    LaserEcho():
      echoes_length(0), echoes(NULL)
    {
    }

    ~LaserEcho()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(this->echoes != NULL)
      {
        delete[] this->echoes;
      }
      this->echoes = NULL;
      this->echoes_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->echoes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->echoes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->echoes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->echoes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->echoes_length);
      for( uint32_t i = 0; i < echoes_length; i++) {
        union {
          float real;
          uint32_t base;
        } u_echoesi;
        u_echoesi.real = this->echoes[i];
        *(outbuffer + offset + 0) = (u_echoesi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_echoesi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_echoesi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_echoesi.base >> (8 * 3)) & 0xFF;
        offset += sizeof(this->echoes[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t echoes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      echoes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      echoes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      echoes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->echoes_length);
      if(!this->echoes || echoes_lengthT > this->echoes_length) {
        this->deconstructor();
        this->echoes = new float[echoes_lengthT];
      }
      this->echoes_length = echoes_lengthT;
      for( uint32_t i = 0; i < echoes_length; i++) {
        union {
          float real;
          uint32_t base;
        } u_st_echoes;
        u_st_echoes.base = 0;
        u_st_echoes.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_st_echoes.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_st_echoes.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_st_echoes.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
        this->st_echoes = u_st_echoes.real;
        offset += sizeof(this->st_echoes);
        this->echoes[i] = this->st_echoes;
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->echoes_length);
      for( uint32_t i = 0; i < echoes_length; i++) {
        length += sizeof(this->echoes[i]);
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "echoes:[";
      for( uint32_t i = 0; i < echoes_length; i++) {
        if( i == (echoes_length - 1)) {
          std::stringstream ss_echoesi; ss_echoesi << echoes[i] <<"";
          string_echo += ss_echoesi.str();
        } else {
          std::stringstream ss_echoesi; ss_echoesi << echoes[i] <<",";
          string_echo += ss_echoesi.str();
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "sensor_msgs/LaserEcho"; }
    static std::string getTypeStatic(){ return "sensor_msgs/LaserEcho"; }
    virtual std::string getMD5(){ return "a8537b388573845b3240b44db5bc4905"; }
    static std::string getMD5Static(){ return "a8537b388573845b3240b44db5bc4905"; }
    virtual std::string getDefinition(){ return "float32[] echoes  \n"; }
    static std::string getDefinitionStatic(){ return "float32[] echoes  \n"; }
    static bool hasHeader(){ return false; }
  };

typedef std::shared_ptr<tinyros::sensor_msgs::LaserEcho> LaserEchoPtr;
typedef std::shared_ptr<tinyros::sensor_msgs::LaserEcho const> LaserEchoConstPtr;

}
}
#endif
