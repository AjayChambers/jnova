#ifndef JSONBUFFER_HPP
#define JSONBUFFER_HPP

// #include <source_location>
// #include <stacktrace>
// #include <optional>  // For optional stacktrace
// #include <exception>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>

namespace fs = std::filesystem;

namespace JNOVA
{
    class JsonBuffer {
        fs::path path         = "";
        std::string data      = "";
        std::string_view view = "";


      public:
        // Constructors
        JsonBuffer();
        JsonBuffer(const std::string& jsonData);

        // Function Members
        void read();
        void clear() noexcept;

        // Accessors & Mutators
        void setFilepath(const std::string& jsonpath) noexcept;
        const std::string getPath() const noexcept;
        const std::string getData() const noexcept;
        const std::string_view viewData() const noexcept;

        // // TODO: Overload the stream operators as follows:
        // friend fstream &operator<<(fs::path fpath, JsonBuffer jbuff);
        // friend fstream &operator>>(fs::path fpath, JsonBuffer jbuff);
    };
}  // namespace JNOVA
#endif