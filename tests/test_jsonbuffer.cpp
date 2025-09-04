#ifndef TEST_JSON_PATH
#define TEST_JSON_PATH ""  // Satisfies Intellisense
#endif

#include <gtest/gtest.h>

#include <jsonbuffer.hpp>




// TEST(JsonBufferTest, JsonBuffer) {}
TEST(JsonBufferTest, JB_Fn_setPath) {}




TEST(JsonBufferTest, ReadsExpectedJsonData)
{
    // Arrange
    const std::string expectedJson =
      "{\n"
      "  \"name\": \"JNOVA\",\n"
      "  \"value\": 2025,\n"
      "  \"nested\": { \"true\": true }\n"
      "}\n";

    // Create a temporary file for the test
    fs::path tempFile = fs::temp_directory_path() / "test.json";
    {
        std::ofstream out(tempFile);
        out << expectedJson;
    }

    JNOVA::JsonBuffer jb;

    jb.setFilepath(TEST_JSON_PATH);  // Assuming you have a setter for `path`

    jb.read();

    EXPECT_EQ(jb.getData(), expectedJson);


    fs::remove(tempFile);
}