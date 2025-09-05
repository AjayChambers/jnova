cmake_minimum_required(VERSION 3.10)
project(JsonBufferTest)

# CONFIG 'jsonbuffer' TO BE A STATIC LIBRARY TARGET
add_library(jsonbuffer STATIC jsonbuffer.cpp)
add_library(jsonlexer STATIC jsonlexer.cpp)

# Inform target where to find project header files
target_include_directories(jsonbuffer PUBLIC "../include")
target_include_directories(jsonlexer PUBLIC "../include")

target_link_libraries(jsonlexer PUBLIC jsonbuffer)