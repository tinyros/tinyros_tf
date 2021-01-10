#ifndef _TINYROS_visualization_msgs_MenuEntry_h
#define _TINYROS_visualization_msgs_MenuEntry_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"

namespace tinyros
{
namespace visualization_msgs
{

  class MenuEntry : public tinyros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef uint32_t _parent_id_type;
      _parent_id_type parent_id;
      typedef tinyros::string _title_type;
      _title_type title;
      typedef tinyros::string _command_type;
      _command_type command;
      typedef uint8_t _command_type_type;
      _command_type_type command_type;
      enum { FEEDBACK = 0 };
      enum { ROSRUN = 1 };
      enum { ROSLAUNCH = 2 };

    MenuEntry():
      id(0),
      parent_id(0),
      title(""),
      command(""),
      command_type(0)
    {
    }

    ~MenuEntry()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      *(outbuffer + offset + 0) = (this->parent_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->parent_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->parent_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->parent_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->parent_id);
      uint32_t length_title = this->title.size();
      varToArr(outbuffer + offset, length_title);
      offset += 4;
      memcpy(outbuffer + offset, this->title.c_str(), length_title);
      offset += length_title;
      uint32_t length_command = this->command.size();
      varToArr(outbuffer + offset, length_command);
      offset += 4;
      memcpy(outbuffer + offset, this->command.c_str(), length_command);
      offset += length_command;
      *(outbuffer + offset + 0) = (this->command_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->command_type);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      this->parent_id =  ((uint32_t) (*(inbuffer + offset)));
      this->parent_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->parent_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->parent_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->parent_id);
      uint32_t length_title;
      arrToVar(length_title, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_title; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_title-1]=0;
      this->title = (char *)(inbuffer + offset-1);
      offset += length_title;
      uint32_t length_command;
      arrToVar(length_command, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_command; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_command-1]=0;
      this->command = (char *)(inbuffer + offset-1);
      offset += length_command;
      this->command_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->command_type);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->id);
      length += sizeof(this->parent_id);
      uint32_t length_title = this->title.size();
      length += 4;
      length += length_title;
      uint32_t length_command = this->command.size();
      length += 4;
      length += length_command;
      length += sizeof(this->command_type);
      return length;
    }

    virtual tinyros::string getType(){ return "visualization_msgs/MenuEntry"; }
    static tinyros::string getTypeStatic(){ return "visualization_msgs/MenuEntry"; }
    virtual tinyros::string getMD5(){ return "09ef68f346107bee9bb8f9c6b994b413"; }
    static tinyros::string getMD5Static(){ return "09ef68f346107bee9bb8f9c6b994b413"; }
    virtual tinyros::string getDefinition(){ return "uint32 id\nuint32 parent_id\nstring title\nstring command\nuint8 command_type\n"; }
    static tinyros::string getDefinitionStatic(){ return "uint32 id\nuint32 parent_id\nstring title\nstring command\nuint8 command_type\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
