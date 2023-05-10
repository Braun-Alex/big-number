cmake_minimum_required(VERSION 3.20)
project(Big_Number)

set(CMAKE_CXX_STANDARD 23)
set(HEADERS bigint.h tests.h)
set(SOURCES bigint.cpp main.cpp tests.cpp)

add_subdirectory(testing/googletest)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} gtest_main gtest)