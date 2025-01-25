cmake_minimum_required(VERSION 3.10)

project(problemaCaxeiroViajante VERSION 1.0 LANGUAGES CXX)

include_directories ( include )

add_executable( Traveling_Salesman_Problem
                source/main.cpp
                source/simulation.cpp
                source/algorithms/grasp.cpp
                source/algorithms/tspGreedy.cpp
                source/algorithms/linKernighan.cpp
                source/algorithms/graspLocalSearch2.cpp
                source/algorithms/tspCheapestInsertion.cpp)

set_property(TARGET  Traveling_Salesman_Problem PROPERTY CXX_STANDARD 20)
