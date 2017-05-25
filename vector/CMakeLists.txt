cmake_minimum_required(VERSION 3.7)
project(vector)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp VectorInt.h VectorInt.cpp)
add_executable(vector ${SOURCE_FILES})