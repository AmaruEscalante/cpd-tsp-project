cmake_minimum_required(VERSION 3.19)
project(norecursivo)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSIZE=4")

add_executable(norecursivo tsp-dfs-v1.cpp)