# Adds a test using the settings passed into the function parameters
#   Arg #1 ${test_id}  -- "The name of the executable target."
#   Arg #2 ${test_cmd} -- "The command used to run the test executable."
#   Arg #3 ${test_src} -- "Path to the test's source code (aka source file)"
#   Arg #4 ${link_lib} -- "The library you wish to test"
#    
# The test library "GTest::gtest_main" is automatically linked, and
# should not be passed in to ${link_lib}

function(add_gtest test_id test_cmd test_src link_lib)
    add_executable(${test_id} ${test_src})
    add_test(${test_id} COMMAND ${test_cmd})
    
    # LINK GTEST & ${link_lib}
    target_link_libraries(${test_id} PRIVATE 
        GTest::gtest_main ${link_lib})
    
    # CONFIG OUT DIR FOR TEST EXECUTABLES
    set_target_properties(${test_id} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests/bin")
endfunction()
