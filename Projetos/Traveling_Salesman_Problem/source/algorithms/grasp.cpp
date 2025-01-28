#include "simulation.h"

using namespace sml;

pair<double, vector<int>> Simulation::grasp(int numCities, int localSearch) {
  const vector<int> tour = vector<int>(numCities, -1);
  const vector<vector<double>> distMatrix = this->graph.adj;

  if (localSearch == 1) {
    cout << "GRASP + Troca de vizinhança" << endl;
    swapLocalSearch(tour, distMatrix);
  } else {
    cout << "GRASP + Reversão de Sub-caminho" << endl;
    subpathReversion(tour, distMatrix);
  }

  return pair<double, vector<int>>(0, vector<int>());
}
