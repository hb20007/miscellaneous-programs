//@hb20007

#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}


int main() {
	int a, b, c, d, middle1, middle2;
	cout << "Enter 4 different integers \n>";
	cin >> a >> b >> c >> d;

	middle1 = min(max(a, b), max(c, d)); // minumum of 2 maximums = middle number
	middle2 = max(min(a, b), min(c, d)); // maximum of 2 minimums = another middle number. Works for all cases.

	cout << "The middle numbers are ";

	if (middle1 > middle2) // the numbers will be displayed in ascending order
		 cout << middle2 << " and " << middle1 << endl;
	else cout << middle1 << " and " << middle2 << endl;

	system("pause");
}
