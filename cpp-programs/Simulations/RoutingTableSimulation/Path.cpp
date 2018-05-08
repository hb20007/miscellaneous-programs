#include "Path.h"

Path::Path(const int& pathCost, Node *destinationNode) {
	cost = pathCost;
	destination = destinationNode;
}