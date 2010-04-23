#CMake file for project ROOT
set(target_name imesh)

cmake_minimum_required(VERSION 2.6)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ../cmake)


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

#assimp importer module
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

# for PythonConsoleWidget
find_package(PythonLibs REQUIRED)
if(PYTHONLIBS_FOUND)
  include_directories(${PYTHON_INCLUDE_PATH})
else(PYTHONLIBS_FOUND)
  message("could not find PythonLibs")
endif(PYTHONLIBS_FOUND)

#find package PythonQt
find_package(PythonQt)
if(PythonQt_FOUND)
  include_directories(${PYTHONQT_INCLUDE_DIR})
  link_directories(${PYTHONQT_LIBRARY})
else(PythonQt_FOUND)
  message(FATAL_ERROR,"Cound not find the PythonQt library")
endif(PythonQt_FOUND)  

#find package google-glog
find_package(glog)
if(glog_FOUND)
  include_directories(${glog_INCLUDE_DIR})
  link_directories(${glog_LIBRARY})
else(glog_FOUND)
  message(ERROR,"Could not found glog library")
endif(glog_FOUND)



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


add_executable(${target_name}
  main.cpp 
  ${APP_HEADERS} 
  ${APP_SOURCES} 
  ${SOURCE_MOCS} 
  )

if(WIN32)
  target_link_libraries(${target_name} MeshCore ${QT_LIBRARIES} gtest gtest_main assimp QGLViewer2 ${glog_LIBRARY})
endif(WIN32)

if(UNIX)
  if(APPLE)
    target_link_libraries(${target_name} MeshCore ${QT_LIBRARIES} ${assimp_LIBRARY} QGLViewer PythonQt ${glog_LIBRARY})
  else(APPLE) #Linux
    target_link_libraries(${target_name} MeshCore ${QT_LIBRARIES} ${assimp_LIBRARY} ${QGLViewer_LIBRARY} PythonQt ${glog_LIBRARY})
  endif(APPLE)
endif(UNIX)




