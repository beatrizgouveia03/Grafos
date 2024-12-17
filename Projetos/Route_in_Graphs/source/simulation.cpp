#include "simulation.h"

using namespace sml;

/**!
 * Construtor padrão da classe Simulation
 */
Simulation::Simulation(void) {
  // Inicializa a simulação
}

/**!
 * Esta função espera por uma entrada no terminal para finalizar.
 */
void Simulation::pause(void){
  cout << "Para retornar ao menu principal, pressione Enter...";
  cin.get(); // Aguarda uma entrada
  cout << endl;
}

/**! 
 * Essa função exibe o menu principal da simulação no terminal.
 * 
 * O menu principal serve como ponto de partida para o usuário
 * interagir com as funcionalidades da simulação.
 */
void Simulation::showMenu(void){
  cout << "============================================" << endl;
  cout << "                Menu Principal              " << endl;
  cout << "============================================" << endl;
  cout << "-- Aŕvores Geradoras Minimas --" << endl;
  cout << "1. Kruskal" << endl;
  cout << "2. Prim" << endl;
  cout << "3. Chu-Liu/Edmonds" << endl;
  cout << "-- Caminho mais curto --" << endl;
  cout << "4. Dijkstra" << endl;
  cout << "5. Bellman-Ford" << endl;
  cout << "6. Floyd-Warshall" << endl;
  cout << "-- Grafos Eulerianos --" << endl;
  cout << "7. Hierholzer (Ciclos)" << endl;
  cout << "-- Fluxo em redes --" << endl;
  cout << "8. Ford-Fulkerson" << endl;
  cout << "9. Edmonds-Karp" << endl;
}


/**!
 * Esta função percorre o menu principal chamando as
 * funções relacionadas a ele, até que o usuário escolha encerrar o programa.
 */
void Simulation::run(void) {
  int opt = -1;
  string str;

  cout << "Inicializando a simulação..." << endl;

  while(opt != 0){
    showMenu();
    cout << "Enter your option: " << endl;
    getline(cin, str);
    opt = stoi(str);

    switch (opt) {
      case 0:
        break;
      case 1:
        kruskal();
        break;
      case 2:
        prim();
        break;
      case 3:
        chuLiuEdmonds();
        break;
      case 4:
        dijkstra();
        break;
      case 5:
        bellmanFord();
        break;
      case 6: 
        floydWarshall();
        break;
      case7: 
        hierholzer();
        break;
      case 8:
        fordFulkerson();
        break;
      case 9: 
        edmondsKarp();
        break;
      default:
        break;
    }
  }
}

/**!
 * Esta função inicializa a simulação lendo o arquivo de entrada
 * e criando representações do grafo como lista de adjacência,
 * matriz de adjacência e matriz de incidência.
 *
 * @param argc Um inteiro indicando a quantidade de argumentos passados no terminal
 * @param argv A lista de argumentos passados no terminal
 * @return Uma estrutura indicando se a inicialização foi bem-sucedida
 */
SimulationResult Simulation::initialize(int argc, char *argv[]) {
  // Inicializa a simulação
  // Processa os argumentos da linha de comando
  if (argc <= 1) {
    return usage("Erro: Nome do arquivo ausente");
  } else {
    string filename = argv[1];
    ifstream file(filename);

    cout << "Inicializando a simulação..." << endl;

    if (!file.is_open()) {
      return usage("Erro: Não foi possível abrir o arquivo");
    } else {

        /* TO - DO */

      // 1. Ler o grafo do arquivo
      
      // 2. Ler as conexões do arquivo
      
      // 3. Atualizar o dicionário

      cout << "Inicialização concluída com sucesso" << endl;

      return SimulationResult("", simulation_result_e(0));
    }
  }
}

/**!
 * Esta função exibe no terminal as opções de uso.
 *
 * @param message A mensagem de descrição do erro de uso a ser exibida
 * @return Uma estrutura indicando que a leitura falhou e a mensagem de erro
 */
SimulationResult Simulation::usage(string message){
  if(message == "")
  {
    string usage = ">>> Uso: graph <arquivo_de_entrada>";

    return SimulationResult(usage, simulation_result_e(1));
  }

  return SimulationResult(">>> "+ message + "\n", simulation_result_e(1));
}
