set(proj toolboxTest)

project(${proj})

cmake_minimum_required(VERSION 2.6)

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})


add_executable(${proj} main.cpp MainWindow.cpp MainWindow.h)
target_link_libraries(${proj} ${QT_LIBRARIES})
