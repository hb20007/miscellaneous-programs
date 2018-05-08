//Passing Arrays as Function Arguments in C++
//1. Formal parameters as a pointer as follows : void myFunction(int *param)
//2. Formal parameters as a sized array as follows : void myFunction(int param[10]) 
//3. Formal parameters as an unsized array.
// As actual parameter, u pass array without the [ ], only name

#include <iostream>
using namespace std;
void deleteElement(int *parameter, int length, int index);
void coutArray(int *parameter, int length);
void cinArray(int *parameter, int &length); //user inserts numbers and -1 is used to stop input. Size of array stored in referenced var
void pickyCinArray(int *parameter, int &length); //user specifies number of entries then inserts that many numbers
void tallyArray(int *parameter1, int *parameter2, int length, int lowerLim, int higherLim); // the second array will be empty and in the end it will correspond to the tally. eg. if first array had 5 0s, 0th element of 2nd array will be 5.. 
int sumArray(int *parameter, int length);
void copyArray(int *parameter1, int *parameter2, int length);  //It's not possible to create an array and equalize it to another so u need this fn
void reverseArray(int *parameter1, int *parameter2, int length);
int count(int *parameter1, int length, int num);  //returns how many times num appears in the array. Also useful to return mode etc. 
bool isMember(int *parameter1, int length, int num); // returns 1 if num is a member of the array
void swap(int &a, int &b); // To be used by the next function
void reverse(int *parameter, int length); // reverseArray() creates a new array which is the reverse. This one reverses the actual array
bool comparison(int *parameter1, int * parameter2, int length); // returns true if arrays have the same contents
void fillWithNumber(int *parameter, int length, int number);
int min(int *parameter, int length);
int max(int *parameter, int length);

void deleteElement(int *parameter, int& length, int index)
{
	for (index ; index < (length - 1) ; index++) parameter[index] = parameter[index + 1];
	length--;
}

void coutArray (int *parameter, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout <<parameter[i] << " ";
	}
	cout << endl;
}

void cinArray(int *parameter, int &length) // the int "&length" is for the cinArray fn to return the size of the array. Should be passed in as a 0
{
	int number;
	cout << "Insert sequence of numbers (insert -1 to signal end of input)\n";
	cin >> number;
	while (number != -1)
	{
		parameter[length]= number;   //NB this line
		length++;
		cin >> number;
	}
}

void pickyCinArray(int *parameter, int &length)
{
	cout << "Insert number of entries\n";
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		cout << "Insert entry " << i + 1 << " of " << length << endl;
		cin >>parameter[i];
	}
}

void tallyArray(int *parameter1, int *parameter2, int length, int lowerLim, int higherLim) // Lim of what? Numbers we are tallying
{
	for (int i = lowerLim; i <= higherLim; i++) 
	{
		for (int j = 0; j < length; j++)
		{
			if (parameter1[j] == i) parameter2[i]++; 
		}
	}
}

int sumArray(int *parameter, int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += parameter[i];
	}
	return sum;
}

void copyArray(int *parameter1, int *parameter2, int length) // parameter 1 copied into parameter 2
{
	for (int i = 0; i < length; i++)
	{
		parameter2[i] = parameter1[i];
	}
}

void reverseArray(int *parameter1, int *parameter2, int length)
{
	int temp = length;
	for (int i = 0; i < length; i++)
	{
		parameter2[i] = parameter1[temp - 1];
		temp--;
	}
}

int count(int *parameter1, int length, int num)
{
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (parameter1[i] = num) counter++;
	}
	return counter;
	// if i  < length after the loop it means the element was found. I could use the value of i to find out which element the match was
}

bool isMember(int *parameter1, int length, int num)
{
	if (count(parameter1, length, num) > 0) return true;
	return false;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void reverse(int *parameter, int length)
{
	for (int i = 0; i < length; i++)
	{
		swap(parameter[i], parameter[(length - 1 - i)]);
	}
}

bool comparison(int *parameter1, int * parameter2, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (parameter1[i] != parameter2[i]) return false; // NB this part
	}
	return true;
}

void fillWithNumber(int *parameter, int length, int number)
{
	for (int i = 0; i < length; i++)
	{
		parameter[i] = number;
	}
}

int min(int *parameter, int length)
{
	int minimum=parameter[0];
	for (int i = 1; i < length; i++)
	{
		if (parameter[i] < minimum) minimum = parameter[i];
	}
	return minimum;
}

int max(int *parameter, int length)
{
	int maximum = parameter[0];
	for (int i = 1; i < length; i++)
	{
		if (parameter[i] >maximum) maximum = parameter[i];
	}
	return maximum;
}

int main()
{
	/*int length = 0;
	int array1[50];
	pickyCinArray(array1, length);   
	coutArray(array1, length);*/
	system("pause");
}