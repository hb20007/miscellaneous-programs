#include "RoutingTable.h"

vector<RoutingEntry> RoutingTable::getTableEntries() {
	return tableEntries;
}

void RoutingTable::addTableEntry(const RoutingEntry& nextEntry) {
	tableEntries.push_back(nextEntry);
}

void RoutingTable::modifyMetric(const int& index, const unsigned int& newCost) {
	tableEntries.at(index).metric = newCost;
}

void RoutingTable::modifyNextNodeID(const int& index, const char& newID) {
	tableEntries.at(index).nextNodeID = newID;
}

void RoutingTable::modifySequenceNo(const int& index, const string& newSeqNo) {
	tableEntries.at(index).sequenceNumber = newSeqNo;
}

void RoutingTable::modifySequenceNoRef(const int&index, const unsigned int newSequenceInteger) {
	tableEntries.at(index).sequenceNumberReference = newSequenceInteger;
}

void RoutingTable::modifyTime(const int& index, const string& newTime) {
	tableEntries.at(index).time = newTime;
}