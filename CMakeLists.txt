cmake_minimum_required(VERSION 3.6)
project(bst_heap)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp heap_3358.h bst_3358.h)
add_executable(bst_heap ${SOURCE_FILES})