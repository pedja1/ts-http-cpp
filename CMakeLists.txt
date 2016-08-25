cmake_minimum_required(VERSION 3.6)
project(ts_http_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/core/include)
file(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/core/src/*.cpp")
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/core/)
#file(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/core/*.cpp")

set(SOURCE_FILES ${SOURCE_FILES} main.cpp)
add_executable(ts_http_cpp ${SOURCE_FILES})