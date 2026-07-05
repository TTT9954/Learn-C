#!/bin/bash

# Set build type
CMAKE_BUILD_TYPE=Debug

# 1. Force delete the old build directory to clear the broken cache
if [ -d "build" ]; then
    rm -rf build
fi

# 2. Configure fresh build files
cmake -S . -B build -DCMAKE_BUILD_TYPE=$CMAKE_BUILD_TYPE

# 3. Build the project
cmake --build build --config $CMAKE_BUILD_TYPE
