#ifndef _TINYROS_diagnostic_msgs_DiagnosticArray_h
#define _TINYROS_diagnostic_msgs_DiagnosticArray_h

#include <stdint.h>
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
      uint32_t status_length;
      typedef tinyros::diagnostic_msgs::DiagnosticStatus _status_type;
      _status_type st_status;
      _status_type * status;

    DiagnosticArray():
      header(),
      status_length(0), status(NULL)
    {
    }

    ~DiagnosticArray()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(status != NULL)
      {
        for( uint32_t i = 0; i < status_length; i++){
          status[i].deconstructor();
        }
        free(status);
      }
      status = NULL;
      status_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->status_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->status_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->status_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->status_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->status_length);
      for( uint32_t i = 0; i < status_length; i++) {
        offset += this->status[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t status_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      status_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->status_length);
      if(status_lengthT > status_length)
        this->status = (tinyros::diagnostic_msgs::DiagnosticStatus*)realloc(this->status, status_lengthT * sizeof(tinyros::diagnostic_msgs::DiagnosticStatus));
      status_length = status_lengthT;
      for( uint32_t i = 0; i < status_length; i++) {
        offset += this->st_status.deserialize(inbuffer + offset);
        memcpy( &(this->status[i]), &(this->st_status), sizeof(tinyros::diagnostic_msgs::DiagnosticStatus));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += sizeof(this->status_length);
      for( uint32_t i = 0; i < status_length; i++) {
        length += this->status[i].serializedLength();
      }
      return length;
    }

    virtual tinyros::string getType(){ return "diagnostic_msgs/DiagnosticArray"; }
    static tinyros::string getTypeStatic(){ return "diagnostic_msgs/DiagnosticArray"; }
    virtual tinyros::string getMD5(){ return "79a87210f85eb6afbd600eb2ba49dd85"; }
    static tinyros::string getMD5Static(){ return "79a87210f85eb6afbd600eb2ba49dd85"; }
    virtual tinyros::string getDefinition(){ return "Header header \nDiagnosticStatus[] status \n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header \nDiagnosticStatus[] status \n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
