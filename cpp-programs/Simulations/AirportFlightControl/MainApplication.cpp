#include "MainApplication.h"

void MainApplication::mainMenu() {
	cout << "\n1> View flights\n";
	cout << "2> Edit current time\n";
	cout << "3> Edit flight information\n";
	cout << "4> Read/write to file\n";
	cout << "5> Sort flights\n";
	cout << "6-9> Exit\n\n> ";
}

void MainApplication::mainParse() {
	switch (readSelection().at(0)) {
	case '1':
		viewFlightsMenu();
		insertSelection();
		checkSelection();
		viewFlightsParse();
		break;
	case '2': 
		enterCurrentTime();
		break;
	case '3':
		editFlightsMenu();
		insertSelection();
		checkSelection();
		editFlightsParse();
		break;
	case '4':
		readWriteMenu();
		insertSelection();
		checkSelection();
		readWriteParse();
		break;
	case '5':
		sortMenu();
		insertSelection();
		checkSelection();
		sortParse();
	}
}

void MainApplication::viewFlightsParse() {
	switch (readSelection().at(0)) {
	case '1':
		displayAllDepartures();
		displayAllArrivals();
		displayCurrentTime();
		backToMainMenu();
		break;
	case '2':
		displayAllDepartures();
		displayCurrentTime();
		backToMainMenu();
		break;
	case '3':
		displayAllArrivals();
		displayCurrentTime();
		backToMainMenu();
		break;
	case '4':
		displayFlightsNotYetDeparted();
		displayCurrentTime();
		backToMainMenu();
	case '5': 
		displayFlightsNotYetArrived();
		displayCurrentTime();
		backToMainMenu();
	default:
		backToMainMenu();
	}
}

void MainApplication::sortParse() {
	switch (readSelection().at(0)) {
	case '1':
		departuresList.sortByFlightNo(0, departuresList.size() - 1); // Both the departures and arrivals list are sorted
		arrivalsList.sortByFlightNo(0, arrivalsList.size() - 1);
		cout << "\n\nFlights succesfully sorted!\n\n";
		backToMainMenu();
		break;
	case '2':
		departuresList.sortByTime(0, departuresList.size() - 1);
		arrivalsList.sortByTime(0, arrivalsList.size() - 1);
		cout << "\n\nFlights succesfully sorted!\n\n";
		backToMainMenu();
		break;
	default:
		backToMainMenu();
	}
}

void MainApplication::editFlightsParse() {
	switch (readSelection().at(0)) {
	case '1':
		newFlight();
		cout << "\n\nFlight succesfully added to system!\n\n";
		backToMainMenu();
		break;
	case '2':
		if (deleteFlight() == SUCCESS) {
			cout << "\n\nFlight succesfully deleted from system!\n\n";
			backToMainMenu();
		}
		break;
	case '3':
		if (modifyFlightTime() == SUCCESS) {
			cout << "\n\nFlight successfully modified!\n\n";
			backToMainMenu();
		}
		break;
	case '4':
		if (insertDelay() == SUCCESS) {
			cout << "\n\nDelay successfully registered!\n\n";
			backToMainMenu();
		}
		break;
	default:
		backToMainMenu();
	}
}

void MainApplication::readWriteParse() {
	switch (readSelection().at(0)) {
	case '1':
		readFlights();
		cout << "\n\nAny existent flights in the specified file were succesfully read!\n\n";
		backToMainMenu();
		break;
	case '2':
		writeFlights();
		cout << "\n\nFlights succesfully written to file!\n\n";
		backToMainMenu();
		break;
	default:
		backToMainMenu();
	}
}

void MainApplication::insertSelection() {
	cin >> selection;
}

string MainApplication::readSelection() {
	return selection;
}

void MainApplication::checkSelection() {
	if ((readSelection().length() != 1) || readSelection().at(0) > '9' || readSelection().at(0) < '1')  // If the user entry is not one byte long or if it's one byte long but not a valid integer
		errorAndBackToMainMenu();
}

void MainApplication::viewFlightsMenu(){
	cout << "\n1> Display all flights\n";
	cout << "2> Display all departure flights today\n";
	cout << "3> Display all arrival flights today\n";
	cout << "4> Display flights not departed yet\n";
	cout << "5> Display flights not arrived yet\n";
	cout << "6-9> Back to main menu\n\n> ";
}

void MainApplication::sortMenu() {
	cout << "\n1> Sort by Flight Number\n";
	cout << "2> Sort by Time\n";
	cout << "3-9> Back to main menu\n\n> ";
}

void MainApplication::editFlightsMenu() {
	cout << "\n1> Enter new flight\n";
	cout << "2> Delete flight\n";
	cout << "3> Modify flight time\n";
	cout << "4> Enter delay in a flight\n";
	cout << "5-9> Back to main menu\n\n> ";

}

void MainApplication::readWriteMenu() {
	cout << "\n1> Read flight info from file\n";
	cout << "2> Write flight info to file\n";
	cout << "3-9> Back to main menu\n\n> ";
}

void MainApplication::enterCurrentTime() {
	string timeEntry;

	cout << "\nInsert hour (0-23)\n> ";
	cin >> timeEntry;
	if ((timeEntry.length() <= 2) && (stoi(timeEntry.substr(0, 2)) <= 23) && (stoi(timeEntry.substr(0, 2)) >= 0)) // stoi() parses a string as an integer. By the specification of the stoi() function, these checks are sufficient to verify that the user input is valid
		currentTime.hour = stoi(timeEntry);
	else {
		errorAndBackToMainMenu();
		return;
	}
	cout << "Insert minutes (0-59)\n> ";
	cin >> timeEntry;
	if ((timeEntry.length() <= 2) && (stoi(timeEntry.substr(0, 2)) <= 59) && (stoi(timeEntry.substr(0, 2)) >= 0))
		currentTime.min = stoi(timeEntry);
	else {
		errorAndBackToMainMenu();
		return;
	}
	cout << "Insert seconds (0-59)\n> ";
	cin >> timeEntry;
	if ((timeEntry.length() <= 2) && (stoi(timeEntry.substr(0, 2)) <= 59) && (stoi(timeEntry.substr(0, 2)) >= 0))
		currentTime.sec = stoi(timeEntry);
	else {
		errorAndBackToMainMenu();
		return;
	}
	cout << "\n\nThe current time has been updated. Going back to main menu...\n\n";
	backToMainMenu();
}

void MainApplication::backToMainMenu() {
	mainMenu();
	insertSelection();
	checkSelection();
	mainParse();
}

void MainApplication::errorAndBackToMainMenu() {
	cout << "\n\nInvalid entry. Going back to main menu...\n\n";
	backToMainMenu();
}

TimeRec MainApplication::readCurrentTime() {
	return currentTime;
}

void MainApplication::readFlights() {
	FlightRec temp;

	char fileName[50];
	char word[25]; // Stores the words as they are read from the file

	ifstream departuresInputStream;
	cout << "\nInsert name of the departures file (including extension)\n> ";
	cin >> fileName;
	departuresInputStream.open(fileName);
	while (departuresInputStream.good()) {
		departuresInputStream >> word;
		strcpy_s(temp.flightNo, word);
		departuresInputStream >> word;
		strcpy_s(temp.city, word);
		departuresInputStream >> word;
		temp.time.hour = stoi(word);
		departuresInputStream >> word;
		temp.time.min = stoi(word);
		departuresInputStream >> word;
		temp.time.sec = stoi(word);
		departuresInputStream >> word;
		temp.delay = stoi(word);
		if (temp.delay == true) {
			departuresInputStream >> word;
			temp.expectedTime.hour = stoi(word);
			departuresInputStream >> word;
			temp.expectedTime.min= stoi(word);
			departuresInputStream >> word;
			temp.expectedTime.sec = stoi(word);
		}
		temp.fType = DEPARTURE;
		if (departuresList.append(temp) == FAIL) { // This both executes the append() method and deals with the error situation 
			cout << "\n\nCritical Error: Out of memory (stack overflow). Going back to main menu...\n\n";
			backToMainMenu();
			return;
		}
	}
	departuresInputStream.close();

	ifstream arrivalsInputStream;
	cout << "\nInsert name of the arrivals file (including extension)\n> ";
	cin >> fileName;
	arrivalsInputStream.open(fileName);
	while (arrivalsInputStream.good()) {
		arrivalsInputStream >> word;
		strcpy_s(temp.flightNo, word);
		arrivalsInputStream >> word;
		strcpy_s(temp.city, word);
		arrivalsInputStream >> word;
		temp.time.hour = stoi(word);
		arrivalsInputStream >> word;
		temp.time.min = stoi(word);
		arrivalsInputStream >> word;
		temp.time.sec = stoi(word);
		arrivalsInputStream >> word;
		temp.delay = stoi(word);
		if (temp.delay == true) {
			arrivalsInputStream >> word;
			temp.expectedTime.hour = stoi(word);
			arrivalsInputStream >> word;
			temp.expectedTime.min = stoi(word);
			arrivalsInputStream >> word;
			temp.expectedTime.sec = stoi(word);
		}
		temp.fType = ARRIVAL;
		if (arrivalsList.append(temp) == FAIL) {
			cout << "\n\nCritical Error: Out of memory (stack overflow). Going back to main menu...\n\n";
			backToMainMenu();
			return;
		}
	}
	arrivalsInputStream.close();
}

void MainApplication::writeFlights() {
	char fileName[50];

	ofstream departuresOutputStream;
	cout << "\nInsert name of the departures file (including extension)\n> ";
	cin >> fileName;
	departuresOutputStream.open(fileName);
	departuresOutputStream << departuresList.toString();
	departuresOutputStream.close();

	ofstream arrivalsOutputStream;
	cout << "\nInsert name of the arrivals file (including extension)\n> ";
	cin >> fileName;
	arrivalsOutputStream.open(fileName);
	arrivalsOutputStream << arrivalsList.toString();
	arrivalsOutputStream.close();
}

void MainApplication::displayAllDepartures() {
	cout << "\nALL DEPARTURES\n\n";
	cout << "Flight       Destination       Departure Time       Delay       Expected Time\n\n";
	departuresList.printFlights();
}

void MainApplication::displayAllArrivals() {
	cout << "\nALL ARRIVALS\n\n";
	cout << "Flight          From            Arrival Time       Delay       Expected Time\n\n";
	arrivalsList.printFlights();
}

void MainApplication::displayFlightsNotYetDeparted() {
	cout << "\nDEPARTURES\n\n";
	cout << "Flight       Destination       Departure Time       Delay       Expected Time\n\n";
	departuresList.printFlightsNotCompletedYet(currentTime);
}

void MainApplication::displayFlightsNotYetArrived() {
	cout << "\nARRIVALS\n\n";
	cout << "Flight          From            Arrival Time       Delay       Expected Time\n\n";
	arrivalsList.printFlightsNotCompletedYet(currentTime);
}

void MainApplication::displayCurrentTime() {
	cout << "\nCurrent time: " << setw(2) << setfill('0') << currentTime.hour << ':' << setw(2) << setfill('0') << currentTime.min << '.' << setw(2) << setfill('0') << currentTime.sec << endl;
}

void MainApplication::newFlight() {
	FlightRec newRecord;
	string userInput;
	cout << "\n\nInsert 'd' to add a departing flight or 'a' for an arriving flight\n> ";
	cin >> userInput;
	if ((userInput.at(0) != 'd' && userInput.at(0) != 'a' && userInput.at(0) != 'A' && userInput.at(0) != 'D') || userInput.length() > 1) {
		errorAndBackToMainMenu();
		return;
	}
	if (userInput.at(0) == 'd' || userInput.at(0) == 'D')
		newRecord.fType = DEPARTURE;
	else
		newRecord.fType = ARRIVAL;
	cout << "\nInsert flight number\n> ";
	cin >> userInput;
	strcpy_s(newRecord.flightNo, userInput.c_str()); // userInput.c_str() converts from a C++ into a C string. This is used because strcpy_s() must take two strings of the same type
	cout << "\nInsert city\n> ";
	cin >> userInput;
	strcpy_s(newRecord.city, userInput.c_str());

	cout << "\nInsert hour (0-23)\n> ";
	cin >> userInput;
	if ((userInput.length() <= 2) && (stoi(userInput.substr(0, 2)) <= 23) && (stoi(userInput.substr(0, 2)) >= 0)) // stoi() parses a string as an integer. By the specification of the stoi() function, these checks are sufficient to verify that the user input is valid
		newRecord.time.hour = stoi(userInput);
	else {
		errorAndBackToMainMenu();
		return;
	}
	cout << "Insert minutes (0-59)\n> ";
	cin >> userInput;
	if ((userInput.length() <= 2) && (stoi(userInput.substr(0, 2)) <= 59) && (stoi(userInput.substr(0, 2)) >= 0))
		newRecord.time.min= stoi(userInput);
	else {
		errorAndBackToMainMenu();
		return;
	}
	cout << "Insert seconds (0-59)\n> ";
	cin >> userInput;
	if ((userInput.length() <= 2) && (stoi(userInput.substr(0, 2)) <= 59) && (stoi(userInput.substr(0, 2)) >= 0))
		newRecord.time.sec = stoi(userInput);
	else {
		errorAndBackToMainMenu();
		return;
	}
	cout << "\nIs there registered delay? (insert 'yes' or 'no')\n> ";
	cin >> userInput;
	if (userInput == "yes") {
		newRecord.delay = true;
		cout << "\nInsert hour after delay (0-23)\n> ";
		cin >> userInput;
		if ((userInput.length() <= 2) && (stoi(userInput.substr(0, 2)) <= 23) && (stoi(userInput.substr(0, 2)) >= 0)) // stoi() parses a string as an integer. By the specification of the stoi() function, these checks are sufficient to verify that the user input is valid
			newRecord.expectedTime.hour= stoi(userInput);
		else {
			errorAndBackToMainMenu();
			return;
		}
		cout << "Insert minutes after delay (0-59)\n> ";
		cin >> userInput;
		if ((userInput.length() <= 2) && (stoi(userInput.substr(0, 2)) <= 59) && (stoi(userInput.substr(0, 2)) >= 0))
			newRecord.expectedTime.min = stoi(userInput);
		else {
			errorAndBackToMainMenu();
			return;
		}
		cout << "Insert seconds after delay (0-59)\n> ";
		cin >> userInput;
		if ((userInput.length() <= 2) && (stoi(userInput.substr(0, 2)) <= 59) && (stoi(userInput.substr(0, 2)) >= 0))
			newRecord.expectedTime.sec = stoi(userInput);
		else {
			errorAndBackToMainMenu();
			return;
		}
	}
	else if (userInput == "no")
		newRecord.delay = false;
	else {
		errorAndBackToMainMenu();
		return;
	}

	if (newRecord.fType == DEPARTURE) {
		if (departuresList.append(newRecord) == FAIL) {
			cout << "\n\nCritical Error: Out of memory (stack overflow). Going back to main menu...\n\n";
			backToMainMenu();
			return;
		}
	}
	else if (arrivalsList.append(newRecord) == FAIL) {
		cout << "\n\nCritical Error: Out of memory (stack overflow). Going back to main menu...\n\n";
		backToMainMenu();
		return;
	}
}

errorCode MainApplication::deleteFlight() {
	string entry;
	cout << "\n\nInsert 'd' if you would like to delete a departing flight, or 'a' for an arriving flight\n\n> ";
	cin >> entry;
	if ((entry.at(0) != 'd' && entry.at(0) != 'a' && entry.at(0) != 'A' && entry.at(0) != 'D') || entry.length() > 1) {
		errorAndBackToMainMenu();
		return FAIL;
	}

	string flightNumber;
	cout << "\n\nInsert the flight number of the flight you want to delete\n\n> ";
	cin >> flightNumber;
	int positionOfFlight; // Will contain the index of the flight when it is located in the array
	if (entry.at(0) == 'd' || entry.at(0) == 'D') {
		if (departuresList.searchByFlightNo(positionOfFlight, flightNumber.c_str()) == FAIL) {
			cout << "\n\nNo flight with this flight number exists. Going back to main menu...\n\n";
			backToMainMenu();
			return FAIL;
		}
		departuresList.cancelFlight(positionOfFlight);
	}
	else {
		if (arrivalsList.searchByFlightNo(positionOfFlight, flightNumber.c_str()) == FAIL) {
			cout << "\n\nNo flight with this flight number exists. Going back to main menu...\n\n";
			backToMainMenu();
			return FAIL;
		}
		arrivalsList.cancelFlight(positionOfFlight);
	}
	return SUCCESS;
}

errorCode MainApplication::modifyFlightTime() {
	string entry;
	cout << "\n\nInsert 'd' if you would like to modify a departing flight, or 'a' for an arriving flight\n\n> ";
	cin >> entry;
	if ((entry.at(0) != 'd' && entry.at(0) != 'a' && entry.at(0) != 'A' && entry.at(0) != 'D') || entry.length() > 1) {
		errorAndBackToMainMenu();
		return FAIL;
	}

	int positionOfFlight;
	string flightNumber;
	cout << "\n\nInsert the flight number of the flight you want to modify\n\n> ";
	cin >> flightNumber;
	if (entry.at(0) == 'd' || entry.at(0) == 'D') {
		if (departuresList.searchByFlightNo(positionOfFlight, flightNumber.c_str()) == FAIL) {
			cout << "\n\nNo flight with this flight number exists. Going back to main menu...\n\n";
			backToMainMenu();
			return FAIL;
		}
	}
	else {
		if (arrivalsList.searchByFlightNo(positionOfFlight, flightNumber.c_str()) == FAIL) {
			cout << "\n\nNo flight with this flight number exists. Going back to main menu...\n\n";
			backToMainMenu();
			return FAIL;
		}
	}
	string timeInput;
	TimeRec newTiming;
	cout << "\nInsert new hour (0-23)\n> ";
	cin >> timeInput;
	if ((timeInput.length() <= 2) && (stoi(timeInput.substr(0, 2)) <= 23) && (stoi(timeInput.substr(0, 2)) >= 0)) 
		newTiming.hour = stoi(timeInput);
	else {
		errorAndBackToMainMenu();
		return FAIL;
	}
	cout << "Insert new minutes (0-59)\n> ";
	cin >> timeInput;
	if ((timeInput.length() <= 2) && (stoi(timeInput.substr(0, 2)) <= 59) && (stoi(timeInput.substr(0, 2)) >= 0))
		newTiming.min = stoi(timeInput);
	else {
		errorAndBackToMainMenu();
		return FAIL;
	}
	cout << "Insert new seconds (0-59)\n> ";
	cin >> timeInput;
	if ((timeInput.length() <= 2) && (stoi(timeInput.substr(0, 2)) <= 59) && (stoi(timeInput.substr(0, 2)) >= 0))
		newTiming.sec = stoi(timeInput);
	else {
		errorAndBackToMainMenu();
		return FAIL;
	}

	if (entry.at(0) == 'd' || entry.at(0) == 'D') 
		departuresList.modifyFlightTime(positionOfFlight, newTiming);
	else 
		arrivalsList.modifyFlightTime(positionOfFlight, newTiming);
	return SUCCESS;
}

errorCode MainApplication::insertDelay() {
	string entry;
	cout << "\n\nInsert 'd' if you would like to modify a departing flight, or 'a' for an arriving flight\n\n> ";
	cin >> entry;
	if ((entry.at(0) != 'd' && entry.at(0) != 'a' && entry.at(0) != 'A' && entry.at(0) != 'D') || entry.length() > 1) {
		errorAndBackToMainMenu();
		return FAIL;
	}

	int positionOfFlight;
	string flightNumber;
	cout << "\n\nInsert the flight number of the flight you want to modify\n\n> ";
	cin >> flightNumber;

	if (entry.at(0) == 'd' || entry.at(0) == 'D') {
		if (departuresList.searchByFlightNo(positionOfFlight, flightNumber.c_str()) == FAIL) {
			cout << "\n\nNo flight with this flight number exists. Going back to main menu...\n\n";
			backToMainMenu();
			return FAIL;
		}
	}
	else {
		if (arrivalsList.searchByFlightNo(positionOfFlight, flightNumber.c_str()) == FAIL) {
			cout << "\n\nNo flight with this flight number exists. Going back to main menu...\n\n";
			backToMainMenu();
			return FAIL;
		}
	}
	string timeInput;
	TimeRec newTiming;
	cout << "\nInsert hour after delay (0-23)\n> ";
	cin >> timeInput;
	if ((timeInput.length() <= 2) && (stoi(timeInput.substr(0, 2)) <= 23) && (stoi(timeInput.substr(0, 2)) >= 0))
		newTiming.hour = stoi(timeInput);
	else {
		errorAndBackToMainMenu();
		return FAIL;
	}
	cout << "Insert minutes after delay (0-59)\n> ";
	cin >> timeInput;
	if ((timeInput.length() <= 2) && (stoi(timeInput.substr(0, 2)) <= 59) && (stoi(timeInput.substr(0, 2)) >= 0))
		newTiming.min = stoi(timeInput);
	else {
		errorAndBackToMainMenu();
		return FAIL;
	}
	cout << "Insert seconds after delay(0-59)\n> ";
	cin >> timeInput;
	if ((timeInput.length() <= 2) && (stoi(timeInput.substr(0, 2)) <= 59) && (stoi(timeInput.substr(0, 2)) >= 0))
		newTiming.sec = stoi(timeInput);
	else {
		errorAndBackToMainMenu();
		return FAIL;
	}

	if (entry.at(0) == 'd' || entry.at(0) == 'D') 
		departuresList.registerFlightDelay(positionOfFlight, newTiming);
	else 
		arrivalsList.registerFlightDelay(positionOfFlight, newTiming);
	return SUCCESS;
}

int main() {
	cout << "Welcome to Larnaca Airport Flight Control v1.0!\n\nSelect an option below\n";
	MainApplication app;
	app.mainMenu();
	app.insertSelection();
	app.checkSelection();
	app.mainParse();
}