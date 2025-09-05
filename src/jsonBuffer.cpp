#include <json/buffer.hpp>

using namespace std;

namespace JNOVA
{
    // JSONBUFFER CONSTRUCTORS

    JsonBuffer::JsonBuffer() {}



    JsonBuffer::JsonBuffer(const string& jsonData)
    : data(jsonData)
    , view(jsonData)
    {}








    // JSONBUFFER LOGIC FUNCTION MEMBERS
    void JsonBuffer::clear() noexcept
    {
        data.clear();
        view = data;
    }



    void JsonBuffer::read()
    {
        if (path == "") {
            throw runtime_error(
              "In order for JsonBuffer to read a file, the file's path needs "
              "to be set"
            );
        }

        if (!fs::exists(path)) {
            throw runtime_error(
              "The file '" + string(path) + "' does not exist."
            );
        }

        std::ifstream jsonFile(path, std::ios::binary);

        if (!jsonFile.is_open()) {
            throw runtime_error("Failed to open file: " + path.string());
        }

        char c;

        while (jsonFile.get(c)) {
            data += c;
        }

        if (jsonFile.bad() && !jsonFile.eof()) {
            throw runtime_error("Fatal I/O error while reading file.");
        }

        if (jsonFile.fail() && !jsonFile.eof()) {
            throw runtime_error(
              "Failed to read entire file. This was likely do to an unexpected "
              "encoding standard, or a an unexpected file type."
            );
        }
    }








    // JSONBUFFER ACCESSORS

    void JsonBuffer::setFilepath(const string& jsonpath) noexcept
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

    void operator>>(const fs::path& fpath, JsonBuffer& jbuff)
    {
        jbuff.setFilepath(fpath);
        jbuff.read();
    }



    ostream& operator<<(ostream& os, JsonBuffer& jbuff)
    {
        os << jbuff.viewData();

        return os;
    }


}  // namespace JNOVA