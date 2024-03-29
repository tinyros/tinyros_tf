#ifndef _TINYROS_rosgraph_msgs_Log_h
#define _TINYROS_rosgraph_msgs_Log_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"

namespace tinyros
{
namespace rosgraph_msgs
{

  class Log : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef int8_t _level_type;
      _level_type level;
      typedef tinyros::string _name_type;
      _name_type name;
      typedef tinyros::string _msg_type;
      _msg_type msg;
      typedef tinyros::string _file_type;
      _file_type file;
      typedef tinyros::string _function_type;
      _function_type function;
      typedef uint32_t _line_type;
      _line_type line;
      uint32_t topics_length;
      typedef tinyros::string _topics_type;
      _topics_type st_topics;
      _topics_type * topics;
      enum { DEBUG = 1  };
      enum { INFO = 2   };
      enum { WARN = 4   };
      enum { ERROR = 8  };
      enum { FATAL = 16  };

    Log():
      header(),
      level(0),
      name(""),
      msg(""),
      file(""),
      function(""),
      line(0),
      topics_length(0), topics(NULL)
    {
    }

    ~Log()
    {
      deconstructor();
    }

    void deconstructor()
    {
      if(topics != NULL)
      {
        free(topics);
      }
      topics = NULL;
      topics_length = 0;
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_level;
      u_level.real = this->level;
      *(outbuffer + offset + 0) = (u_level.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->level);
      uint32_t length_name = this->name.size();
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name.c_str(), length_name);
      offset += length_name;
      uint32_t length_msg = this->msg.size();
      varToArr(outbuffer + offset, length_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->msg.c_str(), length_msg);
      offset += length_msg;
      uint32_t length_file = this->file.size();
      varToArr(outbuffer + offset, length_file);
      offset += 4;
      memcpy(outbuffer + offset, this->file.c_str(), length_file);
      offset += length_file;
      uint32_t length_function = this->function.size();
      varToArr(outbuffer + offset, length_function);
      offset += 4;
      memcpy(outbuffer + offset, this->function.c_str(), length_function);
      offset += length_function;
      *(outbuffer + offset + 0) = (this->line >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->line >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->line >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->line >> (8 * 3)) & 0xFF;
      offset += sizeof(this->line);
      *(outbuffer + offset + 0) = (this->topics_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->topics_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->topics_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->topics_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->topics_length);
      for( uint32_t i = 0; i < topics_length; i++) {
        uint32_t length_topicsi = this->topics[i].size();
        varToArr(outbuffer + offset, length_topicsi);
        offset += 4;
        memcpy(outbuffer + offset, this->topics[i].c_str(), length_topicsi);
        offset += length_topicsi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int8_t real;
        uint8_t base;
      } u_level;
      u_level.base = 0;
      u_level.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->level = u_level.real;
      offset += sizeof(this->level);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_msg;
      arrToVar(length_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
      uint32_t length_file;
      arrToVar(length_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file-1]=0;
      this->file = (char *)(inbuffer + offset-1);
      offset += length_file;
      uint32_t length_function;
      arrToVar(length_function, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_function; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_function-1]=0;
      this->function = (char *)(inbuffer + offset-1);
      offset += length_function;
      this->line =  ((uint32_t) (*(inbuffer + offset)));
      this->line |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->line |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->line |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->line);
      uint32_t topics_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      topics_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->topics_length);
      if(topics_lengthT > topics_length)
        this->topics = (tinyros::string*)realloc(this->topics, topics_lengthT * sizeof(tinyros::string));
      topics_length = topics_lengthT;
      for( uint32_t i = 0; i < topics_length; i++) {
        uint32_t length_st_topics;
        arrToVar(length_st_topics, (inbuffer + offset));
        offset += 4;
        for(unsigned int k= offset; k< offset+length_st_topics; ++k){
          inbuffer[k-1]=inbuffer[k];
        }
        inbuffer[offset+length_st_topics-1]=0;
        this->st_topics = (char *)(inbuffer + offset-1);
        offset += length_st_topics;
        memcpy( &(this->topics[i]), &(this->st_topics), sizeof(tinyros::string));
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += sizeof(this->level);
      uint32_t length_name = this->name.size();
      length += 4;
      length += length_name;
      uint32_t length_msg = this->msg.size();
      length += 4;
      length += length_msg;
      uint32_t length_file = this->file.size();
      length += 4;
      length += length_file;
      uint32_t length_function = this->function.size();
      length += 4;
      length += length_function;
      length += sizeof(this->line);
      length += sizeof(this->topics_length);
      for( uint32_t i = 0; i < topics_length; i++) {
        uint32_t length_topicsi = this->topics[i].size();
        length += 4;
        length += length_topicsi;
      }
      return length;
    }

    virtual tinyros::string getType(){ return "rosgraph_msgs/Log"; }
    static tinyros::string getTypeStatic(){ return "rosgraph_msgs/Log"; }
    virtual tinyros::string getMD5(){ return "2de9daf47e984009074d74dbdd492d49"; }
    static tinyros::string getMD5Static(){ return "2de9daf47e984009074d74dbdd492d49"; }
    virtual tinyros::string getDefinition(){ return "Header header\nbyte level\nstring name \nstring msg \nstring file \nstring function \nuint32 line \nstring[] topics \n"; }
    static tinyros::string getDefinitionStatic(){ return "Header header\nbyte level\nstring name \nstring msg \nstring file \nstring function \nuint32 line \nstring[] topics \n"; }
    static bool hasHeader(){ return true; }

  };

}
}
#endif
