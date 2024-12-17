cmake_minimum_required(VERSION 3.5)

project(rotasEmGrafos VERSION 1.0 LANGUAGES CXX)

include_directories ( include )

add_executable( Simulation
                source/main.cpp
                source/simulation.cpp
                source/algorithms/prim.cpp
                source/algorithms/kruskal.cpp
                source/algorithms/dijkstra.cpp
                source/algorithms/hierholzer.cpp
                source/algorithms/edmondsKarp.cpp
                source/algorithms/bellmanFord.cpp
                source/algorithms/floydWarshall.cpp
                source/algorithms/chuLiuEdmonds.cpp
                source/algorithms/fordFulkerson.cpp )

set_property(TARGET Simulation PROPERTY CXX_STANDARD 20)
