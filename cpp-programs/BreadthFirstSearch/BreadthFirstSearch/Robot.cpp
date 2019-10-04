#include "Robot.h"

Robot::Robot(const string& location)
{
	robotLocation = location;
}

string Robot::location() const
{
	return robotLocation;
}

string Robot::move(const string& newLocation) const
{
	return "Move to " + newLocation;
}

string Robot::carry(Item& item, const string& newLocation) const
{
	return "Carry " + item.name() + " to " + newLocation;
}

void Robot::relocate(const string& newLocation)
{
	robotLocation = newLocation;
}
