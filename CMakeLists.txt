cmake_minimum_required(VERSION 3.5)
project(cyril)
set(APP_NAME cyril)
set(BUNDLE_NAME "cyril")

#set(OF_DIRECTORY "of_v0.9.3_osx_release")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
add_compile_options(-Wno-deprecated-declarations)
add_compile_options(-Wno-delete-incomplete)
add_compile_options(-Wno-deprecated-register)
add_compile_options(-Wno-null-conversion)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)
BISON_TARGET(CyrilParser src/Cyril/cyril.ypp ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
        COMPILE_FLAGS --defines=${CMAKE_CURRENT_BINARY_DIR}/y.tab.h)
FLEX_TARGET(CyrilScanner src/Cyril/cyril.lpp  ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
ADD_FLEX_BISON_DEPENDENCY(CyrilScanner CyrilParser)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

find_package(OpenGL REQUIRED)

include_directories(lib/glew/include)

include_directories(src)
include_directories(src/Engine)
include_directories(src/Cyril)
include_directories(src/Cyril/Funs)
include_directories(src/Cyril/Lang)
include_directories(src/Cyril/Ops)

include_directories(addons/ofxBeat/src)
include_directories(addons/ofxEditor/src)
include_directories(addons/ofxPostProcessing/src)

#set(SOURCE_FILES src/main.cpp)
#include(cmake/addons.cmake)
#include(cmake/openFrameworks.cmake)
#set(TARGET_LINKS $<TARGET_FILE:of_shared>)
#add_executable(cyril ${SOURCE_FILES})
#add_dependencies(cyril of_shared)
#target_link_libraries(cyril of_shared)

add_subdirectory(lib/libtess2)
include_directories(lib/libtess2/Include)

include_directories(lib/utfcpp/source)

include_directories(lib/fmodex/include)

include_directories(lib/freetype/include/freetype2)

include_directories(lib/openssl/include)

file(GLOB POCO_LIBS "lib/poco/lib/osx/*.a")
include_directories(lib/poco/include)

include_directories(lib/cairo/include/cairo)

include_directories(lib/openFrameworks)
include_directories(lib/openFrameworks/3d)
include_directories(lib/openFrameworks/app)
include_directories(lib/openFrameworks/communication)
include_directories(lib/openFrameworks/events)
include_directories(lib/openFrameworks/gl)
include_directories(lib/openFrameworks/graphics)
include_directories(lib/openFrameworks/math)
include_directories(lib/openFrameworks/sound)
include_directories(lib/openFrameworks/types)
include_directories(lib/openFrameworks/utils)
include_directories(lib/openFrameworks/video)

file(GLOB openFrameworks_SRC
        "lib/openFrameworks/*/*.cpp"
        )
list(REMOVE_ITEM openFrameworks_SRC ${CMAKE_CURRENT_SOURCE_DIR}/lib/openFrameworks/app/ofAppEGLWindow.cpp)
#list(REMOVE_ITEM openFrameworks_SRC ${CMAKE_CURRENT_SOURCE_DIR}/lib/openFrameworks/app/ofAppGLFWWindow.cpp)
list(REMOVE_ITEM openFrameworks_SRC ${CMAKE_CURRENT_SOURCE_DIR}/lib/openFrameworks/app/ofAppGlutWindow.cpp)
#list(REMOVE_ITEM openFrameworks_SRC ${CMAKE_CURRENT_SOURCE_DIR}/lib/openFrameworks/graphics/ofCairoRenderer.cpp)
list(REMOVE_ITEM openFrameworks_SRC ${CMAKE_CURRENT_SOURCE_DIR}/lib/openFrameworks/sound/ofRtAudioSoundStream.cpp)
#list(REMOVE_ITEM openFrameworks_SRC ${CMAKE_CURRENT_SOURCE_DIR}/lib/openFrameworks/utils/ofURLFileLoader.cpp)
list(REMOVE_ITEM openFrameworks_SRC ${CMAKE_CURRENT_SOURCE_DIR}/lib/openFrameworks/video/ofGstVideoGrabber.cpp)
list(REMOVE_ITEM openFrameworks_SRC ${CMAKE_CURRENT_SOURCE_DIR}/lib/openFrameworks/video/ofGstVideoPlayer.cpp)
list(REMOVE_ITEM openFrameworks_SRC ${CMAKE_CURRENT_SOURCE_DIR}/lib/openFrameworks/video/ofGstUtils.cpp)
list(REMOVE_ITEM openFrameworks_SRC ${CMAKE_CURRENT_SOURCE_DIR}/lib/openFrameworks/video/ofDirectShowPlayer.cpp)
add_library(openFrameworks ${openFrameworks_SRC})

set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/lib/openFrameworks/app/ofAppGLFWWindow.cpp
        PROPERTIES COMPILE_FLAGS "-x objective-c++")
set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/lib/openFrameworks/utils/ofSystemUtils.cpp
        PROPERTIES COMPILE_FLAGS "-x objective-c++")

set(SOURCE_FILES src/test.cpp)
add_executable(cyrilTemp ${SOURCE_FILES} ${BISON_CyrilParser_OUTPUTS} ${FLEX_CyrilScanner_OUTPUTS})
target_link_libraries(cyrilTemp openFrameworks libtess2 ${POCO_LIBS})
target_link_libraries(cyrilTemp "-framework CoreFoundation")
target_link_libraries(cyrilTemp "-framework Cocoa")
target_link_libraries(cyrilTemp "-framework IOKit")
target_link_libraries(cyrilTemp "-framework CoreVideo")
target_link_libraries(cyrilTemp "-framework CoreText")
target_link_libraries(cyrilTemp ${CMAKE_CURRENT_SOURCE_DIR}/lib/freetype/lib/osx/freetype.a)
target_link_libraries(cyrilTemp ${CMAKE_CURRENT_SOURCE_DIR}/lib/FreeImage/lib/osx/freeimage.a)
target_link_libraries(cyrilTemp ${OPENGL_LIBRARIES})
target_link_libraries(cyrilTemp ${CMAKE_CURRENT_SOURCE_DIR}/lib/boost/lib/osx/boost.a)
target_link_libraries(cyrilTemp ${CMAKE_CURRENT_SOURCE_DIR}/lib/boost/lib/osx/boost_system.a)
target_link_libraries(cyrilTemp ${CMAKE_CURRENT_SOURCE_DIR}/lib/boost/lib/osx/boost_filesystem.a)
target_link_libraries(cyrilTemp ${CMAKE_CURRENT_SOURCE_DIR}/lib/glew/lib/osx/glew.a)
target_link_libraries(cyrilTemp ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw/lib/osx/glfw3.a)
target_link_libraries(cyrilTemp ${CMAKE_CURRENT_SOURCE_DIR}/lib/openssl/lib/osx/crypto.a)
target_link_libraries(cyrilTemp ${CMAKE_CURRENT_SOURCE_DIR}/lib/openssl/lib/osx/ssl.a)
target_link_libraries(cyrilTemp ${CMAKE_CURRENT_SOURCE_DIR}/lib/cairo/lib/osx/cairo-script-interpreter.a)
target_link_libraries(cyrilTemp ${CMAKE_CURRENT_SOURCE_DIR}/lib/cairo/lib/osx/cairo.a)
target_link_libraries(cyrilTemp ${CMAKE_CURRENT_SOURCE_DIR}/lib/cairo/lib/osx/pixman-1.a)
target_link_libraries(cyrilTemp ${CMAKE_CURRENT_SOURCE_DIR}/lib/cairo/lib/osx/png.a)


set(LIB_FMODEX ${CMAKE_CURRENT_SOURCE_DIR}/lib/fmodex/lib/osx/libfmodex.dylib)
target_link_libraries(cyrilTemp ${LIB_FMODEX})
ADD_CUSTOM_COMMAND(TARGET cyrilTemp
        POST_BUILD
        COMMAND /bin/cp
        ARGS ${LIB_FMODEX} ${CMAKE_CURRENT_BINARY_DIR}
        )


file(GLOB cyril_SRC
        "src/Cyril/*.cpp"
        "src/Cyril/Funs/*.cpp"
        "src/Cyril/Lang/*.cpp"
        "src/Cyril/Ops/*.cpp"
        "src/Engine/*.cpp"
        )

target_sources(cyrilTemp PUBLIC ${cyril_SRC})

file(GLOB postProcessing_SRC
        "addons/ofxPostProcessing/src/*.cpp"
        )
target_sources(cyrilTemp PUBLIC ${postProcessing_SRC})



