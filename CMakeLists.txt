cmake_minimum_required(VERSION 3.20)
project(sfpl_dll)

set(CMAKE_CXX_STANDARD 14)

add_library(sfpl_dll SHARED library.cpp sfpl/sources/sfpl.cpp sfpl/sources/font.cpp)
target_include_directories(sfpl_dll PUBLIC sfpl/sources)
