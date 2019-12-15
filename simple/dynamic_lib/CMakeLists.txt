cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)

set(TARGET main)
set(DLIB hoge)

add_executable(${TARGET} ${TARGET}.cpp)
add_library(${DLIB} SHARED ${DLIB}.cpp)
target_link_libraries(${TARGET} ${DLIB})