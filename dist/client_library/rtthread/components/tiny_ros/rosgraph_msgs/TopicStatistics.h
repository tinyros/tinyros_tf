#ifndef _TINYROS_rosgraph_msgs_TopicStatistics_h
#define _TINYROS_rosgraph_msgs_TopicStatistics_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/ros/time.h"
#include "tiny_ros/ros/duration.h"

namespace tinyros
{
namespace rosgraph_msgs
{

  class TopicStatistics : public tinyros::Msg
  {
    public:
      typedef tinyros::string _topic_type;
      _topic_type topic;
      typedef tinyros::string _node_pub_type;
      _node_pub_type node_pub;
      typedef tinyros::string _node_sub_type;
      _node_sub_type node_sub;
      typedef tinyros::Time _window_start_type;
      _window_start_type window_start;
      typedef tinyros::Time _window_stop_type;
      _window_stop_type window_stop;
      typedef int32_t _delivered_msgs_type;
      _delivered_msgs_type delivered_msgs;
      typedef int32_t _dropped_msgs_type;
      _dropped_msgs_type dropped_msgs;
      typedef int32_t _traffic_type;
      _traffic_type traffic;
      typedef tinyros::Duration _period_mean_type;
      _period_mean_type period_mean;
      typedef tinyros::Duration _period_stddev_type;
      _period_stddev_type period_stddev;
      typedef tinyros::Duration _period_max_type;
      _period_max_type period_max;
      typedef tinyros::Duration _stamp_age_mean_type;
      _stamp_age_mean_type stamp_age_mean;
      typedef tinyros::Duration _stamp_age_stddev_type;
      _stamp_age_stddev_type stamp_age_stddev;
      typedef tinyros::Duration _stamp_age_max_type;
      _stamp_age_max_type stamp_age_max;

    TopicStatistics():
      topic(""),
      node_pub(""),
      node_sub(""),
      window_start(),
      window_stop(),
      delivered_msgs(0),
      dropped_msgs(0),
      traffic(0),
      period_mean(),
      period_stddev(),
      period_max(),
      stamp_age_mean(),
      stamp_age_stddev(),
      stamp_age_max()
    {
    }

    ~TopicStatistics()
    {
      deconstructor();
    }

    void deconstructor()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_topic = this->topic.size();
      varToArr(outbuffer + offset, length_topic);
      offset += 4;
      memcpy(outbuffer + offset, this->topic.c_str(), length_topic);
      offset += length_topic;
      uint32_t length_node_pub = this->node_pub.size();
      varToArr(outbuffer + offset, length_node_pub);
      offset += 4;
      memcpy(outbuffer + offset, this->node_pub.c_str(), length_node_pub);
      offset += length_node_pub;
      uint32_t length_node_sub = this->node_sub.size();
      varToArr(outbuffer + offset, length_node_sub);
      offset += 4;
      memcpy(outbuffer + offset, this->node_sub.c_str(), length_node_sub);
      offset += length_node_sub;
      *(outbuffer + offset + 0) = (this->window_start.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->window_start.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->window_start.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->window_start.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->window_start.sec);
      *(outbuffer + offset + 0) = (this->window_start.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->window_start.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->window_start.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->window_start.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->window_start.nsec);
      *(outbuffer + offset + 0) = (this->window_stop.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->window_stop.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->window_stop.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->window_stop.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->window_stop.sec);
      *(outbuffer + offset + 0) = (this->window_stop.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->window_stop.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->window_stop.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->window_stop.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->window_stop.nsec);
      union {
        int32_t real;
        uint32_t base;
      } u_delivered_msgs;
      u_delivered_msgs.real = this->delivered_msgs;
      *(outbuffer + offset + 0) = (u_delivered_msgs.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_delivered_msgs.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_delivered_msgs.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_delivered_msgs.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->delivered_msgs);
      union {
        int32_t real;
        uint32_t base;
      } u_dropped_msgs;
      u_dropped_msgs.real = this->dropped_msgs;
      *(outbuffer + offset + 0) = (u_dropped_msgs.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dropped_msgs.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dropped_msgs.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dropped_msgs.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dropped_msgs);
      union {
        int32_t real;
        uint32_t base;
      } u_traffic;
      u_traffic.real = this->traffic;
      *(outbuffer + offset + 0) = (u_traffic.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_traffic.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_traffic.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_traffic.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->traffic);
      *(outbuffer + offset + 0) = (this->period_mean.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->period_mean.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->period_mean.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->period_mean.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->period_mean.sec);
      *(outbuffer + offset + 0) = (this->period_mean.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->period_mean.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->period_mean.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->period_mean.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->period_mean.nsec);
      *(outbuffer + offset + 0) = (this->period_stddev.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->period_stddev.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->period_stddev.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->period_stddev.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->period_stddev.sec);
      *(outbuffer + offset + 0) = (this->period_stddev.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->period_stddev.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->period_stddev.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->period_stddev.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->period_stddev.nsec);
      *(outbuffer + offset + 0) = (this->period_max.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->period_max.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->period_max.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->period_max.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->period_max.sec);
      *(outbuffer + offset + 0) = (this->period_max.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->period_max.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->period_max.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->period_max.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->period_max.nsec);
      *(outbuffer + offset + 0) = (this->stamp_age_mean.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp_age_mean.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp_age_mean.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp_age_mean.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp_age_mean.sec);
      *(outbuffer + offset + 0) = (this->stamp_age_mean.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp_age_mean.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp_age_mean.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp_age_mean.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp_age_mean.nsec);
      *(outbuffer + offset + 0) = (this->stamp_age_stddev.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp_age_stddev.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp_age_stddev.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp_age_stddev.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp_age_stddev.sec);
      *(outbuffer + offset + 0) = (this->stamp_age_stddev.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp_age_stddev.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp_age_stddev.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp_age_stddev.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp_age_stddev.nsec);
      *(outbuffer + offset + 0) = (this->stamp_age_max.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp_age_max.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp_age_max.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp_age_max.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp_age_max.sec);
      *(outbuffer + offset + 0) = (this->stamp_age_max.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp_age_max.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp_age_max.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp_age_max.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp_age_max.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_topic;
      arrToVar(length_topic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic-1]=0;
      this->topic = (char *)(inbuffer + offset-1);
      offset += length_topic;
      uint32_t length_node_pub;
      arrToVar(length_node_pub, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_node_pub; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_node_pub-1]=0;
      this->node_pub = (char *)(inbuffer + offset-1);
      offset += length_node_pub;
      uint32_t length_node_sub;
      arrToVar(length_node_sub, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_node_sub; ++k){
        inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_node_sub-1]=0;
      this->node_sub = (char *)(inbuffer + offset-1);
      offset += length_node_sub;
      this->window_start.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->window_start.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->window_start.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->window_start.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->window_start.sec);
      this->window_start.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->window_start.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->window_start.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->window_start.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->window_start.nsec);
      this->window_stop.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->window_stop.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->window_stop.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->window_stop.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->window_stop.sec);
      this->window_stop.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->window_stop.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->window_stop.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->window_stop.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->window_stop.nsec);
      union {
        int32_t real;
        uint32_t base;
      } u_delivered_msgs;
      u_delivered_msgs.base = 0;
      u_delivered_msgs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_delivered_msgs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_delivered_msgs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_delivered_msgs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->delivered_msgs = u_delivered_msgs.real;
      offset += sizeof(this->delivered_msgs);
      union {
        int32_t real;
        uint32_t base;
      } u_dropped_msgs;
      u_dropped_msgs.base = 0;
      u_dropped_msgs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dropped_msgs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dropped_msgs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dropped_msgs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dropped_msgs = u_dropped_msgs.real;
      offset += sizeof(this->dropped_msgs);
      union {
        int32_t real;
        uint32_t base;
      } u_traffic;
      u_traffic.base = 0;
      u_traffic.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_traffic.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_traffic.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_traffic.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->traffic = u_traffic.real;
      offset += sizeof(this->traffic);
      this->period_mean.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->period_mean.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->period_mean.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->period_mean.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->period_mean.sec);
      this->period_mean.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->period_mean.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->period_mean.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->period_mean.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->period_mean.nsec);
      this->period_stddev.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->period_stddev.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->period_stddev.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->period_stddev.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->period_stddev.sec);
      this->period_stddev.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->period_stddev.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->period_stddev.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->period_stddev.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->period_stddev.nsec);
      this->period_max.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->period_max.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->period_max.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->period_max.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->period_max.sec);
      this->period_max.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->period_max.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->period_max.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->period_max.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->period_max.nsec);
      this->stamp_age_mean.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp_age_mean.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp_age_mean.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp_age_mean.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp_age_mean.sec);
      this->stamp_age_mean.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp_age_mean.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp_age_mean.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp_age_mean.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp_age_mean.nsec);
      this->stamp_age_stddev.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp_age_stddev.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp_age_stddev.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp_age_stddev.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp_age_stddev.sec);
      this->stamp_age_stddev.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp_age_stddev.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp_age_stddev.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp_age_stddev.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp_age_stddev.nsec);
      this->stamp_age_max.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp_age_max.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp_age_max.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp_age_max.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp_age_max.sec);
      this->stamp_age_max.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp_age_max.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp_age_max.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp_age_max.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp_age_max.nsec);
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      uint32_t length_topic = this->topic.size();
      length += 4;
      length += length_topic;
      uint32_t length_node_pub = this->node_pub.size();
      length += 4;
      length += length_node_pub;
      uint32_t length_node_sub = this->node_sub.size();
      length += 4;
      length += length_node_sub;
      length += sizeof(this->window_start.sec);
      length += sizeof(this->window_start.nsec);
      length += sizeof(this->window_stop.sec);
      length += sizeof(this->window_stop.nsec);
      length += sizeof(this->delivered_msgs);
      length += sizeof(this->dropped_msgs);
      length += sizeof(this->traffic);
      length += sizeof(this->period_mean.sec);
      length += sizeof(this->period_mean.nsec);
      length += sizeof(this->period_stddev.sec);
      length += sizeof(this->period_stddev.nsec);
      length += sizeof(this->period_max.sec);
      length += sizeof(this->period_max.nsec);
      length += sizeof(this->stamp_age_mean.sec);
      length += sizeof(this->stamp_age_mean.nsec);
      length += sizeof(this->stamp_age_stddev.sec);
      length += sizeof(this->stamp_age_stddev.nsec);
      length += sizeof(this->stamp_age_max.sec);
      length += sizeof(this->stamp_age_max.nsec);
      return length;
    }

    virtual tinyros::string getType(){ return "rosgraph_msgs/TopicStatistics"; }
    static tinyros::string getTypeStatic(){ return "rosgraph_msgs/TopicStatistics"; }
    virtual tinyros::string getMD5(){ return "8b30d3f22284a3bee7679b7194bd38a3"; }
    static tinyros::string getMD5Static(){ return "8b30d3f22284a3bee7679b7194bd38a3"; }
    virtual tinyros::string getDefinition(){ return "string topic\nstring node_pub\nstring node_sub\ntime window_start\ntime window_stop\nint32 delivered_msgs\nint32 dropped_msgs\nint32 traffic\nduration period_mean\nduration period_stddev\nduration period_max\nduration stamp_age_mean\nduration stamp_age_stddev\nduration stamp_age_max\n"; }
    static tinyros::string getDefinitionStatic(){ return "string topic\nstring node_pub\nstring node_sub\ntime window_start\ntime window_stop\nint32 delivered_msgs\nint32 dropped_msgs\nint32 traffic\nduration period_mean\nduration period_stddev\nduration period_max\nduration stamp_age_mean\nduration stamp_age_stddev\nduration stamp_age_max\n"; }
    static bool hasHeader(){ return false; }

  };

}
}
#endif
