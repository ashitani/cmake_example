cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 14)

set(TARGET main)

project(${TARGET})
add_executable(${TARGET} ${TARGET}.cpp)

set(GLFW_ROOT /usr/local/Cellar/glfw/3.3.2)
include_directories(${GLFW_ROOT}/include/)
target_link_libraries(${TARGET} ${GLFW_ROOT}/lib/libglfw.dylib)
target_link_libraries(${TARGET} "-framework OpenGL")
