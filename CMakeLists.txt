cmake_minimum_required(VERSION 3.18)
project(sets C)

set(CMAKE_C_STANDARD 11)

add_executable(sets main.c set.c set.h)