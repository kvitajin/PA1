cmake_minimum_required(VERSION 3.17)
project(cv4)

set(CMAKE_CXX_STANDARD 20)
find_package(OpenCV REQUIRED)
set(SOURCE_FILES main.cpp)

add_executable(cv4 main.cpp)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries( cv4 ${OpenCV_LIBS} )