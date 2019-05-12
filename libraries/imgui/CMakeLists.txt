cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 14)

set(TARGET main)

project(${TARGET})

# Main
add_executable(
    ${TARGET}
    ${TARGET}.cpp
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_widgets.cpp
    imgui/examples/imgui_impl_sdl.cpp
    imgui/examples/imgui_impl_opengl3.cpp
    imgui/examples/libs/gl3w/GL/gl3w.c
)

# include: SDL
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# include: ImGui(symbolic linked)
include_directories(
    imgui/
    imgui/examples
    imgui/examples/libs/gl3w
)

# link
target_link_libraries(
    ${TARGET}
    ${SDL2_LIBRARIES}
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)
