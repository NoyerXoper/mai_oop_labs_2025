cmake_minimum_required(VERSION 3.10)
project(lab1)

set(SOURCES src)
set(TESTS tests)
set(HEADERS headers)

include_directories(${HEADERS})
add_library(filter_text ${SOURCES}/filter_text.cpp)
add_executable(lab1 main.cpp)
target_link_libraries(lab1 PRIVATE filter_text)

add_executable(Lab1Tests tests/tests.cpp)
target_link_libraries(Lab1Tests PRIVATE filter_text gtest_main)

enable_testing()
add_test(NAME Lab1Tests COMMAND Lab1Tests)