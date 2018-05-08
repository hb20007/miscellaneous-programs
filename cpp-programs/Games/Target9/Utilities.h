#pragma once
#include <string>
using namespace std;

void ltrim(string &s); // Removes all leading 0s off a string
void rtrim(string &s); // Removes all terminating 0s off a string
int mod(const int &x, const int &m); // I define this function because C++'s % operator is a remainder not a modulo function however I require a modulo function to achieve results such as mod(-1,10) = 9