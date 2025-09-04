# Function: write_test_json
#
# WRITE TEST DATA EXAMPLE:
#
# write_test_data(
#   "testdata-0.json"
#   "{"
#   "    \"Apple\": \"Granny-Smith\","
#   "    \"Grape\": \"Concord\","
#   "    \"Orange\": \"Navel\""
#   "}"
# )
function(write_test_data filename)
  file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/data/${filename}" "")
  file(WRITE "./data/${filename}" "")

  foreach(line IN LISTS ARGN)
    file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/data/${filename}" "${line}\n")
    file(APPEND "./data/${filename}" "${line}\n")
  endforeach()
endfunction()
