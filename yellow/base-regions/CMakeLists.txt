cmake_minimum_required(VERSION 3.12)
project(base_regions)

set(CMAKE_CXX_STANDARD 17)

add_executable(base_regions main.cpp find.cpp region.h)

add_compile_definitions(TEST)