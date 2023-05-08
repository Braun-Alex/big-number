cmake_minimum_required(VERSION 3.20)
project(Big_Number)

set(CMAKE_CXX_STANDARD 23)
set(HEADERS bigint.h)
set(SOURCES bigint.cpp main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
