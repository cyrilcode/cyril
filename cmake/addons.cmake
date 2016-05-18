
file(GLOB OFX_XMLSETTINGS "${OF_DIRECTORY}/addons/ofxXmlSettings/src/*.cpp" "${OF_DIRECTORY}/addons/ofxXmlSettings/libs/*.cpp")
set(HEADER_OFX_XMLSETTINGS "${OF_DIRECTORY}/addons/ofxXmlSettings/src" "${OF_DIRECTORY}/addons/ofxXmlSettings/libs")

set(ADDON_SOURCE_FILES ${OFX_XMLSETTINGS})
set(OF_ADDON_HEADERS ${HEADER_OFX_XMLSETTINGS})


find_library(opencl_lib OpenCL)

set(OF_ADDON_FRAMEWORKS
        ${opencl_lib})