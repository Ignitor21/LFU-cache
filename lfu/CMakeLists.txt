cmake_minimum_required(VERSION 3.8)

project(lfu LANGUAGES CXX)
set(CMAKE_CXX_FLAGS_DEBUG " -Wall -g -O0 -D DEBUG -fsanitize=address -fsanitize=undefined")
add_executable(lfu lfu.cpp)