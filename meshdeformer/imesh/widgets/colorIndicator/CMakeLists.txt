project(ColorIndicator)

cmake_minimum_required(VERSION 2.6)

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

set(SOURCES
	ColorIndicator.cpp
	main.cpp
	)

set(HEADERS
	ColorIndicator.h
	ColorCodingWidget.h
	)

qt4_wrap_cpp(ColorIndicator_MOC ColorIndicator.h)
qt4_wrap_cpp(ColorCodingWidget_MOC ColorCodingWidget.h)

add_executable(colorindicator ${SOURCES} ${Colorindicator_MOC} ${ColorCodingWidget_MOC})
target_link_libraries(colorindicator ${QT_LIBRARIES})
				