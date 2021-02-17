cmake_minimum_required(VERSION 3.16)
project(lib1 C)

set(CMAKE_C_STANDARD 99)

add_executable(lib1 main.c llist.c llist.h)