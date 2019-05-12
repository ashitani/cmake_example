cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 14)

set(TARGET main)

project(${TARGET})
add_subdirectory(hoge)
add_executable(${TARGET} ${TARGET}.cpp)
target_link_libraries(${TARGET} hoge)