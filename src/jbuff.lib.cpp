
#include <jbuff.hpp>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

using namespace std;


namespace Jnova {
    JsonBuffer::JsonBuffer() {}


    JsonBuffer::JsonBuffer(const fs::path& jsonPath)
    : path(jsonPath) {}


    JsonBuffer::JsonBuffer(const string& jsonString)
    : data(jsonString),
      view(jsonString) {}


    JsonBuffer::JsonBuffer(JsonBuffer& rs)
    : data(rs.data),
      view(rs.view),
      path(rs.path) {
        this->data = rs.data;
        this->view = rs.view;
    }




    bool
    JsonBuffer::read() {
        ifstream file("example.txt");  // Open the file
        if (!file) throw runtime_error("Error: File could not be opened!");

        char c;

        while (file.get(c)) {
            data += c;
        }

        if (file.bad() || file.fail()) {
            // TODO | Improve err handling using <expected>
            throw runtime_error("Error: File could not be read!");
        }

        view = data;
        return true;
    }




    void
    JsonBuffer::setPath(const string& filepath) {
        this->path = filepath;
    }




    void
    JsonBuffer::setData(const string& jsonString) {
        data = jsonString;
        view = jsonString;
    }




    const fs::path
    JsonBuffer::getPath() const noexcept {
        return path;
    }
};