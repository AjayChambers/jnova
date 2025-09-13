##################################################################
## FILENAME:
##     "write_test_data_file.cmake"
## FUNCTIONS:
##     #1) "write_test_data_file"
##     #2)  "write_test_data_0"
##     #3)  "write_test_data_1"
## DESCRIPTION:
##     Writes the selected test data file to the path passed
##     into the TEST_DATA_PATH parameter
##################################################################

function(write_test_data_file ASSIGNED_TEST_DATA TEST_DATA_PATH)
  if(ASSIGNED_TEST_DATA STREQUAL "test_data_0")
    write_test_data_0(${TEST_DATA_PATH})
  elseif(ASSIGNED_TEST_DATA STREQUAL "test_data_1")
    write_test_data_1(${TEST_DATA_PATH})
  endif()
endfunction() #(!! WRITE_TEST_DATA_FILE !!)




function(write_test_data_0 TEST_DATA_PATH)
  file(WRITE ${TEST_DATA_PATH}
  "{\n"
  "  \"name\": \"JNOVA\",\n"
  "  \"value\": 2025,\n"
  "  \"nested\": { \"true\": true }\n"
  "}\n")
endfunction()




function(write_test_data_1 TEST_DATA_PATH)
  file(WRITE ${TEST_DATA_PATH}
    "{\n"
    "  \"object\": {\n"
    "    \"array #1\": [\n"
    "      {\n"
    "        \"apple\": \"granny-smith\"\n"
    "      },\n"
    "      {\n"
    "        \"orange\": \"valencia\"\n"
    "      }\n"
    "    ],\n"
    "    \"array #2\": [true, false, null],\n"
    "    \"A\": 0,\n"
    "    \"B\": \"Hello World!\",\n"
    "    \"C\": \"123\",\n"
    "    \"D\": 2507500000,\n"
    "    \"E\": -1,\n"
    "    \"F\": null,\n"
    "    \"G\": null,\n"
    "    \"H\": \"IJK\",\n"
    "    \"I\": \"JK\",\n"
    "    \"J\": \"K\",\n"
    "    \"L\": [-103, 0, false]\n"
    "  }\n"
    "}")
endfunction()
