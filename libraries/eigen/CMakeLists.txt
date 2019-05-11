cmake_minimum_required(VERSION 3.9)
project(main)
set(CMAKE_CXX_STANDARD 14)

# Main
add_executable(main
    main.cpp
)

# include: Eigen is a header only library!
include_directories("/usr/local/Cellar/eigen/3.3.7/include/eigen3")

