cmake_minimum_required(VERSION 3.24)
project(sistema_ecuaciones C)

set(CMAKE_C_STANDARD 11)

add_executable(sistema_ecuaciones main.c functions.h functions.c)
