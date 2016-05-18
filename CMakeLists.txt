cmake_minimum_required(VERSION 3.5)
project(cyril)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(SOURCE_FILES src/main.cpp)
add_executable(cyril ${SOURCE_FILES})
target_link_libraries(cyril ${TARGET_LINKS})
