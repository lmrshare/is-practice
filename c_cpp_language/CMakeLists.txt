project(languagelearn)

set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb -std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -std=c++11")

set(LANLEARN_SRC src)
set(LANLEARN_HEAD head)

set(SRC_LIST main.cpp  ${LANLEARN_SRC}/list1.cpp)

include_directories(${LANLEARN_HEAD})
add_executable(learn ${SRC_LIST})
