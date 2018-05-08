#include "Target9.h"
#include "Utilities.h"
#include <iostream>
using namespace std;

TargetNine::TargetNine() {
	all9s();
}

void TargetNine::all9s() {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			setCell(i, j, 9);
}

void TargetNine::initialize(const int &diffic) {
	for (int i = 0; i < diffic; i++)
		subtract1RowColumn(getRandomCell());
}

bool TargetNine::victory() const {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			if (cellValue(i,j) != 9)
				return false;
	}
	return true;
}

errorCode TargetNine::undo() {
	if (undoStack.empty()) return FAILURE;
	Coordinate moveToUndo = undoStack.top();
	subtract1RowColumn(moveToUndo);
	undoStack.pop();
	redoStack.push(moveToUndo);
	return SUCCESS;
}

errorCode TargetNine::redo() {
	if (redoStack.empty()) return FAILURE;
	Coordinate moveToRedo = redoStack.top();
	registerMove(moveToRedo); // No need for undoStack.push(moveToRedo); because the function registerMove() (unlike subtract1RowColumn) pushes the move into the undo stack by itself
	redoStack.pop();
	return SUCCESS;
}

void TargetNine::registerMove(const Coordinate &move) {
	for (int i = 0; i < 3; i++)
		setCell(i, move.col, mod((cellValue(i, move.col) + 1), 10)); // The cell is assigned a value using setCell() which is equal to its cellValue() - 1. mod 10 is used because after a cell's value goes higher than 9, it should become 0
	for (int j = 0; j < 3; j++) {
		if (j == move.col); // if we have landed on the cell described by Coordiante random, nothing should be done because the cell has already been decremented by 1 in the previous for loop
		else
			setCell(move.row, j, mod((cellValue(move.row, j) + 1), 10));
	}
	undoStack.push(move);
}

void TargetNine::displayGrid() const {
	cout << endl;
	cout << "    0 1 2\n";
	cout << "    =====\n";
	for (int i = 0; i < 3; i++) {
		cout << i << "||" << " ";
		for (int j = 0; j < 3; j++)
			cout << cellValue(i,j) << " ";
		cout << endl;
	}
}

Coordinate TargetNine::getRandomCell() const {
	Coordinate randomC;
	randomC.row = rand() % 3;
	randomC.col = rand() % 3;
	return randomC;
}

void TargetNine::subtract1RowColumn(const Coordinate &random) {
	for (int i = 0; i < 3; i++)
		setCell(i, random.col, mod(((cellValue(i, random.col)) - 1), 10)); // The cell is assigned a value using setCell() which is equal to its cellValue() - 1
	for (int j = 0; j < 3; j++) {
		if (j == random.col) ; // if we have landed on the cell described by Coordiante random, nothing should be done because the cell has already been decremented by 1 in the previous for loop
		else 
			setCell(random.row, j, mod(((cellValue(random.row, j)) - 1), 10)); 
	}
}

void TargetNine::setCell(const Coordinate &location, const int &value) {
	grid[location.row][location.col] = value;
}

void TargetNine::setCell(const int &rowNumber, const int &columnNumber, const int &value) {
	grid[rowNumber][columnNumber] = value;
}

int TargetNine::cellValue(const Coordinate &location) const {
	return	grid[location.row][location.col];
}

int TargetNine::cellValue(const int &rowNumber, const int &columnNumber) const {
	return grid[rowNumber][columnNumber];
}