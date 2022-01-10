cmake_minimum_required(VERSION 3.10)
project(sfpl_dll)

set(CMAKE_CXX_STANDARD 14)

add_library(sfpl SHARED library.cpp sfpl/sources/sfpl.cpp sfpl/sources/font.cpp)
target_include_directories(sfpl PUBLIC sfpl/sources)
