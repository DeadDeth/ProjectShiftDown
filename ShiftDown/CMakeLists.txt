cmake_minimum_required(VERSION 4.2)
project(ShiftDown)

set(CMAKE_CXX_STANDARD 23)

set(MY_BASE_FLAGS "-O1 -fno-unroll-loops -fno-tree-vectorize -Wall -Wextra -march=native")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_BASE_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${MY_BASE_FLAGS}")

add_executable(ShiftDown ShiftDown.cpp
        ShiftDownInput/Devices/Devices.hpp
        ShiftDownInput/Devices/Devices.cpp
        ShiftDownParsers/Parsers.hpp)
