#pragma once

#ifndef LEXER_HPP
#define LEXER_HPP

#include <exception>
#include <iostream>
#include <json/buffer.hpp>
#include <map>
#include <memory>
#include <optional>
#include <set>
#include <stdexcept>
#include <string>
#include <string_view>
#include <unordered_set>
#include <variant>
#include <vector>

using Number          = std::variant<int, double>;
using TokenValue      = std::variant<Number, std::string, char>;
using TokenIdentifier = std::pair<char, std::string>;

enum class TokenType {
    ObjectOpen,  // 0
    ObjectClose, // 1
    ArrayOpen,   // 2
    ArrayClose,  // 3
    Comma,       // 4
    Colon,       // 5
    True,        // 6
    False,       // 7
    Null,        // 8
    String,      // 9
    Number,      // 10
    Linebreak,   // 11
    Space,       // 12
    Tab          // 13
};

namespace Json {
    const std::string toString(TokenType type);




    struct Token {
        // Immutable Properties
        const TokenType type;
        const TokenValue value;
        const std::string toString();
    };





    class TokenControl {
        std::map<char, std::string> token_identifier;
        std::vector<char> char_identity;

      public:
        TokenControl();

        void addTokenIdentifier(char identifiedBy, TokenType tokenType);
        std::pair<char, std::string> getTokenIdentifier();
    };






    class Tokenizer {
      private:
        const JsonBuffer json;
        std::vector<Token> tokens;

      public:
        Tokenizer(const JsonBuffer &json);
    };
} // Namespace Json
#endif