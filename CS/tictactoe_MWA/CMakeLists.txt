cmake_minimum_required(VERSION 3.27)
project(tictactoe_MWA)

set(CMAKE_CXX_STANDARD 17)

add_executable(tictactoe_MWA main.cpp
        implementation.cpp
        header.hpp)
