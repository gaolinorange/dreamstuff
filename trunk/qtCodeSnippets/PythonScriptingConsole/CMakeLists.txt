project(PythonQtTest)
cmake_minimum_required(VERSION 2.6)

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})


find_package(PythonLibs REQUIRED)
if(PYTHONLIBS_FOUND)
  include_directories(${PYTHON_INCLUDE_PATH})
else(PYTHONLIBS_FOUND)
message("could not find PythonLibs")
endif(PYTHONLIBS_FOUND)


#
qt4_wrap_cpp(PyExampleObject_MOC PyExampleObject.h)
qt4_add_resources(PyScriptingConsole_RCS_SOURCES PyScriptingConsole.qrc)




#PythonQt related
include_directories(/usr/local/include/PythonQt)
link_directories(/usr/local/lib)

set(APP_HEADERS
  PyExampleObject.h
  )

set(APP_SOURCES
	PyExampleObject.cpp
	main.cpp
	${PyScriptingConsole_RCS_SOURCES}
	)

set(PYTHONQT_LIBRARIES PythonQt PythonQtGui)

add_executable(test ${APP_SOURCES} ${APP_HEADERS} ${PyExampleObject_MOC})
target_link_libraries(test ${PYTHONQT_LIBRARIES} ${QT_LIBRARIES} ${PYTHON_LIBRARIES})	