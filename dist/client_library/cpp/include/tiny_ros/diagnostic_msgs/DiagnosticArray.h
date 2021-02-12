#ifndef _TINYROS_diagnostic_msgs_DiagnosticArray_h
#define _TINYROS_diagnostic_msgs_DiagnosticArray_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/diagnostic_msgs/DiagnosticStatus.h"

namespace tinyros
{
namespace diagnostic_msgs
{

  class DiagnosticArray : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef tinyros::diagnostic_msgs::DiagnosticStatus _status_type;
      std::vector<_status_type> status;

    DiagnosticArray():
      header(),
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t status_length = this->status.size();
      *(outbuffer + offset + 0) = (status_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (status_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (status_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (status_length >> (8 * 3)) & 0xFF;
      offset += sizeof(status_length);
      for( uint32_t i = 0; i < status_length; i++) {
        offset += this->status[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t status_length = ((uint32_t) (*(inbuffer + offset))); 
      status_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      status_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      status_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->status.resize(status_length); 
      offset += sizeof(status_length);
      for( uint32_t i = 0; i < status_length; i++) {
        offset += this->status[i].deserialize(inbuffer + offset);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      uint32_t status_length = this->status.size();
      length += sizeof(status_length);
      for( uint32_t i = 0; i < status_length; i++) {
        length += this->status[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      uint32_t status_length = this->status.size();
      string_echo += "status:[";
      for( uint32_t i = 0; i < status_length; i++) {
        if( i == (status_length - 1)) {
          string_echo += this->status[i].echo();
          string_echo += "";
        } else {
          string_echo += this->status[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "diagnostic_msgs/DiagnosticArray"; }
    static std::string getTypeStatic(){ return "diagnostic_msgs/DiagnosticArray"; }
    virtual std::string getMD5(){ return "79a87210f85eb6afbd600eb2ba49dd85"; }
    static std::string getMD5Static(){ return "79a87210f85eb6afbd600eb2ba49dd85"; }
    virtual std::string getDefinition(){ return "Header header\nDiagnosticStatus[] status\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nDiagnosticStatus[] status\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::diagnostic_msgs::DiagnosticArray> Ptr;
    typedef std::shared_ptr<tinyros::diagnostic_msgs::DiagnosticArray const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::diagnostic_msgs::DiagnosticArray> DiagnosticArrayPtr;
typedef std::shared_ptr<tinyros::diagnostic_msgs::DiagnosticArray const> DiagnosticArrayConstPtr;

}
}
#endif
