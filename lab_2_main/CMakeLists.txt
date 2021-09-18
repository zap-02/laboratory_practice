cmake_minimum_required(VERSION 3.16)
project(lab_2_main)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_2_main main.cpp)

include_directories(../lab_2_lib)

target_link_libraries(lab_2_main lab_2_lib)


