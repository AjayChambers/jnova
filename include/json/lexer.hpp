#pragma once

#ifndef LEXER_HPP
#define LEXER_HPP

#include <json/buffer.hpp>
#include <optional>
#include <variant>

using Number = std::variant<int, double>;

namespace JNOVA
{
    namespace
    {
        using Number = std::variant<int, double>;

        enum class STRUCT_TOK_TYPE {
            CURLY_OPEN,
            CURLY_CLOSE,
            SQ_OPEN,
            SQ_CLOSE,
            COLON,
            COMMA
        };

        enum class LIT_TOK_TYPE { _TRUE, _FALSE, _NULL };
        enum class VAL_TOK_TYPE { NUMBER, STRING };

        template <typename T>
        struct Token {
            const std::string id;
            const std::string type;
            T value;
        };
    }



    std::optional<STRUCT_TOK_TYPE> ch_to_structTokType(char c);
    std::optional<LIT_TOK_TYPE> ch_to_litTokType(char c);
    std::optional<VAL_TOK_TYPE> ch_to_valTokType(char c);

    std::optional<const char> ch_from_structTokType(STRUCT_TOK_TYPE structuralType);
    std::optional<const std::string> ch_from_litTokType(LIT_TOK_TYPE literalType);
    std::optional<const std::string> ch_from_valTokType(VAL_TOK_TYPE valueType);

    // LIT_TOK_TYPE
    // VAL_TOK_TYPE

    class Parser {
        JsonBuffer json;

      public:
        Parser(const JsonBuffer& json);
    };
}

#endif