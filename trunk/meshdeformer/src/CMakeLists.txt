
#CMake file for project ROOT

cmake_minimum_required(VERSION 2.6)
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")


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


# for PythonConsoleWidget
find_package(PythonLibs REQUIRED)
if(PYTHONLIBS_FOUND)
  include_directories(${PYTHON_INCLUDE_PATH})
  include_directories(/usr/local/include/PythonQt) # for PythonQt
  link_directories(/usr/local/lib)
else(PYTHONLIBS_FOUND)
  message("could not find PythonLibs")
endif(PYTHONLIBS_FOUND)



include_directories(.)
include_directories(Common)
include_directories(MeshCore)





SET(APP_SOURCES
	Core/MainWindow.cpp 
	Core/Viewer.cpp 
	Core/Model.cpp
	widgets/consoleWidgets/ConsoleWidgetManager.cpp
	widgets/consoleWidgets/pythonConsoleWidget/PythonConsoleWidget.cpp
	widgets/consoleWidgets/loggerWidget/LoggerWidget.cpp
	)
SET(APP_HEADERS
	Core/MainWindow.h 
	Core/Viewer.h 
	Core/Model.h
	widgets/consoleWidgets/ConsoleWidgetManager.h
	widgets/consoleWidgets/pythonConsoleWidget/PythonConsoleWidget.h
	widgets/consoleWidgets/loggerWidget/LoggerWidget.h
	)


#warp the Q_OBJECT file
#qt4_wrap_cpp(MainWidget_MOC MainWidget.h)
#qt4_wrap_cpp(MainWindow_MOC MainWindow.h)
qt4_wrap_cpp(SOURCE_MOCS ${APP_HEADERS})



ADD_DEFINITIONS(${QT_DEFINITIONS})

add_subdirectory(MeshCore)#the MeshCore subcore
#add_subdirectory(Math)	#the math subcore
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


add_executable(meshdeformer
  main.cpp 
  ${APP_HEADERS} 
  ${APP_SOURCES} 
  ${SOURCE_MOCS} 
  )

if(WIN32)
target_link_libraries(meshdeformer MeshCore ${QT_LIBRARIES} gtest gtest_main assimp QGLViewer2)
endif(WIN32)

if(UNIX)
  target_link_libraries(meshdeformer MeshCore ${QT_LIBRARIES} gtest gtest_main assimp QGLViewer PythonQt)
endif(UNIX)


