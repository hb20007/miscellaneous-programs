/*  @Hb20007
*  
*   Flight scheduling program using a linked list class
*/

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "FlightRec.h"
#include "List.h"
using namespace std;

class MainApplication {
public:
	void mainMenu(); // Displays the main menu
	void mainParse(); // Deals with the user input at the main menu
	void viewFlightsParse();
	void sortParse();
	void editFlightsParse();
	void readWriteParse();
	void insertSelection(); // Records the user's menu selection
	void checkSelection(); // Validates the user's menu selection
	void enterCurrentTime(); // Allows the user to insert the current time
	TimeRec readCurrentTime(); // Returns the current time
	void readFlights(); // Reads flights from a file
	void writeFlights(); // Wrties flights to file
	void displayAllDepartures(); // Displays all departure flights for the day, regardless of their time
	void displayAllArrivals(); // Displays all arrival flights
	void displayFlightsNotYetDeparted(); // Displays all departure flights not yet departed based on the current time
	void displayFlightsNotYetArrived(); // Displays all arrival flights not yet arrived based on the current time
	void displayCurrentTime(); // Displays the current time
	void newFlight(); // Allows the user to insert data for a new flight
	errorCode deleteFlight(); // Deletes a flight from the list
	errorCode modifyFlightTime(); // Modifies a flight's time
	errorCode insertDelay(); // Registers delay for a flight
protected:
	List arrivalsList; 
	List departuresList;
private:
	void viewFlightsMenu();
	void sortMenu();
	void editFlightsMenu();
	void readWriteMenu();
	void backToMainMenu(); // Returns to main menu
	void errorAndBackToMainMenu(); // Displays an error and returns to main menu
	string readSelection(); // Returns the users' selection
	string selection; // The data type used is string for data validation purposes
	TimeRec currentTime;
};