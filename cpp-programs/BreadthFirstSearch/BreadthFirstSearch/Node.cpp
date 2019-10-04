#include "Node.h"
#include <iostream>
#include <string>

Node::Node(Node* parentNode, const string& description, const string& robbieLocation, const string& juiceLocation, const string& soupLocation)
{
	this->parent = parentNode;
	this->operationDescription = description;
	this->robbieLocation = robbieLocation;
	this->juiceLocation = juiceLocation;
	this->soupLocation = soupLocation;
}

string Node::rLocation() const
{
	return robbieLocation;
}

string Node::jLocation() const
{
	return juiceLocation;
}

string Node::sLocation() const
{
	return soupLocation;
}

string Node::description() const
{
	return operationDescription;
}

bool Node::operator == (Node operand) const
{
	if (rLocation() == operand.rLocation() && jLocation() == operand.jLocation() && sLocation() == operand.sLocation())
		return true;
	return false;
}

bool Node::operator != (Node operand) const
{
	return !(*this == operand); // Uses the == defined in the previous function
}
