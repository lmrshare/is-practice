cmake_minimum_required(VERSION 3.14)
project(ch2)

#compile setting
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=c++11")

#algorithm files
set(ALGO_H algo_h)
set(ALGO_IMPL algo)
include_directories(${ALGO_H})

# #all binary
set(DEMO ${ALGO_IMPL}/ch2.cpp demo/demo.cpp)
add_executable(demo ${DEMO})
set(LCC26 ${ALGO_IMPL}/ch2.cpp lcc26/lcc26.cpp)
add_executable(lcc26 ${LCC26})