#ifndef _TINYROS_visualization_msgs_InteractiveMarkerUpdate_h
#define _TINYROS_visualization_msgs_InteractiveMarkerUpdate_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/visualization_msgs/InteractiveMarker.h"
#include "tiny_ros/visualization_msgs/InteractiveMarkerPose.h"

namespace tinyros
{
namespace visualization_msgs
{

  class InteractiveMarkerUpdate : public tinyros::Msg
  {
    public:
      typedef std::string _server_id_type;
      _server_id_type server_id;
      typedef uint64_t _seq_num_type;
      _seq_num_type seq_num;
      typedef uint8_t _type_type;
      _type_type type;
      uint32_t markers_length;
      typedef tinyros::visualization_msgs::InteractiveMarker _markers_type;
      _markers_type st_markers;
      _markers_type * markers;
      uint32_t poses_length;
      typedef tinyros::visualization_msgs::InteractiveMarkerPose _poses_type;
      _poses_type st_poses;
      _poses_type * poses;
      uint32_t erases_length;
      typedef std::string _erases_type;
      _erases_type st_erases;
      _erases_type * erases;
      enum { KEEP_ALIVE =  0 };
      enum { UPDATE =  1 };

    InteractiveMarkerUpdate():
      server_id(""),
      seq_num(0),
      type(0),
      markers_length(0), markers(NULL),
      poses_length(0), poses(NULL),
      erases_length(0), erases(NULL)
    {
    }

    ~InteractiveMarkerUpdate()
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
      if(this->poses != NULL)
      {
        for( uint32_t i = 0; i < this->poses_length; i++){
          this->poses[i].deconstructor();
        }
        delete[] this->poses;
      }
      this->poses = NULL;
      this->poses_length = 0;
      if(this->erases != NULL)
      {
        delete[] this->erases;
      }
      this->erases = NULL;
      this->erases_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_server_id = this->server_id.size();
      varToArr(outbuffer + offset, length_server_id);
      offset += 4;
      memcpy(outbuffer + offset, this->server_id.c_str(), length_server_id);
      offset += length_server_id;
      *(outbuffer + offset + 0) = (this->seq_num >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->seq_num >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->seq_num >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->seq_num >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->seq_num >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->seq_num >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->seq_num >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->seq_num >> (8 * 7)) & 0xFF;
      offset += sizeof(this->seq_num);
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->markers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->markers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->markers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->markers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->markers_length);
      for( uint32_t i = 0; i < markers_length; i++) {
        offset += this->markers[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->poses_length);
      for( uint32_t i = 0; i < poses_length; i++) {
        offset += this->poses[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->erases_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->erases_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->erases_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->erases_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->erases_length);
      for( uint32_t i = 0; i < erases_length; i++) {
        uint32_t length_erasesi = this->erases[i].size();
        varToArr(outbuffer + offset, length_erasesi);
        offset += 4;
        memcpy(outbuffer + offset, this->erases[i].c_str(), length_erasesi);
        offset += length_erasesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_server_id;
      arrToVar(length_server_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_server_id; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_server_id-1]=0;
      this->server_id = (char *)(inbuffer + offset-1);
      offset += length_server_id;
      this->seq_num =  ((uint64_t) (*(inbuffer + offset)));
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->seq_num |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->seq_num);
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      uint32_t markers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      markers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->markers_length);
      if(!this->markers || markers_lengthT > this->markers_length) {
        this->deconstructor();
        this->markers = new tinyros::visualization_msgs::InteractiveMarker[markers_lengthT];
      }
      this->markers_length = markers_lengthT;
      for( uint32_t i = 0; i < markers_length; i++) {
        offset += this->st_markers.deserialize(inbuffer + offset);
        this->markers[i] = this->st_markers;
      }
      uint32_t poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->poses_length);
      if(!this->poses || poses_lengthT > this->poses_length) {
        this->deconstructor();
        this->poses = new tinyros::visualization_msgs::InteractiveMarkerPose[poses_lengthT];
      }
      this->poses_length = poses_lengthT;
      for( uint32_t i = 0; i < poses_length; i++) {
        offset += this->st_poses.deserialize(inbuffer + offset);
        this->poses[i] = this->st_poses;
      }
      uint32_t erases_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      erases_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      erases_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      erases_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->erases_length);
      if(!this->erases || erases_lengthT > this->erases_length) {
        this->deconstructor();
        this->erases = new std::string[erases_lengthT];
      }
      this->erases_length = erases_lengthT;
      for( uint32_t i = 0; i < erases_length; i++) {
        uint32_t length_st_erases;
        arrToVar(length_st_erases, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_st_erases; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_st_erases-1]=0;
        this->st_erases = (char *)(inbuffer + offset-1);
        offset += length_st_erases;
        this->erases[i] = this->st_erases;
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_server_id = this->server_id.size();
      length += 4;
      length += length_server_id;
      length += sizeof(this->seq_num);
      length += sizeof(this->type);
      length += sizeof(this->markers_length);
      for( uint32_t i = 0; i < markers_length; i++) {
        length += this->markers[i].serializedLength();
      }
      length += sizeof(this->poses_length);
      for( uint32_t i = 0; i < poses_length; i++) {
        length += this->poses[i].serializedLength();
      }
      length += sizeof(this->erases_length);
      for( uint32_t i = 0; i < erases_length; i++) {
        uint32_t length_erasesi = this->erases[i].size();
        length += 4;
        length += length_erasesi;
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      std::size_t server_id_pos = server_id.find("\"");
      while(server_id_pos != std::string::npos){
        server_id.replace(server_id_pos, 1,"\\\"");
        server_id_pos = server_id.find("\"", server_id_pos+2);
      }
      string_echo += "\"server_id\":\"";
      string_echo += server_id;
      string_echo += "\",";
      std::stringstream ss_seq_num; ss_seq_num << "\"seq_num\":" << seq_num <<",";
      string_echo += ss_seq_num.str();
      std::stringstream ss_type; ss_type << "\"type\":" << (uint16_t)type <<",";
      string_echo += ss_type.str();
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
      string_echo += "],";
      string_echo += "poses:[";
      for( uint32_t i = 0; i < poses_length; i++) {
        if( i == (poses_length - 1)) {
          string_echo += this->poses[i].echo();
          string_echo += "";
        } else {
          string_echo += this->poses[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "],";
      string_echo += "erases:[";
      for( uint32_t i = 0; i < erases_length; i++) {
        if( i == (erases_length - 1)) {
          std::stringstream ss_erasesi; ss_erasesi << "\"";
          string_echo += ss_erasesi.str();
          std::size_t erasesi_pos = erases[i].find("\"");
          while(erasesi_pos != std::string::npos){
            erases[i].replace(erasesi_pos, 1,"\\\"");
            erasesi_pos = erases[i].find("\"", erasesi_pos+2);
          }
          string_echo += erases[i];
          string_echo += "\"";
        } else {
          std::stringstream ss_erasesi; ss_erasesi << "\"";
          string_echo += ss_erasesi.str();
          std::size_t erasesi_pos = erases[i].find("\"");
          while(erasesi_pos != std::string::npos){
            erases[i].replace(erasesi_pos, 1,"\\\"");
            erasesi_pos = erases[i].find("\"", erasesi_pos+2);
          }
          string_echo += erases[i];
          string_echo += "\",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "visualization_msgs/InteractiveMarkerUpdate"; }
    static std::string getTypeStatic(){ return "visualization_msgs/InteractiveMarkerUpdate"; }
    virtual std::string getMD5(){ return "ae37189a6cc8de1bae3ccd7710af4288"; }
    static std::string getMD5Static(){ return "ae37189a6cc8de1bae3ccd7710af4288"; }
    virtual std::string getDefinition(){ return "string server_id\nuint64 seq_num\nuint8 type\nInteractiveMarker[] markers\nInteractiveMarkerPose[] poses\nstring[] erases\n"; }
    static std::string getDefinitionStatic(){ return "string server_id\nuint64 seq_num\nuint8 type\nInteractiveMarker[] markers\nInteractiveMarkerPose[] poses\nstring[] erases\n"; }
    static bool hasHeader(){ return false; }
  };

typedef std::shared_ptr<tinyros::visualization_msgs::InteractiveMarkerUpdate> InteractiveMarkerUpdatePtr;
typedef std::shared_ptr<tinyros::visualization_msgs::InteractiveMarkerUpdate const> InteractiveMarkerUpdateConstPtr;

}
}
#endif
