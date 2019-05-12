cmake_minimum_required(VERSION 3.9)

set(TARGET main)

project(${TARGET})
set(CMAKE_CXX_STANDARD 14)

set(Open3D_DIR $ENV{HOME}/git/Open3D/install)
find_package(Open3D HINTS ${Open3D_DIR}/lib/cmake)

if (Open3D_FOUND)
    list(APPEND Open3D_LIBRARIES dl)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${Open3D_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Open3D_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${Open3D_EXE_LINKER_FLAGS}")

    link_directories(${Open3D_LIBRARY_DIRS})
    add_executable(${TARGET} ${TARGET}.cpp)
    target_link_libraries(${TARGET} ${Open3D_LIBRARIES})
    target_include_directories(${TARGET} PUBLIC ${Open3D_INCLUDE_DIRS})
endif()
