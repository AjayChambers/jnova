#pragma GCC diagnostic ignored "-Wunused-function"
#include <json/lexer.hpp>

using namespace std;



namespace JNOVA
{
    Parser::Parser(const JsonBuffer& json)
    : json(json)
    {}




    optional<const char> ch_from_structTokType(STRUCT_TOK_TYPE tokenType)
    {
        switch (tokenType) {
            case STRUCT_TOK_TYPE::CURLY_OPEN : return '{';
            case STRUCT_TOK_TYPE::CURLY_CLOSE: return '}';
            case STRUCT_TOK_TYPE::SQ_OPEN    : return '[';
            case STRUCT_TOK_TYPE::SQ_CLOSE   : return ']';
            case STRUCT_TOK_TYPE::COLON      : return ':';
            case STRUCT_TOK_TYPE::COMMA      : return ',';
            default                          : {
                return nullopt;
            }
        }
    }


    optional<STRUCT_TOK_TYPE> ch_to_structTokType(char c)
    {
        switch (c) {
            case '{': return STRUCT_TOK_TYPE::CURLY_OPEN;
            case '}': return STRUCT_TOK_TYPE::CURLY_CLOSE;
            case '[': return STRUCT_TOK_TYPE::SQ_OPEN;
            case ']': return STRUCT_TOK_TYPE::SQ_CLOSE;
            case ':': return STRUCT_TOK_TYPE::COLON;
            case ',': return STRUCT_TOK_TYPE::COMMA;
            default : {
                return nullopt;
            }
        }
    }




    optional<const string> ch_from_litTokType(LIT_TOK_TYPE literalType)
    {
        switch (literalType) {
            case LIT_TOK_TYPE::_TRUE : return "true";
            case LIT_TOK_TYPE::_FALSE: return "false";
            case LIT_TOK_TYPE::_NULL : return "null";
            default                  : {
                return nullopt;
            }
        }
    }


    std::optional<LIT_TOK_TYPE> ch_to_litTokType(char c)
    {
        switch (c) {
            case 't': return LIT_TOK_TYPE::_TRUE;
            case 'f': return LIT_TOK_TYPE::_FALSE;
            case 'n': return LIT_TOK_TYPE::_NULL;
            default : {
                return nullopt;
            }
        }
    }


    std::optional<VAL_TOK_TYPE> ch_to_valTokType(char c)
    {
        switch (c) {
            case '"': return VAL_TOK_TYPE::STRING;
            case '1': return VAL_TOK_TYPE::NUMBER;
            case '2': return VAL_TOK_TYPE::NUMBER;
            case '3': return VAL_TOK_TYPE::NUMBER;
            case '4': return VAL_TOK_TYPE::NUMBER;
            case '5': return VAL_TOK_TYPE::NUMBER;
            case '6': return VAL_TOK_TYPE::NUMBER;
            case '7': return VAL_TOK_TYPE::NUMBER;
            case '8': return VAL_TOK_TYPE::NUMBER;
            case '9': return VAL_TOK_TYPE::NUMBER;
            case '0': return VAL_TOK_TYPE::NUMBER;
            default : {
                return nullopt;
            }
        }
    }


    optional<const string> ch_from_valTokType(VAL_TOK_TYPE valueType)
    {
        switch (valueType) {
            case VAL_TOK_TYPE::STRING: return "string";
            case VAL_TOK_TYPE::NUMBER: return "number";

            default: {
                return nullopt;
            }
        }
    }
}  // <-- END NAMESPACE
