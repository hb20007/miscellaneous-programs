#include "Item.h"
#include <string>

Item::Item(const string& name)
{
	itemName = name;
}

Item::Item(const string& name, const string& location)
{
	itemName = name;
	itemLocation = location;
}

string Item::name() const
{
	return itemName;
}

string Item::location() const
{
	return itemLocation;
}

void Item::relocate(const string& newLocation)
{
	itemLocation = newLocation;
}