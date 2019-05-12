cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 14)
add_library(hoge STATIC hoge.cpp)
target_include_directories(hoge PUBLIC ${PROJECT_SOURCE_DIR}/hoge)
