file(GLOB MSA_OPENCL "${OF_DIRECTORY}/addons/ofxMSAOpenCL/src/*.cpp")
set(HEADER_MSA_OPENCL "${OF_DIRECTORY}/addons/ofxMSAOpenCL/src")

file(GLOB OFX_CSV "${OF_DIRECTORY}/addons/ofxCsv/src/*.cpp")
set(HEADER_OFX_CSV "${OF_DIRECTORY}/addons/ofxCsv/src")

set(ADDON_SOURCE_FILES ${MSA_OPENCL} ${OFX_CSV})
set(OF_ADDON_HEADERS ${HEADER_MSA_OPENCL} ${HEADER_OFX_CSV})


find_library(opencl_lib OpenCL)

set(OF_ADDON_FRAMEWORKS
        ${opencl_lib})