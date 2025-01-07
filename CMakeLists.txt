cmake_minimum_required(VERSION 3.28)
project(P2A10_Palindrom_C C)

add_definitions(-DPROJECT_DIR="${CMAKE_SOURCE_DIR}")

set(CMAKE_C_STANDARD 11)

add_executable(P2A10_Palindrom_C main.c
        palindrom.c
        palindrom.h)
