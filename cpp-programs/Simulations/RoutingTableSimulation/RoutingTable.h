#pragma once
#include "RoutingEntry.h"
#include <vector>
using namespace std;

class RoutingTable { // The routing table for a particular router
public:
	vector<RoutingEntry> getTableEntries(); // Accessor method for tableEntries
	void addTableEntry(const RoutingEntry& nextEntry); // Appends a new entry to the routing table
	void modifyMetric(const int& index, const unsigned int& newCost); // The cost in the routing table entry with the specified index is changed to the specified new cost
	void modifyNextNodeID(const int& index, const char& newID); // The next node ID in the routing table entry with the specified index is changed to the specified new next node ID
	void modifySequenceNo(const int& index, const string& newSeqNo); // The sequence number in the routing table entry with the specified index is changed to the specified new sequence number
	void modifySequenceNoRef(const int&index, const unsigned int newSequenceInteger); // The sequence number reference in the routing table entry with the specified index is changed to the specified new sequence number reference
	void modifyTime(const int& index, const string& newTime); // The time in the routing table entry with the specified index is changed to the specified new time
private:
	vector<RoutingEntry> tableEntries; // An array of the entries in the routing table
};