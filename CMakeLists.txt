cmake_minimum_required(VERSION 3.5)
project(cyril)
set(APP_NAME cyril)
set(BUNDLE_NAME "cyril")

set(OF_DIRECTORY "of_v0.9.3_osx_release")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
add_compile_options(-Wno-deprecated-declarations)
add_compile_options(-W\#warnings)

include_directories(src)
include_directories(src/Engine)
include_directories(src/Cyril)
include_directories(src/Cyril/Funs)
include_directories(src/Cyril/Lang)
include_directories(src/Cyril/Ops)

include_directories(addons/ofxBeat/src)
include_directories(addons/ofxEditor/src)
include_directories(addons/ofxPostProcessing/src)

set(SOURCE_FILES src/main.cpp)

include(cmake/addons.cmake)
include(cmake/openFrameworks.cmake)

set(TARGET_LINKS $<TARGET_FILE:of_shared>)
add_executable(cyril ${SOURCE_FILES})
#add_dependencies(cyril of_shared)
target_link_libraries(cyril of_shared)
