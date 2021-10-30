cmake_minimum_required(VERSION 3.20)
project(Ordenamiento)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ordenamiento main.cpp Orden.cpp Orden.h Search.cpp Search.h)
