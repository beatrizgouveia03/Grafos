# Graphs Simulation Project

Welcome to the Graphs Simulation project! This project provides a collection of graph algorithms implemented in C++. It serves as a comprehensive resource for learning and applying key operations on both graphs and directed graphs (digraphs).

## Table of Contents

1. [Introduction](#introduction)
2. [Usage](#usage)
3. [Compiling Methods](#compiling-methods)
4. [Contributing](#contributing)

## Introduction

This project delves into the implementation of various graph algorithms, serving as a fundamental resource for learning and applying key operations on both graphs and directed graphs (digraphs). Through this project, we explore different methods of graph representation, traversal techniques, and other important graph-related functions.

The exercises cover a wide range of topics, from basic representations like adjacency lists and matrices to more advanced concepts such as Prüffer codes, articulation points, and bipartiteness. Additionally, we implement essential algorithms for digraphs, including conversions between incidence and adjacency matrices and in-depth search techniques.

Each function and algorithm in this project aims to build a strong foundation in graph theory, helping to understand the relationships between vertices and edges, both in theoretical contexts and practical applications. 

## Usage

To use this project, follow the steps below:

1. Clone the repository to your local machine using the command:

   ```shell
   git clone https://github.com/beatrizgouveia03/Grafos.git
   ```

2. Navigate to the project directory:

   ```shell
   cd Grafos/Exercícios/Módulo_1/
   ```

3. Compile your project according to your preferred method (see [Compiling Methods](#compiling-methods) for more details).

4. Execute the compiled program to see the graphs simulation algorithms in action with the selected source file.

## Compiling Methods

This project uses CMake as the build system, which allows for easy and efficient compilation of the C++ code. To compile the sorting algorithms, follow these steps:

1. Make sure CMake is installed on

 your system.

2. Navigate to the project directory:

   ```shell
   cd Grafos/Exercícios/Módulo_1/
   ```

3. Create a build directory and generate an Unix Makefile based on the script found on the current level:

   ```shell
   cmake -S . -B build
   ```

4. Compile the project using the generated build files:

   ```shell
   cmake --build build
   ```

6. After successful compilation, you will find the executable files for each sorting algorithm in the build directory. Execute the desired program to see the algorithms in action with the selected scenarios.

## Contributing

Contributions to this project are welcome! If you'd like to improve an existing algorithm's implementation, add a new sorting algorithm, introduce new scenarios, or fix any issues, please follow these steps:

1. Fork the repository.

2. Create a new branch for your contribution:

   ```shell
   git checkout -b feature/new-algorithm
   ```

3. Make your modifications and additions.

4. Commit your changes:

   ```shell
   git commit -m "Add new algorithm: [Algorithm Name]"
   ```

5. Push your branch:

   ```shell
   git push origin feature/new-algorithm
   ```

6. Open a pull request, describing your changes and the rationale behind them.
