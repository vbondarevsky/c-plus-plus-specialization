cmake_minimum_required(VERSION 3.12)
project(red)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("week1/logger" "week1/logger/cmake-build-debug")
add_subdirectory("week1/comparator_generator" "week1/comparator_generator/cmake-build-debug")
add_subdirectory("week1/update_field" "week1/update_field/cmake-build-debug")
add_subdirectory("week1/bad_macro" "week1/bad_macro/cmake-build-debug")
