add_library(jsonBuffer STATIC jsonBuffer.cpp)
add_library(jsonLexer STATIC jsonLexer.cpp)

# Inform target where to find project header files
target_include_directories(jsonBuffer PUBLIC "../include")
target_include_directories(jsonLexer PUBLIC "../include")

# Include jsonBuffer lib in jsonLexer lib
target_link_libraries(jsonLexer PUBLIC jsonBuffer)