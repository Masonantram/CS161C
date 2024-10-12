cmake_minimum_required(VERSION 3.27)
project(lab7_MWA)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab7_MWA main.cpp
        Implementation.cpp
        Header.hpp
        "Player Class.cpp"
        "Player Class.hpp"
        "Person Class.cpp"
        "Person Class.hpp")
