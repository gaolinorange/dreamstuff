cmake_minimum_required(VERSION 2.6)

include_directories(../Common)
include_directories(../Helper)

set(math_SOURCES 
	Vector3d.cpp
	Quaternion.cpp
	Matrix44.cpp)
set(math_HEADERS
	Vector3d.hpp
	Matrix44.hpp
	Quaternion.hpp
	)

add_library(Math STATIC ${math_HEADERS} ${math_SOURCES})