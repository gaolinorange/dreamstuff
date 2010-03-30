set(project loggingTestProject)
project(${project})

cmake_minimum_required(VERSION 2.6)


find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

qt4_wrap_cpp(MainClass_MOC MainClass.h)
qt4_wrap_cpp(TestClass_MOC TestClass.h)


add_executable(${project} main.cpp ${MainClass_MOC} ${TestClass_MOC})
target_link_libraries(${project} ${QT_LIBRARIES})
