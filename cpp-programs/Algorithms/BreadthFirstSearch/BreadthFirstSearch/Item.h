/**
* Item.h
* The Item class defining the attributes of an item
*
* @author hb20007
* @version 1.0 04/12/2016
*/

#pragma once
#include "Locations.h"
using std::string;

class Item 
{
private:
	string itemName;
	string itemLocation;
public:
	Item(const string& name);
	Item(const string& name, const string& location);

	/**
	*	itemName accessor method
	*
	*   @returns The name of the item
	*/
	string name() const;
	/**
	*	itemLocation accessor method
	*
	*   @returns The location
	*/
	string location() const;

	/**
	*	Sets the location of the item to a new location
	*
	*   @param newLocation The new location
	*/
	void relocate(const string& newlocation);
};