cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)

set(TARGET main)

project(${TARGET})
add_executable(${TARGET} ${TARGET}.cpp)

set(OpenCV_DIR $ENV{HOME}/git/opencv/build)
find_package(OpenCV REQUIRED)
if(OpenCV_FOUND)
    target_include_directories(${TARGET} PUBLIC ${OpenCV_INCLUDE_DIRS})
    target_link_libraries(${TARGET} ${OpenCV_LIBS})
endif()
