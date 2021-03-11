cmake_minimum_required(VERSION 3.4.1)

# now build app's shared lib
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

add_library(gl2jni SHARED
            gl_code.cpp)

# Import the CMakeLists.txt for the glm library
add_subdirectory(glm) # if your CMakeLists is at '../cpp'

#import NReal
add_library(nrapi-lib SHARED IMPORTED)
set_target_properties(nrapi-lib PROPERTIES IMPORTED_LOCATION
        ${NREAL_LIBPATH}/${ANDROID_ABI}/libnr_api.so
        )

add_library(nrrgbcamera-lib SHARED IMPORTED)
set_target_properties(nrrgbcamera-lib PROPERTIES IMPORTED_LOCATION
        ${NREAL_LIBPATH}/${ANDROID_ABI}/libnr_rgb_camera.so
        )

# add lib dependencies
target_link_libraries(gl2jni
                      android
                      log 
                      EGL
                      GLESv2
        nrapi-lib
        nrrgbcamera-lib
        glm)

