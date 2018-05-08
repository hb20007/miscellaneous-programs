#include "Utilities.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string> // For std::stoi()
using std::cerr;
using std::endl;
using std::vector;
using std::ifstream;

bool Utilities::isValidInteger(const string& toCheck) // static method
{
	try
	{
		int stringAsInt = stoi(toCheck); // If the user inserts a string such as "1 2", stoi() parses it as 1, so it is assumed this is what the user intends
	}
	catch (std::invalid_argument)
	{
		// if no conversion could be performed
		cerr << "The input could not be successfully parsed as a number\n\n";
		return false;
	}
	catch (std::out_of_range)
	{
		// if the converted value would fall out of the range of the result type 
		cerr << "The input is out of range\n\n";
		return false;
	}
	return true;
}

bool Utilities::isInRequiredRange(const int& num, const int& min, const int& max) // static method
{ 
	return num >= min && num <= max ? true : false;
}

bool Utilities::isValidIntegerAndInRequiredRange(const string& toCheck, const int& min, const int& max) 
{
	if (Utilities::isValidInteger(toCheck))
	{
		if (Utilities::isInRequiredRange(stoi(toCheck), min, max))
			return true;
		cerr << "The number you input is not a valid menu option\n\n";
	}
	return false;
}

vector<string> Utilities::getDataAndSplitIntoTokens(const string& fileName)
{
	bool errorPresent = false;
	vector<string> result;
	ifstream file;

	// Set exceptions to be thrown on failure
	file.exceptions(ifstream::failbit | ifstream::badbit);

	try
	{
		file.open(fileName);
	}
	catch (std::system_error e)
	{
		cerr << e.code().message() << endl << endl;
		errorPresent = true;
	}
	if (!errorPresent)
	{
		string line;
		if (!file.eof())
			getline(file, line); // The first row of .csv files is usually the column headers and doesn't need to be stored. So here the first line is read and disregarded
		while (!file.eof() && getline(file, line)) // "!file.eof() &&" is essential because exceptions were enabled and getline would return a failbit exception at the end of file
		{
			std::stringstream lineStream(line);
			string cell;
			while (getline(lineStream, cell, ','))
			{
				result.push_back(cell);
			}
		}
	}
	return result;
}