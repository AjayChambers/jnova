# ####################################################################
# PROJ:  JNOVA | JSON Parser & Support for C++
# FNAME: Unit Test CMake Lists
# FPATH: CMakeLists.txt
# DIR:   jnova/tests
# REPO:  https://www.GitHub.com/AjayChambers/jnova
# DESC:  The file below is the 'tests' dir's CMakeLists.txt file
#   configures targets for unit test executables. It also imports
#   Google Test (or GTest) and enables the CTest CLI.
#####################################################################

####################################################
### INCLUDE TEST DEPENDENCIES
####################################################
include(FetchContent)
FetchContent_Declare(googletest
    URL "https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip")
FetchContent_MakeAvailable(googletest)

# Include GTest Library
include(GoogleTest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Include CTest Utility
include(CTest)
enable_testing()



include(add_jnova_test)

set(LIBS GTest::gtest_main jsonLexer jsonBuffer)
# list(LIBS GTest::gtest_main jsonLexer jsonBuffer)

add_jnova_test("json_buffer" "test_data_0" LIBS)
add_jnova_test("json_lexer" "test_data_1" LIBS)



add_executable(sandbox sandbox.cpp)
target_include_directories(sandbox PUBLIC "../include")
target_link_libraries(sandbox PUBLIC jsonLexer jsonBuffer)

# ####################################################
# ### CONFIGURE TEST EXECUTABLE TARGETS
# ####################################################
# add_executable(TestSuite_JsonLexer JsonLexer.test.cpp)




# ####################################################
# ### WRITE PSEUDO DATA FOR TEST SUITES
# ####################################################
# set(JSON_BUFFER_TEST_DATA "${CMAKE_SOURCE_DIR}/tests/data/JsonBuffer.test.json")
# set(JSON_LEXER_TEST_DATA ${CMAKE_SOURCE_DIR}/tests/data/JsonLexer.test.json)

# ####################################################
# ### ADD & CONFIG TEST 'JsonBufferTest'
# ####################################################
# target_link_libraries(JsonBufferTest PUBLIC GTest::gtest_main jsonBuffer)

# target_include_directories(TestSuite_JsonLexer PUBLIC "../include")

# add_test(NAME TestSuite_JsonLexer COMMAND TestSuite_JsonLexer)
# add_test(NAME JsonBufferTest COMMAND JsonBufferTest)