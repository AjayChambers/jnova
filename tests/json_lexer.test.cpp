/*
 * ------------- JNOVA: C++ JSON Tooling & Support -------------
 *
 *   Copyright (C) 2025 - Andrew Jay Chambers Jr
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version. This program program is distributed in
 * the hope that it will be useful, but WITHOUT ANY WARRANTY; without
 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTIC-
 * ULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU GPL-3.0 license with this
 * program. If you didn't receive a copy, or need another, please visit
 * the URL "https://www.gnu.org/licenses/".
 *
 * ***********************************************************************
 * PROJECT: "JNOVA"
 * SOURCE:  "JSON LEXER SUITE"
 * FILE:    "json_lexer.test.cpp"
 * AUTHOR:  "Andrew J Chambers"
 * CONTACT: "Ajay-Chambers@outlook.com"
 * REPO:    "https://www.GitHub.com/AjayChambers/jnova"
 *
 * DESCRIPTION:
 *   The src code below constitutes the entire "JSON LEXER TEST SUITE". It
 *   contains several tests that each execute 1 - 5 assertions. This test
 *   suite's name explains the purpose for these unit tests. They are
 *   responsible for testing the JsonLexer static library, which includes
 *   any JsonLexer classes and functions. The test should be executed any
 *   time a code change takes place. By unit testing, a project can have
 *   new features added, bugs fixed, and code refactored, without having
 *   unwanted surprises occur in the future (namely bugs).
 * ***********************************************************************/


#ifndef JSON_LEXER_TEST_DATA
#define JSON_LEXER_TEST_DATA ""
#endif

#include <json/buffer.hpp>
#include <json/lexer.hpp>
#include <gtest/gtest.h>

using namespace std;
using namespace Json;

// TEST HELPER FUNCTION
string expectedJsonData()
{
    string expectedJson
      = "{\n"
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
        "}";

    return expectedJson;
}



// TEST #01 @("JsonAnalyzer Ctor Initialization Test")
TEST(SUITE_JsonLexer, JsonAnalyzer_Initialization_Test)
{
    const string jsonpath = JSON_LEXER_TEST_DATA;

    //====================================================================*
    // |> TESTING: Constructor Initialization via JsonBuffer Object
    //====================================================================*
    JsonBuffer jsonBuffer;        // (1) Instantiate JsonBuffer obj
    jsonBuffer.setPath(jsonpath); // (2) Set path property to a json filepath
    jsonBuffer.read();            // (3) Read from the JsonFile @ JsonBuffer::path

    // (4) Initialize 'jsonAnalyzer' using 'JsonBuffer' obj
    JsonAnalyzer jsonAnalyzer_A(jsonBuffer);

    // (5) Extract the data from both jsonBuffer & jsonAnalyzer_A
    string expected_data_A = jsonBuffer.getData();
    string actual_data_A   = jsonAnalyzer_A.getData();

    // (6) Check that both objects contain data, if one doesn't the test fails.
    ASSERT_TRUE(expected_data_A.length() > 0 && actual_data_A.length() > 0);

    // (7) If both data strings are equal the test passes.
    EXPECT_EQ(expected_data_A, actual_data_A);

    //==========================================================*
    // |> Test 'Constructor' init via json formatted string
    //==========================================================*

    // (1) create a weebit of pseudo datas
    const string expected_data_B = "{\n    \"Testing\": 123\n}";

    // (2) Initialize jsonAnalyzer_B using json formatted string. When JsonAnalyzer is
    // initialized using a JsonBuffer obj, it instantiates its own internal buffer by
    // copying the JsonBuffer obj. If a JSON string is passed instead of a JsonBuffer obj,
    // it uses the string to initialize its internal JsonBuffer.
    JsonAnalyzer jsonAnalyzer_B(expected_data_B);

    // (3) JsonAnalyzer's getData method doesn't return a string it stores, calls its
    // internal JsonBuffer's getData() method. So by testing that getData is working, we
    // are testing ' JsonAnalyzer's internal buffer is working.
    const string actual_data_B = jsonAnalyzer_B.getData();

    // (4) Make sure that the test fails if no data is moved through the pipline.
    ASSERT_TRUE(actual_data_B.length() > 0);

    // (5) If actual_data_B equals expected_data_B the test passes.
    EXPECT_EQ(expected_data_B, actual_data_B);
}










TEST(SUITE_JsonLexer, JSON_Analysis_Test)
{
    JsonBuffer json;
    json.setPath(JSON_LEXER_TEST_DATA);
    json.read();

    JsonAnalyzer jsonAnalyzer(json);

    jsonAnalyzer.analyze();

    EXPECT_EQ(1, 1);
}