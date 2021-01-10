#ifndef _TINYROS_visualization_msgs_MarkerArray_h
#define _TINYROS_visualization_msgs_MarkerArray_h

#include <stdint.h>
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
      if(markers != NULL)
      {
        for( uint32_t i = 0; i < markers_length; i++){
          markers[i].deconstructor();
        }
        free(markers);
      }
      markers = NULL;
      markers_length = 0;
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
      if(markers_lengthT > markers_length)
        this->markers = (tinyros::visualization_msgs::Marker*)realloc(this->markers, markers_lengthT * sizeof(tinyros::visualization_msgs::Marker));
      markers_length = markers_lengthT;
      for( uint32_t i = 0; i < markers_length; i++) {
        offset += this->st_markers.deserialize(inbuffer + offset);
        memcpy( &(this->markers[i]), &(this->st_markers), sizeof(tinyros::visualization_msgs::Marker));
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

    virtual tinyros::string getType(){ return "visualization_msgs/MarkerArray"; }
    static tinyros::string getTypeStatic(){ return "visualization_msgs/MarkerArray"; }
    virtual tinyros::string getMD5(){ return "032534c86d6c02fcd8eb187cf568eb46"; }
    static tinyros::string getMD5Static(){ return "032534c86d6c02fcd8eb187cf568eb46"; }
    virtual tinyros::string getDefinition(){ return "Marker[] markers\n"; }
    static tinyros::string getDefinitionStatic(){ return "Marker[] markers\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
