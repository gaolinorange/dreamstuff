set(target_name curvature)

cmake_minimum_required(VERSION 2.6)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/plugins)

find_package(Qt4 REQUIRED)

include(${QT_USE_FILE})
include_directories(../imesh)


qt4_wrap_cpp(Curvature_MOC Curvature.h)

add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_PLUGIN)
add_definitions(-DQT_SHARED)
add_definitions(-DQT_NO_DEBUG)

add_library(${target_name} SHARED Curvature.cpp ${Curvature_MOC})
target_link_libraries(${target_name} ${QT_LIBRARIES})
