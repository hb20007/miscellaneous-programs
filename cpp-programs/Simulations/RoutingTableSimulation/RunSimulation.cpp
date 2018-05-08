/*
* COMP-358 Networks and Data Communication
* Instructor: Dr Constandinos Mavromoustakis
*
* Final Project - Simulating a Routing Table (Topic 3)
*
* @HANNA SABABA (U144N0959)
*/

#include "Simulation.h"
	
const unsigned int nodesInvolved = 10;
const unsigned int maxCostOfPath = 9;

int main() { // C++ does not support running main() directly from inside a class as in pure object oriented languages like Java so I call the method main() in my class from here
	Simulation sim(nodesInvolved, maxCostOfPath); // The constructor of the Simulation class is used to initialized the number of nodes and the maximum cost of a Path constants
	return sim.main();
}