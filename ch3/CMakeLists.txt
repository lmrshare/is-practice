cmake_minimum_required(VERSION 3.14)
project(ch3)

set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=c++11")

set(CH3_SRC src)
set(CH3_HEAD head)

set(SRC_LIST ${CH3_SRC}/ch3.cpp main.cpp)

include_directories(${CH3_HEAD})
add_executable(ch3 ${SRC_LIST})
