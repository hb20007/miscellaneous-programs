#pragma once
#include <string>
using namespace std;

struct RoutingEntry { // An entry in a routing table
	int rowNumber; // The row number in the routing table
	char destinationNodeID; // The ID of the final destination node 
	string destinationNodeIPAddress; // The final destination IP address which is compared by the router to the destination address in the packet header in order to make routing decisions
	char nextNodeID; // The ID of the next Node in the route to this destination
	unsigned int metric; // The cost of following this route to the destination Node
	unsigned int portNumber; // The router port involved in routing a packet along this Route
	string sequenceNumber; // The sequence number of this routing table entry 
	string time; // The time that the routing table entry was mad
	unsigned int sequenceNumberReference; // The integer part of the sequence number is stored here only for making comparisons easier
};