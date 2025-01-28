#include "simulation.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace sml;
using namespace std; 

//Função para imprimir o resultado final do algoritmo GRASP
//Recebe o melhor tour encontrado e seu custo
//Imprime a sequência de cidades e o custo total formatado
void printGRASPResult(const vector<int>& tour, double cost) {
    cout << "\nMelhor tour encontrado:" << endl;
    cout << "Sequência de cidades: ";
    //Imprime cada cidade do tour com setas entre elas
    for (size_t i = 0; i < tour.size(); i++) {
        cout << tour[i];
        if (i < tour.size() - 1) cout << " -> ";
    }
    //Adiciona retorno à cidade inicial para completar o ciclo
    cout << " -> " << tour[0] << endl;
    //Imprime o custo total com 2 casas decimais
    cout << "Custo total do tour: " << fixed << setprecision(2) << cost << endl;
}

//Função para calcular o custo total de um tour
//Recebe o vetor com a ordem das cidades e a matriz de distâncias
//Retorna a soma das distâncias entre cidades consecutivas, incluindo o retorno à primeira cidade
double calculateTourCost(const vector<int>& tour, const vector<vector<float>>& distMatrix) {
    double cost = 0;
    //Soma as distâncias entre cada par de cidades consecutivas
    for (size_t i = 0; i < tour.size() - 1; i++) {
        cost += distMatrix[tour[i]][tour[i + 1]];
    }
    //Adiciona o custo de retorno à cidade inicial
    cost += distMatrix[tour.back()][tour[0]];
    return cost;
}

//Implementação da primeira estratégia de busca local: troca de pares de cidades
//Tenta melhorar a solução trocando pares de cidades de posição
//Continua até não encontrar mais melhorias
void swapLocalSearch(vector<int>& tour, const vector<vector<float>>& distMatrix) {
    bool improved = true;
    //Loop principal: continua enquanto houver melhorias
    while (improved) {
        improved = false;
        double bestCost = calculateTourCost(tour, distMatrix);
        
        //Testa todas as possíveis trocas de pares de cidades
        for (size_t i = 0; i < tour.size() - 1; i++) {
            for (size_t j = i + 1; j < tour.size(); j++) {
                //Realiza a troca temporária
                std::swap(tour[i], tour[j]);
                double newCost = calculateTourCost(tour, distMatrix);
                
                //Se a troca melhorou o custo, mantém a mudança
                if (newCost < bestCost) {
                    bestCost = newCost;
                    improved = true;
                } else {
                    //Se não melhorou, desfaz a troca
                    std::swap(tour[i], tour[j]);
                }
            }
        }
    }
}

//Implementação da segunda estratégia de busca local: reversão de subcaminhos
//Tenta melhorar a solução revertendo a ordem de segmentos do caminho
//Continua até não encontrar mais melhorias
void subpathReversion(vector<int>& tour, const vector<vector<float>>& distMatrix) {
    bool improved = true;
    //Loop principal: continua enquanto houver melhorias
    while (improved) {
        improved = false;
        double bestCost = calculateTourCost(tour, distMatrix);
        
        //Testa todas as possíveis reversões de subcaminhos
        for (size_t i = 0; i < tour.size() - 1; i++) {
            for (size_t j = i + 2; j < tour.size(); j++) {
                //Reverte o subcaminho temporariamente
                std::reverse(tour.begin() + i, tour.begin() + j + 1);
                double newCost = calculateTourCost(tour, distMatrix);
                
                //Se a reversão melhorou o custo, mantém a mudança
                if (newCost < bestCost) {
                    bestCost = newCost;
                    improved = true;
                } else {
                    //Se não melhorou, desfaz a reversão
                    std::reverse(tour.begin() + i, tour.begin() + j + 1);
                }
            }
        }
    }
}

//Função que constrói uma solução inicial de forma gulosa randomizada
//Usa o parâmetro alpha para controlar o equilíbrio entre aleatoriedade e gulodice
//alpha = 0 -> totalmente guloso, alpha = 1 -> totalmente aleatório
vector<int> constructGreedyRandomizedSolution(const vector<vector<float>>& distMatrix, float alpha) {
    int n = distMatrix.size();
    vector<int> solution;
    vector<bool> visited(n, false);
    
    //Configuração do gerador de números aleatórios
    std::random_device rd;  //Fonte de entropia para seed
    std::mt19937 gen(rd()); //Gerador Mersenne Twister
    std::uniform_int_distribution<> dis(0, n - 1); //Distribuição uniforme
    
    //Escolhe a primeira cidade aleatoriamente
    int currentCity = dis(gen);
    solution.push_back(currentCity);
    visited[currentCity] = true;
    
    //Constrói o resto do caminho uma cidade por vez
    while (solution.size() < n) {
        //Lista de candidatos (cidades não visitadas) com suas distâncias
        vector<pair<int, float>> candidates;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                candidates.push_back({i, distMatrix[currentCity][i]});
            }
        }
        
        //Ordena candidatos por distância (do mais próximo ao mais distante)
        sort(candidates.begin(), candidates.end(), 
             [](const pair<int, float>& a, const pair<int, float>& b) {
                 return a.second < b.second;
             });
        
        //Calcula o tamanho da Lista Restrita de Candidatos (RCL)
        //RCL contém as alpha% melhores cidades candidatas
        int rclSize = std::max(1, int(alpha * candidates.size()));
        std::uniform_int_distribution<> rclDis(0, rclSize - 1);
        int selectedIdx = rclDis(gen);
        
        //Seleciona próxima cidade aleatoriamente da RCL
        currentCity = candidates[selectedIdx].first;
        solution.push_back(currentCity);
        visited[currentCity] = true;
    }
    
    return solution;
}

//Função principal do algoritmo GRASP
//Combina construção gulosa randomizada com busca local
//Executa várias iterações e retorna o melhor resultado encontrado
pair<double, vector<int>> Simulation::grasp(int numCities, int localSearch) {
    //Obtém a matriz de distâncias do grafo
    const vector<vector<float>> distMatrix = this->graph.adj;
    
    //Parâmetros do GRASP
    float alpha = 0.3;  //Controla o nível de aleatoriedade (0 = guloso, 1 = aleatório)
    int maxIterations = 100;  //Número de iterações do algoritmo
    
    //Variáveis para armazenar a melhor solução encontrada
    vector<int> bestTour;
    double bestCost = numeric_limits<double>::infinity();
    
    //Imprime informações iniciais
    cout << "\nExecutando GRASP..." << endl;
    cout << "Número de iterações: " << maxIterations << endl;
    cout << "Parâmetro alpha: " << alpha << endl;
    cout << "Método de busca local: " << (localSearch == 1 ? "Troca de pares" : "Reversão de subcaminho") << endl;
    
    //Loop principal do GRASP
    for (int i = 0; i < maxIterations; i++) {
        //Mostra progresso a cada 10 iterações
        if (i % 10 == 0) {
            cout << "Iteração " << i << " de " << maxIterations << endl;
        }
        
        //Fase de construção: gera uma solução inicial
        vector<int> currentTour = constructGreedyRandomizedSolution(distMatrix, alpha);
        
        //Fase de busca local: tenta melhorar a solução
        if (localSearch == 1) {
            swapLocalSearch(currentTour, distMatrix);  //Método 1: troca de pares
        } else {
            subpathReversion(currentTour, distMatrix); //Método 2: reversão de subcaminhos
        }
        
        //Verifica se encontrou uma solução melhor
        double currentCost = calculateTourCost(currentTour, distMatrix);
        if (currentCost < bestCost) {
            bestCost = currentCost;
            bestTour = currentTour;
            cout << "Nova melhor solução encontrada na iteração " << i << " com custo: " << currentCost << endl;
        }
    }
    
    //Imprime o resultado final e retorna
    printGRASPResult(bestTour, bestCost);
    return make_pair(bestCost, bestTour);
}