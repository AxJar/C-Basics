cmake_minimum_required(VERSION 3.19)
project(Gauss)

set(CMAKE_CXX_STANDARD 14)

add_executable(Gauss main.cpp NGauss.cpp NGauss.h)