#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <tiny_ros/ros.h>
#include "tiny_ros/package.h"

namespace tinyros {
namespace package {
  std::string getPath(std::string package) {
    char  exe_path[PATH_MAX+1];
    int  cnt = readlink( "/proc/self/exe" , exe_path, PATH_MAX+1);
    if(cnt > 0 && cnt < (PATH_MAX+1)) {
      for(int i = cnt; i >=0; --i) {
       if(exe_path[i] ==  '/' ) {
          exe_path[i+1] =  '\0' ;
          std::string packate_path = std::string(exe_path) + "share/" + package;
          return packate_path;
       }
      }
    }
    return "";
  }
}
}

