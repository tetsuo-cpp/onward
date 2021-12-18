add_executable(onward onward.cpp)

target_include_directories(onward PRIVATE "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(onward onward_lib)
