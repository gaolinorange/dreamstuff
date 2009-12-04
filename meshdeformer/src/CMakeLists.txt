#CMake file for project ROOT

#PROJECT(MeshDeformer)

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


find_package(Qt4 COMPONENTS QtGui QtCore QtOpenGL QtTest REQUIRED)
set(QT_USE_QTOPENGL true)
set(QT_USE_QTTEST true)
include(${QT_USE_FILE})

#find_package(BOOST REQUIRED)
find_package(Boost)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  link_directories(${Boost_LIBRARY_DIRS})
endif()

  

#the MainWindow subcore
include_directories(MainWindow)
include_directories(Math)



ADD_SUBDIRECTORY(MainWindow)
#the MeshCore subcore
add_subdirectory(MeshCore)

#the IO Plugin subcore
add_subdirectory(IOPlugin)

#the math subcore
add_subdirectory(Math)
add_subdirectory(Renderer)


#add external link libraries
link_directories(../3rdparty/assimp/lib)


add_executable(meshdeformer main.cpp )
target_link_libraries(meshdeformer MainWindow MeshCore Renderer Math ${QT_LIBRARIES} )


