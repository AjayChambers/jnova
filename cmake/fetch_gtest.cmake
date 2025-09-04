# Fetches Google Tests and adds it to the project
function(fetch_gtest gtest_zip_url)
    include(FetchContent)
    
    FetchContent_Declare(
      googletest
      URL ${gtest_zip_url}
    )
    
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    include(GoogleTest)
    # message(STATUS "")
endfunction() 