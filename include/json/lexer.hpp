#pragma once

#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <json/buffer.hpp>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

using namespace std;

using Number     = variant<int, double>;
using TokenValue = variant<Number, string, char>;

enum class TokenType {
    Curly_Brace_Opened, // <- Curly Brace Opened
    Curly_Brace_Closed, // <- Curly Brace Closed
    Sq_Bracket_Opened,  // <- Square Bracket Opened
    Sq_Bracket_Closed,  // <- Square Bracket Closed
    Comma,              // <- Comma
    Colon,              // <- Colon
    String,             // <- Dynamic String Value
    Number,             // <- Dynamic Number Value
    Null_Literal,       // <- Null Literal
    True_Literal,       // <- True Literal
    False_Literal,      // <- False Literal
    Newline,            // <- Whitespace Linebreak
    Space,              // <- Whitespace Space
    Tab
};






// [CTRL] + [SHIFT] + [B]

namespace JNOVA {
    struct Token {
        const TokenType type;
        const TokenValue value;

        unsigned int row;
        unsigned int col;

      public:
        Token(
          const TokenType &type,
          const TokenValue &val,
          unsigned int row,
          unsigned int col);

        void setRow(unsigned int row);
        void setCol(unsigned int col);

        unsigned int getRow() const noexcept;
        unsigned int getCol() const noexcept;
    };

    class Tokenizer
    {
        std::vector<Token> tokens;

      public:
        Tokenizer();
        Tokenizer(JsonBuffer json);

        auto tokenFactory(
          TokenType type,
          TokenValue value,
          unsigned int row,
          unsigned int col);
    };


    optional<string> toString(TokenType type);



}






#endif