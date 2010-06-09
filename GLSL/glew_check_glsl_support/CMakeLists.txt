project(glew_check_glsl_support)

cmake_minimum_required(VERSION 2.6)

find_package(OpenGL)
if(OPENGL_FOUND)
  include_directories(${OPENGL_INCLUDE_DIR})
endif(OPENGL_FOUND)
find_package(GLUT)
if(GLUT_FOUND)
  include_directories(${GLUT_INCLUDE_DIR})
endif(GLUT_FOUND)

find_package(GLEW)
if(GLEW_FOUND)
  include_directories(${GLEW_INCLUDE_PATH})  
endif(GLEW_FOUND)

set(target_name test)
add_executable(${target_name} glew_check_glsl_version.cpp)
target_link_libraries(${target_name} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIBRARY})