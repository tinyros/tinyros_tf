#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <tiny_ros/ros.h>
#include "tiny_ros/package.h"

namespace tinyros {
namespace package {
  std::string getPath(std::string package) {
#ifdef __linux__
    char  exec_path[PATH_MAX+1];
    int  cnt = readlink( "/proc/self/exe" , exec_path, PATH_MAX+1);
    if(cnt > 0 && cnt < (PATH_MAX+1)) {
      for(int i = cnt; i >=0; --i) {
       if(exec_path[i] ==  '/' ) {
          exec_path[i+1] =  '\0' ;
          std::string packate_path = std::string(exec_path) + "pkg_" + package + "/";
          return packate_path;
       }
      }
    }
#endif
    return "";
  }

  std::string getExecPath() {
#ifdef __linux__
    char  exec_path[PATH_MAX+1];
    int  cnt = readlink( "/proc/self/exe" , exec_path, PATH_MAX+1);
    if(cnt > 0 && cnt < (PATH_MAX+1)) {
      for(int i = cnt; i >=0; --i) {
       if(exec_path[i] ==  '/' ) {
          exec_path[i+1] =  '\0' ;
          return exec_path;
       }
      }
    }
#endif
    return "";
  }
}
}

