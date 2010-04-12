# Find Include Path
find_path(assimp_INCLUDE_DIR
  NAMES assimp.h assimp.hpp
  PATHS ${CMAKE_SOURCE_DIR}/3rdparty/assimp/include /usr/include /usr/local/include ../3rdparty/assimp/include)

#Find Library
find_library(assimp_LIBRARY
  NAMES assimp
  PATHS 3rdparty/assimp/lib ${CMAKE_SOURCE_DIR}/3rdparty/assimp/lib /usr/lib /usr/local/lib)


if(assimp_INCLUDE_DIR AND assimp_LIBRARY)
  set(assimp_FOUND TRUE)
  message(STATUS "Found assimp include: ${assimp_INCLUDE_DIR}")
  message(STATUS "Foud asismp library:  ${assimp_LIBRARY}")
elseif(assimp_INCLUDE_DIR AND assimp_LIBRARY)
  message(STATUS assimp_INCLUDE_DIR)
  message(STATUS assimp_LIBRARY)
  message(FATAL_ERROR "Could not find assimp")
  set(assimp_FOUND FALSE)
endif(assimp_INCLUDE_DIR AND assimp_LIBRARY)




