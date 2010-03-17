project(boostTest)

cmake_minimum_required(VERSION 2.6)

find_package(Boost REQUIRED)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()

#add_executable(test main.cpp)
add_executable(test test_ptr_property_map_main.cpp)
target_link_libraries(test ${Boost_LIBRARIES})
