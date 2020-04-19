cmake_minimum_required(VERSION 3.14)
project(april_prac)

#compile setting
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=c++11")

#algorithm files
set(ALGO_H algo_h)
set(ALGO_IMPL algo)
include_directories(${ALGO_H})

#all binary
set(HWLCC3_LIST ${ALGO_IMPL}/april_algo.cpp hwlcc3/hwlcc3.cpp)
add_executable(hwlcc3 ${HWLCC3_LIST})