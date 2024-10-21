include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/releases/download/v1.15.2/googletest-1.15.2.tar.gz
  URL_HASH MD5=7e11f6cfcf6498324ac82d567dcb891e
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test_main main.cpp)
target_link_libraries(test_main GTest::gtest_main)

# Remove me
file(GLOB DUMMY_TEST dummy_*.cpp)
add_executable(test_dummy ${DUMMY_TEST})
target_link_libraries(test_dummy GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_main)
