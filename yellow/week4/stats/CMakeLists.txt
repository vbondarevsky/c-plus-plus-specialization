cmake_minimum_required(VERSION 3.13)
project(stats)

set(CMAKE_CXX_STANDARD 14)

add_executable(stats main.cpp PrintStats.cpp)

add_compile_definitions(TEST)