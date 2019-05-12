cmake_minimum_required(VERSION 3.9)

set(TARGET addmdl)
project(${TARGET})
set(PYBIND11_CPP_STANDARD -std=c++14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")

find_package(pybind11 REQUIRED)
pybind11_add_module(${TARGET} SHARED ${TARGET}.cpp)