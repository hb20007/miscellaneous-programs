#pragma once

void displayMenu(); // Prints the menu
void respondToSelection(const char &userSelection); // Does appropriate action based on user selection
void runGame(); // Runs the main game
void displayInstructions(); // Prints the rules of the game
void printMoveCount(const int &moves, const int &difficulty); // Prints the number of moves the user has made so far
int getDesiredDifficulty(); // Retrieves the user's input for difficulty
void continueOrQuit(); // User selection of proceeding or exiting