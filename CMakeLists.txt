cmake_minimum_required(VERSION 3.17)
project(stack C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_executable(stack
        main.c
        stack/stack.c
        stack/stack.h
        menu/menu.c
        menu/menu.h
        )