cmake_minimum_required(VERSION 3.13)
project(course_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(course_project main.cpp database.cpp test_runner.cpp condition_parser.cpp token.cpp node.cpp date.cpp comparison.cpp logical_operation.cpp condition_parser_test.cpp entry.cpp)