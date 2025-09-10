# Include FetchContent
include(FetchContent)
FetchContent_Declare(googletest
    URL "https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip")
FetchContent_MakeAvailable(googletest)

# Include GTest
include(GoogleTest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Include CTest
include(CTest)
enable_testing()


# ADD A SANDBOX ENV THAT COMPILES TO AN EXECUTABLE
add_executable(sandbox sandbox.cpp)
target_include_directories(sandbox PUBLIC ../include)
target_link_libraries(sandbox PUBLIC jsonLexer jsonBuffer)




################################
######## JsonBufferTest ########
################################
add_executable(JsonBufferTest JsonBuffer.test.cpp)
add_test(NAME JsonBufferTest COMMAND JsonBufferTest)
target_include_directories(JsonBufferTest PUBLIC "../include")
target_link_libraries(
    JsonBufferTest PUBLIC
    GTest::gtest_main
    jsonBuffer
)

set(JSON_BUFFER_TEST_DATA "${CMAKE_SOURCE_DIR}/tests/data/JsonBuffer.test.json")
target_compile_definitions(JsonBufferTest PUBLIC JSON_BUFFER_TEST_DATA=\"${JSON_BUFFER_TEST_DATA}\")
file(WRITE ${JSON_BUFFER_TEST_DATA}
    "{\n"
    "  \"name\": \"JNOVA\",\n"
    "  \"value\": 2025,\n"
    "  \"nested\": { \"true\": true }\n"
    "}\n"
)




###############################
######## JsonLexerTest ########
###############################
add_executable(JsonLexerTest JsonLexer.test.cpp)
add_test(NAME JsonLexerTest COMMAND JsonLexerTest)

target_include_directories(JsonLexerTest PUBLIC "../include")
target_link_libraries(
    JsonLexerTest PUBLIC
    GTest::gtest_main
    jsonLexer
    jsonBuffer
)

set(JSON_LEXER_TEST_DATA "${CMAKE_SOURCE_DIR}/tests/data/JsonLexer.test.json")
target_compile_definitions(JsonLexerTest PUBLIC JSON_LEXER_TEST_DATA=\"${JSON_LEXER_TEST_DATA}\")
file(WRITE ${JSON_LEXER_TEST_DATA}
    "{\n"
    "  \"object\": {\n"
    "    \"array #1\": [\n"
    "      {\n"
    "        \"apple\": \"granny-smith\"\n"
    "      },\n"
    "      {\n"
    "        \"orange\": \"valencia\"\n"
    "      }\n"
    "    ],\n"
    "    \"array #2\": [true, false, null],\n"
    "    \"A\": 0,\n"
    "    \"B\": \"Hello World!\",\n"
    "    \"C\": \"123\",\n"
    "    \"D\": 2507500000,\n"
    "    \"E\": -1,\n"
    "    \"F\": null,\n"
    "    \"G\": null,\n"
    "    \"H\": \"IJK\",\n"
    "    \"I\": \"JK\",\n"
    "    \"J\": \"K\",\n"
    "    \"L\": [-103, 0, false]\n"
    "  }\n"
    "}\n"
)