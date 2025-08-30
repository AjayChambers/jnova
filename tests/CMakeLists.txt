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
add_gtest(json_buffer_test json_buffer_test "json_buffer.test.cpp" jnova)
#   set(t1 "test_id;test_cmd;test_src;link_lib")
#   set(t2 "test_id;test_cmd;test_src")
#   add_tests("${t1}" "${t2}")

