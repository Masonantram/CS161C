cmake_minimum_required(VERSION 3.26)
project(NIM_MWA)

set(CMAKE_CXX_STANDARD 17)

add_executable(NIM_MWA main.cpp
        NIM_MWAtest.cpp
        NIM_MWAtest.h)
