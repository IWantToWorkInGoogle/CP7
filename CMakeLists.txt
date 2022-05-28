cmake_minimum_required(VERSION 3.22)
project(CP7 C)

set(CMAKE_C_STANDARD 99)

add_executable(CP7 main.c matrix.c matrix.h row_item.h api.c api.h row.c row.h)
