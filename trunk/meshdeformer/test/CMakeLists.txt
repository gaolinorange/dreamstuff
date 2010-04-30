cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ../cmake)

include_directories(../imesh)
include_directories(..)



find_package(Boost REQUIRED)
if(Boost_FOUND)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
endif()


find_package(Qt4 REQUIRED)
set(QT_USE_QTCORE true)
set(QT_USE_QTGUI true)
set(QT_USE_QTXML true)
set(QT_USE_QTTEST true)
set(QT_USE_QTOPENGL true)

include(${QT_USE_FILE})

if(UNIX)
set(CGAL_DIR /usr/local/lib/CGAL)
endif(UNIX)
find_package(CGAL REQUIRED)
if(CGAL_FOUND)
include(${CGAL_USE_FILE})
endif()

#google test support
find_package(gtest REQUIRED)
if(gtest_FOUND)
  include_directories(${gtest_INCLUDE_DIR})
endif(gtest_FOUND)

#google glog support
find_package(glog REQUIRED)
include_directories(${glog_INCLUDE_DIR})
  
#assimp support
find_package(assimp REQUIRED)
if(assimp_FOUND)
  include_directories(${assimp_INCLUDE_DIR})
endif(assimp_FOUND)

#searching for QGLViewer library
if(UNIX)
  #for apple only, explicitly linking directory
  if(APPLE)
    include_directories(/usr/local/include)
    link_directories(/usr/local/lib)
  else(APPLE)
    find_package(QGLViewer REQUIRED)
    if(QGLViewer_FOUND)
      include_directories(${QGLViewer_INCLUDE_DIR})
    endif(QGLViewer_FOUND)
  endif(APPLE)
endif(UNIX)




#add some more moc generated files of test objects
qt4_wrap_cpp(TestPlugin_MOC ../Plugin-TestPlugin/TestPlugin.h)


set(TEST_HEADERS
  test.h)

set(TEST_SOURCES
  testMain.cpp
  ${TestPlugin_MOC}
  ../Plugin-EDS/DeformationGraph.cpp #for testing DeformationGraph
  )


add_executable(test
  ${TEST_HEADERS}
  ${TEST_SOURCES}
  )
target_link_libraries(test
  ${QT_LIBRARIES}
  MeshCore
  ${assimp_LIBRARY}
  ${gtest_LIBRARY}
  ${glog_LIBRARY}
  curvature  #the curvature plugin
  eds
  )