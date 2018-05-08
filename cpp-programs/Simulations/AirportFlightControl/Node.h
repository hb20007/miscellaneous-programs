#pragma once
#include "FlightRec.h"

struct Node {
	FlightRec flight;
	Node *next;
	Node();
	Node(const FlightRec &flightData,  Node *nextNode = nullptr); // in C++11, nullptr is used instead of null
};