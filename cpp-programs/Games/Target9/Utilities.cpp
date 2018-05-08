#include "Utilities.h"

void ltrim(string &s) {
	int i = 0;
	for (i; s.at(i) == ' '; i++); // i becomes the count of the number of leading 0s
	s.erase(0, i); // Starts erasing at position 0 and erases i characters in the string
}

void rtrim(string &s) {
	int i = (s.length() - 1); 
	for (i; s.at(i) == ' '; i--); // i becomes the position of the character after which are the trailing zeros
	s.erase(i+1, (s.length() - i - 1)); // We erase from position i+1 until the end of the string
}

int mod(const int &x, const int &m) {
	return (x % m + m) % m; // Adding m to x%m and then taking the remainder with m does not change the answer if x were positive. If it is negative, x%m +m is the answer and later taking the modulo with m does not change the answer which is already correct because x%m + m is less than m
}