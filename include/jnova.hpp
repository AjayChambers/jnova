#include "typedefs.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

namespace fs = std::filesystem;

using fs::path;
using std::string;
using std::string_view;

namespace Jnova
{
  class JsonBuffer
  {
    string      data;
    string_view view;

    fs::path filepath = "";


   public:
    // COPY CTOR
    JsonBuffer();
    JsonBuffer(JsonBuffer& rs);
    // STRING
    JsonBuffer(string& jsonString);
    JsonBuffer(string&& jsonString);
    // STRING VIEW
    JsonBuffer(string_view jsonString);

    // SET FILEPATH
    // fs::path
    void setFilepath(const fs::path& filepath);
    void setFilepath(fs::path&& filepath);
    void setFilepath(const string& json_str);
    void setFilepath(string&& filepath);
    void setFilepath(std::string_view filepath);

    fs::path getFilepath() const noexcept;
  };






  class Lexer
  {
    JsonBuffer json;

   public:
    Lexer(JsonBuffer json);
  };
}