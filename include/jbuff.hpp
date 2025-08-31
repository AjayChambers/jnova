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


namespace Jnova {
    class JsonBuffer {
        string      data = "";
        string_view view = "";
        fs::path    path = "";

       public:
        // COPY CTOR
        JsonBuffer();
        JsonBuffer(JsonBuffer& rs);
        JsonBuffer(const string& jsonString);
        JsonBuffer(const fs::path& jsonPath);

        bool read();  // TODO | Add a mode option parameter

        void setData(const string& jsonString);
        void setPath(const string& filepath);

        const string      getData() const noexcept;
        const fs::path    getPath() const noexcept;
        const string_view viewData();  // string_view view getter
        void copyData(string& data);   // Data Getter using referenced argument
    };
}