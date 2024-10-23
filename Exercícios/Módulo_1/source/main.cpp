/**!
 *  This program implements the Snaze simulation.
 *
 *  @author Beatriz Gouveia
 *
 *  To compile: use cmake script.
*/

#include <iostream>

#include "simulation.hpp"

int main(int argc, char *argv[]) {
    sml::Simulation simulation;

    simulation.initialize(argc, argv);
    simulation.run();

  return 0;
}
