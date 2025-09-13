#############################################
####      CMakeLists @('root/src')       ####
#############################################

# ADD LIB JSON_BUFFER @('jsonBuffer')
add_library(jsonBuffer STATIC jsonBuffer.cpp)
target_include_directories(jsonBuffer PUBLIC "../include")

# ADD LIB JSON_LEXER @('jsonLexer')
add_library(jsonLexer STATIC jsonLexer.cpp)
target_include_directories(jsonLexer PUBLIC "../include")
target_link_libraries(jsonLexer PUBLIC jsonBuffer)

# ADD LIB JNOVA @('jnova')
add_library(jnova STATIC jnova.cpp)
target_include_directories(jnova PUBLIC "../include")
target_link_libraries(jnova PUBLIC jsonBuffer jsonLexer)