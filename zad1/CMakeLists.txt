cmake_minimum_required(VERSION 3.4)
project(zad1 C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES main.c)
add_executable(printer ${SOURCE_FILES})