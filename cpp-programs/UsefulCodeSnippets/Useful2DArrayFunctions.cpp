#include <iostream>
using namespace std;

const int rows = 3;
const int cols = 2;

void cout2DArray(int array[rows][cols]);
void cinSet2DArray(int array[rows][cols]); //The number of rows and columns are the same as the global vars
void cinCustom2DArray(int array[rows][cols], int& rowsNum, int& colsNum); // The number of rows and columns are specified by the user and the global vars are set to large numbers and only a part of the 2D array is used
void copySet2DArray(int array1[rows][cols], int array2[rows][cols]); //array1 copied into array2
void copyCustom2DArray(int array1[rows][cols], int array2[rows][cols], int rowsNumb, int colsNum);
int sumSet2DArray(int array[rows][cols]);
int sumCustomt2DArray(int array[rows][cols], int rowsNum, int colsNum);
bool comparison2D(int array1[rows][cols], int array2[rows][cols]);
void fillWithNumber2D(int array[rows][cols], int number);
int max2D(int array[rows][cols]);
int min2D(int array[rows][cols]);
// I have ignored some fns like count and isMemeber cuz usually they are used with 1d arrays

void cout2DArray(int array[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

void cinSet2DArray(int array[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		cout << "Insert elements in row " << rows << endl;
		for (int j = 0; j < cols; j++)
		{
			cin >> array[i][j];
		}
	}
}

void cinCustom2DArray(int array[rows][cols], int& rowsNum, int& colsNum)
{
	cout << "Insert number of rows\n";
	cin >> rowsNum;
	cout << "Insert numberof columns\n";
	cin >> colsNum;
	for (int i = 0; i < rowsNum; i++)
	{
		cout << "Insert elements in row " << rowsNum << endl;
		for (int j = 0; j < colsNum; j++)
		{
			cin >> array[i][j];
		}
	}
}

void copySet2DArray(int array1[rows][cols], int array2[rows][cols] )
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array2[i][j] = array1[i][j];
		}
	}
}

void copyCustom2DArray(int array1[rows][cols], int array2[rows][cols], int rowsNum, int colsNum)
{
	for (int i = 0; i < rowsNum; i++)
	{
		for (int j = 0; j < colsNum; j++)
		{
			array2[i][j] = array1[i][j];
		}
	}
}

int sumSet2DArray(int array[rows][cols])
{
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum += array[i][j];
		}
	}
	return sum;
}

int sumCustomt2DArray(int array[rows][cols], int rowsNum, int colsNum)
{
	int sum = 0;
	for (int i = 0; i < rowsNum; i++)
	{
		for (int j = 0; j < colsNum; j++)
		{
			sum += array[i][j];
		}
	}
	return sum;
}

bool comparison2D(int array1[rows][cols], int array2[rows][cols])
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (array1[i][j] != array2[i][j]) return false;
		}
	}
	return true; 
}

void fillWithNumber2D(int array[rows][cols], int number)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = number;
		}
	}
}

int max2D(int array[rows][cols])
{
	int maximum = array[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j	< cols; j++)
		{
			if (array[i][j] > maximum) maximum = array[i][j];
		}
	}
	return maximum;
}

int min2D(int array[rows][cols])
{
	int minimum = array[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (array[i][j] < minimum) minimum = array[i][j];
		}
	}
	return minimum;
}

int main()
{
	//int array[rows][cols] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	//cout2DArray(array);
	system("pause");
}