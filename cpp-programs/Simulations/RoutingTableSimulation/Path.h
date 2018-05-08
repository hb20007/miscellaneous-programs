#pragma once

class Node; // Forward declaration of the Node class to avoid circular reference in importing files

struct Path { // A Path represents a weighted connection between 2 nodes
	Path(const int& pathCost, Node *destinationNode); // Constructor that initializes the two variables to chosen values
	unsigned int cost; // The cost is an integer from 1 to 9
	Node *destination; // The direction of the connection is always towards the destination node
};