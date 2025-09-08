# Include CTest
include(CTest)
enable_testing()

# Include GTest
include(FetchContent)
FetchContent_Declare(
    googletest 
    URL "https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip")
    FetchContent_MakeAvailable(googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
include(GoogleTest)

# test_jsonbuffer
add_executable(test_jsonbuffer test_jsonbuffer.cpp)
target_include_directories(test_jsonbuffer PUBLIC "../include")
target_link_libraries(test_jsonbuffer PUBLIC 
    GTest::gtest_main jsonBuffer)
add_test(NAME JsonBufferTest COMMAND test_jsonbuffer)

# Write test data for test_jsonbuffer
set(TEST_JSON_PATH "${CMAKE_SOURCE_DIR}/tests/data/test_0.json")
target_compile_definitions(test_jsonbuffer PUBLIC
    TEST_JSON_PATH=\"${TEST_JSON_PATH}\")
file(WRITE ${TEST_JSON_PATH}
    "{\n"
    "  \"name\": \"JNOVA\",\n"
    "  \"value\": 2025,\n"
    "  \"nested\": { \"true\": true }\n"
    "}\n")
