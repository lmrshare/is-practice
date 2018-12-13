project(dynamic-programming)

set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=c++11")

set(DYNAMIC_SRC src)
set(DYNAMIC_HEAD head)

set(SRC_LIST main.cpp  ${DYNAMIC_SRC}/dynamic.cpp)

include_directories(${DYNAMIC_HEAD})
add_executable(dp ${SRC_LIST})
