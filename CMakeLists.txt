cmake_minimum_required(VERSION 3.6)
project(ts_http_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Request.cpp Request.h IRequestHandler.h IResponseHandler.h ResponseHandlerImpl.cpp ResponseHandlerImpl.h Http.h Http.cpp IInternet.h IUI.h INetwork.h ITextManager.h ResponseParser.cpp ResponseParser.h RequestManager.cpp RequestManager.h)
add_executable(ts_http_cpp ${SOURCE_FILES})