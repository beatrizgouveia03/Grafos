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
 * interagir com as funcionalidades da simulação. Nele o usuário pode escolher
 * qual algoritmo deseja testar para resolver o problema do caixeiro viajante.
 */
void Simulation::showAlgMenu(void){
  cout << "============================================" << endl;
  cout << "              Menu de Algoritmos            " << endl;
  cout << "============================================" << endl;
  cout << "1. Algoritmo Guloso" << endl;
  cout << "2. Insercao mais barata" << endl;
  cout << "3. GRASP + <Busca Local 1>" << endl;
  cout << "4. GRASP + <Busca Local 2>" << endl;
  cout << "0. Encerrar programa" << endl;
}

/**!
 * Essa função exibe o menu dos problemas da simulação no terminal.
 * 
 * Esse menu serve como ponto de partida para o usuário
 * interagir com as funcionalidades da simulação. Nele o usuário pode escolher
 * qual dos problema deseja resolver com a simulação.
 */
void Simulation::showProbMenu(void){
  cout << "============================================" << endl;
  cout << "              Menu de Problemas            " << endl;
  cout << "============================================" << endl;
  cout << "1. Problema 1" << endl;
  cout << "2. Problema 2" << endl;
  cout << "3. Problema 3" << endl;
  cout << "4. Problema 4" << endl;
  cout << "5. Problema 5" << endl;
  cout << "6. Problema 6" << endl;
  cout << "0. Retornar ao menu de algoritmos" << endl;
}


/**!
 * Esta função percorre o menu principal chamando as
 * funções relacionadas a ele, até que o usuário escolha encerrar o programa.
 */
void Simulation::run(void) {
  int algOption = -1, probOption = -1;
  string str;

  while(true){
    showAlgMenu();
    cout << "Digite a opção escolhida: " << endl;
    getline(cin, str);
    algOption = stoi(str);

    if(algOption == 0) break;

    showProbMenu();
    cout << "Digite a opção escolhida: " << endl;
    getline(cin, str);
    probOption = stoi(str);

    if(probOption == 0) continue;

    runProblem(probOption, algOption);
    pause();
  }
}

/**!
 * Esta função executa o problema escolhido pelo usuário
 * com o algoritmo escolhido.
 *
 * @param problem O problema escolhido pelo usuário
 * @param algorithm O algoritmo escolhido pelo usuário
 */
void Simulation::runProblem(int algorithm, int problem) {
  int numCities = 0;
  switch(problem){
    case 1:
      numCities = 5;
      break;
    case 2:
      numCities = 10;
      break;
    case 3:
      numCities = 15;
      break;
    case 4:
      numCities = 20;
      break;
    case 5:
      numCities = 25;
      break;
    case 6:
      numCities = 30;
      break;
    default:
      numCities = 5;
      break;
  }

  switch(algorithm){
    case 1:
      tspGreedy(numCities);
      break;
    case 2:
      tspCheapestInsertion(numCities);
      break;
    case 3:
      grasp(numCities, 1); // Busca Local 1
      break;
    case 4:
      grasp(numCities, 2); // Busca Local 2
      break;
    default:
      break;
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
  if (argc <= 2) {
    return usage("Erro: Nome do arquivo ausente");
  } 
  
  string filename = argv[1];
  string filename2 = argv[2];
  ifstream file(filename);

  cout << "Inicializando a simulacao..." << endl;

  if (!file.is_open()) {
    return usage("Erro: Nao foi possivel abrir o arquivo");
  }

   // Leitura das cidades (dicionário)
  while (!file.eof()) {
    cout << filename << endl;
   
    string line;
    int numNodes; //!< Número de vértices
    map<int, string> dictionary;    //!< Lista que mantém o nome de cada vértice

    cout << "Lendo numero de vertices..." << endl;
    string numNodesStr;
    getline(file, numNodesStr);
    numNodes = stoi(numNodesStr);
    cout << "Numero de vertices: " << numNodes << endl;

    cout << "Lendo nome dos vertices..." << endl;
    for (int i = 0; i < numNodes; i++) {
      string name;
      getline(file, name);
      dictionary[i] = name;
      cout << "Nome do vertice " << i << ": " << name << endl;
    }

    this->graph.n = numNodes;
    this->graph.dictionary = dictionary;
  }
  file.close();

  ifstream file2(filename2);
  if (!file2.is_open()) {
    return usage("Erro: Nao foi possivel abrir o arquivo");
  }

  // Leitura da entrada
  while(!file2.eof()){
    cout << filename2 << endl;

    string line;
    vector<vector<float>> adj = vector<vector<float>>(this->graph.n, vector<float>(this->graph.n, -1)); //!< Matriz de adjacência

    
    cout << "Lendo matriz de adjacencia..." << endl;
    for (int i = 0; i < this->graph.n; i++) {
      getline(file2, line);
      istringstream iss(line);
      for (int j = 0; j < this->graph.n; j++) {
        iss >> adj[i][j];
        cout << i << " " << j << " -> " << adj[i][j] << endl;
      }
    }

    this->graph.adj = adj;
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
  string usage = ">>> Uso: Traveling_Salesman_Problem <arquivo_dicionario> <arquivo_de_entrada>\n";

  if(message != "")
  {
    usage = ">>> " + message + "\n" + usage;
  }

  return SimulationResult(usage, simulation_result_e(1));
}
