# **J Nova**

Copyright (C) 2025 - Andrew Jay Chambers Jr

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see the link below.

  - 'https://www.gnu.org/licenses/'


## JSON Structure

```
#include <json/typedef.hpp>

Json j = {
  {"a", "b"},
  {"true", nullptr},
  {"newObject", // <- json obj
  Obj_J({ 
    // Some K/V pairs
    {"fig", "watermelon"},
    {"lime", "raspberry"},
    {"pear", "apricot"},
    {"apple", "orange"},
    {"grape", "cherry"},
    {"peach", "avocado"},
    {"Numbers", // <- num arr
      Arr_J({
        2,
        4,
        8,
        16,
        "HelloWorld", // <- OK
        32,
        64,
        128
      })},
    {"Booleans", // <- bool arr
      Arr_J({
        false, 
        4, // <- OK
        nullptr, // <- OK
        true,
        true, 
        true
    })},
    {"nulls", // <- null array
      Arr_J({ 
        nullptr, 
        nullptr
      })} 
  })}
};
```