#ifndef JSON_BUFFER_TEST_DATA
#define JSON_BUFFER_TEST_DATA "" // Satisfies Intellisense
#endif

#include <format>
#include <gtest/gtest.h>
#include <json/buffer.hpp>

using namespace std;
using namespace Json;


/*
 ****************************************************************
 * TEST HELPER FUNCTIONS
 ****************************************************************/
bool expectedJsonEquals(const string &actualJson)
{
    string expectedJson
      = "{\n"
        "  \"name\": \"JNOVA\",\n"
        "  \"value\": 2025,\n"
        "  \"nested\": { \"true\": true }\n"
        "}\n";

    return expectedJson == actualJson;
}


TEST(SUITE_JSON_BUFFER, Test_setFilepath)
{
    string jsonFilepath = JSON_BUFFER_TEST_DATA;
    JsonBuffer jbuf;

    jbuf.setFilepath(jsonFilepath);
    EXPECT_EQ(jsonFilepath, jbuf.getPath());
}



TEST(SUITE_JSON_BUFFER, Test_readJsonFile)
{
    JsonBuffer jbuf;

    jbuf.setFilepath(JSON_BUFFER_TEST_DATA);
    jbuf.read();

    EXPECT_TRUE(expectedJsonEquals(jbuf.getData()));
}



TEST(SUITE_JSON_BUFFER, Test_inStreamOperatorOverload)
{
    JsonBuffer jbuf;
    fs::path jsonFilepath = JSON_BUFFER_TEST_DATA;

    jsonFilepath >> jbuf;

    EXPECT_TRUE(expectedJsonEquals(jbuf.getData()));
}




TEST(SUITE_JSON_BUFFER, Test_ctorInitialization)
{
    JsonBuffer jbuf(
      "{\n"
      "  \"name\": \"JNOVA\",\n"
      "  \"value\": 2025,\n"
      "  \"nested\": { \"true\": true }\n"
      "}\n");

    EXPECT_TRUE(expectedJsonEquals(jbuf.getData()));
}