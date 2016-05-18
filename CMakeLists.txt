cmake_minimum_required(VERSION 3.5)
project(cyril)
set(APP_NAME cyril)
set(BUNDLE_NAME "cyril")

set(OF_DIRECTORY "openFrameworks")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_compile_options(-Wno-deprecated-declarations)

set(SOURCE_FILES src/main.cpp)

include(cmake/addons.cmake)
include(cmake/openFrameworks.cmake)


add_executable(cyril ${SOURCE_FILES})
target_link_libraries(cyril ${TARGET_LINKS})
