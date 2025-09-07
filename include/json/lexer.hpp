#pragma once
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <json/buffer.hpp>
#include <string>
#include <string_view>
#include <variant>
#include <vector>





using Number     = std::variant<int, double>;
using string     = std::string;
using TokenValue = std::variant<Number, string, char>;



enum class TOKEN_TYPE {
  // STRUCTURAL TOKENS
  COLON,
  COMMA,
  CURLY_OPENED,
  CURLY_CLOSED,
  SQ_BRACKET_OPENED,
  SQ_BRACKET_CLOSED,

  // LITERAL TOKENS
  LITERAL_TRUE,
  LITERAL_NULL,
  LITERAL_FALSE,

  // Dynamic JSON Value Tokens
  VALUE_STRING,
  VALUE_NUMBER,

  // WHITESPACE TOKENS
  WS_NEWLINE,
  WS_SPACE // Tabs should be converted to WS_SPACE
};





namespace JNOVA
{
  class LexicalAnalyzer
  {
    struct Token {
      TOKEN_TYPE type;
      TokenValue value;

      const unsigned int size;
      const unsigned int row;
      const unsigned int col;
    };

    std::vector<Token> tokens;

    public:
    LexicalAnalyzer(JsonBuffer json);

    void TokenGenerator(TOKEN_TYPE type, TokenValue value);
  };



}