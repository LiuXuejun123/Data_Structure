cmake_minimum_required(VERSION 3.16)
project(liststack C)

set(CMAKE_C_STANDARD 99)

add_executable(liststack main.c stack.c stack.h llist.c llist.h )