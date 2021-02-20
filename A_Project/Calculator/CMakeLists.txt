cmake_minimum_required(VERSION 3.16)
project(Calculator C)

set(CMAKE_C_STANDARD 99)

add_executable(Calculator main.c sqstack.c sqstack.h)