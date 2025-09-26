cmake_minimum_required(VERSION 3.10)
project(lab2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE "src")
set(HEADER "headers")

enable_testing()

add_library(lab2_array ${HEADER}/array.hpp ${SOURCES}/array.cpp)
#add_library(lab2_seven ${HEADER}/seven.hpp ${SOURCES}/seven.cpp)

add_executable(lab2 main.cpp)

#add_executable(Lab1Tests tests/tests.cpp)
#target_link_libraries(Lab1Tests PRIVATE gtest_main)
#target_include_directories(Lab1Tests PRIVATE src)
#add_test(NAME Lab1Tests COMMAND Lab1Tests)
