#include "List.h"

List::List() {
	head = nullptr;
}

bool List::empty() {
	return head == nullptr;
}

//If FAIL is returned, it signifies overflow
errorCode List::append(const FlightRec &item) {
	Node *temp = new Node(item);
	if (temp == nullptr)
		return FAIL;
	if (empty())
		head = temp;
	else {
		Node *i = head;
		for (i; i->next != nullptr; i = i->next);
		i->next = temp;
	}
	return SUCCESS; 
}

//If FAIL is returned, it means that the flight number was not found
errorCode List::searchByFlightNo(int &positionInList, const char flightNum[10]) {
	Node *c = head;
	int counter = 0;
	for (c; c != nullptr; c = c->next) {
		string str1(c->flight.flightNo); // The string constructor is used to convert the c-strings into C++ strings to make comparing them easier
		string str2(flightNum);
		if (str1 == str2) {
			positionInList = counter;
			return SUCCESS;
		}
		counter++;
	}
	return FAIL;
}

int List::size() {
	int counter = 0;
	for (Node *t = head; t != nullptr;t = t->next)
		counter++;
	return counter;
}

// The flight index is guaranteed to not be out of bounds because in this program the flight index is always derived from the searchByFlightNo() method
void List::cancelFlight(const int &flightIndex) {
	Node *tempNode = head;
	if (flightIndex == 0) { // If the first flight is to be deleted
		head = head->next;
		delete tempNode;
		return;
	}
	for (int i = 1; i < flightIndex; i++)
		tempNode = tempNode->next;
	Node *toDelete = tempNode->next;
	tempNode->next = tempNode->next->next;
	delete toDelete;
	return;
}

void List::modifyFlightTime(const int &flightIndex, const TimeRec &newTime) {
	Node *tempNode = head;
	for (int i = 0; i < flightIndex; i++)
		tempNode = tempNode->next;
	tempNode->flight.time = newTime;
	return;
}

void List::registerFlightDelay(const int &flightIndex, const TimeRec &arrivalTimeWithDelay) {
	if (flightIndex >= size())
		return;
	Node *tempNode = head;
	for (int i = 0; i < flightIndex; i++)
		tempNode = tempNode->next;
	tempNode->flight.delay = true;
	tempNode->flight.expectedTime = arrivalTimeWithDelay;
	return;
}

// When this method is first called, left = 0 and right = upper bound of array
// The algorithm used is quicksort.
void List::sortByFlightNo(const int &left, const int &right) {
	int i = left, j = right, pivotIndex = (left + right) / 2;
	Node *tmp = new Node;
	Node *pivot = head; // The pivotIndex is the index of the pivot element in the list and pivot is a pointer pointing to the pivot element
	for (int c = 0; c < pivotIndex; c++) // The pivot pointer is made to point at the pivot element
		pivot = pivot->next;
	Node *ithElement = head;
	for (int c = 0; c < i; c++) // The ith element pointer is made to point at the right element
		ithElement = ithElement->next;
	Node *jthElement = head; 
	for (int c = 0; c < j; c++) // The jth element pointer is made to point at the right element
		jthElement = jthElement->next;
	while (i <= j) { // The algorithm begins
		while (_stricmp(ithElement->flight.flightNo, pivot->flight.flightNo) < 0) { // The method used returns a value less than 0 if the first string is less than the second, and a positive value if the second string is greater
			i++;
			ithElement = ithElement->next;
		} 
		while (_stricmp(jthElement->flight.flightNo, pivot->flight.flightNo) > 0) { // _stricmp() is used instead of strcmp() because it ignores case. This is because the user may insert flight numbers where the letters are not capitalized
			j--;
			jthElement = head; // There is no pointer pointing to the previous element to go backward so I need to go back to head in order to go to the previous element
			for (int c = 0; c < j; c++)
				jthElement = jthElement->next;
		}
		if (i <= j) { // The ith and jth element are switched with the help of the temp pointer and then i is incremented and j is decremented and the ithElement and jthElement pointers are adjusted accordingly
			tmp->flight = ithElement->flight;
			ithElement->flight = jthElement->flight;
			jthElement->flight = tmp->flight;
			i++;
			ithElement = ithElement->next;
			j--;
			jthElement = head; 
			for (int c = 0; c < j; c++)
				jthElement = jthElement->next;
		}
	}
	if (left < j)
		sortByFlightNo(left, j);
	if (i < right)
		sortByFlightNo(i, right);
}

// Works in exactly the same way as the sortByFlightNo() method
void List::sortByTime(const int &left, const int &right) {
	int i = left, j = right, pivotIndex = (left + right) / 2;
	Node *tmp = new Node;
	Node *pivot = head;
	for (int c = 0; c < pivotIndex; c++)
		pivot = pivot->next;
	Node *ithElement = head;
	for (int c = 0; c < i; c++)
		ithElement = ithElement->next;
	Node *jthElement = head;
	for (int c = 0; c < j; c++)
		jthElement = jthElement->next;
	while (i <= j) {
		while (timeRecComp(ithElement->flight.time, pivot->flight.time) < 0) { // timeRecComp() is a function that compares the TimeRecs
			i++;
			ithElement = ithElement->next;
		}
		while (timeRecComp(jthElement->flight.time, pivot->flight.time) > 0) {
			j--;
			jthElement = head; 
			for (int c = 0; c < j; c++)
				jthElement = jthElement->next;
		}
		if (i <= j) {
			tmp->flight = ithElement->flight;
			ithElement->flight = jthElement->flight;
			jthElement->flight = tmp->flight;
			i++;
			ithElement = ithElement->next;
			j--;
			jthElement = head;
			for (int c = 0; c < j; c++)
				jthElement = jthElement->next;
		}
	}
	if (left < j)
		sortByTime(left, j);
	if (i < right)
		sortByTime(i, right);
}

void List::printFlights() {
	Node *c = head;
	for (c; c != nullptr; c = c->next) {
		cout << c->flight.flightNo << "\t\t";
		cout << setw(10) << setfill(' ') << c->flight.city << "\t\t"; // setfill(' ') is neccessary because when the function is executed the second time the fill will have been set to '0' because of the code below
		cout << setw(2) << setfill('0') << c->flight.time.hour << ':' << setw(2) << setfill('0') << c->flight.time.min << "\t\t";
		if (c->flight.delay == true) 
			cout << "Yes\t\t" << setw(2) << setfill('0') << c->flight.expectedTime.hour << ':' << setw(2) << setfill('0') << c->flight.expectedTime.min;
		cout << endl;
	}
}

void List::printFlightsNotCompletedYet (TimeRec timeNow) {
	Node *c = head;

	for (c; c != nullptr; c = c->next) { // The flight's time taking into account any delay is compared to the current time before displaying it
		if (!c->flight.delay) {
			if (timeRecComp(c->flight.time, timeNow) < 0)
				continue;
		}
		else if (timeRecComp(c->flight.expectedTime, timeNow) < 0)
			continue;
	
		cout << c->flight.flightNo << "\t\t";
		cout << setw(10) << setfill(' ') << c->flight.city << "\t\t";
		cout << setw(2) << setfill('0') << c->flight.time.hour << ':' << setw(2) << setfill('0') << c->flight.time.min << "\t\t";
		if (c->flight.delay == true)
			cout << "Yes\t\t" << setw(2) << setfill('0') << c->flight.expectedTime.hour << ':' << setw(2) << setfill('0') << c->flight.expectedTime.min;
		cout << endl;
	}
}

string List::toString() {
	string allFlights = "";
	Node *c = head;
	for (c; c != nullptr; c = c->next) {
		stringstream ss;
		allFlights += c->flight.flightNo;
		allFlights += ' ';
		allFlights += c->flight.city;
		allFlights += ' ';
		ss << setfill('0') << setw(2) << c->flight.time.hour << ' ';
		ss << setfill('0') << setw(2) << c->flight.time.min << ' ';
		ss << setfill('0') << setw(2) << c->flight.time.sec << ' ';
		if (!c->flight.delay)
			ss << 0;
		else {
			ss << "1 ";
			ss << setfill('0') << setw(2) << c->flight.expectedTime.hour << ' ';
			ss << setfill('0') << setw(2) << c->flight.expectedTime.min << ' ';
			ss << setfill('0') << setw(2) << c->flight.expectedTime.sec;
		}
		allFlights += ss.str(); // The integers were first added to the string stream with the right formatting and then the string value of the stream is concatenated to allFlights
		if (c->next != nullptr) // Creates a new line at the end of each flight record except for the last
			allFlights += '\n';
	}
	return allFlights;
}