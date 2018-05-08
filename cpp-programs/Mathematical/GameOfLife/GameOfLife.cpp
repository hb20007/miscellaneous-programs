// @hb20007

#include "utilities.h"
#include "life.h"

int main() {
	Life configuration;
	welcome();
	cout << "Would you like to change the size of the grid? (Default " << defaultrownum << "x" << defaultcolnum << ")\n";
	if (user_says_yes()) {
		int newrownum, newcolnum;
		cout << "\nInsert new number of rows (Max " << maxrownum << ")\n> ";
		cin >> newrownum;
		if (newrownum > maxrownum) {
			cout << "\nNumber inserted greater than " << maxrownum << ".\nThe maximum value of " << maxrownum << " will be used\n\n";
			configuration.setmaxrow(maxrownum);
		}
		else if (newrownum <= 0 ) {
			cout << "\nA positive integer value was expected.\n" << "The default value of " << defaultrownum << " will be used\n\n";
			configuration.setmaxrow(defaultrownum);
		}
		else
			configuration.setmaxrow(newrownum);
		cout << "Insert new number of columns (Max 100)\n> ";
		cin >> newcolnum;
		if (newcolnum > maxcolnum) {
			cout << "\nNumber inserted greater than " << maxcolnum << ".\nThe maximum value of " << maxcolnum << " will be used\n";
			configuration.setmaxcol(maxcolnum);
		}
		else if (newcolnum <= 0) {
			cout << "\nA positive integer value was expected.\n" << "The default value of " << defaultcolnum << " will be used\n\n";
			configuration.setmaxcol(defaultcolnum);
		}
		else
		configuration.setmaxcol(newcolnum);
	};
	configuration.initialize();
	configuration.print();
	cout << "Continue viewing new generations?" << endl;
	while (user_says_yes()) {
		configuration.update();
		configuration.print();
		cout << "Continue viewing new generations?" << endl;
	}
}