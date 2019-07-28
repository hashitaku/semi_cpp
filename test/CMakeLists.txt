cmake_minimum_required(VERSION 3.10)
project(semi_cpp_test CXX)

set(CMAKE_CXX_FLAGS "-std=c++17 -pedantic -Wall -Wextra -O3")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

file(GLOB ALL_CPP_FILE "*.cpp")

add_executable(semi_cpp_test ${ALL_CPP_FILE})

find_package(GTest REQUIRED)

target_link_libraries(semi_cpp_test
                      PRIVATE
                      GTest::GTest
                      GTest::Main
)

