include(CTest)
enable_testing()

include(fetch_gtest)
fetch_gtest("https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip")



# Add the test executable
add_executable(test_jsonbuffer test_jsonbuffer.cpp)
target_link_libraries(test_jsonbuffer PRIVATE jsonbuffer)
target_include_directories(test_jsonbuffer PUBLIC "../include")

# Add the test
add_test(NAME JsonBufferTest COMMAND test_jsonbuffer)

# Where to generate the file
set(TEST_JSON_PATH "${CMAKE_SOURCE_DIR}/tests/data/test_0.json")

# Generate JSON data for testing
file(WRITE ${TEST_JSON_PATH}
"{\n"
"  \"name\": \"JNOVA\",\n"
"  \"value\": 2025,\n"
"  \"nested\": { \"true\": true }\n"
"}\n"
)

configure_file(${TEST_JSON_PATH} ${CMAKE_BINARY_DIR}/tests/data/test.json COPYONLY)


 target_link_libraries(test_jsonbuffer
   PUBLIC GTest::gtest_main jsonbuffer)

# Inject the path into the test code as a compile definition
target_compile_definitions(test_jsonbuffer PUBLIC TEST_JSON_PATH=\"${TEST_JSON_PATH}\")
