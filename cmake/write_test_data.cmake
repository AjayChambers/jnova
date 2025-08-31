# Function: write_test_json
# Args:
#   OUTPUT_PATH — full path to the JSON file to write
#   ...         — one or more lines of JSON content
function(write_test_data OUTPUT_PATH)
  # Ensure parent directory exists
  get_filename_component(OUT_DIR "${OUTPUT_PATH}" DIRECTORY)
  file(MAKE_DIRECTORY "${OUT_DIR}")

  # Write the first argument (path), then append each JSON line
  file(WRITE "${OUTPUT_PATH}" "")            # clear any existing file
  foreach(line IN LISTS ARGN)
    file(APPEND "${OUTPUT_PATH}" "${line}\n")
  endforeach()
  message(STATUS "Generated test JSON at: ${OUTPUT_PATH}")
endfunction()
