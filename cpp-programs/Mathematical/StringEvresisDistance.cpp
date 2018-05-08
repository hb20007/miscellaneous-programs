// @Hb20007  --- Code to calculate the String Everesis Distance (SED) between 2 strings

#include <iostream>
using namespace std;

int minOfThree(int i, int j, int k) { // Returns the minimum of 3 integers
	int minOfTwo;
	minOfTwo = (i <= j) ? i : j;
	return (k <= minOfTwo) ? k : minOfTwo;
}

int charcmp(char c1, char c2) { // Compares two characters and returns 0 if they are equal, 1 if not
	return (c1 == c2) ? 0 : 1;
}

int D(char s1[], char s2[], int i, int j) { // Recursive function to calculate the String Everesis Distance between 2 strings
	if (i == 0) 
		return j;
	if (j == 0) 
		return i;
	return minOfThree(D(s1, s2, i - 1, j) + 1, D(s1, s2, i, j - 1) + 1, D(s1, s2, i - 1, j - 1) + charcmp(s1[i-1], s2[j-1]));
}

void testing() { // Test cases
	char wrd1[50], wrd2[50];
	for (int i = 0; i < 5; i++) {
		switch (i) {
		case 0:
			strcpy_s(wrd1, "FIFA");
			strcpy_s(wrd2, "UEFA");
			break;
		case 1:
			strcpy_s(wrd1, "GGTACGGCTAAK");
			strcpy_s(wrd2, "GTACGGCTATAC");
			break;
		case 2:
			strcpy_s(wrd1, "GGTAGAGGCTAK");
			strcpy_s(wrd2, "GTAGCGGCTATC");
			break;
		case 3:
			strcpy_s(wrd1, "the long    ");
			strcpy_s(wrd2, "    long day");
			break;
		case 4:
			strcpy_s(wrd1, "moving");
			strcpy_s(wrd2, "good movie");
			break;
		}
		cout << "Ex. " << i + 1 << " - Minimum edits required to convert is ";
		cout << D(wrd1, wrd2, strlen(wrd1), strlen(wrd2)) << endl; //strlen() returns the length of the string not including the null terminator ( sizeof() includes the null terminator )
	}
}

int main() {
	testing();
	// Conclusion: Program works but is quite slow
	system("pause");
}