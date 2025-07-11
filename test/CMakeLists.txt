add_executable(test_main main.cpp)
target_link_libraries(test_main GTest::gtest_main private_headers)

# Remove me
file(GLOB DUMMY_TEST dummy_*.cpp)
add_executable(test_dummy ${DUMMY_TEST})
target_link_libraries(test_dummy GTest::gtest_main private_headers)

include(GoogleTest)
gtest_discover_tests(test_main)
