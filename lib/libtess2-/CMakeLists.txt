cmake_minimum_required(VERSION 3.5)

file(GLOB libtess2_SRC "Source/*.c")

set(libtess2_INC Include)
include_directories(${libtess2_INC})

add_library(libtess2 ${libtess2_SRC})
