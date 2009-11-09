cmake_minimum_required(VERSION 2.6)

set(renderer_SOURCES Arcball.cpp Camera.cpp Viewport.cpp)

include_directories(../Math)
include_directories(../Helper)
include_directories(../)

add_library(Renderer STATIC ${renderer_SOURCES})
target_link_libraries(Renderer Math)