#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

#include <json/lexer.hpp>

using namespace std;
using sv_iterator = std::string_view::const_iterator;

namespace Json {





const string toString(TOKEN_TYPE token_id)
{
  switch (token_id)
  {
    case TOKEN_TYPE::OBJECT_OPEN : return "ObjectOpen";
    case TOKEN_TYPE::OBJECT_CLOSE: return "ObjectClose";
    case TOKEN_TYPE::ARRAY_OPEN  : return "ArrayOpen";
    case TOKEN_TYPE::ARRAY_CLOSE : return "ArrayClose";
    case TOKEN_TYPE::KV_OPERATOR : return "KV_Operator";
    case TOKEN_TYPE::DELEMITER   : return "Delimeter";
    case TOKEN_TYPE::JSON_STRING : return "StringValue";
    case TOKEN_TYPE::JSON_NUMBER : return "NumericValue";
    case TOKEN_TYPE::TRUE        : return "True";
    case TOKEN_TYPE::FALSE       : return "False";
    case TOKEN_TYPE::NUL         : return "Null";
    case TOKEN_TYPE::LINEBREAK   : return "WS_Linebreak";
    case TOKEN_TYPE::SPACE       : return "WS_Space";
    case TOKEN_TYPE::TAB         : return "WS_Tab";
    default                      : {
      throw runtime_error(
         "Failed to convert TOKEN_TYPE toString(). The "
         "token_id argument was not a valid TOKEN_TYPE.");
    }
  }
}

const string toString(TOKEN_GROUP tokenType)
{
  switch (tokenType)
  {
    case TOKEN_GROUP::STRUCTURAL   : return "structural";
    case TOKEN_GROUP::LITERAL_VALUE: return "literal_value";
    case TOKEN_GROUP::DYNAMIC_VALUE: return "dynamic_value";
    case TOKEN_GROUP::WHITESPACE   : return "whitespace";
    default                        : {
      throw runtime_error(
         "Failed to convert TOKEN_GROUP toString(). The "
         "tokenType was not a valid TOKEN_GROUP.");
    }
  }
}





JsonAnalyzer::JsonAnalyzer(JsonBuffer jsonBuffer)
{
  jsonBuffer = jsonBuffer;
}

JsonAnalyzer::JsonAnalyzer(const string &jsonString)
: jsonBuffer(jsonString)
{}





void JsonAnalyzer::addToken(Token token)
{
  tokens.push_back(token); // FIFO
}





const string JsonAnalyzer::getData() const
{
  return jsonBuffer.getData();
}





string_view JsonAnalyzer::viewData() const
{
  return jsonBuffer.viewData();
}





void JsonAnalyzer::trackPosition(unsigned char ch)
{
  if (ch == '\n')
  {
    row += 1;
    col = 0;
  }
  else if (ch == '\n')
  {
    row += 1;
    col = 0;
  }
}




optional<TOKEN_TYPE> JsonAnalyzer::identifyTokenType(const unsigned char ch)
{
  if (tokenTypeIdentifiers.contains(ch))
  {
    switch (ch)
    {
      default: return tokenTypeIdentifiers.at(ch);
    }
  }

  return nullopt;
}



void JsonAnalyzer::analyze()
{
  string_view json = jsonBuffer.viewData();

  if (json.length() < 2)
    throw new range_error(
       "Ex, json data contains to few chars to be able to analyze it.");

  sv_iterator iter = json.begin();

  size_t index = 0;

  while (iter != json.end())
  {
    const char ch = *iter++;

    trackPosition(ch);

    auto tokenType = identifyTokenType(ch);

    if (tokenType == nullopt)
    {
      // format("An err PARSER ERROR", ch);
      throw runtime_error("ERROR: invalid json format. ");
    }
  }
}
}
