#include "FlightRec.h"

// Returns 1 if TimeRec1 is greater than TimeRec2, -1 if TimeRec2 is greater and 0 if they are equal
int timeRecComp(const TimeRec &timeRec1, const TimeRec &timeRec2) { 
	if (timeRec1.hour > timeRec2.hour)
		return 1;
	else if (timeRec1.hour < timeRec2.hour)
		return -1;
	else if (timeRec1.min > timeRec2.min)
		return 1;
	else if (timeRec1.min < timeRec2.min)
		return -1;
	else if (timeRec1.sec > timeRec2.sec)
		return 1;
	else if (timeRec1.sec < timeRec2.sec)
		return -1;
	else return 0;
}