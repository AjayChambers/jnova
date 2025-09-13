#pragma once
#ifndef LEXER_HPP
#define LEXER_HPP

#include <json/buffer.hpp>

#include <array>
#include <map>
#include <set>
#include <vector>

#include <iostream>
#include <optional>
#include <ranges>
#include <variant>

using std::string;                               // JSON String
using Number        = std::variant<int, double>; // JSON Number
using TokenValue    = std::variant<Number, std::string, unsigned char>;
using File_Position = std::pair<unsigned int, unsigned int>;

namespace Json {



enum class TOKEN_TYPE {
  OBJECT_OPEN,
  OBJECT_CLOSE,
  ARRAY_OPEN,
  ARRAY_CLOSE,
  KV_OPERATOR,
  DELEMITER,
  JSON_STRING,
  JSON_NUMBER,
  TRUE,
  FALSE,
  NUL,
  LINEBREAK,
  SPACE,
  TAB
};



enum class TOKEN_GROUP {
  STRUCTURAL,
  LITERAL_VALUE,
  DYNAMIC_VALUE,
  WHITESPACE
};



struct Token {
  TOKEN_TYPE type;
  TOKEN_GROUP group;
  TokenValue value;
};





class JsonAnalyzer {
  unsigned int row = 0;
  unsigned int col = 0;

  std::vector<Token> tokens;
  JsonBuffer jsonBuffer;


public:
  JsonAnalyzer(JsonBuffer jsonBuffer);
  JsonAnalyzer(const string &jsonString);

  // ACCESSORS
  const string getData() const;
  File_Position getPosition() const;
  std::string_view viewData() const; // string_view getter

  // LOGICAL / ALGORITHMIC
  void analyze();
  void addToken(Token token);
  void trackPosition(const unsigned char ch);
  std::optional<TOKEN_TYPE> identifyTokenType(const unsigned char ch);

  inline static const std::map<const unsigned char, TOKEN_TYPE> tokenTypeIdentifiers{
     {'{', TOKEN_TYPE::OBJECT_OPEN}, {'}', TOKEN_TYPE::OBJECT_CLOSE},
     {'[', TOKEN_TYPE::ARRAY_OPEN},  {']', TOKEN_TYPE::ARRAY_CLOSE},
     {':', TOKEN_TYPE::KV_OPERATOR}, {',', TOKEN_TYPE::DELEMITER},
     {'t', TOKEN_TYPE::TRUE},        {'f', TOKEN_TYPE::FALSE},
     {'n', TOKEN_TYPE::NUL},         {' ', TOKEN_TYPE::SPACE},
     {'\n', TOKEN_TYPE::LINEBREAK},  {'\t', TOKEN_TYPE::TAB},
     {'"', TOKEN_TYPE::JSON_STRING}, {'1', TOKEN_TYPE::JSON_NUMBER},
     {'2', TOKEN_TYPE::JSON_NUMBER}, {'3', TOKEN_TYPE::JSON_NUMBER},
     {'4', TOKEN_TYPE::JSON_NUMBER}, {'5', TOKEN_TYPE::JSON_NUMBER},
     {'6', TOKEN_TYPE::JSON_NUMBER}, {'7', TOKEN_TYPE::JSON_NUMBER},
     {'8', TOKEN_TYPE::JSON_NUMBER}, {'9', TOKEN_TYPE::JSON_NUMBER},
     {'0', TOKEN_TYPE::JSON_NUMBER}, {'-', TOKEN_TYPE::JSON_NUMBER},
     {'+', TOKEN_TYPE::JSON_NUMBER}, {'e', TOKEN_TYPE::JSON_NUMBER},
  };
};
} // End Namespace Json
#endif