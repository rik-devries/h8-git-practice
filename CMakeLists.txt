cmake_minimum_required(VERSION 2.7)
project(hw7)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-Wall -pedantic -Werror -Wno-unused-result")

add_executable(main main.cpp ex1.cpp ex2.cpp ex3.cpp)
