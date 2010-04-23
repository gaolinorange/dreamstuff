### CMakeLists.txt --- A Test Script for FindXXX.cmake script
## copyright (c) 2010 dreamway
## 
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by the Free Software Foundation;
##  Free free to contact dreamway(jingwenlai@163.com)
## 
## website: cg.xplore.cn
## 
######################################################################
## 
### Commentary: This is a Test script for testing the FindXXX.cmake script of
##              external libraries
## 
######################################################################
##  
cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")
message(STATUS,${CMAKE_MODULE_PATH})


find_package(glog REQUIRED)
if(glog_FOUND)
  message(STATUS,${glog_INCLUDE_DIR})
  message(STATUS,${glog_LIBRARY})
else(glog_FOUND)
  message(FATEL,"Could not found glog : ${glog_INCLUDE_DIR}")
  message(FATEL,"Could not found glog lib: ${glog_LIBRARY}")
endif(glog_FOUND)

  
######################################################################
### CMakeLists.txt ends here
