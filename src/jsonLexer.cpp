#include <json/lexer.hpp>

#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-parameter"

using namespace std;

namespace Json {

    const std::string toString(TokenType type)
    {
        switch (type) {
            case TokenType::ObjectOpen : return "ObjectOpen";
            case TokenType::ObjectClose: return "ObjectClose";
            case TokenType::ArrayOpen  : return "ArrayOpen";
            case TokenType::ArrayClose : return "ArrayClose";
            case TokenType::Comma      : return "Comma";
            case TokenType::Colon      : return "Colon";
            case TokenType::True       : return "True";
            case TokenType::False      : return "False";
            case TokenType::Null       : return "Null";
            case TokenType::String     : return "String";
            case TokenType::Number     : return "Number";
            case TokenType::Linebreak  : return "Linebreak";
            case TokenType::Space      : return "Space";
            case TokenType::Tab        : return "Tab";
            default:
                {
                    throw runtime_error(
                      "Token::toString failed to convert the token "
                      "becaus the token's type was invalid.");
                }
        }
    }



    const string Token::toString()
    {
        return Json::toString(type);
    }



    void TokenControl::addTokenIdentifier(char identifiedBy, TokenType tokenType)
    {
        token_identifier[identifiedBy] = toString(tokenType);
    }
}
