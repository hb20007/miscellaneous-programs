#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
// This preprocessor directive is used to disable a warning message in my IDE (Visual Studio) asking me to use the function localtime_s() instead of localtime(). Even though localtime_s() is thread safe, it is Microsoft's implementation of the function and would lead to my code only being executable on Windows

#include "Node.h"
#include "Utility.h"
#include "RoutingTable.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace std;

class Simulation {
public:
	Simulation(const int& nodesNumber, const int& maxConnectionCost); // A constructor that initializes the number of nodes and the maximum possible cost for a connection
	int main(); 
private: 
	// The methods below are private because they are all called by the main() method in this class and do not need to be called elsewhere
	void mainMenu(char& menuSelection); // Displays the main menu and returns the user's selection as a reference parameter
	void createNodes(); // Creates the Nodes to be used in the simulation
	void displayListOfNodes(); // Prints a list of the Nodes and their IP addresses
	void createPaths(); // Creates the Paths between the Nodes that will be present in the simulation scenario
	void displayConnections(); // Displays the Paths made between the Nodes and their costs
	void generateNodeARoutingTable(); // Genereates the routing table for router A
	void printNodeARoutingTable(); // Displays router A's routing table
	bool userWantsToContinue(); // Prompts the user if they would like to proceed with the simulation, returning true if they would like to and false if they wouldn't
	void updateNodeARoutingTable(unsigned int& modifiedNodeIndex); // Updates the routing table of node A after the scenario has been modified

	const unsigned int numberOfNodes; // The number of Nodes that the simulation will involve
	const unsigned int maxPathCost; // The maximum weight of a path in the simulation
	vector<Node> nodesArray; // An array with all the Nodes
	RoutingTable nodeARoutingTable; 

	/* Please note the distinction in my usage of the words "Path" and "Route". 
	A Path is a direct connection between two Nodes while a Route is a series of 
	Paths to get from one Node to another */
};
