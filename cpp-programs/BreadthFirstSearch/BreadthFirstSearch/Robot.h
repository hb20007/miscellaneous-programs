/**
* Robot.h
* The Robot class defining the attributes and behavior of a robot
*
* @author hb20007
* @version 1.0 04/12/2016
*/

#pragma once
#include "Locations.h"
#include "Item.h"
using std::string;

class Robot
{
private:
	string robotLocation;
public:
	Robot() {};
	Robot(const string& location);
	/**
	*	robotLocation accessor method
	*
	*   @returns The location
	*/
	string location() const;

	/**
	*	Generates a string describing the movement of the robot to a new location
	*
	*   @param newLocation The new location
	*   @returns A string with the description of the action
	*/
	string move(const string& newLocation) const;

	/**
	*	Generates a string describing the robot carrying an item to a new location
	*
	*   @param newLocation The new location
	*	@returns A string with the description of the action
	*/
	string carry(Item& item, const string& newLocation) const;

	/**
	*	Sets the location of the robot to a new location
	*
	*   @param newLocation The new location
	*/
	void relocate(const string& newLocation);
};