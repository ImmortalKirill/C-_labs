cmake_minimum_required(VERSION 3.21)
project(lab1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS"${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror")
add_executable(lab1 additional_2.cpp)
