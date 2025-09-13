#include <json/buffer.hpp>

using namespace std;

namespace Json {

JsonBuffer::JsonBuffer() {}



JsonBuffer::JsonBuffer(const string &jsonData)
: data(jsonData)
, view(jsonData)
{}



JsonBuffer::JsonBuffer(const JsonBuffer &other)
: path(other.getPath())
, data(other.getData())
, view(other.viewData())
{}



JsonBuffer JsonBuffer::operator=(JsonBuffer &other)
{
  if (this != &other)
  {
    this->data = other.data;
    this->path = other.path;
    this->view = other.view;
  }

  return *this;
}



// JSONBUFFER LOGIC FUNCTION MEMBERS
void JsonBuffer::clear() noexcept
{
  data.clear();
  view = data;
}



void JsonBuffer::read()
{
  if (path == "")
  {
    throw runtime_error("Stream failed. JsonBuffer doesn't have a filepath set.");
  }

  if (!fs::exists(path)) { throw runtime_error("File does not exist."); }

  std::ifstream jsonFile(path, std::ios::binary);

  if (!jsonFile.is_open()) { throw runtime_error("Failed to open file."); }

  char c;

  while (jsonFile.get(c))
  {
    data += c;
  }

  if (jsonFile.bad() && !jsonFile.eof())
  {
    throw runtime_error("Bad bit found. Possible corrupted data or system error.");
  }

  if (jsonFile.fail() && !jsonFile.eof())
  {
    throw runtime_error(
       "Failed to read entire file. This was likely do to an unexpected "
       "encoding standard, or a an unexpected file type.");
  }
}








// JSONBUFFER ACCESSORS

void JsonBuffer::setPath(const string &jsonpath) noexcept
{
  path = jsonpath;
}



const std::string_view JsonBuffer::viewData() const noexcept
{
  return this->view;
}



const std::string JsonBuffer::getPath() const noexcept
{
  return this->path;
}



const std::string JsonBuffer::getData() const noexcept
{
  return this->data;
}








// JSONBUFFER OVERLOADED OPERATORS

void operator>>(const fs::path &fpath, JsonBuffer &jbuff)
{
  jbuff.setPath(fpath);
  jbuff.read();
}



ostream &operator<<(ostream &os, JsonBuffer &jbuff)
{
  os << jbuff.viewData();

  return os;
}










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
}