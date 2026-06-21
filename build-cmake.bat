@echo off
set CMAKE_GENERATOR=MinGW Makefiles
set CMAKE_BUILD_TYPE=Debug

:: 1. Force delete the old build directory to clear the broken cache
if exist build rmdir /s /q build

:: 2. Configure fresh build files using the new 64-bit compiler paths
cmake -S . -B build -G "%CMAKE_GENERATOR%" -DCMAKE_BUILD_TYPE=%CMAKE_BUILD_TYPE%

:: 3. Build the project
cmake --build build --config %CMAKE_BUILD_TYPE%

:: 4. Run your executable
.\build\Learn-C.exe