cmake_minimum_required(VERSION 3.17)
project(GoLCpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(CMAKE_CXX_STANDARD 20)

add_executable(GoLCpp main.cpp)