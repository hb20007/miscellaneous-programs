#pragma once
#include "Node.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream> // Used to aid conversion from integer to string
using namespace std;

enum errorCode {
	SUCCESS, FAIL
};

class List {
public:
	List();
	bool empty(); // Checks if the last contains entries
	errorCode append(const FlightRec &item); // Adds a flight to the end of the list
	errorCode searchByFlightNo(int &positionInList, const char flightNum[10]); // Returns the position of the flight with the specified flight number in the linked list via a reference parameter
	int size(); // Returns the number of entries in the list
	void cancelFlight(const int &flightIndex); // Deletes the entry with the specified flight index. This is used in conjuction with the searchByFlightNumber() method. 
	void modifyFlightTime(const int &flightIndex, const TimeRec &newTime); // Modifies the time of the flight with the specified index in the list
	void registerFlightDelay(const int &flightIndex, const TimeRec &arrivalTimeWithDelay); // Adds delay to a chosen flight in the list
	void sortByFlightNo(const int &left, const int &right); // Sorts the flights in the list by flight number
	void sortByTime(const int &left, const int &right); // Sorts the flights in the list by time
	void printFlights(); // Displays all flight information with the right spacing to be displayed in the arrivals and departures tables.
	void printFlightsNotCompletedYet(TimeRec timeNow); // Displays only the flights
	string toString(); // Returns a string with all flight information. Used when writing to file
private:
	Node *head;
};