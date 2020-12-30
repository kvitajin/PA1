cmake_minimum_required(VERSION 3.17)
project(GoLOMP LANGUAGES CXX)

#OPTION (USE_OpenMP "Use OpenMP" ON)
find_package(OpenMP REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fopenmp")

set(CMAKE_CXX_STANDARD 20)

add_executable(GoLOMP main.cpp)