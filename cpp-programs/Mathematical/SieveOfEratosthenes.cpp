//Write a program that finds and prints all the prime numbers between 1 and 500. 

// Create an array with all elements initialized to 1 (true). Array elements with prime
//subscripts will remain 1 and all other(non - prime) elements will be eventually set
//to 0 (false).
//Starting with array subscript 2, every time an array element is found whose value
//is 1, loop through the remainder of the array and set to zero every element whose
//subscript is a multiple of the subscript for the element with value 1. For example,
//for array subscript 2, all elements beyond 2 in the array that are multiples of 2 will
//be set to 0 (subscripts 4, 6, 8, 10, etc.); for array subscript 3, all elements beyond 3
//in the array that are multiples of 3 will be set to zero(subscripts 6, 9, 12, 15, etc);
//and so on.
//When this process is complete, the array elements that are still set to 1 indicate that the
//subscript is a prime number.These subscripts can then be printed out.

// So by subscript they mean index

//useful functions for arrays: generate, replace, fill, fill_n
// fill_n(array, 100, 1); fills the first 100 elements of array with 1
// replace (myvector.begin(), myvector.end(), 20, 99); etc

// These 4 functions, along with find, copy, count, search, swap, transform, remove, rotate, reverse, sort, merge, min, max, set_union, set_intersection are all found in <algorithm>


#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	const int length = 500; // so prime numbers till 500. Note my array is actually 2,3,4...500. If 1-500 we have 501 elements inclusive so for me 2-500 there are 500 elements
	int array[length];
	fill_n(array, length, 1);

	for (int i = 0; i < length; i++)
	{
		if (array[i] == 1)
		{
			int initial_j = i + 2;
			int j = initial_j; //j is basically the subscript. For eg. first element with index 0 corresponds to the number 2.
			while ((i+j)<500) // note it's < not <= cuz we have 500 elements but the indexes go only up to 499
			{
				array[i + j] = 0;
				j += initial_j;
			}
		}
	}

	cout << "Prime numbers between 1 to " << length <<":\n";
	for (int i = 0; i < length; i++)
	{
		if (array[i] == 1) cout << i+2 << "  ";
	}
	cout << endl;
	system("pause");
}