cmake_minimum_required(VERSION 3.31.6)
project(jnova LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(include_dir "${CMAKE_CURRENT_SOURCE_DIR}/include")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(logger)

add_subdirectory(src)
add_subdirectory(tests)

logger("Include Directory: ${include}")