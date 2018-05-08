// https://github.com/hb20007/
// Assignment 3 - Calculating π

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void menu(int& num)
{
	cout << "1. Approximate pi using one function\n";
	cout << "2. Compare the different approximations\n";
	cout << "3. Exit\n";
	cin >> num;
}

int selectApprox()
{
	int approx;
	cout << "Enter number (1-3) corresponding to desired approximation method\n";
	cin >> approx;
	return approx;
}

int setIterations()
{
	int iterationInput;
	cout << "How many iterations?\n";
	cin >> iterationInput;
	return iterationInput;
}

string coutAid(int approximationChosen) // This function is used in my cout statements to display the text "first", "second" or "third" as needed
{
	if (approximationChosen == 1) return "first";
	else if (approximationChosen == 2) return "second";
	else return "third";
}

bool unitCircleChecker(long double random1, long double random2)
{
	if ((random1*random1 + random2*random2) < 1.0) return true;
	return false;
}

void bestApproximationAnalyzer(long double piee1, long double piee2, long double piee3)
{
	long double realPi = atan(1) * 4, oneError = abs(realPi - piee1), twoError = abs(realPi - piee2), threeError = abs(realPi - piee3), leastError = oneError;
	string ordinal = "first";
	if (twoError < leastError)
	{
		leastError = twoError;
		ordinal = coutAid(2);
	}
	if (threeError < leastError)
	{
		leastError = threeError;
		ordinal = coutAid(3);
	}
	cout << "The actual value of pi is: " << realPi << endl;
	cout << "The approximation that was most accurate was the " << ordinal << endl;
	cout << "The error in the value of pi calcuated from the " << ordinal << " approximation is " << leastError << endl;
}

void error()
{
	cout <<"\nZut alors! That is not a valid menu choice\n" << "Please try again\n\n";
}

long double firstApproximation(int n1)
{
	long double pi1=0; 
	int seriesOneAid = 1; //this variable  helps me generate the series
	for (int i = 0; i < n1; i++)
	{
		if (i % 2 == 0) pi1 += 4/static_cast<long double>(seriesOneAid);
		else pi1 -= 4 / static_cast<long double>(seriesOneAid);
		seriesOneAid += 2;
	}
	return pi1;
}

long double secondApproximation(int n2)
{
	long double pi2=0;
	int seriesTwoAid = 1;
	for (int j = 0;  j < n2;  j++)
	{
		pi2 += 6.0/ (seriesTwoAid*seriesTwoAid);
		seriesTwoAid++;
	}
	pi2 = sqrtl(pi2);
	return pi2;
}

long double thirdApproximation(int n3)
{
	srand(static_cast<unsigned int>(time(0))); //the static cast is used to silence a warning message about the data types 
	long double pi3, rand1, rand2;
	int pointsInUnitCircle = 0, numberOfPointsInvestigated=0;
	for (numberOfPointsInvestigated; numberOfPointsInvestigated < n3; numberOfPointsInvestigated++)
	{
		rand1 = 1 - 2 * (rand() / static_cast<long double>(RAND_MAX));
		rand2 = 1 - 2 * (rand() / static_cast<long double>(RAND_MAX));
		if (unitCircleChecker(rand1, rand2)) pointsInUnitCircle++;
	}
	pi3 = 4 * (pointsInUnitCircle / static_cast<long double>(numberOfPointsInvestigated));
	return pi3;
}

void onSelectingMenu1(int iterationNumber)
{
		int approximationNumber = selectApprox();
		while (approximationNumber > 3 || approximationNumber < 1 ) //input validation
		{
			error();
			approximationNumber = selectApprox();
		}
		long double pi;
		switch (approximationNumber)
		{
		case 1: 
		pi= firstApproximation(iterationNumber); 
		break;
		case 2: 
		pi = secondApproximation(iterationNumber); 
		break;
		case 3: 
		pi = thirdApproximation(iterationNumber); 
		break;
		}
		cout << "The " << coutAid(approximationNumber) << " approximation with " << iterationNumber << " iteration(s) approximated pi as: " << pi << endl;
}

void onSelectingMenu2(int iterationNum)
{
	long double pie1, pie2, pie3;
	pie1 = firstApproximation(iterationNum);
	pie2 = secondApproximation(iterationNum);
	pie3 = thirdApproximation(iterationNum);
	cout << "APPROXIMATION\tPI\n";
	cout << "First\t\t" << pie1 << endl;
	cout << "Second\t\t" << pie2 << endl;
	cout << "Third\t\t" << pie3 << endl;
	bestApproximationAnalyzer(pie1, pie2, pie3);
}

int main()
{
	int numChoice;
	menu(numChoice);
	if (numChoice == 3) return 0;
	while (numChoice != 1 && numChoice != 2) // input validation
	{
		error();
		menu(numChoice);
	}
	int iterationNumberChosen = setIterations();
	if (numChoice == 1) onSelectingMenu1(iterationNumberChosen);
	if (numChoice == 2) onSelectingMenu2(iterationNumberChosen);
	system("pause");
	return 0;
}
// The second series is consistently the best method at approximating pi for both small and large numbers of iterations.