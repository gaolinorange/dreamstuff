find_path(PYTHONQT_INCLUDE_DIR PythonQt.h /usr/include/PythonQt /usr/local/include/PythonQt)

find_library(PYTHONQT_LIBRARY NAMES PythonQt PATH /usr/lib /usr/local/lib)

if(PYTHONQT_INCLUDE_DIR AND PYTHONQT_LIBRARY)
  set(PythonQt_FOUND TRUE)
endif(PYTHONQT_INCLUDE_DIR AND PYTHONQT_LIBRARY)

if(PythonQt_FOUND)
  message(STATUS "Found PythonQt: ${PYTHONQT_LIBRARY}")
else(PythonQt_FOUND)
  message(FATAL_ERROR "Could not find PythonQt")
endif(PythonQt_FOUND)
