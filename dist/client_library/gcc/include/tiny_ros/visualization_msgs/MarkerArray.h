#ifndef _TINYROS_visualization_msgs_MarkerArray_h
#define _TINYROS_visualization_msgs_MarkerArray_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/visualization_msgs/Marker.h"

namespace tinyros
{
namespace visualization_msgs
{

  class MarkerArray : public tinyros::Msg
  {
    public:
      uint32_t markers_length;
      typedef tinyros::visualization_msgs::Marker _markers_type;
      _markers_type st_markers;
      _markers_type * markers;

    MarkerArray():
      markers_length(0), markers(NULL)
    {
    }

    ~MarkerArray()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(this->markers != NULL)
      {
        for( uint32_t i = 0; i < this->markers_length; i++){
          this->markers[i].deconstructor();
        }
        delete[] this->markers;
      }
      this->markers = NULL;
      this->markers_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->markers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->markers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->markers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->markers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->markers_length);
      for( uint32_t i = 0; i < markers_length; i++) {
        offset += this->markers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t markers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->markers_length);
      if(!this->markers || markers_lengthT > this->markers_length) {
        this->deconstructor();
        this->markers = new tinyros::visualization_msgs::Marker[markers_lengthT];
      }
      this->markers_length = markers_lengthT;
      for( uint32_t i = 0; i < markers_length; i++) {
        offset += this->st_markers.deserialize(inbuffer + offset);
        this->markers[i] = this->st_markers;
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->markers_length);
      for( uint32_t i = 0; i < markers_length; i++) {
        length += this->markers[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "markers:[";
      for( uint32_t i = 0; i < markers_length; i++) {
        if( i == (markers_length - 1)) {
          string_echo += this->markers[i].echo();
          string_echo += "";
        } else {
          string_echo += this->markers[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "visualization_msgs/MarkerArray"; }
    static std::string getTypeStatic(){ return "visualization_msgs/MarkerArray"; }
    virtual std::string getMD5(){ return "032534c86d6c02fcd8eb187cf568eb46"; }
    static std::string getMD5Static(){ return "032534c86d6c02fcd8eb187cf568eb46"; }
    virtual std::string getDefinition(){ return "Marker[] markers\n"; }
    static std::string getDefinitionStatic(){ return "Marker[] markers\n"; }
    static bool hasHeader(){ return false; }
  };

typedef std::shared_ptr<tinyros::visualization_msgs::MarkerArray> MarkerArrayPtr;
typedef std::shared_ptr<tinyros::visualization_msgs::MarkerArray const> MarkerArrayConstPtr;

}
}
#endif
