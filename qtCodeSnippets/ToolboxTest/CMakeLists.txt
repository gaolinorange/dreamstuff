set(proj toolboxTest)

project(${proj})

cmake_minimum_required(VERSION 2.6)

#set the custom directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})


find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

add_subdirectory(Plugin-ToolBoxTest)

include_directories(.)
include_directories(Interfaces)

qt4_wrap_cpp(MainWindow_MOC MainWindow.h)

add_executable(${proj} main.cpp MainWindow.cpp MainWindow.h ${MainWindow_MOC})
target_link_libraries(${proj} ${QT_LIBRARIES})
