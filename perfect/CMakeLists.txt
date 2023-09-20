cmake_minimum_required(VERSION 3.8)

project(perfect LANGUAGES CXX)

set(CMAKE_CXX_FLAGS_DEBUG " -Wall -g -O0 -D DEBUG -fsanitize=address -fsanitize=undefined")

add_executable(perfect perfect.cpp)