# Graphs Simulation Project

Welcome to the Graphs Simulation project! This project provides a collection of graph algorithms implemented in C++. It serves as a comprehensive resource for learning and applying key operations on both graphs and directed graphs (digraphs).

## Table of Contents

1. [Introduction](#introduction)
2. [Algorithms](#algorithms)
3. [Usage](#usage)
4. [Compiling Methods](#compiling-methods)
5. [Contributing](#contributing)

## Introduction

This project delves into the implementation of various graph algorithms, serving as a fundamental resource for learning and applying key operations on both graphs and directed graphs (digraphs). Through this project, we explore different methods of graph representation, traversal techniques, and other important graph-related functions.

The exercises cover a wide range of topics, from basic representations like adjacency lists and matrices to more advanced concepts such as Prüffer codes, articulation points, and bipartiteness. Additionally, we implement essential algorithms for digraphs, including conversions between incidence and adjacency matrices and in-depth search techniques.

Each function and algorithm in this project aims to build a strong foundation in graph theory, helping to understand the relationships between vertices and edges, both in theoretical contexts and practical applications. 

## Algorithms
   - A. Para GRAFOS (as opcionais possuem a sigla OPC ao final da função)
   - [x] (1)  Representação do Grafo a partir da Lista de Adjacências.[Beatriz]
   - [x] (2)  Representação do Grafo a partir da Matriz de Adjacências.[Beatriz]
   - [x] (3)  Representação do Grafo a partir da Matriz de Incidência.[Beatriz]
   - [x] (4)  Conversão de matriz de adjacência para lista de Adjacências e vice-versa.[Beatriz]
   - [x] (5)  Função que calcula o grau de cada vértice.[Anny]
   - [x] (6)  Função que determina se dois vértices são adjacentes.[Anny]
   - [x] (7)  Função que determina o número total de vértices[Anny]
   - [x] (8)  Função que determina o número total de arestas[Anny]
   - [x] (9)  Inclusão de um novo vértice[Davi]
   - [x] (10) Exclusão de um vértice existente[Davi]
   - [x] (11) Função que determina se um grafo é conexo ou não[Davi]
   - [ ] (12) Determinar se um grafo é bipartido (OPC = 1,0 ponto)[Alisson]
   - [ ] (13) Dada uma representação de uma árvore por matriz de adjacência, faça um algoritmo que
   produza o código de Prüffer e vice versa. (OPC= 1,0 ponto)[Alisson]
   - [x] (14) Busca em Largura, a partir de um vértice específico[Davi]
   - [x] (15) Busca em Profundidade, a partir de um vértice em específico. [José]
   - [x] (16) Determinação de articulações e blocos (biconectividade), utilizando obrigatoriamente a
fu ão lowpt[Alisson]
   - B. Para DIGRAFOS (as opcionais possuem a sigla OPC ao final da função)
   - [x] (17)  Representação do Digrafo a partir da Matriz de Adjacências [José]
   - [x] (18)  Representação do Digrafo a partir da Matriz de Incidência [José]
   - [ ] (19)  Determinação do Grafo subjacente (OPC= 0,5 ponto)
   - [ ] (20)  Conversão de matriz de incidência para estrela direta e vice versa(OPC= 0,5 ponto).
   - [ ] (21)  Conversão de matriz de adjacência para estrela reversa e vice-versa (OPC= 0,5 ponto).
   - [x] (22)  Busca em profundidade, com determinação de profundidade de entrada e de saída de cada [José]
   - vértice.
   - [ ] (23) Pesquisar e implementar uma aplicação, usando busca em profundidade (OPC= 1,0 ponto). [José]

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
