cmake_minimum_required(VERSION 2.6)

include_directories(../include)

SET(src_SOURCES GLWidget.cpp main.cpp app_window.cpp)
SET(src_HEADERS GLWidget.h app_window.h)

set(CMAKE_BUILD_TYPE Release)


FIND_PACKAGE(Qt4 4.5.2 COMPONENTS QtCore QtGui QtOpenGL REQUIRED)
INCLUDE (${QT_USE_FILE})

find_package(OpenGL REQUIRED)

find_package(JPEG)
find_package(ZLIB)

if(UNIX)
	if(APPLE)
		find_library(CARBON_LIBRARY Carbon)
	endif(APPLE)
endif(UNIX)		



if(UNIX)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include /usr/local/include/G3D /usr/local/include/GLG3D ${OPENGL_INCLUDE_DIR} ${JPEG_INCLUDE_DIR} ${ZLIB_INCLUDE_DIR}) #due to the conflict between OpenGL framework and QtOpenGL framework
elseif(UNIX)
if(WIN32)
include_directories(${CMAKE_SOURCE_DIR}/include ${OPENGL_INCLUDE_DIR} {JPEG_INCLUDE_DIR} ${ZLIB_INCLUDE_DIR})
endif(WIN32)
endif(UNIX)

if(UNIX)
	link_directories(/usr/local/lib ${OPENGL_LIBRARIES} ${JPEG_LIBRARIES} ${ZLIB_LIBRARIES})
elseif(UNIX)
	link_directories(${OPENGL_LIBRARIES} ${JPEG_LIBRARIES} ${ZLIB_LIBRARIES})
endif(UNIX)


if(APPLE)
	add_definitions(-D__powerpc__)
endif(APPLE)

ADD_DEFINITIONS(${QT_DEFINITIONS})

add_executable(MeshDeformer ${src_SOURCES})

#if(APPLE)
# 	target_link_libraries(MeshDeformer  GLG3D G3D ${QT_LIBRARIES} avcodec avdevice avutil avformat png jpeg z zip ${CARBON_LIBRARY})
#elseif(APPLE)
# 	target_link_libraries(MeshDeformer GLD3D G3D ${QT_LIBRARIES} avcodec avdevice avutil avformat png jpeg z zip)
#end(APPLE)

target_link_libraries(MeshDeformer  GLG3D G3D ${QT_LIBRARIES} avcodec avutil avformat png jpeg zip ) 

#target_link_libraries(MeshDeformer ${QT_LIBRARIES} GLG3D G3D ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} avcodec avdevice avutil avformat png jpeg z zip ${CARBON_LIBRARY})
