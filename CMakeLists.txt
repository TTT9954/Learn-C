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

add_library(Stack STATIC
    src/Stack.c
    inc/Stack.h
)

add_library(StringSelf STATIC
    src/StringSelf.c
    inc/StringSelf.h
)

target_include_directories(LinkedList PUBLIC inc)
target_include_directories(Common_Func PUBLIC inc)
target_include_directories(RingBuffer PUBLIC inc)
target_include_directories(Stack PUBLIC inc)
targiet_include_directories(StringSelf PUBLIC inc)

add_executable(Learn-C main.c 
    src/LinkedList.c
    src/Common_Func.c
    src/RingBuffer.c
    src/Stack.c
    src/StringSelf.c
)

target_link_libraries(Learn-C PRIVATE LinkedList Common_Func RingBuffer Stack StringSelf)