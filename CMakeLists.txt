cmake_minimum_required(VERSION 3.23)
project(defuse)

set(CMAKE_CXX_STANDARD 17)

add_executable(defuse main.cpp HeatSystem.cpp HeatSystem.h Matrix.cpp Matrix.h Cell.cpp Cell.h)
