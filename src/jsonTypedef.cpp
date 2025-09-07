#include <json/typedef.hpp>


Json j= 
{
  {"a", "b"}, 
  {"true", nullptr}, 
  {"newObject", 
    JsonObj({
      {   "fig", "watermelon" },
      {  "lime", "raspberry"  },
      {  "pear", "apricot"    },
      { "apple", "orange"     },
      { "grape", "cherry"     },
      { "peach", "avocado"    },
      { "anArr", JsonArray({
          "a", 
          "b", 
          "c", 
          "d"}
        )}
    })
  }
};