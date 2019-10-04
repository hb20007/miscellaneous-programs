/**
* Utilities.h
* The Utilities class contains generic static methods useful in the program
*
* @author hb20007
* @version 1.0 03/12/2016
*/

#pragma once
#include <vector>
using std::string;

class Utilities
{
public:
	/**
	*	Checks if the string passed as a parameter can be successfully parsed to an integer
	*
	*	@param selection The string to check
	*	@returns true if the string can be parsed to an integer, else false
	*/
	static bool isValidInteger(const string& toCheck);

	/**
	*	Checks if the integer passed as a parameter is in the required range (also passed as parameters)
	*
	*	@param num The number to check
	*	@param min The minimum value the number is allowed to be
	*	@param max The maximum value the number is allowed to be
	*	@returns true if the number is in the required range, else false
	*/
	static bool isInRequiredRange(const int& num, const int& min, const int& max);

	/**
	*	Uses the methods isValidInteger() and isInRequiredRange() to check if the string provided can be parsed to an integer and is in the range specified by the arguments
	*
	*	@param toCheck The string to check
	*	@param min The minimum value the number is allowed to be
	*	@param max The maximum value the number is allowed to be
	*	@returns true if the number is in the required range, else false
	*/
	static bool Utilities::isValidIntegerAndInRequiredRange(const string& toCheck, const int& min, const int& max);

	/**
	*	Loads data into a vector of strings from the specified file name
	*
	*	@param fileName A string with the file name to load from
	*   @returns The vector of strings with the data. Empty if data not loaded successfully
	*/
	static std::vector<string> getDataAndSplitIntoTokens(const string& fileName);
};
