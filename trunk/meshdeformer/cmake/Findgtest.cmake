# Find Include Path
find_path(gtest_INCLUDE_DIR
  NAMES gtest.h 
  PATHS /usr/include /usr/local/include)

#Find Library
find_library(gtest_LIBRARY
  NAMES gtest gtest_main
  PATHS /usr/lib /usr/local/lib)


if(gtest_INCLUDE_DIR AND gtest_LIBRARY)
  set(gtest_FOUND TRUE)
  message(STATUS "Found gtest include: ${gtest_INCLUDE_DIR}")
  message(STATUS "Foud asismp library:  ${gtest_LIBRARY}")
elseif(gtest_INCLUDE_DIR AND gtest_LIBRARY)
  set(gtest_FOUND FALSE)
  message(FATAL_ERROR "Could not find gtest")
endif(gtest_INCLUDE_DIR AND gtest_LIBRARY)


