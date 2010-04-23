# Find Include Path
find_path(glog_INCLUDE_DIR
  NAMES logging.h
  PATHS /usr/include /usr/local/include)

#Find Library
find_library(glog_LIBRARY
  NAMES glog
  PATHS /usr/lib /usr/local/lib)


if(glog_INCLUDE_DIR AND glog_LIBRARY)
  set(glog_FOUND TRUE)
  message(STATUS "Found glog include: ${glog_INCLUDE_DIR}")
  message(STATUS "Foud glog library:  ${glog_LIBRARY}")
elseif(glog_INCLUDE_DIR AND glog_LIBRARY)
  set(glog_FOUND FALSE)
  message(FATAL_ERROR "Could not find glog")
endif(glog_INCLUDE_DIR AND glog_LIBRARY)


