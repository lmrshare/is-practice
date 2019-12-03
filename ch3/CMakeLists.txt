cmake_minimum_required(VERSION 3.14)
project(ch3)

#compile setting
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=c++11")

#algorithm files
set(ALGO_H algo_h)
set(ALGO_IMPL algo)
include_directories(${ALGO_H})

#all binary
set(LCC125_LIST ${ALGO_IMPL}/ch3.cpp lcc125/lcc125.cpp)
add_executable(lcc125 ${LCC125_LIST})
set(LCC28_LIST ${ALGO_IMPL}/ch3.cpp lcc28/lcc28.cpp)
add_executable(lcc28 ${LCC28_LIST})
set(LCC44_LIST ${ALGO_IMPL}/ch3.cpp lcc44/lcc44.cpp)
add_executable(lcc44 ${LCC44_LIST})
set(LCC8_LIST ${ALGO_IMPL}/ch3.cpp lcc8/lcc8.cpp)
add_executable(lcc8 ${LCC8_LIST})
set(LCC67_LIST ${ALGO_IMPL}/ch3.cpp lcc67/lcc67.cpp)
add_executable(lcc67 ${LCC67_LIST})
set(LCC516 ${ALGO_IMPL}/ch3.cpp lcc516/lcc516.cpp)
add_executable(lcc516 ${LCC516})
