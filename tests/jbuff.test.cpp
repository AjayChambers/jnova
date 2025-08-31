#include <gtest/gtest.h>

#include <cassert>
#include <iostream>
#include <jbuff.hpp>


using namespace std;

const string TEST_DATA_PATH = "../data/jbuff_test_data.json";

const string DATA_EXPECTED =
  "{\n"
  "    \"Apple\": \"Granny-Smith\",\n"
  "    \"Grape\": \"Concord\",\n"
  "    \"Orange\": \"Navel\"\n"
  "}\n";



TEST(HelloTest, BasicAssertions) 
{
    Jnova::JsonBuffer buff = Jnova::JsonBuffer();

    buff.setPath("../data/jbuff_test_data.json");

    buff.read();

    // buff.
}

