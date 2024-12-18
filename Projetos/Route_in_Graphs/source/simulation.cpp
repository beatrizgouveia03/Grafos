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
  cout << "0. Encerrar programa" << endl;
}


/**!
 * Esta função percorre o menu principal chamando as
 * funções relacionadas a ele, até que o usuário escolha encerrar o programa.
 */
void Simulation::run(void) {
  int opt = -1;
  string str;

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
        pause();
        break;
      case 2:
        prim();
        pause();
        break;
      case 3:
        chuLiuEdmonds();
        pause();
        break;
      case 4:
        dijkstra();
        pause();
        break;
      case 5:
        bellmanFord();
        pause();
        break;
      case 6: 
        floydWarshall();
        pause();
        break;
      case7: 
        hierholzer();
        pause();
        break;
      case 8:
        fordFulkerson();
        pause();
        break;
      case 9: 
        edmondsKarp();
        pause();
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
  }
  if (argc <= 2){
    return usage("Erro: Tipo de entrada não especificada");
  } 
  
  string filename = argv[1];
  ifstream file(filename);

  cout << "Inicializando a simulação..." << endl;

  if (!file.is_open()) {
    return usage("Erro: Não foi possível abrir o arquivo");
  }

  int entryType;

  try
  {
    entryType = stoi(argv[2]);
  }
  catch(exception e)
  {
    return usage("Erro: Tipo de entrada inválido");
  }
  

  int size, value;
  vector<vector<int>> matrix;

  file >> size;

   // Leitura da entrada
  while (!file.eof()) {
    if(entryType == 1){
        vector<int> line;
        for (int i = 0; i < size; i++) {  
            file >> value;
            line.push_back(value);
        }
        matrix.push_back(line);
    }
  }

  cout << "Inicialização concluída com sucesso" << endl;

  return SimulationResult("", simulation_result_e(0));
}

/**!
 * Esta função exibe no terminal as opções de uso.
 *
 * @param message A mensagem de descrição do erro de uso a ser exibida
 * @return Uma estrutura indicando que a leitura falhou e a mensagem de erro
 */
SimulationResult Simulation::usage(string message){
  string usage = ">>> Uso: Route_in_Graphs <arquivo_de_entrada> <tipo_de_entrada>\n";
  usage += ">>> Tipo de entrada:\n";
  usage += ">>> 1 - Matriz de adjacência\n";

  if(message != "")
  {
    usage = ">>> " + message + "\n" + usage;
  }

  return SimulationResult(usage, simulation_result_e(1));
}
