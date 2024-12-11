cmake_minimum_required(VERSION 3.29)
project(PontInPlain C)

set(CMAKE_C_STANDARD 23)

include_directories(
        Inc
)

add_executable(PontInPlain
        Src/main.c
        Src/sqare_find.c
)

