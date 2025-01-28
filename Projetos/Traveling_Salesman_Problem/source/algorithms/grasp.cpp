#include "simulation.h"
#include <random>
#include <iomanip>
#include <algorithm>

using namespace sml;
using namespace std;

//Função para a fase construtiva do GRASP
vector<int> faseConstrutiva(int numCidades, const vector<vector<float>>& matrizDist, float alfa) {
    vector<int> rota;  //Vetor para armazenar a rota construída
    vector<bool> visitada(numCidades, false);  //Vetor para verificar se uma cidade foi visitada
    
    std::random_device rd;
    std::mt19937 gerador(rd());
    std::uniform_int_distribution<> dist(0, numCidades - 1);
    
    //Seleciona aleatoriamente a cidade inicial
    int cidadeAtual = dist(gerador);
    rota.push_back(cidadeAtual);  //Adiciona a cidade inicial à rota
    visitada[cidadeAtual] = true;  //Marca a cidade como visitada

    //Enquanto a rota não contiver todas as cidades
    while (rota.size() < numCidades) {
        vector<pair<float, int>> candidatos;  //Lista de candidatos a serem visitados
        
        //Percorre todas as cidades e calcula o custo de visitação para cidades não visitadas
        for (int i = 0; i < numCidades; i++) {
            if (!visitada[i]) {
                float custo = matrizDist[cidadeAtual][i];  //Cálculo do custo para a cidade 'i'
                candidatos.push_back({custo, i});
            }
        }
        
        std::sort(candidatos.begin(), candidatos.end());  //Ordena os candidatos pelo custo
        
        //Determina o tamanho da lista de candidatos baseando-se no parâmetro alfa
        int tamanhoLrc = std::max(1, std::min(int(candidatos.size()), 
                         int(alfa * candidatos.size())));
                         
        std::uniform_int_distribution<> distLrc(0, tamanhoLrc - 1);
        
        //Seleciona aleatoriamente um candidato da lista
        int selecionado = distLrc(gerador);
        
        //Atualiza a cidade atual e adiciona à rota
        cidadeAtual = candidatos[selecionado].second;
        rota.push_back(cidadeAtual);
        visitada[cidadeAtual] = true;  //Marca a cidade como visitada
    }
    
    return rota;  //Retorna a rota gerada
}

//Função de busca local utilizando troca de posições (SWAP)
vector<int> Simulation::buscaLocalTroca(const vector<int>& rota, const vector<vector<float>>& matrizDist) {
    vector<int> melhorRota = rota;  //Inicializa a melhor rota com a rota fornecida
    float melhorCusto = calcularCustoRota(rota, matrizDist);  //Calcula o custo da rota inicial
    bool melhorou = true;  //Flag para verificar se houve melhoria
    
    //Enquanto houver melhorias
    while (melhorou) {
        melhorou = false;  //Inicializa como sem melhoria
        
        //Percorre todos os pares de cidades na rota
        for (size_t i = 0; i < rota.size() - 1; i++) {
            for (size_t j = i + 1; j < rota.size(); j++) {
                vector<int> novaRota = melhorRota;  //Copia a melhor rota encontrada até agora
                std::swap(novaRota[i], novaRota[j]);  //Troca as cidades i e j
                
                float novoCusto = calcularCustoRota(novaRota, matrizDist);  //Calcula o custo da nova rota
                if (novoCusto < melhorCusto) {  //Se o custo foi melhor, atualiza a melhor rota
                    melhorRota = novaRota;
                    melhorCusto = novoCusto;
                    melhorou = true;  //Marca que houve melhoria
                }
            }
        }
    }
    
    return melhorRota;  //Retorna a melhor rota encontrada
}

//Função de busca local utilizando reversão de subcaminho
vector<int> Simulation::reversaoSubcaminho(const vector<int>& rota, const vector<vector<float>>& matrizDist) {
    vector<int> melhorRota = rota;  //Inicializa a melhor rota com a rota fornecida
    float melhorCusto = calcularCustoRota(rota, matrizDist);  //Calcula o custo da rota inicial
    bool melhorou = true;  //Flag para verificar se houve melhoria
    
    //Enquanto houver melhorias
    while (melhorou) {
        melhorou = false;  //Inicializa como sem melhoria
        
        //Percorre todos os pares de cidades na rota, com a condição de não inverter subsequências triviais
        for (size_t i = 0; i < rota.size() - 1; i++) {
            for (size_t j = i + 2; j < rota.size(); j++) {
                vector<int> novaRota = melhorRota;  //Copia a melhor rota encontrada até agora
                std::reverse(novaRota.begin() + i, novaRota.begin() + j + 1);  //Inverte a subsequência de cidades
                
                float novoCusto = calcularCustoRota(novaRota, matrizDist);  //Calcula o custo da nova rota
                if (novoCusto < melhorCusto) {  //Se o custo foi melhor, atualiza a melhor rota
                    melhorRota = novaRota;
                    melhorCusto = novoCusto;
                    melhorou = true;  //Marca que houve melhoria
                }
            }
        }
    }
    
    return melhorRota;  //Retorna a melhor rota encontrada
}

//Função principal do GRASP
pair<double, vector<int>> Simulation::grasp(int numCidades, int buscaLocal) {
    const vector<vector<float>> matrizDist = this->grafo.adj;  //Matriz de distâncias entre as cidades
    float alfa = 0.3;  //Parâmetro alfa que controla o tamanho da lista de candidatos
    int maxIteracoes = 100;  //Número máximo de iterações do GRASP
    
    vector<int> melhorRota;  //Melhor rota encontrada
    float melhorCusto = numeric_limits<float>::infinity();  //Melhor custo inicial (infinito)
    
    //Imprime os parâmetros do algoritmo
    cout << "\n=====================================================" << endl;
    cout << "                     GRASP + ";
    if (buscaLocal == 1) {
        cout << "BUSCA LOCAL POR TROCA" << endl;
    } else {
        cout << "REVERSÃO DE SUBCAMINHO" << endl;
    }
    cout << "=====================================================" << endl;
    cout << "\nParâmetros:" << endl;
    cout << "- Alfa: " << alfa << endl;
    cout << "- Número de iterações: " << maxIteracoes << endl;
    cout << "- Número de cidades: " << numCidades << endl;
    
    //Marca o início do tempo de execução
    auto inicio = high_resolution_clock::now();
    
    //Loop principal do GRASP
    for (int i = 0; i < maxIteracoes; i++) {
        vector<int> rotaAtual = faseConstrutiva(numCidades, matrizDist, alfa);  //Fase construtiva
        
        //Aplica busca local dependendo da escolha
        if (buscaLocal == 1) {
            rotaAtual = buscaLocalTroca(rotaAtual, matrizDist);
        } else {
            rotaAtual = reversaoSubcaminho(rotaAtual, matrizDist);
        }
        
        float custoAtual = calcularCustoRota(rotaAtual, matrizDist);  //Calcula o custo da rota atual
        if (custoAtual < melhorCusto) {  //Se a rota é melhor, atualiza a melhor solução
            melhorCusto = custoAtual;
            melhorRota = rotaAtual;
            
            //Exibe progresso da solução
            cout << "\nNova melhor solução encontrada na iteração " << i + 1 << ":" << endl;
            cout << "Custo: " << std::fixed << std::setprecision(2) << melhorCusto << endl;
        }
    }
    
    //Marca o fim do tempo de execução
    auto fim = high_resolution_clock::now();
    auto duracao = duration_cast<seconds>(fim - inicio);
    
    //Imprime o resultado final
    cout << "\n====================== RESULTADO ======================" << endl;
    cout << "Melhor rota encontrada:" << endl;
    cout << "[ ";
    for (size_t i = 0; i < melhorRota.size(); i++) {
        cout << melhorRota[i] + 1;
        if (i < melhorRota.size() - 1) cout << " -> ";
    }
    cout << " -> " << melhorRota[0] + 1 << " ]" << endl;
    
    cout << "\nCusto total da rota: " << std::fixed << std::setprecision(2) << melhorCusto << endl;
    cout << "Tempo de execução: " << duracao.count() << " segundos" << endl;
    cout << "=====================================================" << endl;
    
    return make_pair(melhorCusto, melhorRota);  //Retorna o custo e a melhor rota encontrada
}

//Função que calcula o custo total de uma rota
float Simulation::calcularCustoRota(const vector<int>& rota, const vector<vector<float>>& matrizDist) {
    float custo = 0;
    //Soma os custos de todas as transições de cidades
    for (size_t i = 0; i < rota.size() - 1; i++) {
        custo += matrizDist[rota[i]][rota[i + 1]];
    }
    //Adiciona o custo do retorno à cidade inicial
    custo += matrizDist[rota.back()][rota[0]];
    return custo;  //Retorna o custo total
}