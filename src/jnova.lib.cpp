/*
 * ***********************************************************************
 * @file "src/jnova.lib.cpp"
 * @author "Andrew Chambers" - (you@domain.com)
 * @brief "Definitions for JNova library functions."
 * @version 0.1
 * @date 2025-08-28
 *
 * @copyright Copyright (c) 2025
 **************************************************************************/
#include <jnova.hpp>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

using std::string;
using std::vector;

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
  // JsonBuffer::
};