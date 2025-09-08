#ifndef JSON_BUFFER_TEST_DATA
#define JSON_BUFFER_TEST_DATA "" // Satisfies Intellisense
#endif

#include <format>
#include <gtest/gtest.h>
#include <json/buffer.hpp>

using namespace std;
using namespace JNOVA;




/*
 ****************************************************************
 * TEST HELPER FUNCTIONS
 ****************************************************************/

bool expectedJsonEquals(const string &actualJson)
{
    string expectedJson = "{\n"
                          "  \"name\": \"JNOVA\",\n"
                          "  \"value\": 2025,\n"
                          "  \"nested\": { \"true\": true }\n"
                          "}\n";

    return expectedJson == actualJson;
}




/*
 ****************************************************************
 * ACTUAL TESTS
 ****************************************************************/

/*
 *==========================================================*
 * [SUITE A | TEST 00]
 *--------------------------------*
 * Suite-A: 'JsonBuffer Suite'
 * Test-00: 'Read Test'
 * Description: "Tests JBuff::setFilepath()."
 *==========================================================*/
TEST(SxA_JsonBuffer, testSettingPath_setPathFuncMem)
{
    string jsonFilepath = JSON_BUFFER_TEST_DATA;
    JsonBuffer jbuf;

    jbuf.setFilepath(jsonFilepath);
    EXPECT_EQ(jsonFilepath, jbuf.getPath());
}


/*
 *==========================================================*
 * [SUITE A | TEST 01]
 *--------------------------------*
 * Suite-A: 'JsonBuffer Suite'
 * Test-01: 'Read Test'
 * Desc: "Tests JBuff::read()."
 *==========================================================*/
TEST(SxA_JsonBuffer, testReadingData_readFuncMem)
{
    JsonBuffer jbuf;

    jbuf.setFilepath(JSON_BUFFER_TEST_DATA);
    jbuf.read();

    EXPECT_TRUE(expectedJsonEquals(jbuf.getData()));
}


/*
 */
TEST(SxA_JsonBuffer, testReadingData_iStreamOper)
{
    JsonBuffer jbuf;
    fs::path jsonFilepath = JSON_BUFFER_TEST_DATA;

    jsonFilepath >> jbuf;

    EXPECT_TRUE(expectedJsonEquals(jbuf.getData()));
}


/*
 */
TEST(SxA_JsonBuffer, testSettingData_ctor)
{
    JsonBuffer jbuf(
      "{\n"
      "  \"name\": \"JNOVA\",\n"
      "  \"value\": 2025,\n"
      "  \"nested\": { \"true\": true }\n"
      "}\n");

    EXPECT_TRUE(expectedJsonEquals(jbuf.getData()));
}