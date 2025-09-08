#include <json/lexer.hpp>

#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-parameter"

using namespace std;

namespace JNOVA {
    Token::Token(
      const TokenType &type,
      const TokenValue &val,
      unsigned int row,
      unsigned int col)
    : type(type)
    , value(val)
    , row(row)
    , col(col)
    {}


    void Token::setRow(unsigned int row)
    {
        this->row = row;
    }

    void Token::setCol(unsigned int col)
    {
        this->col = col;
    }

    unsigned int Token::getRow() const noexcept
    {
        return this->row;
    }


    unsigned int Token::getCol() const noexcept
    {
        return this->col;
    }


    std::string getType();

    auto Tokenizer::tokenFactory(
      TokenType type,
      TokenValue value,
      unsigned int row,
      unsigned int col)
    {

        return make_unique<Token>(type, value, row, col);
    }

    optional<string> toString(TokenType type)
    {
        switch (type) {

        case TokenType::Curly_Brace_Opened: return "Curly_Brace_Opened";
        case TokenType::Curly_Brace_Closed: return "Curly_Brace_Closed";
        case TokenType::Sq_Bracket_Opened : return "Sq_Bracket_Opened";
        case TokenType::Sq_Bracket_Closed : return "Sq_Bracket_Closed";
        case TokenType::Comma             : return "Comma";
        case TokenType::Colon             : return "Colon";
        case TokenType::String            : return "String";
        case TokenType::Number            : return "Number";
        case TokenType::Null_Literal      : return "Null_Literal";
        case TokenType::True_Literal      : return "True_Literal";
        case TokenType::False_Literal     : return "False_Literal";
        case TokenType::Newline           : return "Newline";
        case TokenType::Space             : return "Space";
        case TokenType::Tab               : return "Tab";
        default                           : {
            return nullopt;
        }
        }
    }
}

int main()
{
    return 0;
}
