#pragma once

#include <stack>
using namespace std;

enum errorCode {
	SUCCESS, FAILURE
};

struct Coordinate {
	int row, col;
}; // A move is simply a coordinate chosen by the user

class TargetNine {
public:
	TargetNine(); //Calls all9s() to set the value of all cells in the grid to 9s
	void all9s(); // Sets the values in all cells of the grid to 9s
	void initialize(const int &diffic); // Initializes the grid based on difficulty. Uses helper functions getRandomCell() and subtract1RowColumn()
	bool victory() const; // Checks if the player has completed the game
	errorCode undo(); // Go back one step
	errorCode redo(); // Go forwards one step
	void registerMove(const Coordinate &move); // One is added to all the cells in the same row or column as the selected cell. Uses helper function setCell()
	void displayGrid() const; // Prints the integer grid
private:
	int grid[3][3]; // The 3x3 integer grid that forms the basis of the game
	stack<Coordinate> undoStack; // A stack with the moves made by the user
	stack<Coordinate> redoStack; // A stack with the moves that have been undone
	Coordinate getRandomCell() const; // Returns the coordinate of a random cell from the grid
	void subtract1RowColumn(const Coordinate &random); // Subtracts 1 from all the cells in the same row or column as the designated cell. Uses helper function setCell()
	void setCell(const Coordinate &location, const int &value); // The value passed is inserted in the cell corresponding to the row and column dimensions
	void setCell(const int &rowNumber, const int &columnNumber, const int &value); // If the client wishes to provide the row and column numbers as-is instead of using the Coordinate struct
	int cellValue(const Coordinate &location) const; // Returns the value of the cell with certain row and column dimensions
	int cellValue(const int &rowNumber, const int &columnNumber) const; // If the client wishes to provide the row and column numbers 
};
