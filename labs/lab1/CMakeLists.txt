cmake_minimum_required(VERSION 3.10)
project(lab1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_library(lab1lib src/filter_text.cpp)
add_executable(lab1 main.cpp)

set(INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(Lab1Tests tests/tests.cpp)
target_link_libraries(Lab1Tests PRIVATE gtest_main)
# target_include_directories(lab1 PRIVATE ${INCLUDES})
target_include_directories(Lab1Tests PRIVATE src)
add_test(NAME Lab1Tests COMMAND Lab1Tests)
