#include "simulation.h"

using namespace sml;

const int INF = std::numeric_limits<int>::max();

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
        { int maxFlow = edmondsKarp(this->graph);
          cout << "====================================================" << endl;
          cout << endl;
          cout << "FLUXO MÁXIMO DO GRAFO: " << maxFlow << endl;
          cout << endl;
          cout << "====================================================" << endl;
          pause();
          break;
        }
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
  
  string filename = argv[1];
  ifstream file(filename);

  cout << "Inicializando a simulação..." << endl;

  if (!file.is_open()) {
    return usage("Erro: Não foi possível abrir o arquivo");
  }

   // Leitura da entrada
  while (!file.eof()) {
   
      // Read the graph from the file
      string v1, v2, w;
      int numNodes;

      string line;
      char trash, type;

      cout << "Reading number of nodes..." << endl;

      file >> type >> numNodes;

      map<int, string> dictionary;    //!< Lista que mantém o nome de cada vértice
      vector<vector<int>> adj = vector<vector<int>>(numNodes, vector<int>(numNodes, INF)); //!< Matriz de adjacência


      // Read the connections from the file
      while (getline(file, line)) {
        if (line == string())
          continue;

        istringstream ss(line);
        getline(ss, v1, ' ');
        getline(ss, v2, ' ');
        getline(ss, w);

        if(dictionary.empty()){
          if(v1 == "s"){
            dictionary[0] = "s";
            for(int i{1}; i<numNodes-1; ++i){
              dictionary[i] = string(1, 'a' + (i-1));
            }
            dictionary[numNodes-1] = "t";
          } else {
            for(int i{0}; i<numNodes; ++i){
              dictionary[i] = to_string(i+1);
            }
          }
        }

        cout << "Reading connection " << v1 << " " << v2 << " weighting " << w << endl;
        
        int x = -1, y = -1;

        //Update the dictionary
        for(auto i{0}; i<dictionary.size();++i){
          if(dictionary[i] == v1){
            x = i;
          }
          else if(dictionary[i] == v2){
            y = i;
          }
        }
        
        if(x == -1){
          x = dictionary.size();
          dictionary[x] = v1;
        }
        
        if(y == -1){
          y = dictionary.size();
          dictionary[y] = v2;
        }

        if (dictionary.size() > numNodes) {
          return usage("Error: Node out-of-index");
        }

    
        adj[x][y] = stoi(w);

        (type == 'G') ? adj[y][x] = stoi(w) : INF;

        this->graph.adj = adj;
        this->graph.n = numNodes;
        this->graph.dictionary = dictionary;
        this->graph.type = (type == 'G')? DIRECTED : UNDIRECTED;
      }
  }

  cout << "Inicialização concluída com sucesso" << endl;
  cout << this->graph << endl;

  return SimulationResult("", simulation_result_e(0));
}

/**!
 * Esta função exibe no terminal as opções de uso.
 *
 * @param message A mensagem de descrição do erro de uso a ser exibida
 * @return Uma estrutura indicando que a leitura falhou e a mensagem de erro
 */
SimulationResult Simulation::usage(string message){
  string usage = ">>> Uso: Route_in_Graphs <arquivo_de_entrada>\n";

  if(message != "")
  {
    usage = ">>> " + message + "\n" + usage;
  }

  return SimulationResult(usage, simulation_result_e(1));
}
