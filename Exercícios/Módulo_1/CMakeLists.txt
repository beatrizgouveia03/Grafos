cmake_minimum_required(VERSION 3.5)

project(snaze VERSION 1.0 LANGUAGES CXX)

include_directories ( include )

add_executable( graph
                source/main.cpp
                source/graph.cpp
                source/digraph.cpp
                source/simulation.cpp)
set_property(TARGET graph PROPERTY CXX_STANDARD 20)