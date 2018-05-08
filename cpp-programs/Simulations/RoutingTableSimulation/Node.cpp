#pragma once
#include "Node.h"
#include "Route.h"

char Node::getID() {
	return ID;
}

void Node::setID(const char& id) {
	ID = id;
}

string Node::getIPAddress() {
	return IPAddress;
}

void Node::setIPAddress(const string& ip) {
	IPAddress = ip;
}

vector<Path> Node::getPaths() {
	return paths;
}

void Node::addPath(const Path& newPath) {
	paths.push_back(newPath);
}

vector<Node> Node::nodesReachableFromThisNode() {
	vector<Node> reachableNodes;
	reachableNodes.push_back(*this); // The Node itself is also added to the list of Nodes that can be reached from it 
	for (unsigned int i = 0; i < paths.size(); i++) 
		if (Utility::appendNodeIfUnique(reachableNodes, *paths.at(i).destination)) 
			for (unsigned int j = 0; j < paths.at(i).destination->getPaths().size(); j++)
				if (Utility::appendNodeIfUnique(reachableNodes, *paths.at(i).destination->getPaths().at(j).destination)) 
					for (unsigned int k = 0; k < paths.at(i).destination->getPaths().at(j).destination->getPaths().size(); k++)
						if (Utility::appendNodeIfUnique(reachableNodes, *paths.at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination)) 
							for (unsigned int m = 0; m < paths.at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().size(); m++)
								if (Utility::appendNodeIfUnique(reachableNodes, *paths.at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination)) 
									for (unsigned int n = 0; n < paths.at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().size(); n++)
										if (Utility::appendNodeIfUnique(reachableNodes, *paths.at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination)) 
											for (unsigned int p = 0; p < paths.at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().size(); p++)
												if (Utility::appendNodeIfUnique(reachableNodes, *paths.at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination)) 
													for (unsigned int q = 0; q < paths.at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().size(); q++)
														if (Utility::appendNodeIfUnique(reachableNodes, *paths.at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).destination)) 
															for (unsigned int r = 0; r < paths.at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).destination->getPaths().size(); r++)
																if (Utility::appendNodeIfUnique(reachableNodes, *paths.at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).destination->getPaths().at(r).destination)) 
																	for (unsigned int s = 0; s < paths.at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).destination->getPaths().at(r).destination->getPaths().size(); s++)
																		Utility::appendNodeIfUnique(reachableNodes, *paths.at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).destination->getPaths().at(r).destination->getPaths().at(s).destination);
	return reachableNodes;
/* Note my usage of 9 nested for loops above. It may seem unconventional but I believe there is no any other possible
way of doing it, except for recursion which would be slower than using loops. The above code examines all the paths 
that can be taken from the starting Node and all of their branches in order to result in a list with all the Nodes that 
can possibly be reached from the starting Node. The way this works is that in the outermost loop the list of all Paths 
is examined and the destination Nodes are added to the list. In the next nested loop, each subpath resulting from following 
each direct Path from the starting Node is examined in the same way. This goes on for 9 levels because at maximum there could be 9 
layers of paths that can be examined in a simulation with 10 Nodes and 10 router table entries
*/
}

bool Node::isEqual(const Node& comparisonNode) {
	if (ID == comparisonNode.ID && IPAddress == comparisonNode.IPAddress)
		return true;
	return false;
}

void Node::routeInfoToNode(Node target, unsigned int& routeCost, Node& nextNode) {
	// NB: This method compares ALL possible routes to get to the target Node and returns information related to the best one
	vector<Route> possibleRoutes;
	routeCost = 0;
	if (this->isEqual(target)) { // The trivial case if the destination node is the same as the source node
		nextNode = target;
		return;
	}
	for (unsigned int i = 0; i < getPaths().size(); i++) { 
		nextNode = *getPaths().at(i).destination; // The nextNode is dependant on i and is updated every time i increments. Note the nextNode variable changes a few times before it's returned with the correct value
		if (target.isEqual(*getPaths().at(i).destination)) { // If the desired node was reached
			Route routeFound;
			routeFound.nextNodeInRoute = nextNode; 
			routeFound.routeMetric += getPaths().at(i).cost;
			possibleRoutes.push_back(routeFound); // The new Route found is added to the array of possible Routes
			continue;
		}
		for (unsigned int j = 0; j < getPaths().at(i).destination->getPaths().size(); j++) {
			if (target.isEqual(*getPaths().at(i).destination->getPaths().at(j).destination)) {
				Route routeFound;
				routeFound.nextNodeInRoute = nextNode;
				routeFound.routeMetric += getPaths().at(i).cost; 
				routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).cost; // The costs of every Path involved in this route are added
				possibleRoutes.push_back(routeFound);
				continue;
			}
			for (unsigned int k = 0; k < getPaths().at(i).destination->getPaths().at(j).destination->getPaths().size(); k++) {
				if (target.isEqual(*getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination)) {
					Route routeFound;
					routeFound.nextNodeInRoute = nextNode;
					routeFound.routeMetric += getPaths().at(i).cost;
					routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).cost;
					routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).cost;
					possibleRoutes.push_back(routeFound);
					continue;
				}
				for (unsigned int m = 0; m < getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().size(); m++) {
					if (target.isEqual(*getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination)) {
						Route routeFound;
						routeFound.nextNodeInRoute = nextNode;
						routeFound.routeMetric += getPaths().at(i).cost;
						routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).cost;
						routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).cost;
						routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).cost;
						possibleRoutes.push_back(routeFound);
						continue;
					}
					for (unsigned int n = 0; n < getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().size(); n++) {
						if (target.isEqual(*getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination)) {
							Route routeFound;
							routeFound.nextNodeInRoute = nextNode;
							routeFound.routeMetric += getPaths().at(i).cost;
							routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).cost;
							routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).cost;
							routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).cost;
							routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).cost;
							possibleRoutes.push_back(routeFound);
							continue;
						}
						for (unsigned int p = 0; p < getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().size(); p++) {
							if (target.isEqual(*getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination)) {
								Route routeFound;
								routeFound.nextNodeInRoute = nextNode;
								routeFound.routeMetric += getPaths().at(i).cost;
								routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).cost;
								routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).cost;
								routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).cost;
								routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).cost;
								routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).cost;
								possibleRoutes.push_back(routeFound);
								continue;
							}
							for (unsigned int q = 0; q < getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().size(); q++) {
								if (target.isEqual(*getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).destination)) {
									Route routeFound;
									routeFound.nextNodeInRoute = nextNode;
									routeFound.routeMetric += getPaths().at(i).cost;
									routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).cost;
									routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).cost;
									routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).cost;
									routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).cost;
									routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).cost;
									routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).cost;
									possibleRoutes.push_back(routeFound);
									continue;
								}
								for (unsigned int r = 0; r < getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).destination->getPaths().size(); r++) {
									if (target.isEqual(*getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).destination->getPaths().at(r).destination)) {
										Route routeFound;
										routeFound.nextNodeInRoute = nextNode;
										routeFound.routeMetric += getPaths().at(i).cost;
										routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).cost;
										routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).cost;
										routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).cost;
										routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).cost;
										routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).cost;
										routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).cost;
										routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).destination->getPaths().at(r).cost;
										possibleRoutes.push_back(routeFound);
										continue;
									}
									for (unsigned int s = 0; s < getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).destination->getPaths().at(r).destination->getPaths().size(); s++) {
										if (target.isEqual(*getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).destination->getPaths().at(r).destination->getPaths().at(s).destination)) {
											Route routeFound;
											routeFound.nextNodeInRoute = nextNode;
											routeFound.routeMetric += getPaths().at(i).cost;
											routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).cost;
											routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).cost;
											routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).cost;
											routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).cost;
											routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).cost;
											routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).cost;
											routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).destination->getPaths().at(r).cost;
											routeFound.routeMetric += getPaths().at(i).destination->getPaths().at(j).destination->getPaths().at(k).destination->getPaths().at(m).destination->getPaths().at(n).destination->getPaths().at(p).destination->getPaths().at(q).destination->getPaths().at(r).destination->getPaths().at(s).cost;
											// Optimization could not be performed here. The costs need to be added up when the route is found and starting to add them earlier does not work
											possibleRoutes.push_back(routeFound);
											continue;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	unsigned int indexOfLeastCostRoute = 0;
	for (unsigned int i = 1; i < possibleRoutes.size(); i++) { // All the possible routes to the destination Node are examined to find the best one
		if (possibleRoutes[i].routeMetric < possibleRoutes[indexOfLeastCostRoute].routeMetric)
			indexOfLeastCostRoute = i;
	}
	routeCost = possibleRoutes[indexOfLeastCostRoute].routeMetric;
	nextNode = possibleRoutes[indexOfLeastCostRoute].nextNodeInRoute;

/* Note my usage of 9 nested loops again in this function. However, this time some optimization was possible.
When it is found that one of the routes leads to the destination Node, the continue keyword is used 
in order to go to the next iteration of the for loop at that level, without processing the nested loops for that branch.
This means that further subbranches from the route which led to the destination Node are not examined.
It is not neccessary to do so, since that route already led to the destination Node
*/
}

void Node::modifyPathCost(int indexOfPath, const unsigned int& newCost) {
	paths.at(indexOfPath).cost = newCost;
}