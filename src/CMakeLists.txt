cmake_minimum_required(VERSION 3.10)
project(JsonBufferTest)

# CONFIG 'jsonbuffer' TO BE A STATIC LIBRARY TARGET
add_library(jsonbuffer STATIC jsonbuffer.cpp)

# CONFIG LOCATION OF PUBLIC INTERFACE HEADER FILES 
target_include_directories(jsonbuffer PRIVATE "../include")

# ENFORCE C++23 STANDARD
# target_compile_features(jsonbuffer PUBLIC cxx_std_23)

# CONFIGURE COMPILER TO WARN ABOUT UNSAFE PRACTICES
# target_compile_options(jsonbuffer PRIVATE $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>)