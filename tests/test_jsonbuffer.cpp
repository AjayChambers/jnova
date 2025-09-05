#ifndef TEST_JSON_PATH
#define TEST_JSON_PATH ""  // Satisfies Intellisense
#endif

#include <gtest/gtest.h>

#include <format>
#include <json/buffer.hpp>

using namespace std;
using namespace JNOVA;




/*
 ****************************************************************
 * TEST HELPER FUNCTIONS
 ****************************************************************/

bool expectedJsonEquals(const string& actualJson)
{
    string expectedJson =
      "{\n"
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
    string jsonFilepath = TEST_JSON_PATH;
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

    jbuf.setFilepath(TEST_JSON_PATH);
    jbuf.read();

    EXPECT_TRUE(expectedJsonEquals(jbuf.getData()));
}


/*
 */
TEST(SxA_JsonBuffer, testReadingData_iStreamOper)
{
    JsonBuffer jbuf;
    fs::path jsonFilepath = TEST_JSON_PATH;

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
      "}\n"
    );

    EXPECT_TRUE(expectedJsonEquals(jbuf.getData()));
}