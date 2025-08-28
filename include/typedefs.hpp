#include <variant>

enum class TOKEN_TYPE
{
  CURLY_OPEN,
  CURLY_CLOSE,
  SQ_OPEN,
  SQ_CLOSE,
  COLON,
  COMMA,
  TRUE_,
  FALSE_,
  NULL_
};

using Number = std::variant<int, double>;