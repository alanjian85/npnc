cmake_minimum_required(VERSION 3.0)
project(npnc)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(npnc ${SOURCE_FILES})
target_include_directories(npnc PRIVATE include)
