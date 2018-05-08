#pragma once
#include <iostream>
#include <vector>
#include "Path.h"
#include "Utility.h"
using namespace std;

class Node { // The nodes in this simulation are routers. 
public:
	char getID(); // ID accessor method
	void setID(const char& id); // ID modifier method
	string getIPAddress(); // IPAddress accessor method
	void setIPAddress(const string& ip); // IPAddress modifier method
	vector<Path> getPaths(); // paths accessor method
	void addPath(const Path& newPath); // Adds a new path from this node
	vector<Node> nodesReachableFromThisNode(); // Returns a list of the IDs of the nodes that can be directly or indirectly reached via paths from this node
	bool isEqual(const Node& comparisonNode); // Returns true if comparisonNode has the same ID and IP address as the Node calling the method, else returns false
	void routeInfoToNode(Node target, unsigned int& routeCost, Node& nextNode); // Returns using pass by reference the routeCost to get to a target node and which node needs to be taken next. 
	void modifyPathCost(int indexOfPath, const unsigned int& newCost); // Gives the path with the desired index the new cost inserted as a parameter
private:
	char ID; // The ID is a letter used to conveniently identify the node eg. A or B etc...
	string IPAddress; // The IP address of the router
	vector<Path> paths; // An array with the immediate paths the node is able to route to
};