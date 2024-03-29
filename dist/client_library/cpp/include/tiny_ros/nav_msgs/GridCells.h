#ifndef _TINYROS_nav_msgs_GridCells_h
#define _TINYROS_nav_msgs_GridCells_h

#include <stdint.h>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tiny_ros/ros/msg.h"
#include "tiny_ros/std_msgs/Header.h"
#include "tiny_ros/geometry_msgs/Point.h"

namespace tinyros
{
namespace nav_msgs
{

  class GridCells : public tinyros::Msg
  {
    public:
      typedef tinyros::std_msgs::Header _header_type;
      _header_type header;
      typedef float _cell_width_type;
      _cell_width_type cell_width;
      typedef float _cell_height_type;
      _cell_height_type cell_height;
      typedef tinyros::geometry_msgs::Point _cells_type;
      std::vector<_cells_type> cells;

    GridCells():
      header(),
      cell_width(0),
      cell_height(0),
      cells(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_cell_width;
      u_cell_width.real = this->cell_width;
      *(outbuffer + offset + 0) = (u_cell_width.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cell_width.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cell_width.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cell_width.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cell_width);
      union {
        float real;
        uint32_t base;
      } u_cell_height;
      u_cell_height.real = this->cell_height;
      *(outbuffer + offset + 0) = (u_cell_height.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cell_height.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_cell_height.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_cell_height.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->cell_height);
      uint32_t cells_length = this->cells.size();
      *(outbuffer + offset + 0) = (cells_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (cells_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (cells_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (cells_length >> (8 * 3)) & 0xFF;
      offset += sizeof(cells_length);
      for( uint32_t i = 0; i < cells_length; i++) {
        offset += this->cells[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_cell_width;
      u_cell_width.base = 0;
      u_cell_width.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cell_width.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cell_width.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cell_width.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cell_width = u_cell_width.real;
      offset += sizeof(this->cell_width);
      union {
        float real;
        uint32_t base;
      } u_cell_height;
      u_cell_height.base = 0;
      u_cell_height.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cell_height.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_cell_height.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_cell_height.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->cell_height = u_cell_height.real;
      offset += sizeof(this->cell_height);
      uint32_t cells_length = ((uint32_t) (*(inbuffer + offset))); 
      cells_length |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      cells_length |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      cells_length |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      this->cells.resize(cells_length); 
      offset += sizeof(cells_length);
      for( uint32_t i = 0; i < cells_length; i++) {
        offset += this->cells[i].deserialize(inbuffer + offset);
      }
      return offset;
    }

    virtual int serializedLength() const
    {
      int length = 0;
      length += this->header.serializedLength();
      length += sizeof(this->cell_width);
      length += sizeof(this->cell_height);
      uint32_t cells_length = this->cells.size();
      length += sizeof(cells_length);
      for( uint32_t i = 0; i < cells_length; i++) {
        length += this->cells[i].serializedLength();
      }
      return length;
    }

    virtual std::string echo()
    {
      std::string string_echo = "{";
      string_echo += "\"header\":";
      string_echo += this->header.echo();
      string_echo += ",";
      std::stringstream ss_cell_width; ss_cell_width << "\"cell_width\":" << cell_width <<",";
      string_echo += ss_cell_width.str();
      std::stringstream ss_cell_height; ss_cell_height << "\"cell_height\":" << cell_height <<",";
      string_echo += ss_cell_height.str();
      uint32_t cells_length = this->cells.size();
      string_echo += "cells:[";
      for( uint32_t i = 0; i < cells_length; i++) {
        if( i == (cells_length - 1)) {
          string_echo += this->cells[i].echo();
          string_echo += "";
        } else {
          string_echo += this->cells[i].echo();
          string_echo += ",";
        }
      }
      string_echo += "]";
      string_echo += "}";
      return string_echo;
    }

    virtual std::string getType(){ return "nav_msgs/GridCells"; }
    static std::string getTypeStatic(){ return "nav_msgs/GridCells"; }
    virtual std::string getMD5(){ return "13ce9063aaf922c39d3a2207d3926427"; }
    static std::string getMD5Static(){ return "13ce9063aaf922c39d3a2207d3926427"; }
    virtual std::string getDefinition(){ return "Header header\nfloat32 cell_width\nfloat32 cell_height\ngeometry_msgs/Point[] cells\n"; }
    static std::string getDefinitionStatic(){ return "Header header\nfloat32 cell_width\nfloat32 cell_height\ngeometry_msgs/Point[] cells\n"; }
    static bool hasHeader(){ return true; }
    typedef std::shared_ptr<tinyros::nav_msgs::GridCells> Ptr;
    typedef std::shared_ptr<tinyros::nav_msgs::GridCells const> ConstPtr;
  };
typedef std::shared_ptr<tinyros::nav_msgs::GridCells> GridCellsPtr;
typedef std::shared_ptr<tinyros::nav_msgs::GridCells const> GridCellsConstPtr;

}
}
#endif
