#CMake file for project ROOT

cmake_minimum_required(VERSION 2.6)

find_package(Qt4 COMPONENTS QtGui QtCore QtOpenGL QtTest REQUIRED)
set(QT_USE_QTOPENGL true)
set(QT_USE_QTTEST true)

include(${QT_USE_FILE})

find_package(Boost)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  link_directories(${Boost_LIBRARY_DIRS})
endif()


SET(MAINWINDOW_SOURCES
	main_window.cpp 
	main_widget.cpp 
	app_data.cpp
	QOutputLogger.cpp
	)
SET(MAINWINDOW_HEADERS
	main_window.h 
	main_widget.h 
	app_data.h
	QOutputLogger.hpp
	)


#warp the Q_OBJECT file
qt4_wrap_cpp(MainWidget_MOC main_widget.h)
qt4_wrap_cpp(MainWindow_MOC main_window.h)

include_directories(Renderer)
include_directories(Math)
include_directories(Common)
include_directories(MeshCore)


if(UNIX)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)
endif(UNIX)

ADD_DEFINITIONS(${QT_DEFINITIONS})

add_subdirectory(MeshCore)#the MeshCore subcore
add_subdirectory(Math)	#the math subcore
add_subdirectory(Renderer)

#assimp importer module
include_directories(../3rdparty/assimp/include)
link_directories(../3rdparty/assimp/lib)



add_executable(meshdeformer main.cpp 
	${MAINWINDOW_HEADERS} 
	${MAINWINDOW_SOURCES} 
	${MainWindow_MOC} 
	${MainWidget_MOC}
	)
target_link_libraries(meshdeformer MeshCore Renderer Math ${QT_LIBRARIES} gtest gtest_main assimp)


