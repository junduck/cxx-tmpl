# Remove me
add_executable(bench_dummy dummy.cpp)
target_link_libraries(bench_dummy PRIVATE benchmark::benchmark private_headers)
