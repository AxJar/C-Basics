cmake_minimum_required(VERSION 3.19)
project(Sobrecarga_de_operadores)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sobrecarga_de_operadores main.cpp Rectangular.cpp Rectangular.h Polar.cpp Polar.h)