cmake_minimum_required(VERSION 3.13)
project(task_tracker)

set(CMAKE_CXX_STANDARD 14)

add_executable(task_tracker main.cpp TasksInfo.h TeamTasks.cpp)

add_compile_definitions(TEST)