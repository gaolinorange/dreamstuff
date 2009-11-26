cmake_minimum_required(VERSION 2.6)

include_directories(../MeshCore)
include_directories(../Math)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

find_package(Qt4 4.5.2 REQUIRED)
if(Qt_FOUND)
  include(${USE_QT_FILE})
endif()

set(test_SOURCES testVector3d.cpp)


add_library(test STATIC ${test_SOURCES})
target_link_libraries(test gtest gtest_main ${QT_LIBRARIES})
