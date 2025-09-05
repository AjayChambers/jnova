#include <variant>

using Number = std::variant<int, double>;

enum class STRUCT_TOK_TYPE { CURLY_OPEN, CURLY_CLOSE, SQ_OPEN, SQ_CLOSE, COLON, COMMA };
enum class LIT_TOK_TYPE { _TRUE, _FALSE, _NULL };
enum class VAL_TOK_TYPE { NUMBER, STRING };

template<typename T>
struct Token {
    const std::string id;
    const std::string type;
    T value;
};

struct JsonPrimitive {};