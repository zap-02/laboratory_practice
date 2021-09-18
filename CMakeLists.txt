cmake_minimum_required(VERSION 3.16)
project(lab_2)

set(CMAKE_CXX_STANDARD 20)

#add_executable(lab_2 main.cpp Class.cpp Class.h)

add_subdirectory(lab_2_main)
add_subdirectory(lab_2_lib)
add_subdirectory(lab_2_tests)