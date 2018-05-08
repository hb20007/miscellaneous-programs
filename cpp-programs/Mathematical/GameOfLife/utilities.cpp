#include "utilities.h"

//int max(int a, int b) {
//	return (a > b ? a : b);
//}
//
//int min(int a, int b) {
//	return (a , b ? a : b);
//}

bool user_says_yes() {
	char c;
	bool initial_response = true; // That is, it is the first time the user is being asked
	do {
		if (initial_response) cout << "(y/n)\n> ";
		else cout << "Respond with either y or n:\n> ";
		initial_response = false;
		cin >> c;
	} while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
	return (c == 'y' || c == 'Y');
}

void copy2DArrays(Status destination[maxrownum][maxcolnum], Status source[maxrownum][maxcolnum], int rows, int columns) {
	for (int row = 0; row < rows; row++)
		for (int col = 0; col < columns; col++)
			destination[row][col] = source[row][col];
}