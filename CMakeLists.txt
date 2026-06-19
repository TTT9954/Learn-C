cmake_minimum_required(VERSION 3.10)
project(Learn-C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)


add_executable(Learn-C main.c 
    src/LinkedList.c
    src/Common_Func.c
    src/RingBuffer.c
)

target_include_directories(Learn-C PRIVATE inc)