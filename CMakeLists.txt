# CMAKE INTEGRATION
cmake_minimum_required(VERSION 3.31.6)
project(jnova LANGUAGES CXX)

# Configure GNU/GCC C++ (g++) 
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wpedantic 
-fdiagnostics-color=always -fno-diagnostics-show-caret)

# Config modules/scripts dir @("RootDir/cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Configure Project
add_subdirectory(src)
add_subdirectory(tests)

