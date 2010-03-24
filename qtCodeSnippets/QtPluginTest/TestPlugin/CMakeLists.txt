project(PluginTest)

cmake_minimum_required(VERSION 2.6)

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

qt4_wrap_cpp(TestPlugin_MOC  TestPlugin.h)


# a plugin is a shared library, but build in a certain environment
add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_PLUGIN)
add_definitions(-DQT_SHARED)
add_definitions(-DQT_NO_DEBUG)


add_library(test_plugin SHARED TestPlugin.cc ${TestPlugin_MOC})
target_link_libraries(test_plugin ${QT_LIBRARIES})