cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 14)

set(TARGET main)
project(${TARGET})
add_executable(${TARGET} ${TARGET}.cpp)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(${TARGET} ${SDL2_LIBRARIES})
