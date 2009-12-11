project(MeshDeformer)


cmake_minimum_required(VERSION 2.6)


SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib )


if(UNIX)
  if(APPLE)
    add_definitions(-D__APPLE__)
    set(Platform "apple")
  else(APPLE)
    add_definitions(-D__LINUX__)
    set(Platform "linux")
  endif(APPLE)
else(UNIX)
  if(WIN32)
    add_definitions(-D__WIN32__)
    set(Platform "win32")
  endif(WIN32)
endif(UNIX)
message("Platform is ${Platform}")


add_subdirectory(src)
