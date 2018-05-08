// @hb20007
//
// Program that can verify if a 2D array is a magic square and generate magic squares of n dimensions where n is odd

#include <iostream>
#include <iomanip> //Included in order to format output streams
#include <string>
#include "windows.h" //Included in order to use the Sleep() function
#include "Source.h"
using namespace std;

int main()
{
	string choice;
	menu(choice);
	parseInput(choice);
}

void restart() {
	cout << "\nGoing back to menu...";
	Sleep(2000); //pause for 2 seconds
	system("cls");
}

void menu(string &selection ) 
{
	cout << "Welcome to the Magic Squares program! Select an option\n\n";
	cout << "1. Determine if a square integer array is a magic square\n";
	cout << "2. Generate a magic square\n";
	cout << "3. Exit\n\n> ";
	cin >> selection;
}

void parseInput(string &input) 
{
	if (input.length() != 1) //std::string::length() and std::string::size() are synonyms. They return a value in bytes. 1 char is 1 byte. 
	{
		Error_Label: cout << "\nInvalid input. Please enter a one-digit integer from 1-3 as your selection\n";
		restart();
		menu(input);
		return;
	}
	switch (input.at(0)) //string.at() prints the character at that position
	{
	case '1':
		magicSquareChecker();
		break;
	case '2':
		magicSquareGenerator();
		break;
	case '3':
		break;
	default: 
		goto Error_Label; //goto is generally only used to escape nested loops though (I think it's used more in C though)
	}
}

int getSize() 
{
	int size;
	cout << "Insert the size of your array (integer between 2 and " << arrayMaxSize << ")\n\n> ";
	cin >> size;
	while (size < 2 || size >20)
	{
		cout << "\nInvalid input. Insert an integer between 2 and " << arrayMaxSize << "\n\n> ";
		cin >> size;
	}
	return size;
	//This approach for validation crashes if the user inserts a character.
}

void magicSquareChecker() 
{
	system("cls");
	int intArray[arrayMaxSize][arrayMaxSize];
	int size = getSize();
	cout << "\nInsert the first number in your integer array\n\n> ";
	cin >> intArray[0][0];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((i == 0) && (j == 0)) continue;
			cout << "\nInsert the next number in your integer array\n\n> ";
			cin >> intArray[i][j];
		}
	}
	system("cls");
	cout << "Array:\n";
	displaySquareArray(intArray, size);
	int magicConstant = 0; //Arbitrary initialization
	if (checkingAlgorithm(intArray, size, magicConstant))
	{
		cout << "\nThe array you inserted is a magic square\n\n";
		cout << "Magic constant = " << magicConstant << endl << endl;
	}
	else
		cout << "\nThe array you inserted is not a magic square\n\n";
	system("pause");
	restart();
	main();
}

void displaySquareArray(int userArray[arrayMaxSize][arrayMaxSize], int arraySize) //note the neccessity of the arrayMaxSize here
{
	cout << endl;
	int fieldWidth = 5; //Supports elements of up to 4 digits
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize; j++)
		{
			cout << " " << setw(fieldWidth) << left << userArray[i][j];
		}
		cout << endl;
	}
}

bool checkingAlgorithm(int userArray[arrayMaxSize][arrayMaxSize], int arraySize, int &magicSum){
	int backDiagonalSum = 0;
	int forwardDiagonalSum = 0;
	for (int i = 0; i < arraySize; i++)
	{
		int rowSum= 0;
		int columnSum = 0;
		for (int j = 0; j < arraySize; j++)
		{
			rowSum += userArray[i][j];
			columnSum += userArray[j][i];
			if (i == j)
				backDiagonalSum += userArray[i][j];
			if (i + j == arraySize - 1) //Note the simple logic of this
				forwardDiagonalSum += userArray[i][j];
		}
		if (i == 0)
			magicSum = rowSum;
		if (rowSum != magicSum || columnSum != magicSum)	
			return false;
	}
	if (backDiagonalSum != magicSum || forwardDiagonalSum != magicSum)
		return false;
	return true;
}

void magicSquareGenerator() //We use Loubere's method to generate normal magic squares. Size must be an odd number. The sequence of magic sums is 0,1,5,15 (3x3), 34, 65, 111, 175, 260... The equation is a(n) = n*(n^2+1)/2. How do we arrive at this equation? Write the natural numbers in groups : 1; 2, 3; 4, 5, 6; 7, 8, 9, 10; ... and add the groups.In other words, "sum of the next n natural numbers". Nice! So the magic sum of a 2 magic square has the sum of the term with 2 numbers ie "2,3" = 5. But now I need only the odd terms ie. 1,15,65,175,369... Well these are the rhombic dodecahedral numbers. a(n) = n^4 - (n-1)^4. Actually no for this equation we insert 2 to get the magic sum of the 3x3 magic square so we use the previous one, user inserts 3 we use it to get the value of the 3x3 magic sum and we simply don't care about the even numbers
{
	system("cls");
	int intArray[arrayMaxSize][arrayMaxSize], size = getSize(), i = 0; //NB as we go diagonally upwards i decreases but j increases
	if (size % 2 == 0) {
		cout << "\nThe method used in this program (La Loubere's) can only\ngenerate magic squares of odd dimensions.\n\nInsert an odd number\n\n";
		system("pause");
		system("cls");
		size = getSize();
	}
	int j = size / 2;
	//Now the question is, how many times do we perform the algorithm? (size*size) times cuz every time one square is filled. So we either loop from zero to <(size*size) or from 1 to <=(size*size)
	for (int counter = 1; counter <= size*size; counter++)
	{
		intArray[i][j] = counter;
		if (intArray[(i - 1 + size) % size][(j + 1) % size] >= 1 && intArray[(i + 1) % size][(j + 1) % size] < counter)
			i++;
		else
		{
			i = (--i + size) % size; //Note I wanted a system where we count down 2, 1, 0 (for 3x3) and when we reach 0 we go back to 2 and count down again. I found a way to do this without if statements. Here's how: 1. Minus the count by 1. 2. Add size (here it's 3) 3. Take what u have modulus size bam
			j = ++j%size; // My previous version of this line was the erroneous "++j%size;" 
		}
	} 
	displaySquareArray(intArray, size);
	cout << "\nMagic constant = " << size*(size*size + 1) / 2 << endl << endl;
	system("pause");
	restart();
	main();
}