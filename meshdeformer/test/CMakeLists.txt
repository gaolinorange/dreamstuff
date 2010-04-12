cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ../cmake)

include_directories(../src)

find_package(Boost)
if(Boost_FOUND)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
endif()


find_package(Qt4 REQUIRED)
set(QT_USE_QTTEST true)
set(QT_USE_QTOPENGL true)
include(${QT_USE_FILE})

if(UNIX)
set(CGAL_DIR /usr/local/lib/CGAL)
endif(UNIX)
find_package(CGAL REQUIRED)
if(CGAL_FOUND)
include(${CGAL_USE_FILE})
endif()



# #Add google test support
# if(APPLE)
#   include_directories(/usr/local/include)
#   link_directories(/usr/local/lib)
# endif(APPLE)
# if(LINUX)
#   include_directories(/usr/include)
#   link_directories(/usr/lib)
# endif(LINUX)
# if(WIN32)
#   include_directories("D:/DevTools")
# endif(WIN32)
find_package(gtest REQUIRED)
if(gtest_FOUND)
  include_directories(${gtest_INCLUDE_DIR})
endif(gtest_FOUND)

#assimp support
find_package(assimp REQUIRED)
if(assimp_FOUND)
  include_directories(${assimp_INCLUDE_DIR})
endif(assimp_FOUND)



set(TEST_HEADERS
  test.h)

set(TEST_SOURCES
  testMain.cpp
  )


add_executable(test
  ${TEST_HEADERS}
  ${TEST_SOURCES}
  )
target_link_libraries(test ${QT_LIBRARIES}  MeshCore ${assimp_LIBRARY} ${gtest_LIBRARY})