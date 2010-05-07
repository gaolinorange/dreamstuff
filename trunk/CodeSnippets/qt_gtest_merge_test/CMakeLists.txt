project(qt_gtest_merge_test)


cmake_minimum_required(VERSION 2.6)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules/")


find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

find_package(gtest REQUIRED)
if(gtest_FOUND)
  include_directories(${gtest_INCLUDE_DIR})
endif(gtest_FOUND)


set(app_sources
  main.cpp
  TestWidget.cpp
  )

set(test_sources
  test_main.cpp
  TestWidget.cpp
  )

add_executable(app ${app_sources})
target_link_libraries(app ${QT_LIBRARIES})

add_executable(test ${test_sources})
target_link_libraries(test ${QT_LIBRARIES} ${gtest_LIBRARY})

  
  
