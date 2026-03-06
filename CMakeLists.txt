cmake_minimum_required(VERSION 3.10)

project(Lab9 C)

set(CMAKE_C_STANDARD 99)

# Add source files
add_executable(lab9
        lab9.c
        utils/fileUtils.c
        utils/utils.c
)

# Include directories
target_include_directories(lab9 PRIVATE ./utils)