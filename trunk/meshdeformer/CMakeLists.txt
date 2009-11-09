#CMake file for project ROOT

PROJECT(MeshDeformer)

cmake_minimum_required(VERSION 2.6)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin )
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib )

find_package(Qt4 REQUIRED)
set(QT_USE_QTOPENGL true)
include(${QT_USE_FILE})

#find_package(BOOST REQUIRED)
find_package(Boost)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  link_directories(${Boost_LIBRARY_DIRS})
endif()

  

#the MainWindow subcore
include_directories(${CMAKE_SOURCE_DIR}/MainWindow)
ADD_SUBDIRECTORY(MainWindow)
#the MeshCore subcore
add_subdirectory(MeshCore)
include_directories(${CMAKE_SOURCE_DIR}/MeshCore)
#the IO Plugin subcore
add_subdirectory(IOPlugin)

#the Common module
include_directories(${CMAKE_SOURCE_DIR}/Common)
add_subdirectory(Common)


#the math subcore
include_directories(${CMAKE_SOIURCE_DIR}/Math)

add_subdirectory(test)#adding test support

add_subdirectory(Renderer)

add_executable(MeshDeformer main.cpp )
target_link_libraries(MeshDeformer MainWindow MeshCore Common test)


