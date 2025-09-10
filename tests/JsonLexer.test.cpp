#ifndef JSON_LEXER_TEST_DATA
#define JSON_LEXER_TEST_DATA "" // Satisfies Intellisense
#endif

#include <filesystem>
#include <gtest/gtest.h>
#include <iostream>
#include <json/buffer.hpp>
#include <json/lexer.hpp>

namespace fs = std::filesystem;
using namespace std;
using namespace Json;






TEST(SUITE_JSON_LEXER, Test_foo)
{
    string jsonExpected = //
      "{\n"
      "  \"object\": {\n"
      "    \"array #1\": [\n"
      "      {\n"
      "        \"apple\": \"granny-smith\"\n"
      "      },\n"
      "      {\n"
      "        \"orange\": \"valencia\"\n"
      "      }\n"
      "    ],\n"
      "    \"array #2\": [true, false, null],\n"
      "    \"A\": 0,\n"
      "    \"B\": \"Hello World!\",\n"
      "    \"C\": \"123\",\n"
      "    \"D\": 2507500000,\n"
      "    \"E\": -1,\n"
      "    \"F\": null,\n"
      "    \"G\": null,\n"
      "    \"H\": \"IJK\",\n"
      "    \"I\": \"JK\",\n"
      "    \"J\": \"K\",\n"
      "    \"L\": [-103, 0, false]\n"
      "  }\n"
      "}\n";

    JsonBuffer jbuff;

    jbuff.setFilepath(JSON_LEXER_TEST_DATA);
    jbuff.read();

    const string actualJson = jbuff.getData();

    EXPECT_EQ(jsonExpected, actualJson);
}
