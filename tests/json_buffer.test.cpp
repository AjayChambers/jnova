#ifndef JSON_BUFFER_TEST_DATA
#define JSON_BUFFER_TEST_DATA "" // Satisfies Intellisense
#endif

#include <gtest/gtest.h>
#include <json/buffer.hpp>

#include <format>

using namespace std;
using namespace Json;




TEST(SUITE_JSON_BUFFER, Test_FilepathAccessors)
{
    JsonBuffer jbuf;

    jbuf.setPath(JSON_BUFFER_TEST_DATA);
    EXPECT_EQ(JSON_BUFFER_TEST_DATA, jbuf.getPath());
}




TEST(SUITE_JSON_BUFFER, Test_Read)
{
    string expectedJson
      = "{\n"
        "  \"name\": \"JNOVA\",\n"
        "  \"value\": 2025,\n"
        "  \"nested\": { \"true\": true }\n"
        "}\n";

    JsonBuffer jbuf;

    jbuf.setPath(JSON_BUFFER_TEST_DATA);
    jbuf.read();

    EXPECT_EQ(expectedJson, jbuf.getData());
}




TEST(SUITE_JSON_BUFFER, Test_CTorInitialization)
{
    JsonBuffer jbuf_A(
      "{\n"
      "  \"name\": \"JNOVA\",\n"
      "  \"value\": 2025,\n"
      "  \"nested\": { \"true\": true }\n"
      "}\n");
    JsonBuffer jbuf_B;

    jbuf_B.setPath(JSON_BUFFER_TEST_DATA);
    jbuf_B.read();

    EXPECT_EQ(jbuf_A.getData(), jbuf_B.getData());
}




TEST(SUITE_JSON_BUFFER, Test_CopyConstructor)
{
    JsonBuffer jbuf_A(
      "{\n"
      "  \"name\": \"JNOVA\",\n"
      "  \"value\": 2025,\n"
      "  \"nested\": { \"true\": true }\n"
      "}\n");

    JsonBuffer jbuf_B(jbuf_A);

    EXPECT_EQ(jbuf_A.getPath(), jbuf_B.getPath());
    EXPECT_EQ(jbuf_A.getData(), jbuf_B.getData());
    EXPECT_EQ(jbuf_A.viewData(), jbuf_B.viewData());
}




TEST(SUITE_JSON_BUFFER, Test_OverloadedAssignmentOperator)
{
    JsonBuffer jbuf_A(
      "{\n"
      "  \"name\": \"JNOVA\",\n"
      "  \"value\": 2025,\n"
      "  \"nested\": { \"true\": true }\n"
      "}\n");

    JsonBuffer jbuf_B = jbuf_A;

    EXPECT_EQ(jbuf_A.getPath(), jbuf_B.getPath());
    EXPECT_EQ(jbuf_A.getData(), jbuf_B.getData());
    EXPECT_EQ(jbuf_A.viewData(), jbuf_B.viewData());
}
