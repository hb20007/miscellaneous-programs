/**
* Node.h
* The Node data structure class
*
* @author hb20007
* @version 1.0 04/12/2016
*/

#pragma once
#include "Robot.h"
#include "Item.h"

class Node
{
private:
	string robbieLocation;
	string juiceLocation;
	string soupLocation;

	/**
	*	Description of the operation associated with this node
	*/
	string operationDescription;
public:
	/**
	*	A pointer to the parent node
	*/
	Node* parent;

	Node(Node* parentNode, const string& description, const string& robbieLocation, const string& juiceLocation, const string& soupLocation);

	/**
	*	robbieLocation accessor method
	*
	*   @returns Robbie's location
	*/
	string rLocation() const;

	/**
	*	juiceLocation accessor method
	*
	*   @returns The location of the juice
	*/
	string jLocation() const;

	/**
	*	soupLocation accessor method
	*
	*   @returns The location of the soup
	*/
	string sLocation() const;

	/**
	*	operationDescription accessor method
	*
	*   @returns The description
	*/
	string description() const;

	/**
	*	Overriding the == operator to allow comparing two Nodes
	*
	*   @returns true if the Nodes are deemed to be equal, else false
	*/
	bool operator == (Node operand) const; // const Node& was not used because operand would then not be able to call its member functions

	/**
	*	Overriding the != operator to allow comparing two Nodes
	*
	*   @returns true if the Nodes are deemed to be inequal, else false
	*/
	bool operator != (Node operand) const;
};