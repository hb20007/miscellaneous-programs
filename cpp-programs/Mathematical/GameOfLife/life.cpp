// @hb20007

#include "life.h"

Life::Life() {
	setmaxrow(defaultrownum); 
	setmaxcol(defaultcolnum);
} //In my variation of the program the bounds of the 2D array are instance variables in the Life class. They are initialized to constant values with the default numbers of rows and columns using the setmaxcol() and setmaxrow() methods

void Life::initialize() { // Allows the user to initialize the Life grid with alive cells in the desired locations
	zeroGrid(); 
	int row = 0, col = 0; //arbitrary initializations
	cout << "\nEnter coordinate pairs of initial living cells and finish with -1 -1\n> ";
	while ((row != -1) && (col != -1)) {
		cin >> row >> col;
		if ((row == -1) && (col == -1))
			cout << "\nDone\n\n";
		else if (((col < 0) || (col >= getmaxcol())) && (row < 0) || (row >= getmaxrow())) //This if statement is placed before the subsequent 2 statements in the if.. else if sequence because if both the row and column are greater than the maximum allowed value, we want only this message to be displayed
			cout << "\nRow and column out of range. Try again\n\n";
		else if ((row < 0) || (row >= getmaxrow()))
			cout << "\nRow out of range. Try again\n\n";
		else if ((col < 0) || (col >= getmaxcol()))
			cout << "\nColumn out of range. Try again\n\n";
		else
			grid[row][col] = ALIVE; 
	}
}

void Life::print() const { // Displays the alive and dead cells as a grid
	for (int row = 0; row < getmaxrow(); row++) {
		for (int col = 0; col < getmaxcol(); col++)
			if (grid[row][col] == ALIVE)
				cout << "*";
			else cout << "-"; // "-" is a placeholder for dead cells
		cout << endl;
	}
	cout << endl;
}

int Life::neighbor_count(int row, int col) const { //Counts the number of alive neighbors for the cell with the given row and column index
	int count = 0;
	for (int i = row - 1; i <= row + 1; i++) {
		if (i < 0 || i >= getmaxrow()) //If the row coordinate is out of range 
			continue;
		for (int j = col - 1; j <= col + 1; j++) {
			if (((i == row) && (j == col)) || j < 0 || j >= getmaxcol()) //If the cell we are on is the cell for which we are counting neighbors, or if the column coordinate is out of range 
				continue;
			if (grid[i][j] == ALIVE) //If the neighbor cell is alive, the count is incremented 
				count++;
		}
	}
	return count;
}

void Life::update() { //Updates the grid when going to the next generation
	Status newGrid[maxrownum][maxcolnum];
	for (int row = 0; row < getmaxrow(); row++)  
		for (int col = 0; col < getmaxcol(); col++) {
			if ((neighbor_count(row, col) == 3) || ((grid[row][col] == ALIVE) && (neighbor_count(row, col) == 2))) //If the cell is dead/alive and has 3 neighbors or if the cell is alive and has 2 neighbors, it will be alive in the next generation
				newGrid[row][col] = ALIVE;
			else
				newGrid[row][col] = DEAD;
	}
	copy2DArrays(grid, newGrid, getmaxrow(), getmaxcol()); //A function I have defined in utilities.cpp which copies the second 2D array into the first and also takes as arguments the number of rows and columns of the arrays
}

void Life::zeroGrid() { //Initializes the grid to all dead cells
	int row, col;
	for (row = 0; row < getmaxrow(); row++)
		for (col = 0; col < getmaxcol(); col++)
			grid[row][col] = DEAD;
}

void Life::setmaxrow(int row) { //Mutator method for the maxrow instance variable which represents the number of rows in the grid
	maxrow = row;
}

void Life::setmaxcol(int col) { //Mutator method for the maxcol instance variable which represents the number of cols in the grid
	maxcol = col;
}

int Life::getmaxrow() const { //maxrow accessor method
	return maxrow;
}

int Life::getmaxcol() const {//maxcol accessor method
	return maxcol;
}

void welcome() {
	cout << "Welcome to the game of life!\n\n";
}

