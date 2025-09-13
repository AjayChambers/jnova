#################################################################
## FILENAME:
##     "add_jnova_test.cmake"
## FUNCTIONS:
##     "add_jnova_test"
## DESCRIPTION:
##     Add test with data configures a unit test executable
##     target, writes a test data file for the unit test, and
##     adds the path as a compile definition to the target unit
##     test executable, so that the path is accessible before,
##     and after, runtime.
#################################################################

include(write_test_data_file)

function(add_jnova_test test_id assigned_test_data libs)
  string(TOUPPER "${test_id}" test_id_upper)
  set(unit_test_path "${CMAKE_CURRENT_SOURCE_DIR}/${test_id}.test.cpp")
  set(test_data_path "${CMAKE_CURRENT_SOURCE_DIR}/data/${test_id}-testdata.json")
  set(test_data_var_def "${test_id_upper}_TEST_DATA")

  if(NOT EXISTS ${unit_test_path})
    file(TOUCH ${unit_test_path})
    file(WRITE ${unit_test_path}
    "\n/**"
    "\n  * ---- JNOVA | JSON Toolset & C++ Support ----"
    "\n  * "
    "\n  * Copyright (C) 2025 - Andrew Jay Chambers Jr"
    "\n  * "
    "\n  * This program is free software: you can redistribute it and/or modify"
    "\n  * it under the terms of the GNU General Public License as published by"
    "\n  * the Free Software Foundation, either version 3 of the License, or (at"
    "\n  * your option) any later version. This program program is distributed in"
    "\n  * the hope that it will be useful, but WITHOUT ANY WARRANTY; without"
    "\n  * even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTIC-"
    "\n  * ULAR PURPOSE. See the GNU General Public License for more details."
    "\n  * You should have received a copy of the GNU GPL-3.0 license with this"
    "\n  * program.  If not visit 'https://www.gnu.org/licenses/'."
    "\n  * "
    "\n  *     -- Contact Email: Ajay-Chambers@outlook.com"
    "\n  * ***********************************************************************"
    "\n  * Project:   'JNOVA'"
    "\n  * Source Id: '${test_id_upper} TEST SUITE'"
    "\n  * Filepath:  '${unit_test_path}'"
    "\n  * Repo URL:  'https://GitHub.com/AjayChambers/jnova'"
    "\n  * Author:    'Andrew J Chambers <Ajay-Chambers@outlook.com>'"
    "\n  * Desc:"
    "\n  * ***********************************************************************/"
    "\n\n"
    "\n#pragma GCC diagnostic ignored \"-Wunused-function\""
    "\n#pragma GCC diagnostic ignored \"-Wunused-parameter\""
    "\n#pragma GCC diagnostic ignored \"-Wunused-but-set-variable\"\n"
    "\n#ifndef ${test_data_var_def}"
    "\n#define ${test_data_var_def}\"\""
    "\n#endif\n"
    "\n#include <gtest/gtest.h>\n\n\n"
    "\nTEST(SUITE_${test_id_upper}, TestNameHere)"
    "\n{"
    "\n    EXPECT_EQ(1, 1);"
    "\n}"
    "\n\n\n\n"
    "\nTEST(SUITE_${test_id_upper}, TestNameHere)"
    "\n{"
    "\n    EXPECT_EQ(1, 1);"
    "\n}"
    "\n\n\n\n"
    "\nTEST(SUITE_${test_id_upper}, TestNameHere)"
    "\n{"
    "\n    EXPECT_EQ(1, 1);"
    "\n}"
    )
  endif()

  if(assigned_test_data STREQUAL "test_data_0")
    write_test_data_file("test_data_0" ${test_data_path})
  elseif(assigned_test_data STREQUAL "test_data_1")
    write_test_data_file("test_data_1" ${test_data_path})
  endif()

  add_executable(${test_id} "${CMAKE_CURRENT_SOURCE_DIR}/${test_id}.test.cpp")
  target_compile_definitions(${test_id} PUBLIC ${test_data_var_def}=\"${test_data_path}\")
  target_include_directories(${test_id} PUBLIC ${CMAKE_SOURCE_DIR}/include)
  target_link_libraries(${test_id} PUBLIC "${${libs}}")

  # Add test to CTest
  add_test(NAME ${test_id} COMMAND ${test_id})
endfunction()
