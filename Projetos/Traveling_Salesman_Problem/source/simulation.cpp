#include "simulation.h"

using namespace sml;

const int INF = numeric_limits<int>::max();

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
 * Essa função exibe o menu dos algoritmos da simulação no terminal.
 * 
 * Esse menu serve como ponto de partida para o usuário
 * interagir com as funcionalidades da simulação.
 */
void Simulation::showAlgMenu(void){
  cout << "============================================" << endl;
  cout << "              Menu de Algoritmos            " << endl;
  cout << "============================================" << endl;
  cout << "1. Algoritmo Guloso" << endl;
  cout << "2. Inserção mais barata" << endl;
  cout << "3. GRASP + <Busca Local 1>" << endl;
  cout << "4. GRASP + <Busca Local 2>" << endl;
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
        pause();
        break;
      case 1:
        pause();
        break;
      case 2:
        pause();
        break;
      case 3:
        pause();
        break;
      case 4:
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
  
  string filename = argv[1];
  ifstream file(filename);

  cout << "Inicializando a simulacao..." << endl;

  if (!file.is_open()) {
    return usage("Erro: Nao foi possivel abrir o arquivo");
  }

   // Leitura da entrada
  while (!file.eof()) {

      cout << filename << endl;
   
      // Read the graph from the file
      string line;
      int numNodes; //!< Número de vértices
      map<int, string> dictionary;    //!< Lista que mantém o nome de cada vértice
      vector<vector<int>> adj = vector<vector<int>>(numNodes, vector<int>(numNodes, -1)); //!< Matriz de adjacência

      cout << "Lendo número de vértices..." << endl;
      file >> numNodes;

      cout << "Lendo nome dos vértices..." << endl;
      for (int i = 0; i < numNodes; i++) {
          string name;
          file >> name;
          dictionary[i] = name;
      }

      cout << "Lendo matriz de adjacência..." << endl;
      for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
          file >> adj[i][j];
        }
      }

      this->graph.adj = adj;
      this->graph.n = numNodes;
      this->graph.dictionary = dictionary;
  }

  cout << "Inicializacao concluida com sucesso" << endl;
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
  string usage = ">>> Uso: Traveling_Salesman_Problem <arquivo_de_entrada>\n";

  if(message != "")
  {
    usage = ">>> " + message + "\n" + usage;
  }

  return SimulationResult(usage, simulation_result_e(1));
}
