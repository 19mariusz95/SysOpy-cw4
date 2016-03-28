cmake_minimum_required(VERSION 3.4)
project(zad2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(sender sender.c ksiadz.h)
add_executable(catcher catcher.c ksiadz.h)
add_executable(sender2 sender2.c ksiadz.h)
add_executable(catcher2 catcher2.c ksiadz.h)