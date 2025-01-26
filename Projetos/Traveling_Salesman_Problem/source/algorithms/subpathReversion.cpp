#include "simulation.h"

using namespace sml;

vector<int> Simulation::subpathReversion(const vector<int>& tour, const vector<vector<float>>& distMatrix) {
	vector<int> currTour = tour;
  float currCost = calculateTourCost(currTour, distMatrix);

	bool improved = true;
	while(improved){
		improved = false;
		for(int i = 0; i < tour.size() - 1; i++){
			for(int j = i; j < tour.size(); j++){
				vector<int> newTour = currTour;
				reverse(newTour.begin() + i, newTour.end() + j);
				float newCost = calculateTourCost(newTour, distMatrix);
				if(newCost < currCost){
					currTour = newTour;
					currCost = newCost;
					improved = true;
				}
			}
		}
	}

	return currTour;
}
