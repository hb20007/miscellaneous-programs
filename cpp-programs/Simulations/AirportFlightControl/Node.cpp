#include "Node.h"

Node::Node() {
	next = nullptr;
}

Node::Node(const FlightRec &flightData, Node *nextNode) {
	flight = flightData;
	next = nextNode;
}