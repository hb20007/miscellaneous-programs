/**
* Program.h
* Contains functions and constants related to the running of the program
*
* @author hb20007
* @version 1.0 26/12/2016
*/

#pragma once
#include "Item.h"
#include "Locations.h"
#include "Robot.h"
#include "Node.h"
#include "Utilities.h"
#include <queue>
using std::vector;
using std::queue;

/**
*	The number of possible options in the main menu (useful for input validation)
*/
const static int NUMBER_OF_MENU_OPTIONS = 2;

/**
*	The name of the file with the data about the initial location of the items
*/
const static string DATA_FILE_NAME = "Scenario.csv";

/**
*	Prints the main menu
*/
static void displayMenu();

/**
*	Calls displayMenu() and validates the input until a valid menu selection is made
*
*   @returns The user's selection from the menu
*/
static int showMenuAndGetSelection();

/**
*	Converts a given string describing a location in the program to one of the constants in Locations.h
*
*   @param location The location as a string
*   @returns The location as one of the constants defined in Locations.h
*/
static string stringToLocationConst(const string& location);

/**
*	Sets the Location of the entities in the program based on the data passed in as a vector of strings
*
*	@param data The location data in the form of a vector of strings
*	@param robbie The robot in the scenario
*	@param juice The first item in the scenario
*	@param soup The second item in the scenario
*/
void initializeEntityLocations(vector<string> data, Robot& robbie, Item& juice, Item& soup);

/**
*	Prints a summary of the problem
*
*	@param robbie The robot in the scenario
*	@param juice The first item in the scenario
*	@param soup The second item in the scenario
*/
void printProblemSummary(Robot robbie, Item juice, Item soup);

/**
*   Checks if the state passed in has been encountered before
*
*	@param robbieLocation The location of the robot
*	@param juiceLocation The location of the juice
*	@param soupLocation The location of the soup
*   @param closedList The list of closed Nodes (states already examined)
*/
bool isNewState(const string& robbieLocation, const string& juiceLocation, const string& soupLocation, const vector<Node>& closedList);

/**
*   Adds the state passed in as a Node in the open list if it's new
*
*	@param parent A pointer to the parent Node
*	@param openList The open list
*	@param description The description associated with the state being passed in
*	@param robbieLocation The location of the robot
*	@param juiceLocation The location of the juice
*	@param soupLocation The location of the soup
*   @param closedList The list of closed Nodes (states already examined)
*/
void addChildNodeIfNewState(Node* parent, queue<Node>& openList, const string& description, const string& robbieLocation, const string& juiceLocation, const string& soupLocation, const vector<Node>& closedList);

/**
*   Expands the front node in the open queue, pops it from the queue and adds its children to the openlist if they represent new states.
*	Order of operations used: carry, move
*
*	@param openList The open list
*   @param closedList The list of closed Nodes (states already examined)
*/
void expandNextNode(queue<Node>& openList, vector<Node>& closedList);

/**
*   The front node of the open list is expanded until the goal is found or the list becomes empty. If the goal is found the operations are printed, else a suitable message is printed
*
*	@param start The start Node with the initial state
*	@param goal The goal state
*	@param openList The open list
*   @param closedList The list of closed Nodes (states already examined)
*/
void performBFS(const Node& start, const Node& goal, queue<Node>& openList, vector<Node>& closedList);
