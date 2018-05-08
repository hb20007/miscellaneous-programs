#pragma once
#include "Node.h"

struct Route { // A Route is a way to get from one node to another
	Node nextNodeInRoute; // The next node in the specified Route
	unsigned int routeMetric = 0; // The total cost of sending a packet along the Route
};
