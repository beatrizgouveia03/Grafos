#include "simulation.h"

using namespace sml;

void Simulation::grasp(int numCities, int localSearch) {
  if (localSearch == 1) {
    cout << "GRASP + Busca Local 1" << endl;
    graspLocalSearch1();
  } else {
    graspLocalSearch2();
    cout << "GRASP + Busca Local 2" << endl;
  }
}