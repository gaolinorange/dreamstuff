cmake_minimum_required(VERSION 2.6)

SET(app_SOURCES 
	main_window.cpp 
	main_widget.cpp 
	app_data.cpp
	)
SET(app_HEADERS 
	main_window.h 
	main_widget.h 
	app_data.h
	QOutputLogger.hpp
	)

FIND_PACKAGE(Qt4 4.5.2 COMPONENTS QtGui QtCore QtOpenGL REQUIRED)
set(QT_USE_QTOPENGL true) #set this true if you want to use OpenGL, see FindQt4.cmake for more details
INCLUDE( ${QT_USE_FILE})

#warp the Q_OBJECT file
QT4_WRAP_CPP(MainWidget_MOC main_widget.h)
qt4_wrap_cpp(MainWindow_MOC main_window.h)

include_directories(../)
include_directories(../Renderer)
include_directories(../Math)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)


ADD_DEFINITIONS(${QT_DEFINITIONS})


ADD_library(MainWindow STATIC ${app_SOURCES} ${MainWidget_MOC} ${MainWindow_MOC} ${app_HEADERS})
target_link_libraries(MainWindow ${QT_LIBRARIES} gtest gtest_main MeshCore Renderer)

