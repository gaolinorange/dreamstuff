cmake_minimum_required(VERSION 2.6)


# find_package(CGAL REQUIRED)
# if(CGAL_FOUND)
#   include(${CGAL_USE_FILE})
# endif()
#find_package(BOOST REQUIRED)
find_package(Boost)
if(Boost_FOUND)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
endif()


find_package(OpenGL REQUIRED)
if(OpenGL_FOUND)
include_directories(${GLU_INCLUDE_PATH})
link_libraries(${OPENGL_LIBRARIES})
endif()

if(UNIX)
	set(CGAL_DIR /usr/local/lib/CGAL)
endif(UNIX)


find_package(CGAL REQUIRED)
if(CGAL_FOUND)
  include(${CGAL_USE_FILE})   
endif()

set(MeshCore_HEADERS MeshCore.h MeshBuilder.h MeshLoader.h)
set(MeshCore_SOURCES MeshCore.cpp)
  
include_directories(../Common)  
include_directories(/usr/local/include)
link_directories(/usr/local/lib)


add_library(MeshCore STATIC ${MeshCore_HEADERS} ${MeshCore_SOURCES})
target_link_libraries(MeshCore ${Boost_LIBRARIES})

