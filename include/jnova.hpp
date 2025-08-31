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

#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

#include "jbuff.hpp"
#include "typedefs.hpp"

namespace fs = std::filesystem;

using fs::path;
using std::string;
using std::string_view;

namespace Jnova {
    class Lexer
    {
        JsonBuffer json;

       public:
        Lexer(JsonBuffer json);
    };
}