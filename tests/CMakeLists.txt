include(CTest)
enable_testing()
include(fetch_gtest)
fetch_gtest("https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip")

# ADD/CONFIG Test executable 'test_jsonbuffer'
add_executable(test_jsonbuffer test_jsonbuffer.cpp)
target_include_directories(test_jsonbuffer PUBLIC "../include")
target_link_libraries(test_jsonbuffer PUBLIC GTest::gtest_main jsonBuffer)
add_test(NAME JsonBufferTest COMMAND test_jsonbuffer)

# WRITE TEST DATA & CONFIG TEST TO BE ABLE TO MAKE USE OF IT
set(TEST_JSON_PATH "${CMAKE_SOURCE_DIR}/tests/data/test_0.json") # Set Filepath: 'TEST_JSON_PATH'
target_compile_definitions(test_jsonbuffer PUBLIC                # Inject 'TEST_JSON_PATH' into test
    TEST_JSON_PATH=\"${TEST_JSON_PATH}\")


file(WRITE ${TEST_JSON_PATH}                                     # Write data to 'TEST_JSON_PATH'
    "{\n"
    "  \"name\": \"JNOVA\",\n"
    "  \"value\": 2025,\n"
    "  \"nested\": { \"true\": true }\n"
    "}\n")
