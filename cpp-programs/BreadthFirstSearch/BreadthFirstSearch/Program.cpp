#include "Program.h"
#include <iostream>
#include <algorithm> // For transform()
#include <vector>
#include <queue>
using std::cout;
using std::endl;

int main()
{
	bool exitFlag = false;
	do // The do while loop is used along with the exitFlag to restart the program when needed. The program repeats to the main menu until the user chooses to exit
	{
		if (showMenuAndGetSelection() == 1)
		{
			Robot robbie; // The new keyword is not used in order to avoid manual storage duration. The default constructor is called.
			Item juice("juice"), soup("soup");

			vector<string> locationData = Utilities::getDataAndSplitIntoTokens(DATA_FILE_NAME);
			if (locationData.empty())  // If the data failed to be loaded
				std::cerr << "The file " + DATA_FILE_NAME + " was not found or was empty\n\n";
			else // If the data was successfully loaded
			{
				initializeEntityLocations(locationData, robbie, juice, soup);
				printProblemSummary(robbie, juice, soup);
				Node start(nullptr, "Start", robbie.location(), juice.location(), soup.location());
				Node goal(nullptr, "This is a goal Node made only for comparison purposes", TABLE, TABLE, TABLE);
				queue<Node> openList;
				vector<Node> closedList;
				performBFS(start, goal, openList, closedList);
			}
		}
		else // If the user chooses menu option 2 ie. Exit
			exitFlag = true;
	} while (!exitFlag);
}

static void displayMenu()
{
	cout << "1. Run scenario\n";
	cout << "2. Exit\n\n";
}

static int showMenuAndGetSelection()
{
	string menuSelection;
	do // Input validation
	{
		//system("cls");
		displayMenu();
		cout << "Select an item\n> ";
		std::getline(std::cin, menuSelection);
	} while (!Utilities::isValidIntegerAndInRequiredRange(menuSelection, 1, NUMBER_OF_MENU_OPTIONS));
	return stoi(menuSelection);
}

static string stringToLocationConst(const string& location)
{
	if (location == "table")
		return TABLE;
	if (location == "fridge")
		return FRIDGE;
	return STOVE;
}

void initializeEntityLocations(vector<string> data, Robot& robbie, Item& juice, Item& soup)
{
	for (unsigned int i = 0; i < data.size(); i++)
	{
		transform(data.at(i).begin(), data.at(i).end(), data.at(i).begin(), ::tolower); // Tranforms string to lower case
		if (data.at(i) == "robot")
			robbie.relocate(stringToLocationConst(data.at(i + 1))); // The relocate() method is used to initialize the robot's location to the entry in the vector of strings after the word "robot"
		else if (data.at(i) == "juice")
			juice.relocate(stringToLocationConst(data.at(i + 1))); // The relocate() method is used to initialize the juice's location
		else if (data.at(i) == "soup")
			soup.relocate(stringToLocationConst(data.at(i + 1))); // The relocate() method is used to initialize the soup's location
	}
}

void printProblemSummary(Robot robbie, Item juice, Item soup)
{
	cout << "\n INITIAL STATE\n";
	cout << "-----------------\n";
	cout << "ENTITIY\tLOCATION\n";
	cout << "Robbie\t" + robbie.location() << endl;
	cout << "Juice\t" + juice.location() << endl;
	cout << "Soup\t" + soup.location() << endl;
	cout << "\n  GOAL STATE\n";
	cout << "-----------------\n";
	cout << "ENTITY\tLOCATION\n";
	cout << "Robbie\t" + TABLE << endl;
	cout << "Juice\t" + TABLE << endl;
	cout << "Soup\t" + TABLE << endl;
}

bool isNewState(const string& robbieLocation, const string& juiceLocation, const string& soupLocation, const vector<Node>& closedList)
{
	for (Node closedNode : closedList)
		if (closedNode.rLocation() == robbieLocation && closedNode.jLocation() == juiceLocation && closedNode.sLocation() == soupLocation)
			return false;
	return true;
}

void addChildNodeIfNewState(Node* parent, queue<Node>& openList, const string& description, const string& robbieLocation, const string& juiceLocation, const string& soupLocation, const vector<Node>& closedList)
{
	if (isNewState(robbieLocation, juiceLocation, soupLocation, closedList))
	{
		Node child(parent, description, robbieLocation, juiceLocation, soupLocation);
		openList.push(child);
	}
}

void expandNextNode(queue<Node>& openList, vector<Node>& closedList)
{
	Node *toExpand = new Node(openList.front());
	openList.pop();
	closedList.push_back(*toExpand);

	Robot robbie(toExpand->rLocation());
	Item juice("juice", toExpand->jLocation()), soup("soup", toExpand->sLocation());

	// Actions not useful in the problem are not considered by the algorithm in the code below. Specifically, carrying an item to a location which is not the table and moving to the table without carrying an item are useless in solving the problem and are not examined

	// Carry actions
	if (robbie.location() != TABLE && robbie.location() == juice.location())
		addChildNodeIfNewState(toExpand, openList, robbie.carry(juice, TABLE), TABLE, TABLE, soup.location(), closedList);
	else if (robbie.location() != TABLE && robbie.location() == soup.location())
		addChildNodeIfNewState(toExpand, openList, robbie.carry(soup, TABLE), TABLE, juice.location(), TABLE, closedList);
	// Move actions
	if (robbie.location() != FRIDGE)
		addChildNodeIfNewState(toExpand, openList, robbie.move(FRIDGE), FRIDGE, juice.location(), soup.location(), closedList);
	if (robbie.location() != STOVE)
		addChildNodeIfNewState(toExpand, openList, robbie.move(STOVE), STOVE, juice.location(), soup.location(), closedList);
}

void performBFS(const Node& start, const Node& goal, queue<Node>& openList, vector<Node>& closedList)
{
	openList.push(start);
	while (!openList.empty() && openList.front() != goal) // !openList.empty() must precede openlist.front() != goal in the AND clause
		expandNextNode(openList, closedList);
	if (openList.empty())
		cout << "\nThe state space was exhausted, the open list is empty and the goal state was not found for the scenario given.\n\nGoing back to main menu...\n\n";
	else // If the open list is not empty at this point, the front element is the goal
	{
		cout << "\nSuccess!\n\nSOLUTION BY BFS:\n";
		Node foundGoal = openList.front();
		closedList.push_back(foundGoal); // The goal is added to the closed list because the order of expansion may be printed by the program later
		vector<Node> pathToGoal;
		for (Node* i = &foundGoal; i != nullptr; i = i->parent)
			pathToGoal.push_back(*i);
		reverse(pathToGoal.begin(), pathToGoal.end()); // Reversing the path to goal from goal -> start to start -> goal serves 2 purposes: 1. So that the path is printed in the correct order. 2. When the parent pointer is for the nodes in the pathToGoal vector when iterating through them, they will be deleted in the order which does not create dangling pointers and hence having memory leaks
		for (unsigned int i = 0; i < pathToGoal.size(); i++)
		{
			Node *n = &pathToGoal[i];
			cout << i + 1 << ". " << n->description() << endl;
			delete n->parent;
		}
		// The commented-out code below would print the order of nodes expanded until the goal from the closed list
		//cout << "\nORDER OF NODE EXPANSION:\n";
		//for (unsigned int j = 0; j < closedList.size(); j++) // This is preferred over for (Node n : closedList) in order to display increasing numbers
		//{
		//	cout << j + 1 << ". " << closedList.at(j).description() << endl;
		//}
		cout << "\nGoing back to main menu...\n\n";
	}
}