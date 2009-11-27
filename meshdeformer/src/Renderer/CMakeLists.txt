cmake_minimum_required(VERSION 2.6)

set(renderer_HEADERS
	Arcball.hpp
	Camera.hpp
	Viewport.hpp
	)
set(renderer_SOURCES 
	Arcball.cpp 
	Camera.cpp 
	Viewport.cpp
	)

include_directories(../Math)
include_directories(../Helper)
include_directories(../)

add_library(Renderer STATIC ${renderer_SOURCES} ${renderer_HEADERS})
target_link_libraries(Renderer Math)