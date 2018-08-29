

cmake_minimum_required(VERSION 3.4.1)
add_definitions( -DFLITE_PLUS_HTS_ENGINE )

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

set(SOURCE_DIR src/main/cpp)




add_library(native-lib
            SHARED
            ${SOURCE_DIR}/native-lib.cpp )



find_library( log-lib log )



add_subdirectory(${SOURCE_DIR}/flite)


add_subdirectory(${SOURCE_DIR}/analyze)


target_link_libraries(native-lib analyze)

target_link_libraries(native-lib  ${log-lib} )