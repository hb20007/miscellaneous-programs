#pragma once

enum FlightType {
	DEPARTURE, ARRIVAL
};

struct TimeRec {
	int hour; // 0 to 23
	int min; // 0 to 59
	int sec; // 0 to 59
};

int timeRecComp(const TimeRec &timeRec1, const TimeRec &timeRec2); //A function for comparing two TimeRecs. 

struct FlightRec {
	char flightNo[10];
	char city[30];
	TimeRec time;
	FlightType fType;
	bool delay;
	TimeRec expectedTime; // If the flight is delayed
};

