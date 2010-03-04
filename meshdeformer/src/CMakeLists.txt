
#CMake file for project ROOT

cmake_minimum_required(VERSION 2.6)

find_package(Qt4 COMPONENTS QtGui QtCore QtOpenGL QtTest REQUIRED)
set(QT_USE_QTOPENGL true)
set(QT_USE_QTTEST true)
set(QT_USE_QTXML true)

include(${QT_USE_FILE})

find_package(Boost)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  link_directories(${Boost_LIBRARY_DIRS})
endif()


SET(MAINWINDOW_SOURCES
	MainWindow.cpp 
	MainWidget.cpp 
	AppData.cpp
	LoggerWidget.cpp
	)
SET(MAINWINDOW_HEADERS
	MainWindow.h 
	MainWidget.h 
	AppData.h
	LoggerWidget.h
	)


#warp the Q_OBJECT file
qt4_wrap_cpp(MainWidget_MOC MainWidget.h)
qt4_wrap_cpp(MainWindow_MOC MainWindow.h)

#include_directories(Renderer)
include_directories(Math)
include_directories(Common)
include_directories(MeshCore)


ADD_DEFINITIONS(${QT_DEFINITIONS})

add_subdirectory(MeshCore)#the MeshCore subcore
add_subdirectory(Math)	#the math subcore
#add_subdirectory(Renderer)

#assimp importer module
include_directories(../3rdparty/assimp/include)
link_directories(../../3rdparty/assimp/lib)

#for libQGLViewer
if(APPLE)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)
endif(APPLE)
if(LINUX)
  include_directories(/usr/include)
  link_directories(/usr/lib)
endif(LINUX)
if(WIN32)
include_directories("D:/DevTools")
link_directories("D:/DevTools/QGLViewer/release")
endif(WIN32)


add_executable(meshdeformer main.cpp 
	${MAINWINDOW_HEADERS} 
	${MAINWINDOW_SOURCES} 
	${MainWindow_MOC} 
	${MainWidget_MOC}
	)
if(WIN32)
target_link_libraries(meshdeformer MeshCore Math ${QT_LIBRARIES} gtest gtest_main assimp QGLViewer2)
endif(WIN32)

if(UNIX)
  target_link_libraries(meshdeformer MeshCore Math ${QT_LIBRARIES} gtest gtest_main assimp QGLViewer)
endif(UNIX)


