#include "simulation.h"

using namespace sml;

pair<double, vector<int>> Simulation::grasp(int numCities, int localSearch) {
  if (localSearch == 1) {
    cout << "GRASP + Busca Local 1" << endl;
    linKernighan();
  } else {
    graspLocalSearch2();
    cout << "GRASP + Busca Local 2" << endl;
  }

  return pair<double, vector<int>>(0, vector<int>());
}