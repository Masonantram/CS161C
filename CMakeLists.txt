cmake_minimum_required(VERSION 3.27)
project(CS161C)

set(CMAKE_CXX_STANDARD 14)

include_directories(CS/260lab1_MWA)
include_directories(CS/Deque)

add_executable(CS161C


        CS/Deque/Deque.cpp
        CS/Deque/Deque.hpp
        CS/Deque/main.cpp
        CS/Deque/Deque.cpp
        CS/Deque/Deque.cpp)
