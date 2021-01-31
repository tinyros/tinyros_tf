#ifndef _TINYROS_sensor_msgs_Joy_h
#define _TINYROS_sensor_msgs_Joy_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"

namespace tinyros
{
namespace sensor_msgs
{

  class Joy : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef float _axes_type;
      std::vector<_axes_type> axes;
      typedef int32_t _buttons_type;
      std::vector<_buttons_type> buttons;

    Joy():
      header(),
      axes(0),
      buttons(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t axes_length = this->axes.size();
      *(outbuffer + offset + 0) = (axes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (axes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (axes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (axes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(axes_length);
      for( uint32_t i = 0; i < axes_length; i++) {
        union {
          float real;
          uint32_t base;
        } u_axesi;
        u_axesi.real = this->axes[i];
        *(outbuffer + offset + 0) = (u_axesi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_axesi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_axesi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_axesi.base >> (8 * 3)) & 0xFF;
        offset += sizeof(this->axes[i]);
      }
      uint32_t buttons_length = this->buttons.size();
      *(outbuffer + offset + 0) = (buttons_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (buttons_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (buttons_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (buttons_length >> (8 * 3)) & 0xFF;
      offset += sizeof(buttons_length);
      for( uint32_t i = 0; i < buttons_length; i++) {
        union {
          int32_t real;
          uint32_t base;
        } u_buttonsi;
        u_buttonsi.real = this->buttons[i];
        *(outbuffer + offset + 0) = (u_buttonsi.base >> (8 * 0)) & 0xFF;
        *(outbuffer + offset + 1) = (u_buttonsi.base >> (8 * 1)) & 0xFF;
        *(outbuffer + offset + 2) = (u_buttonsi.base >> (8 * 2)) & 0xFF;
        *(outbuffer + offset + 3) = (u_buttonsi.base >> (8 * 3)) & 0xFF;
        offset += sizeof(this->buttons[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t axes_length = ((uint32_t) (*(inbuffer + offset))); 
      axes_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      axes_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      axes_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->axes.resize(axes_length); 
      offset += sizeof(axes_length);
      for( uint32_t i = 0; i < axes_length; i++) {
        union {
          float real;
          uint32_t base;
        } u_axesi;
        u_axesi.base = 0;
        u_axesi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_axesi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_axesi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_axesi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
        this->axes[i] = u_axesi.real;
        offset += sizeof(this->axes[i]);
      }
      uint32_t buttons_length = ((uint32_t) (*(inbuffer + offset))); 
      buttons_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      buttons_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      buttons_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->buttons.resize(buttons_length); 
      offset += sizeof(buttons_length);
      for( uint32_t i = 0; i < buttons_length; i++) {
        union {
          int32_t real;
          uint32_t base;
        } u_buttonsi;
        u_buttonsi.base = 0;
        u_buttonsi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
        u_buttonsi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
        u_buttonsi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
        u_buttonsi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
        this->buttons[i] = u_buttonsi.real;
        offset += sizeof(this->buttons[i]);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      uint32_t axes_length = this->axes.size();
      length += sizeof(axes_length);
      for( uint32_t i = 0; i < axes_length; i++) {
        length += sizeof(this->axes[i]);
      }
      uint32_t buttons_length = this->buttons.size();
      length += sizeof(buttons_length);
      for( uint32_t i = 0; i < buttons_length; i++) {
        length += sizeof(this->buttons[i]);
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      uint32_t axes_length = this->axes.size();
      string_echo += "axes:[";
      for( uint32_t i = 0; i < axes_length; i++) {
        if( i == (axes_length - 1)) {
          std::stringstream ss_axesi; ss_axesi << axes[i] <<"";
          string_echo += ss_axesi.str();
        } else {
          std::stringstream ss_axesi; ss_axesi << axes[i] <<",";
          string_echo += ss_axesi.str();
        }
      }
      string_echo += "],";
      uint32_t buttons_length = this->buttons.size();
      string_echo += "buttons:[";
      for( uint32_t i = 0; i < buttons_length; i++) {
        if( i == (buttons_length - 1)) {
          std::stringstream ss_buttonsi; ss_buttonsi << buttons[i] <<"";
          string_echo += ss_buttonsi.str();
        } else {
          std::stringstream ss_buttonsi; ss_buttonsi << buttons[i] <<",";
          string_echo += ss_buttonsi.str();
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "sensor_msgs/Joy"; }
    static std::string getTypeStatic(){ return "sensor_msgs/Joy"; }
    virtual std::string getMD5(){ return "da3438323dbe92a4d6e4658e06bf8da1"; }
    static std::string getMD5Static(){ return "da3438323dbe92a4d6e4658e06bf8da1"; }
    virtual std::string getDefinition(){ return "Header header\nfloat32[] axes\nint32[] buttons\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nfloat32[] axes\nint32[] buttons\n"; }
    static bool hasHeader(){ return true; }
  };

typedef std::shared_ptr<tinyros::sensor_msgs::Joy> JoyPtr;
typedef std::shared_ptr<tinyros::sensor_msgs::Joy const> JoyConstPtr;

}
}
#endif
