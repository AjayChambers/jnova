#include <jnova.hpp>

using namespace std;

namespace JNOVA {

Ex::Ex(string reason, const source_location &srcLoc)
: srcLoc_(srcLoc)
, reason_(move(reason))
, message_(make_message())
{}

const char *Ex::what() const noexcept
{
  return message_.c_str();
}

string Ex::make_message() const
{
  return format(
     "\n\nA FATAL ERROR CAUSED THE PROGRAM TO HALT EXECUTION.\n\n"
     "CAUSE: {}\n\n"
     "Error Location Details:\n"
     "\t* FILE LOC: {}\n"
     "\t* FUNCTION: {}\n"
     "\t* AT LINE: {}\n\n",
     reason_,
     srcLoc_.file_name(),
     srcLoc_.function_name(),
     srcLoc_.line());
}

} // namespace JNOVA
