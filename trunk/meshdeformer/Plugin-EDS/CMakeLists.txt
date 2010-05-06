set(target_name eds)

cmake_minimum_required(VERSION 2.6)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/plugins)

find_package(Qt4 REQUIRED)
set(QT_USE_QTOPENGL TRUE)
include(${QT_USE_FILE})

include_directories(../imesh)

find_package(Boost REQUIRED)
if(Boost_FOUND)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
endif()

find_package(glog REQUIRED)
if(glog_FOUND)
  include_directories(${glog_INCLUDE_DIR})
  link_libraries(${glog_LIBRARY})
endif(glog_FOUND)


qt4_wrap_cpp(EDS_MOC EDS.h)


set(headers
  EDS.h
  DeformationGraph.h
  )

set(sources
  EDS.cpp
  DeformationGraph.cpp
  ${EDS_MOC}
  )


add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_PLUGIN)
add_definitions(-DQT_SHARED)
add_definitions(-DQT_NO_DEBUG)

add_library(${target_name} SHARED ${sources} ${headers})
target_link_libraries(${target_name} ${QT_LIBRARIES} MeshCore)
