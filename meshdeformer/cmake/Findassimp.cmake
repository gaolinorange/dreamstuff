find_path(assimp_INCLUDE_DIR assimp.hpp 3rdparty/assimp/include )

find_library(assimp_LIBRARY NAMES assimp PATH 3rdparty/assimp/lib )

if(assimp_INCLUDE_DIR AND assimp_LIBRARY)
  set(assimp_FOUND TRUE)
endif(assimp_INCLUDE_DIR AND assimp_LIBRARY)

if(assimp_FOUND)
  message(STATUS "Found assimp: ${assimp_LIBRARY}")
else(assimp_FOUND)
  message(FATAL_ERROR "Could not find assimp")
endif(assimp_FOUND)
