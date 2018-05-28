/*
*  Target 9 Game
*  @hb20007
*/

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#include "RunApplication.h"
#include "Target9.h"
#include "Utilities.h"

int main() {
	srand(unsigned int(time(0)));
	string selection;
	displayMenu();
	cin >> selection;
	while ((selection.length() > 1) || selection.at(0) > '3' || selection.at(0) < '1') { // Deals with all possibilites of incorrect input
		cout << "\nInput error: Please insert a number from 1-3\n\n> ";
		cin >> selection;
	}
	respondToSelection(selection.at(0));
}

void displayMenu() {
	cout << "Welcome to Target 9!\n\nSelect an option below...\n\n";
	cout << "1. Start game\n";
	cout << "2. Instructions\n";
	cout << "3. Quit\n\n> ";
}

void respondToSelection(const char &userSelection ) {
	switch (userSelection) {
	case '1':
		runGame();
		break;
	case '2':
		displayInstructions();
	} // If the user has selected 3, the program will terminate at this point
}

void runGame() {
	TargetNine t9;
	bool firstRun = true;
	int movesMade = 0, difficulty = getDesiredDifficulty();
	t9.initialize(difficulty);
	while (!t9.victory()) {
		t9.displayGrid();
		printMoveCount(movesMade, difficulty);
		string moveInput;
		cout << "Make a move (or type undo/redo)\n> ";
		if (firstRun) {
			cin.ignore(); //cin.ignore() only needs to be called the first time the while loop is executed because of a previous usage of cin >>. I needed to use a flag instead of checking if movesMade == 0 because if the user types undo on the first move it is not registered as a move but cin.ignore() is executed.
			firstRun = false;
		}
		getline(cin, moveInput);
		ltrim(moveInput);
		rtrim(moveInput); // The string is trimmed to get rid of leading/terminating zeros the user might have included by mistake
		while ((((moveInput.length() != 3)) || moveInput.at(1) != ' ' || moveInput.at(0) > '2' || moveInput.at(0) < '0' || moveInput.at(2) > '2' || moveInput.at(2) < '0') && ((moveInput != "undo") && (moveInput != "redo"))) { // Deals with all possibilites of incorrect input (ie. user input is not a valid move AND not a valid keyword (undo/redo)
			cout << "\nInput error: Please insert a valid coordinate for a cell (eg. 0 1)\nor one of the keywords undo/redo\n\n> ";
			getline(cin, moveInput);
		}
		if (moveInput == "undo")
			if (t9.undo() == FAILURE)
				cout << "\nError: There are no moves to undo\n\n";
			else
				movesMade++; //An undo or redo is considered a move
		else if (moveInput == "redo")
			if (t9.redo() == FAILURE)
				cout << "\nError: There are no moves to redo\n\n";
			else
				movesMade++;
		else {
			Coordinate move;
			move.row = moveInput.at(0) - 48;
			move.col = moveInput.at(2) - 48;
			t9.registerMove(move);
			movesMade++;
		}
	}
	t9.displayGrid();
	if (movesMade == difficulty)
		cout << "\nCongratulations!\nYou completed the puzzle in the minimum number of moves possible\n\n";
	else
		cout << "\nGood job.\nA better solution would have been possible in " << difficulty << " moves\n\n";
	cout << "Insert 1 to start a new game or 2 to exit\n\n> ";
	continueOrQuit();
}

void displayInstructions() {
	cout << "\n\nINSTRUCTIONS\n\n";
	cout << "A Target 9 game is set on a 3x3 grid of integers.\n";
	cout << "The game starts with an initial random configuration of digits.\n\n";
	cout << "Each puzzle has a solution with an ideal minimum number of moves\ndetermined by its difficulty.\n\n";
	cout << "In order to make a move, insert the coordinates of a cell separated by a space.\n\n";
	cout << "For instance, 0 1 means you have selected the cell in row 0 and column 1.\n\n";
	cout << "Once you select a cell, all the cells in the same same row\nand column (including itself) are incremented by 1.\n\n";
	cout << "Your task is to change all of the cells to 9.\n\n\n";
	cout << "Are you ready? Type 1 to start game or 2 if you would like to exit\n\n> ";
	continueOrQuit();
}

void printMoveCount(const int &moves, const int &difficulty) {
	cout << "\nMoves made: " << moves << endl; 
	if (difficulty == 1) // The case where difficulty == 1 is treated separately in order to display the singular of the word "move"
		cout << "Best Solution: 1 move\n\n";
	else
		cout << "Best Solution: " << difficulty << " moves\n\n";
}

int getDesiredDifficulty() {
	string inputDifficulty;
	cout << "\nInsert desired difficulty (1-9)\n\n> ";
	cin >> inputDifficulty;
	while ((inputDifficulty.length() > 1) || inputDifficulty.at(0) > '9' || inputDifficulty.at(0) < '1') {
		cout << "\nInput error: Please insert a number from 1-9\n\n> ";
		cin >> inputDifficulty;
	}
	return (int)(inputDifficulty.at(0) - 48); // '1' has ASCII code 49
}

void continueOrQuit() {
	string selection;
	cin >> selection;
	while ((selection.length() > 1) || selection.at(0) > '2' || selection.at(0) < '1') {
		cout << "\nInput error: Please insert a number from 1-2\n\n> ";
		cin >> selection;
	}
	if (selection.at(0) == '1') runGame(); // Program exits if the user's selection were 2
}