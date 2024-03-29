#ifndef _TINYROS_actionlib_msgs_GoalID_h
#define _TINYROS_actionlib_msgs_GoalID_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/ros/time.h"

namespace tinyros
{
namespace actionlib_msgs
{

  class GoalID : public tinyros::Msg
  {
    public:
      typedef tinyros::Time _stamp_type;
      _stamp_type stamp;
      typedef tinyros::string _id_type;
      _id_type id;

    GoalID():
      stamp(),
      id("")
    {
    }

    ~GoalID()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      uint32_t length_id = this->id.size();
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id.c_str(), length_id);
      offset += length_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += sizeof(this->stamp.sec);
      length += sizeof(this->stamp.nsec);
      uint32_t length_id = this->id.size();
      length += 4;
      length += length_id;
      return length;
    }

    virtual tinyros::string getType(){ return "actionlib_msgs/GoalID"; }
    static tinyros::string getTypeStatic(){ return "actionlib_msgs/GoalID"; }
    virtual tinyros::string getMD5(){ return "a6cee90e5a185f4cb050de49bc4fa1f4"; }
    static tinyros::string getMD5Static(){ return "a6cee90e5a185f4cb050de49bc4fa1f4"; }
    virtual tinyros::string getDefinition(){ return "time stamp\nstring id\n"; }
    static tinyros::string getDefinitionStatic(){ return "time stamp\nstring id\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
