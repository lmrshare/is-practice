cmake_minimum_required(VERSION 3.14)
project(ch4)

set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=c++11")

set(CH4_SRC src)
set(CH4_HEAD head)

set(SRC_LIST main.cpp  ${CH4_SRC}/ch4.cpp)

include_directories(${CH4_HEAD})
add_executable(ch4 ${SRC_LIST})
