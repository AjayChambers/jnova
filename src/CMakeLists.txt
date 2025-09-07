#############################################
####      CMakeLists @('root/src')       ####
#############################################

# ADD LIBRARY JSON_TYPEDEF @('jsonTypedef')
add_library(jsonTypedef STATIC jsonTypedef.cpp)
target_include_directories(jsonTypedef PUBLIC "../include")


# ADD LIBRARY JSON_BUFFER @('jsonBuffer')
add_library(jsonBuffer STATIC jsonBuffer.cpp)
target_include_directories(jsonBuffer PUBLIC "../include")
target_link_libraries(jsonBuffer PUBLIC jsonTypedef)


# ADD LIBRARY JSON_LEXER @('jsonLexer')
add_library(jsonLexer STATIC jsonLexer.cpp)
target_include_directories(jsonLexer PUBLIC "../include")
target_link_libraries(jsonLexer PUBLIC jsonBuffer jsonTypedef)