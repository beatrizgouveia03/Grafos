#include "simulation.h"

using namespace sml;

pair<double, vector<int>> Simulation::grasp(int numCities, int localSearch) {
  const vector<int> tour = vector<int>(numCities, -1);
  const vector<vector<float>> distMatrix = this->graph.adj;

  if (localSearch == 1) {
    cout << "GRASP + Busca Local 1" << endl;
    swapLocalSearch(tour, distMatrix);
  } else {
    subpathReversion(tour, distMatrix);
    cout << "GRASP + Busca Local 2" << endl;
  }

  return pair<double, vector<int>>(0, vector<int>());
}
