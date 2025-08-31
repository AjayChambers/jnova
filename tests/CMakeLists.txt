# INCLUDE CTest & GTest
include(CTest)
include(fetch_gtest)
fetch_gtest("https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip")

# ADD/CONFIG TEST RUNNER 
add_executable(run_tests "runner.test.cpp")
target_link_libraries(run_tests PRIVATE jnova GTest::gtest_main)
add_test(run_tests COMMAND run_tests)

include(add_gtest)

add_gtest(test_suite_01 run_suite_01 "suite_01.test.cpp" jnova)
add_gtest(jbuff_test jbuff_test "jbuff.test.cpp" jnova)



# Define where to drop your test JSON
set(TEST_JSON_FILE )


include(write_test_data)
set(jbuff_test_data "${CMAKE_CURRENT_BINARY_DIR}/data/jbuff_test_data.json")
# Call the function with static pseudo data
write_test_data(
  "${jbuff_test_data}"
  "{"
  "    \"Apple\": \"Granny-Smith\","
  "    \"Grape\": \"Concord\","
  "    \"Orange\": \"Navel\""
  "}"
)