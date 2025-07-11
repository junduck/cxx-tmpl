cmake_minimum_required(VERSION 3.22)
project(cxx_tmpl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wshadow -Wconversion")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost CONFIG REQUIRED)

add_library(prj_main_headers INTERFACE)
target_include_directories(prj_main_headers INTERFACE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(prj_main_headers INTERFACE Boost::boost)

# For header library
add_library(cxx_tmpl::headers ALIAS prj_main_headers)

if(NOT CMAKE_BUILD_TYPE STREQUAL "Release")
  # Fetch Google test and benchmark
  include(cmake/GoogleBenchAndTest.cmake)

  # Dummy TU to make clangd happy
  add_executable(_clangd_tu src/_clangd_tu.cpp)
  target_link_libraries(_clangd_tu PRIVATE prj_main_headers)

  # Add private dev headers
  add_library(private_headers INTERFACE)
  target_include_directories(private_headers INTERFACE ${PROJECT_SOURCE_DIR}/private)

  # enable testing
  enable_testing()
  add_subdirectory(test)

  # enable benchmarking
  add_subdirectory(bench)
endif()
