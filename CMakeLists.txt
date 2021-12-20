cmake_minimum_required(VERSION 3.0)
project(npnc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(npnc ${SOURCE_FILES})
target_include_directories(npnc PRIVATE include)
