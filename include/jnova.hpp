/*************************************************************************
 * Copyright (C) 2025 - Andrew Jay Chambers Jr
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see 'https://www.gnu.org/licenses/'.
 * 
 * --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 * 
 * source: "include/jnova.hpp"
 * author: "Andrew Chambers" 
 * email:  "w3dojo@gmail.com"
 * repo:   "https://GitHub.com/AjayChambers/jnova.git"
 * desc:
 *************************************************************************/

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
    //
    JsonBuffer(const fs::path& filepath);
    JsonBuffer(fs::path&& filepath);
    // STRING VIEW
    JsonBuffer(string_view jsonString);


    void
    fromFile()
    {}

    void setFilepath(const fs::path& filepath);
    void setFilepath(fs::path&& filepath);
    void setFilepath(const string& json_str);
    void setFilepath(string&& filepath);
    void setFilepath(std::string_view filepath);

    fs::path getFilepath() const noexcept;

    bool read(); // TODO | Add a mode option parameter
  };






  class Lexer
  {
    JsonBuffer json;

   public:
    Lexer(JsonBuffer json);
  };
}