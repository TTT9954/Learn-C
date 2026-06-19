cmake_minimum_required(VERSION 3.10)
project(Learn-C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)


add_library(LinkedList STATIC
    src/LinkedList.c
    inc/LinkedList.h
)

add_library(Common_Func STATIC
    src/Common_Func.c
    inc/Common_Func.h
)

add_library(RingBuffer STATIC
    src/RingBuffer.c
    inc/RingBuffer.h
)

add_executable(Learn-C main.c 
    src/LinkedList.c
    src/Common_Func.c
    src/RingBuffer.c
)

target_include_directories(Learn-C PRIVATE inc)

target_link_libraries(Learn-C PRIVATE LinkedList Common_Func RingBuffer)