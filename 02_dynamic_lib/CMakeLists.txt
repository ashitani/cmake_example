cmake_minimum_required(VERSION 3.9)
add_executable(test test.c)
add_library(hoge SHARED hoge.c)
target_link_libraries(test hoge)