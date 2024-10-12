cmake_minimum_required(VERSION 3.26)
project(FileStream)

set(CMAKE_CXX_STANDARD 17)

add_executable(FileStream main.cpp
        files_MWA.cpp
        files_MWA.h)
