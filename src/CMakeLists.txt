# ADD TARGET LIBRARY 'jbuff'
add_library(jbuff STATIC "jbuff.lib.cpp")
target_include_directories(jbuff PUBLIC ${inc_dir})

# ADD TARGET LIBRARY 'jnova'
add_library(jnova STATIC "jnova.lib.cpp")
target_include_directories(jnova PUBLIC ${inc_dir})
target_link_libraries(jnova PUBLIC jbuff)