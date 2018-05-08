#include "Utility.h"

bool Utility::isReserved(const string& IP4Address) { 
	if (IP4Address.substr(0, 2) == "0." || IP4Address.substr(0, 3) == "10." || IP4Address.substr(0, 7) == "100.64." || IP4Address.substr(0, 4) == "127." || IP4Address.substr(0, 7) == "169.254" || IP4Address.substr(0, 7) == "172.16." || IP4Address.substr(0, 7) == "192.0.0" || IP4Address.substr(0, 8) == "192.0.2." || IP4Address.substr(0, 9) == "192.88.99" || IP4Address.substr(0, 4) == "127." || IP4Address.substr(0, 7) == "192.168" || IP4Address.substr(0, 7) == "198.18." || IP4Address.substr(0, 10) == "198.51.100" || IP4Address.substr(0, 9) == "203.0.113" || IP4Address.substr(0, 3) == "224" || IP4Address.substr(0, 3) == "240" || IP4Address == "255.255.255.255")
		return true; // I referenced the list of reserved IP4 addresses here https://www.wikiwand.com/en/IPv4#/Special-use_addresses 
	return false;
}

string Utility::generateIPAddress() {
	string ip4;
	do {
	ip4 = ""; // The IP address is generated again from scratch if it is a reserved address so ip4 is initialized to "" in the do while loop 
		for (int i = 0; i < 4; i++)
		{
			ip4 += to_string(rand() % 256); // the std::to_string() function allows concatenating the integer to the string without implicit casting to a character
			if (i != 3)
				ip4 += '.';
		}
	} while (isReserved(ip4));
	return ip4;
}

int Utility::specialRandomIntegerGenerate(const int& exclude, const int& lessThan) {
	int random = rand() % lessThan;
	return random != exclude ? random : specialRandomIntegerGenerate(exclude, lessThan); // If the random number is not equal to 'exclude', it is returned, else the function is called again recursively until the random number generated is not equal to 'exclude'
}

bool Utility::appendNodeIfUnique(vector<Node>& nodeVector, const Node& newNode) {
	if (!nodeVector.empty()) { // If the Node vector is empty the new Node is added without the need to perform any checks
		for (unsigned int i = 0; i < nodeVector.size(); i++)
			if (nodeVector.at(i).isEqual(newNode))
				return false;
	}
	nodeVector.push_back(newNode); // if reachableNodes does NOT contain the Node that the path leads to, the Node is added to the list of reachable Nodes
	return true;
}

bool Utility::pathToDestinationAlreadyExists(const vector<Path>& pathsArray,  Node newDestination) { // Checks for direct paths to the destination
	for (unsigned int i = 0; i < pathsArray.size(); i++) 
		if (newDestination.isEqual(*pathsArray.at(i).destination))
			return true;
	return false;
}