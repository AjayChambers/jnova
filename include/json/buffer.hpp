#pragma once

#ifndef JSONBUFFER_HPP
#define JSONBUFFER_HPP

#include <exception>
#include <filesystem>
#include <format>
#include <fstream>
#include <stdexcept>
#include <string>
#include <string_view>


namespace fs = std::filesystem;

namespace Json {
class JsonBuffer {
    fs::path path         = "";
    std::string data      = "";
    std::string_view view = "";

  public:
    // Constructors
    JsonBuffer();
    JsonBuffer(const std::string &jsonData);
    JsonBuffer(const JsonBuffer &rval);

    // Function Members
    void read();
    void clear() noexcept;

    // Accessors & Mutators
    void setPath(const std::string &jsonpath) noexcept;
    void setData(const std::string &jsonData) noexcept;

    const std::string getPath() const noexcept;
    const std::string getData() const noexcept;
    const std::string_view viewData() const noexcept;

    JsonBuffer operator=(JsonBuffer &jsonBuffer);

    friend void operator>>(const fs::path &is, JsonBuffer &jbuff);
    friend std::ostream &operator<<(std::ostream &os, JsonBuffer &jbuff);
};
} // namespace Json
#endif