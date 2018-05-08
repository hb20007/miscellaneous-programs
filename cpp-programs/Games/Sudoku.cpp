// Sudoku by @hb20007

// I decided to write my own sudoku from scratch for an extra challenge

#include <iostream>
#include <cstdlib> //used because I was initially working in another IDE where the system() function required this library
using namespace std;

const int sudokuSize = 9;
const int blockSize = 3;
const int emptyCellValue = 0; // empty cells are given the value '0'

int table[sudokuSize][sudokuSize] = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 }, { 6, 0, 0, 1, 9, 5, 0, 0, 0 }, { 0, 9, 8, 0, 0, 0, 0, 6, 0 }, { 8, 0, 0, 0, 6, 0, 0, 0, 3 }, { 4, 0, 0, 8, 0, 3, 0, 0, 1 }, { 7, 0, 0, 0, 2, 0, 0, 0, 6 }, { 0, 6, 0, 0, 0, 0, 2, 8, 0 }, { 0, 0, 0, 4, 1, 9, 0, 0, 5 }, { 0, 0, 0, 0, 8, 0, 0, 7, 9 } }; //my awesome sudoku game has only one puzzle
int solution[sudokuSize][sudokuSize] = { { 5, 3, 4, 8, 7, 8, 9, 1, 2 }, { 6, 7, 2, 1, 9, 5, 3, 4, 8 }, { 1, 9, 8, 3, 4, 2, 5, 6, 7 }, { 8, 5, 9, 7, 6, 1, 4, 2, 3 }, { 4, 2, 6, 8, 5, 3, 7, 9, 1 }, { 7, 1, 3, 9, 2, 4, 8, 5, 6 }, { 9, 6, 1, 5, 3, 7, 2, 8, 4 }, { 2, 8, 7, 4, 1, 9, 6, 3, 5 }, { 3, 4, 5, 2, 8, 6, 1, 7, 9 } }; //this array is used for comparison to check if the user soln is coorect

enum coordinate //used for the column coordinate of the cells
{
	A, B, C, D, E, F, G, H, I
};

bool validRow(const coordinate column, const int row,const int entry); //checks for conflicts in row
bool validColumn(const coordinate column, const int row, const int entry); // checks for conflicts in column
bool validBlock(const coordinate column, const int row, const int entry); //checks for conflicts in block
template <class firstCell> // used for the finction template 'firstCell' becuase I will use this function to work with multiple data types, namely int and coordinate
firstCell findFirstCell(firstCell num);
bool gameOver(); //checks if the end of the game is reached
void enterNumber(coordinate &column, int &row, int &entry); //allows user to cin their guess
void displaySudoku(); // displays the sudoku grid
void displayMenu(); //displays the menu
void playSudoku(); // initiates the game
void processEntry(const coordinate column, const int row, const int entry); // interprets the user's entry
void displayInstructions(); // displays instructions and then pauses and clears the screen
bool arraysIdentical2D(int array1[sudokuSize][sudokuSize], int array2[sudokuSize][sudokuSize]); // checks if 2 2D arrays are identical. Used to compare table** with solution**

bool validRow(coordinate column, int row, int entry)
{
	for (int i = 0; i <sudokuSize; i++)
	{
		if (i == column) break;
		if (table[row][i] == entry) return false; // row fixed, i loops
	}
	return true;
}

bool validColumn(coordinate column, int row, int entry)
{
	for (int j = 0; j <sudokuSize; j++)
	{
		if (j == row) break;
		if (table[j][column] == entry) return false; // column fixed, j loops
	}
	return true;
}

bool validBlock(coordinate column, int row, int entry)
{
	int rowIndex, columnIndex;
	rowIndex = findFirstCell(row);
	for (int x = 0; x < blockSize; x++)
	{
		columnIndex = findFirstCell(column); // NB: Resets columnIndex to enable looping at the next row
		for (int y = 0; y < blockSize; y++) // the x and y variables are used to achieve 3 repetitions. columnIndex and rowIndex cannot be used because they would be different depending on the block
		{
			if ((rowIndex != row) || (columnIndex != column)) // if it's a different cell than the one the user attempted to manipulate
			{
				if (table[rowIndex][columnIndex] == entry)
					return false;
			}
			columnIndex++;
		}
		rowIndex++;
	}
	return true;
}

template <class firstCell>
firstCell findFirstCell(firstCell num)
{
	switch (num)
	{
	case 0:
	case 1:
	case 2:
		return static_cast<firstCell>(0);
	case 3:
	case 4:
	case 5:
		return static_cast<firstCell>(3);
	case 6:
	case 7:
	default: // i.e. case 8
		return static_cast<firstCell>(6);
	}
}

bool gameOver()
{
	if (arraysIdentical2D(table, solution))
		return true;
	return false;
}

void enterNumber(coordinate &column, int &row, int &entry)
{
	const int AinASCII = 65;
	char column_temp;
	cout << "> ";
	cin >> column_temp >> row >> entry;
	if (entry > sudokuSize) // validation check. For example, in 9x9 sudoku, entries greater than 9 are not allowed.
	{
		cout << "\nEntries greater than " << sudokuSize << " do not exist in sudoku. What the hell!?\n\n";
		cout << "Insert your query again\n\n";
		enterNumber(column, row, entry);
	}
	else //else is neccessary due to the recursive call of enterNumber()
	{
		column_temp -= AinASCII;
		column = static_cast<coordinate>(column_temp);
		row--;
	}
}

void displaySudoku()
{
	system("cls");
	cout << "    A  B  C     D  E  F     G  H  I\n"; // column labels
	cout << "---------------------------------------\n";
	cout << "---------------------------------------\n";
	cout << "| |\t     |\t         |          | |\n| | ";
	for (int i = 0; i < sudokuSize; i++)
	{
		for (int j = 0; j < sudokuSize; j++)
		{
			if (table[i][j] == emptyCellValue) cout << "x"; //empty cells show 'x' as a placeholder value
			else
			{
				cout << table[i][j];
			}
			if (j == blockSize - 1) cout << "  |";
			if (j == (2 * blockSize) - 1) cout << "  |";
			if ((j == (sudokuSize - 1))) cout << " | | " << i + 1; // "i+1" : row labels
			else cout << "  ";
		}
		if (i == blockSize - 1)
		{
			cout << "\n| |\t     |\t         |          | | ";
			cout << "\n---------------------------------------";
		}
		if (i == (2 * blockSize) - 1)
		{
			cout << "\n| |\t     |\t         |          | | ";
			cout << "\n---------------------------------------";
		}
		if (i == (sudokuSize - 1)) cout << endl;
		else cout << "\n| |\t     |\t         |          | |\n| | ";   //The lines for the sudoku table are very precisely generated. The logic and endlines took my hours
	}
	cout << "| |\t     |\t         |          | |\n";
	cout << "---------------------------------------\n";
	cout << "---------------------------------------\n";
}

void displayMenu()
{
	cout << "Welcome to Extreme Sukoku by Hb20007\n\n";
	cout << "1. Start Game\n";
	cout << "2. Quit\n\n> ";
}

void playSudoku()
{
	coordinate column;
	int row, entry;
	while (!gameOver())
	{
		displaySudoku();
		cout << endl;
		enterNumber(column, row, entry);
		processEntry(column, row, entry);
	}
	cout << "CONGRATULATIONS!!! You just solved the Extreme Sukoku!@#@!#!#RDSAF\n\n"; //gameOver() becomes true only if the user's solution is correct
}

void processEntry(coordinate column, int row, int entry) // if all the validity checks are passed, the value is inserted to the sudoku array
{
	if ((table[row][column] != emptyCellValue))
		cout << "\nThe cell you tried to manipulate already has a number. Try again\n\n";
	else
	{
		if (!validColumn(column, row, entry))
			cout << "\nThere is a conflict in the column\n\nLook closely and you will find another " << entry << "\n\nIdiot\n\n";
		if (!validRow(column, row, entry))
			cout << "\nThere is a conflict in the row\n\nLook closely and you will find another " << entry << "\n\nIdiot\n\n";
		if (!validBlock(column, row, entry))
			cout << "\nThere is a conflict in the block\n\nLook closely and you will find another " << entry << "\n\nIdiot\n\n";
		if ((validColumn(column, row, entry) && validRow(column, row, entry) && validBlock(column, row, entry)))
			table[row][column] = entry;
	}
	cout << endl;
	system("pause");
	playSudoku();
}

void displayInstructions()
{
	cout << "\t\t\t-INSTRUCTIONS-\n\n\n";
	cout << "Use the following format to enter a number to the sudoku grid:\n\n";
	cout << "[Column Co-ordinate] [Row Co-Ordinate] [Guess]\n\n";
	cout << "For instance, \"A 2 5\" would insert the number 5 into the cell A2\n\n\n";
	cout << "In Extreme Sukoku, once an entry has been made, you are not allowed to change it\n";
	cout << "The program will notify you if the entry you attempted is illegal\n\n";
	cout << "A number which caused no conflicts at time of entry but is incorrect is final\n\n\n";
	cout << "NB: Column Co-ordinates should be entered in capital letters\n\n\n";
	system("pause");
	system("cls");
}

bool arraysIdentical2D(int array1[sudokuSize][sudokuSize], int array2[sudokuSize][sudokuSize])
{
	for (int k = 0; k < sudokuSize; k++)
	{
		for (int m = 0; m < sudokuSize; m++)
		{
			if ((array1[k][m]) != array2[k][m])
				return false;
		}
	}
	return true;
}

int main()
{
	char selection;
	displayMenu();
	cin >> selection;
	system("cls");
	if (selection == '1')
	{
		displayInstructions();
		playSudoku();
	}
	else if (selection == '2')
	{
		cout << "Bye\n\n";
	}
	else // essentially a validation check
	{
		cout << "Seriously re!? Was " << selection << " an option in the menu?\n\n";
		cout << "If you can't make a menu selection how the heck will you play sudoku?\n\n";
		cout << "BYE\n\n";
	}
	system("pause");
}
