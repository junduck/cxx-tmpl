cmake_minimum_required(VERSION 3.22)
project(cxx_tmpl)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost CONFIG REQUIRED)

add_library(prj_main_headers INTERFACE)
target_include_directories(prj_main_headers INTERFACE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(prj_main_headers INTERFACE Boost::boost)

# For header library
add_library(cxx_tmpl::headers ALIAS prj_main_headers)

add_executable(_clangd_tu src/_clangd_tu.cpp)
target_link_libraries(_clangd_tu PRIVATE prj_main_headers)

enable_testing()
add_subdirectory(test)

add_subdirectory(bench)
