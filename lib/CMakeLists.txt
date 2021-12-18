set(
  ONWARD_LIB_FILES
  Dictionary.cpp
  Engine.cpp
  Intrinsics.cpp
  )

add_library(onward_lib ${ONWARD_LIB_FILES})
target_include_directories(onward_lib PRIVATE "${PROJECT_SOURCE_DIR}/include")
