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


#Add google test support
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
endif(WIN32)


set(TEST_HEADERS
  test.h)

set(TEST_SOURCES
  testMain.cpp
  )


add_executable(test
  ${TEST_HEADERS}
  ${TEST_SOURCES}
  )
target_link_libraries(test ${QT_LIBRARIES} gtest gtest_main MeshCore)