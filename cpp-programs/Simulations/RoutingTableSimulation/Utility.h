#pragma once
#include "Node.h"
#include <vector>
#include <string>
using namespace std;

class Utility final { // This is a class with static utility functions. The private constructor prevents it from being instantiated. It is also final to prevent it from being inherited
public:
	static bool isReserved(const string &IP4Address); // Checks if the inserted IP4 address is in the reserved address blocks 
	static string generateIPAddress(); // Generates a random IP4 address which does not belong to any of the reserved address blocks
	static int specialRandomIntegerGenerate(const int& exclude, const int& lessThan); // Generates a random integer x where (0 < x < lessThan) AND (x != exclude)
	static bool appendNodeIfUnique(vector<Node>& nodeVector, const Node& newNode); // Appends a Node to the Node array passed by reference only if it does not already exist in the array and returns true if the appending occured or false if the Node already existed
	static bool pathToDestinationAlreadyExists(const vector<Path>& pathsArray, Node newDestination); // Returns true if a path to the given node already exists and false if it doesn't
private:
	Utility();
};