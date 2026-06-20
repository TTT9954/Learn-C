/bin/bash
@echo off
set CMAKE_GENERATOR=MinGW Makefiles
set CMAKE_BUILD_TYPE=Debug
cmake -S . -B build -G "%CMAKE_GENERATOR%" -DCMAKE_BUILD_TYPE=%CMAKE_BUILD_TYPE%
cmake --build build --config %CMAKE_BUILD_TYPE%

cmake -DCMAKE_BUILD_TYPE=Debug -S . -B build -G "%CMAKE_GENERATOR%"
cmake --build build --config Debug

.\build\Learn-C.exe