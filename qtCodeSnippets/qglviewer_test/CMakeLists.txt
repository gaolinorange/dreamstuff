project(qglviewer_test)
set(target_name test)

set(CMAKE_BUILD_TYPE Debug)

cmake_minimum_required(VERSION 2.6)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")

find_package(Qt4 COMPONENTS  QtCore QtGui QtOpenGL REQUIRED)
set(QT_USE_OPENGL true)
set(QT_USE_QTXML true)
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

#for QGLViewer
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

set(app_sources
  MainWidget.cpp
  main.cpp)

set(app_headers
  MainWidget.hh
  )



add_executable(${target_name}
  ${app_sources}
  ${app_headers}
  )
target_link_libraries(${target_name}
  ${QT_LIBRARIES}
  QGLViewer
#  bind_at_load
  )
