#include "simulation.h"
using namespace sml;

/**
 * Implementação do algoritmo GRASP (Greedy Randomized Adaptive Search Procedure)
 * para a resolução do problema do caixeiro-viajante (TSP - Traveling Salesman Problem).
 * Este código utiliza uma combinação de heurísticas de construção gulosa randomizada
 * e busca local para encontrar soluções de boa qualidade de forma eficiente.
 * 
 * - A fase de construção inicializa uma solução utilizando aleatoriedade controlada.
 * - A fase de busca local melhora a solução encontrada por meio de otimizações adicionais.
 * - A melhor solução ao longo de múltiplas iterações é armazenada e retornada.
 * 
 * Parâmetros ajustáveis, como o número de iterações e o tamanho da RCL, permitem
 * controlar o equilíbrio entre exploração e intensificação no espaço de soluções.
 */
pair<double, vector<int>> Simulation::grasp(int numCities, int localSearch) {
    //Obtém a matriz de distâncias do grafo
    const vector<vector<float>> distMatrix = this->graph.adj;
    
    //Variáveis para armazenar a melhor solução encontrada
    vector<int> bestTour;  //Armazena o melhor caminho encontrado
    double bestCost = numeric_limits<double>::infinity();  //Inicializa com infinito para garantir primeira atualização
    
    //Parâmetros do algoritmo GRASP
    int maxIterations = 100;  //Número de vezes que o algoritmo será executado
    int rcl_size = 3;        //Tamanho da Lista Restrita de Candidatos (RCL) - controla o nível de aleatoriedade
    
    //Loop principal do GRASP - cada iteração gera uma solução diferente
    for (int iter = 0; iter < maxIterations; iter++) {
        //Fase 1: Construção da solução inicial usando método guloso randomizado
        vector<int> tour(numCities, -1);        //Vetor que armazenará o caminho atual (-1 indica posição vazia)
        vector<bool> visited(numCities, false);  //Controle de cidades já visitadas
        
        //Seleciona a primeira cidade aleatoriamente
        int currentCity = rand() % numCities;
        tour[0] = currentCity;
        visited[currentCity] = true;
        
        //Constrói o resto do caminho cidade por cidade
        for (int i = 1; i < numCities; i++) {
            //Vector para armazenar candidatos possíveis e suas distâncias
            vector<pair<float, int>> candidates;
            
            //Para cada cidade não visitada, calcula sua distância da cidade atual
            for (int j = 0; j < numCities; j++) {
                if (!visited[j]) {
                    //Armazena par {distância, índice_cidade}
                    candidates.push_back({distMatrix[currentCity][j], j});
                }
            }
            
            //Ordena candidatos pela distância (primeiro elemento do par)
            sort(candidates.begin(), candidates.end());
            
            //Define tamanho atual da RCL (mínimo entre rcl_size e número de candidatos disponíveis)
            int rcl_current_size = min(rcl_size, (int)candidates.size());
            
            //Seleciona aleatoriamente uma cidade dentre as melhores (RCL)
            int random_index = rand() % rcl_current_size;
            currentCity = candidates[random_index].second;
            
            //Adiciona cidade escolhida ao tour e marca como visitada
            tour[i] = currentCity;
            visited[currentCity] = true;
        }
        
        //Fase 2: Melhoria da solução usando busca local
        vector<int> improvedTour = tour;
        if (localSearch == 1) {
            cout << "GRASP + Troca de vizinhança" << endl;
            swapLocalSearch(improvedTour, distMatrix);
        } else {
            cout << "GRASP + Reversão de Sub-caminho" << endl;
            subpathReversion(improvedTour, distMatrix);
        }
        
        //Fase 3: Avaliação da solução melhorada
        //Calcula o custo total do caminho (soma das distâncias)
        double currentCost = 0;
        //Soma distâncias entre cidades consecutivas
        for (int i = 0; i < numCities - 1; i++) {
            currentCost += distMatrix[improvedTour[i]][improvedTour[i + 1]];
        }
        //Adiciona distância de retorno à cidade inicial (fecha o ciclo)
        currentCost += distMatrix[improvedTour[numCities - 1]][improvedTour[0]];
        
        //Fase 4: Atualização da melhor solução
        //Se encontrou um caminho melhor, atualiza a melhor solução
        if (currentCost < bestCost) {
            bestCost = currentCost;
            bestTour = improvedTour;
        }
    }
    
    //Retorna par contendo o custo do melhor caminho e o caminho em si
    return make_pair(bestCost, bestTour);
}