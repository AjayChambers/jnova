# CMAKE INTEGRATION
cmake_minimum_required(VERSION 3.31.6)


# Configure Compiler - Enforce C++23 Standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(
    -Wall -Wextra -Wpedantic
    -fdiagnostics-color=always 
    -fno-diagnostics-show-caret
)

# Config CMake Scripts & Modules Directory
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(logger)

# Configure Project
project(jnova LANGUAGES CXX)
add_subdirectory(src)
add_subdirectory(tests)

