/************************************************************************
 *  * Copyright (C) 2025 - Andrew Jay Chambers Jr
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
 * source: "src/jnova.lib.cpp"
 * author: "Andrew Chambers" 
 * email:  "w3dojo@gmail.com"
 * repo:   "https://GitHub.com/AjayChambers/jnova.git"
 * desc:   "Definitions for JNova library functions."
 **************************************************************************/

#include <jnova.hpp>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

using namespace std;






namespace Jnova
{
  JsonBuffer::JsonBuffer()
  {}



  JsonBuffer::JsonBuffer(JsonBuffer& rs)
      : data(rs.data),
        view(rs.view),
        filepath(rs.filepath)
  {
    this->data = rs.data;
    this->view = rs.view;
  }




  JsonBuffer::JsonBuffer(string& json_str)
      : data(move(json_str)),
        view(this->data)
  {}




  JsonBuffer::JsonBuffer(string&& json_str)
      : data(move(json_str)),
        view(this->data)
  {}



  JsonBuffer::JsonBuffer(const fs::path& filepath)
      : filepath(filepath)
  {
    this->read();
  }




  JsonBuffer::JsonBuffer(fs::path&& filepath)
      : filepath(filepath)
  {
    this->read();
  }





  void
  JsonBuffer::setFilepath(const std::filesystem::path& filepath)
  {
    this->filepath = filepath;
  }




  void
  JsonBuffer::setFilepath(std::filesystem::path&& filepath)
  {
    this->filepath = std::move(filepath);
  }




  void
  JsonBuffer::setFilepath(const std::string& filepath)
  {
    this->filepath = filepath;
  }




  void
  JsonBuffer::setFilepath(std::string&& filepath)
  {
    this->filepath = std::move(filepath);
  }




  void
  JsonBuffer::setFilepath(std::string_view filepath)
  {
    this->filepath = std::filesystem::path{std::string{filepath}};
  }



  fs::path
  JsonBuffer::getFilepath() const noexcept
  {
    return filepath;
  }






  bool
  JsonBuffer::read()
  {
    ifstream file("example.txt"); // Open the file

    if (!file) {
      cerr << "Error: File could not be opened!" << std::endl;
      return false;
    }

    char c;

    while (file.get(c)) {
      data += c;
    }

    if (file.bad() || file.fail()) {
      cerr << "Error: File could not be read!" << std::endl;
      return false; // TODO | Improve err handling using <expected>
    }

    view = data;

    return true;
  }

















  // JsonBuffer::
};