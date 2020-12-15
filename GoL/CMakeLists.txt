cmake_minimum_required(VERSION 3.17)
project(GoL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(CMAKE_CXX_STANDARD 14)

add_executable(GoL main.cpp)