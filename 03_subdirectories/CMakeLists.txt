cmake_minimum_required(VERSION 3.9)
add_subdirectory(hoge)
add_executable(test test.c)
target_link_libraries(test hoge)