# CONFIG CMAKE & C++
cmake_minimum_required(VERSION 3.31.6)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# CONFIG CMAKE SCRIPTS
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(logger)

# CONFIG PROJECT
project(jnova LANGUAGES CXX)
set(inc_dir "${CMAKE_CURRENT_SOURCE_DIR}/include")

# CONFIG PROJECT STRUCTURE
add_subdirectory(src)
add_subdirectory(tests)