
cmake_minimum_required(VERSION 2.6)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin/plugins)

find_package(Qt4 REQUIRED)

include(${QT_USE_FILE})
include_directories(../imesh)

qt4_wrap_cpp(TestPlugin_MOC TestPlugin.h)

add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_PLUGIN)
add_definitions(-DQT_SHARED)
add_definitions(-DQT_NO_DEBUG)

#add_library(test_plugin SHARED TestPlugin.cpp ${TestPlugin_MOC})
add_library(test_plugin STATIC TestPlugin.cpp ${TestPlugin_MOC})
target_link_libraries(test_plugin ${QT_LIBRARIES})
