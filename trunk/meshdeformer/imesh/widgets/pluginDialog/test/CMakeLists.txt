set(target_name plugindialog_test)

cmake_minimum_required(VERSION 2.6)

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

include_directories(../)

add_executable(${target_name} test_plugindialog.cpp)
target_link_libraries(${target_name} ${QT_LIBRARIES})

