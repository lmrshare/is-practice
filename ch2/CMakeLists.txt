cmake_minimum_required(VERSION 3.14)
project(ch2)

set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=c++11")

set(CH2_SRC src)
set(CH2_HEAD head)

set(SRC_LIST ${CH2_SRC}/ch2.cpp main.cpp)

include_directories(${CH2_HEAD})
add_executable(ch2 ${SRC_LIST})
