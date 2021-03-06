#cmake module
#finding the INCLUDE and LIBRARY for libQGLViewer
find_path(QGLViewer_INCLUDE_DIR
  NAMES QGLViewer/qglviewer.h
  PATHS /usr/include /usr/local/include
  )

find_library(QGLViewer_LIBRARY
  NAMES QGLViewer
  PATHS /usr/local/lib /usr/lib
  )


if(QGLViewer_INCLUDE_DIR AND QGLViewer_LIBRARY)
  set(QGLViewer_FOUND TRUE)
  message(STATUS "Found QGLViewer include: ${QGLViewer_INCLUDE_DIR}")
  message(STATUS "Foud QGLViewer library:  ${QGLViewer_LIBRARY}")
elseif(QGLViewer_INCLUDE_DIR AND QGLViewer_LIBRARY)	
  message(STATUS "Could not found QGLViewer_INCLUDE_DIR, current found is : ${QGLViewer_INCLUDE_DIR}")
  message(STATUS "Could not found QGLViewer_LIBRARY, current found is : ${QGLViewer_LIBRARY}")
  message(FATAL_ERROR "Could not find QGLViewer")
  set(QGLViewer_FOUND FALSE)
endif(QGLViewer_INCLUDE_DIR AND QGLViewer_LIBRARY)
