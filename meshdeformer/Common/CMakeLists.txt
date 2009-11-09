cmake_minimum_required(VERSION 2.6)

find_package(Qt4 REQUIRED)
if(QT_FOUND)
  include(${QT_USE_FILE})
endif()

add_library(Common STATIC common.cpp )
target_link_libraries(Common ${QT_LIBRARIES})

