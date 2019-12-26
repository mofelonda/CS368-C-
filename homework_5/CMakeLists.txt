cmake_minimum_required(VERSION 3.15)
project(homework_5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(homework_5
        CAVE.cpp
        CAVE.h
        homework_5.cpp PLAYER.h PLAYER.cpp)
