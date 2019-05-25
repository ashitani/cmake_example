cmake_minimum_required(VERSION 3.9)

# project
project(pybind11test)
set(TARGETS addmdl;numpytest)

# c++ compiler settings
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")

# python path
find_package(python REQUIRED)

# pybind11
set(PYBIND11_CPP_STANDARD -std=c++14)
find_package(pybind11 REQUIRED)

# targets
foreach(TARGET IN LISTS TARGETS)
    pybind11_add_module(${TARGET} SHARED ${TARGET}.cpp)
endforeach()