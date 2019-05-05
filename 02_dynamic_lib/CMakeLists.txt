cmake_minimum_required(VERSION 3.9)
add_executable(test test.cpp)
add_library(hoge SHARED hoge.cpp)
target_link_libraries(test hoge)