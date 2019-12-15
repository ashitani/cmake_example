cmake_minimum_required(VERSION 3.0)

# project
project(pybind11test)
set(TARGETS addmdl;numpytest)

# c++ compiler settings
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")

# python path
find_package(python REQUIRED)


#eigen
include_directories("/usr/local/Cellar/eigen/3.3.7/include/eigen3")

# pybind11
set(PYBIND11_CPP_STANDARD -std=c++14)
find_package(pybind11 REQUIRED)

# targets
foreach(TARGET IN LISTS TARGETS)
    pybind11_add_module(${TARGET} SHARED ${TARGET}.cpp)
endforeach()