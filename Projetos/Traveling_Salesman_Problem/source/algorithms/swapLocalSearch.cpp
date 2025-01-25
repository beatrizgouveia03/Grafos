#include "simulation.h"

using namespace sml;

vector<int> Simulation::swapLocalSearch(const vector<int>& tour, const vector<vector<float>>& distMatrix) {
  vector<int> currTour = tour;
  float currCost = calculateTourCost(currTour, distMatrix);
  
  bool improved = true;
  while (improved) {
    improved = false;
    for (int i = 0; i < tour.size() - 1; i++) {
      for (int j = i + 1; j < tour.size(); j++) {
        vector<int> newTour = currTour;
        reverse(newTour[i], newTour[j]);
        float newCost = calculateTourCost(newTour, distMatrix);
        if (newCost < currCost) {
          currTour = newTour;
          currCost = newCost;
          improved = true;
        }
      }
    }
  }
  return currTour;
}



float Simulation::calculateTourCost(const vector<int>& tour, const vector<vector<float>>& distMatrix) {
  float cost = 0;
  for (int i = 0; i < tour.size() - 1; i++) cost += distMatrix[tour[i]][tour[i + 1]];
  cost += distMatrix[tour[tour.size() - 1]][tour[0]];
  return cost;
}