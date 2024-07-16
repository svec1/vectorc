cmake_minimum_required(VERSION 3.12)

project(test_m C)

file(GLOB MAIN "src/*.c" "src/*.h" "include/vec_f.h")
file(GLOB TEST "test/*.c" "test/*.h")

add_library(_test ${MAIN})