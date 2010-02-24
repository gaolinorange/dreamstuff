project(PythonQtTest)
cmake_minimum_required(VERSION 2.6)

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})


find_package(PythonLibs REQUIRED)
include(${PYTHON_INCLUDE_PATH})



include_directories(/usr/local/include/PythonQt)
link_directories(/usr/local/lib)

set(APP_SOURCES
	PyExampleObject.cpp
	main.cpp
	)

set(PYTHONQT_LIBRARIES PythonQt)

add_executable(test ${APP_SOURCES})
target_link_libraries(test ${PYTHONQT_LIBRARIES} ${QT_LIBRARIES} ${PYTHON_LIBRARIES})	