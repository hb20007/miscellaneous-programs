/**
* @file caesar.c
* @author hb20007
* @date 04/03/2017
* @brief Uses command line arguments to implement Caesar encryption, decryption, brute force attack and informed brute force attack.
*
* Usage instructions: 
* "caesar -e 1 message" for encryption with offset 1, 
* "caesar -d 5 message" for decryption with offset 5.
* "caesar -a message" for a brute force attack on ciphertext
* "caesar -a substring message" for a brute force attack that only prints out decryptions containing the substring
* Command line options are case sensitive.
* If the message contains spaces, then it should be enclosed in " ". This is because a string surrounded by double quotation marks is interpreted as a single argument, regardless of white space contained within. A quoted string can be embedded in an argument. The quotation marks are NOT placed in argv.
*/

#include "caesar.h"
#include <stdio.h>
#include <stdlib.h> // For EXIT_FAILURE & EXIT_SUCCESS. Also for strtol() (There is no strtoi(). Also atoibut should be avoided due to the fact it lacks a mechanism for error reporting from invalid input.
#include <string.h>
#include <errno.h> // errno.h is a header file in the standard library of the C programming language. It defines macros for reporting and retrieving error conditions through error codes stored in a static memory location called errno (short for "error number").
#include <limits.h> // For LONG_MAX and LONG_MIN
#include <ctype.h> // For isupper(), tolower() etc.
#include <stdbool.h> // For the macros bool, true and false

int mod(const int a, const int b) {
   if (b < 0) // b is usually not negative but just in case it is.
     return mod(a, -b);   
   int ret = a % b;
   if (ret < 0)
     ret += b;
   return ret;
}

char caesarShift(const char toShift, const int shiftVal) {
	if (!isalpha(toShift))
		return toShift;
	int charIndex, aValue;
	if (islower(toShift))
		aValue = 97; // 'a' ASCII = 97
	else
		aValue = 65; // 'A' ASCII = 65
	charIndex = toShift - aValue;
	return (char)(mod(charIndex + shiftVal, 26) + aValue);
}

long parseShiftValue(const char* shiftAmount) {
	/* For validating the shift_value */
	char *endptr;
	errno = 0; // To distinguish success/failure after call
	
	long shiftValue = strtol(shiftAmount, &endptr, 10);		// strtol() rejects the '.' character as required. The second argument is an address to store the location where conversion stops. The last argument is the base.
	
	/* Check for various possible errors */
	if ((errno == ERANGE && (shiftValue == LONG_MAX || shiftValue == LONG_MIN)) || (errno != 0 && shiftValue == 0)) {	// ERANGE is an error code implying the resulting value was out of range. If an underflow occurs, strtol() returns LONG_MIN.  If an overflow occurs, strtol() returns LONG_MAX.
		perror("Error (strtol)");	// The C library function void perror(const char *str) prints a descriptive error message to stderr. First the string str is printed, followed by a colon then a space. Then the exit(EXIT_FAILURE) will add the error description after the colon.
		exit(EXIT_FAILURE); // The error that would be printed here is "Result too large" etc. Btw it doesn't print a period after the string and also prints a new line after the string.
    }
	if (endptr == shiftAmount) {
        fprintf(stderr, "Error (strtol): No digits were found in the shift value\n");
		exit(EXIT_FAILURE);
    }
	if (*endptr != '\0') {
        fprintf(stderr, "Error (strtol): The non-numerical character(s) \"%s\" were detected after shift value\n", endptr);
		exit(EXIT_FAILURE);
	}
	
	return shiftValue;
}

void shiftAndPrint(const long caesarKey, const char* msg) {
	const char* ptr = msg;
	while (*ptr != '\0') {
		putchar(caesarShift(*ptr, caesarKey));	// putchar is a C function that writes a single character to the standard output stream, stdout.
		ptr++;
	}
}

void encryptDecrypt(const char* mode, const char* shiftAmt, const char* message) {
	long key = parseShiftValue(shiftAmt); // In cryptography, a key is a piece of information (a parameter) that determines the functional output of a cryptographic algorithm. For encryption algorithms, a key specifies the transformation of plaintext into ciphertext, and vice versa for decryption algorithms.
	
	/* If we got here, strtol() successfully parsed a number in parseShiftValue() */
	if (key > 25 || key < 1) {
		fprintf(stderr, "Error: The shift value should be in the range [1, 25]\n");	// If a right shift of 3 is intended ie. eg. a value of -3, just input -3 mod 26 which is 23
		exit(EXIT_FAILURE);
	}	
	
	/* The algorithm begins here */
	if (!strcmp(mode, "-d"))
		key -= 2 * key;
	shiftAndPrint(key, message);
	printf("\n");
}

void bruteForceAttack(const char* ciphertext) {
	for (int i = 1; i < 26; i++) { // Loop through all possible key values
		printf("Key: %d Plaintext: ", i);
		shiftAndPrint(i - 2 * i, ciphertext); // i - 2 * i because we are decrypting, so we need to shift to the left
		printf("\n");
	}
}

void shiftCharsOnce(char* string) {
	for (char* ptr = string; *ptr != '\0'; ptr++)	// putchar is a C function that writes a single character to the standard output stream, stdout.
		*ptr = caesarShift(*ptr, 1);
}

void dictionaryAttack(char* word, const char* ciphertext) {
	// Shifting the ciphertext every time and checking the output for the word is tedious so instead I will shift the word for every possible key and see if it is contained in the ciphertext to determine the key
	bool successFlag = false;
	for (int i = 1; i < 26; i++) {
		shiftCharsOnce(word);
		if (strstr(ciphertext, word)) { // strstr() in <cstring> takes 2 arguments str1 and str2. Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1. The null pointer is 0. So if(ptr) is true if ptr is not null.
			successFlag = true;
			printf("Success! Key: %d Plaintext: ", i);
			shiftAndPrint(i - 2 * i, ciphertext);
			printf("\n");
		}
	}
	
	if (!successFlag) {
		shiftCharsOnce(word); // We get back the original word 
		printf("The string %s was not a substring of any plaintext for all possible shift values\n", word);
	}
}

/**
* @brief Main function
*
* Validates the command line arguments and then executes the algorithm.
*
* @param argc Count of the command line arguments
* @param argv An argument array of the command line arguments
* @return 0 upon exit success, and a non-zero integer upon exit failure
*/
int main(int argc, char *argv[]) {
	if (argc < 3 || argc > 4) {
		fprintf(stderr, "Error: The program must be called with 2 or 3 arguments\n");
		exit(EXIT_FAILURE);
	}
	if (strcmp(argv[1], "-e") && strcmp(argv[1], "-d") && strcmp(argv[1], "-a")) {
		fprintf(stderr, "Error: %s is not a valid option\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((!strcmp(argv[1], "-d") || !strcmp(argv[1], "-e")) && argc != 4) { // ie. if ((argv[1] == "-d" || argv[1] == "-e") && argc != 4
		fprintf(stderr, "Error: With %s the program must be called with 3 arguments", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	if (!strcmp(argv[1], "-d") || !strcmp(argv[1], "-e"))
		encryptDecrypt(argv[1], argv[2], argv[3]);
	else // if argv[1] == "-a"
		if (argc == 3) // If a substring is not specified
			bruteForceAttack(argv[2]);
		else // argc == 4
			dictionaryAttack(argv[2], argv[3]);
	// return EXIT_SUCCESS;
}