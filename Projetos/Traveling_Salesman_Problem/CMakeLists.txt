cmake_minimum_required(VERSION 3.10)

project(problemaCaxeiroViajante VERSION 1.0 LANGUAGES CXX)

include_directories ( include )

add_executable( Traveling_Salesman_Problem
                source/main.cpp
                source/simulation.cpp)

set_property(TARGET  Traveling_Salesman_Problem PROPERTY CXX_STANDARD 20)
