/**
* @file passcheck.c
* @author hb20007
* @date 05/03/2017
* @brief Checks the strength of the given password
*/

#include "passcheck.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h> // For strlen()
#include <math.h> // For log2() and pow()
#include <limits.h>

int getPassType(const char* pass) {
	bool charTypes[4] = { false }; // Lower case letter, upper case letter, digit, symbol
	for (const char* ptr = pass; *ptr != '\0'; ptr++) {
		if (*ptr >= 'a' && *ptr <= 'z')
			charTypes[0] = true;
		else if (*ptr >= 'A' && *ptr <= 'Z')
			charTypes[1] = true;
		else if (*ptr >= '0' && *ptr <= '9')
			charTypes[2] = true;
		else
			charTypes[3] = true;
		if (charTypes[0] && charTypes[1] && charTypes[2] && charTypes[3])
			break; // Added for extra efficiency
	}
	
	int passType;	
	if (charTypes[0] && charTypes[1] && charTypes[2] && charTypes[3])
		passType = ALL;
	else if (charTypes[0] && charTypes[1] && charTypes[2])
		passType = ALNUM;
	else if (charTypes[0] && charTypes[1] && charTypes[3])
		passType = DOUBLE_CASE_AND_SYMBOLS;
	else if ((charTypes[0] && charTypes[2] && charTypes[3]) || (charTypes[1] && charTypes[2] && charTypes[3]))
		passType = SINGLE_CASE_NUMBERS_SYMBOLS;
	else if (charTypes[0] && charTypes[1])
		passType = DOUBLE_CASE_ALPHA;
	else if ((charTypes[0] && charTypes[2]) || (charTypes[1] && charTypes[2]))
		passType = SINGLE_CASE_AND_DIGITS;
	else if ((charTypes[0] && charTypes[3]) || (charTypes[1] && charTypes[3]))
		passType = SINGLE_CASE_AND_SYMBOLS;
	else if (charTypes[2] && charTypes[3])
		passType = DIGITS_AND_SYMBOLS;
	else if (charTypes[0] || charTypes[1])
		passType = SINGLE_CASE_ALPHA;
	else if (charTypes[2])
		passType = DIGITS;
	else
		passType = SYMBOLS;
	
	return passType;
}

char* deduceCharsetSizeAndAdvice(const int passLength, const int passType, int* charsetSizePtr) {
		switch (passType) {
			case SINGLE_CASE_ALPHA:
				*charsetSizePtr = SINGLE_CASE_CHARSET_SIZE;
				return "Try varying the case of letters, and including numbers and symbols";
			case DOUBLE_CASE_ALPHA:
				*charsetSizePtr = 2*SINGLE_CASE_CHARSET_SIZE;
				return "Try including numbers and symbols";
			case DIGITS:
				*charsetSizePtr = DIGITS_CHARSET_SIZE;
				return "Try including letters and symbols";
			case SINGLE_CASE_AND_DIGITS:
				*charsetSizePtr = SINGLE_CASE_CHARSET_SIZE + DIGITS_CHARSET_SIZE;
				return "Try varying the case of letters, and including symbols";
			case ALNUM:
				*charsetSizePtr = 2*SINGLE_CASE_CHARSET_SIZE + DIGITS_CHARSET_SIZE;
				return "Try including special symbols (eg. _)";
			case SYMBOLS:
				*charsetSizePtr = SYMBOLS_CHARSET_SIZE;
				return "Try including letters and numbers";
			case SINGLE_CASE_AND_SYMBOLS:
				*charsetSizePtr = SINGLE_CASE_CHARSET_SIZE + SYMBOLS_CHARSET_SIZE;
				return "Try varying the case of letters and including numbers";
			case SINGLE_CASE_NUMBERS_SYMBOLS:
				*charsetSizePtr = SINGLE_CASE_CHARSET_SIZE + DIGITS_CHARSET_SIZE + SYMBOLS_CHARSET_SIZE;
				return "Try varying the case of letters used in the password";
			case DOUBLE_CASE_AND_SYMBOLS:
				*charsetSizePtr = 2*SINGLE_CASE_CHARSET_SIZE + SYMBOLS_CHARSET_SIZE;
				return "Try including numbers";
			case DIGITS_AND_SYMBOLS:
				*charsetSizePtr = DIGITS_CHARSET_SIZE + SYMBOLS_CHARSET_SIZE;
				return "Try including letters";
			case ALL:
				*charsetSizePtr = 2*SINGLE_CASE_CHARSET_SIZE + DIGITS_CHARSET_SIZE + SYMBOLS_CHARSET_SIZE;
				if (passLength < 8)
					return "Try making your password longer";
				if (passLength < 13)
					return "The password is fairly secure and skilled hackers may need good computing power to crack it.\nTry making it longer for even extra security";
				if (passLength < 25)
					return "The password is good enough to safely guard sensitive or financial information";
				return "The password is virtually impossible to crack. Often this level of security is overkill";
		}
}

bool isCommonPassword(const char* pass) {
	FILE *fp = fopen(COMMON_PASS_FILE_NAME, "r"); // The most straightforward way to read from file in C is line by line so I write a password on each line in the file as opposed to have the passwords as comma-separated variables
    if (fp != NULL) {						// For multiple fields of data this can be used for .csv: http://stackoverflow.com/questions/26443492/read-comma-separated-values-from-a-text-file-in-c
        char password[20];
		while (fgets(password, sizeof password, fp) != NULL) {
			// Trick to remove trailing newline characters from fgets() input.
			size_t ln = strlen(password) - 1;
			if (*password && password[ln] == '\n') 
				password[ln] = '\0';
			
			if (!strcmp(pass, password))
				return true;
        }
        fclose(fp);
    } else
        perror(COMMON_PASS_FILE_NAME);
	return false;
}

void printResult(const char* passStrength, const bool commonPassword, const bool manySeconds, const bool tooManySeconds, const int centuries, const int years, const int days, const unsigned long long hours, const unsigned long long minutes, const unsigned long long secondsULL, const double seconds) {
	printf("Your password strength is %s.\n", passStrength);
	if (commonPassword)
		printf("It can be cracked instantly.\n\n");
	else if (!manySeconds && !tooManySeconds)
		printf("It can be cracked in %f seconds on a core i5-6600K processor.\n\n", seconds);
	else if (tooManySeconds)
		printf("Cracking this password would take hundreds of centuries on a core i5-6600K processor.\n\n", secondsULL);
	else {
		printf("It can be cracked in ");
		if (centuries > 0)
			printf("%d centuries ", centuries);
		if (years > 0)
			printf("%d year(s) ", years);
		if (days > 0)
			printf("%d day(s) ", days);
		if (hours > 0)
			printf("%d hour(s) ", hours);
		if (minutes > 0)
			printf("%d minute(s) ", minutes);
		if (secondsULL > 0)
			printf("%d second(s) ", secondsULL);
		printf("on a core i5-6600K processor.\n\n");
	}
}

void printDetails(const char* pass, const int passLength, const int charsetSize, const double passBitStrength, const char* charsetAdvice) {
	printf("DETAILS\n");
	printf("> Password: %s\n", pass);
	printf("> Password length: %d characters\n", passLength);
	printf("> Charset size: %d characters\n", charsetSize);
	printf("> Entropy: %.1f bits\n", passBitStrength);
	printf("> Advice: %s.\n", charsetAdvice);
}

/**
* @brief Main function
* @param argc Count of the command line arguments
* @param argv An argument array of the command line arguments
* @return 0 upon exit success, and a non-zero integer upon exit failure
*/
int main(int argc, char* argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Error: The program must be called with 1 argument, the password.\n");
		exit(EXIT_FAILURE);
	}
	
	char *pass = argv[1];
	unsigned long long passLength = strlen(pass);
	int charsetSize = 0;
	char* charsetAdvice = "Arbitrary initialization"; // The arbitrary initialization here is a must because the pointer will be passed into a function for initialization and would point to a random place in memory otherwise. An alt to this is using malloc()
	int passType;
	int passwordScore = 0; // The passwordScore is my invention. It is a function of the password length and type.
	bool commonPassword = false;
	char* passStrength = "Arbitrary initialization";
	double entropy;
	double passBitStrength;
	double seconds;
	
	passType = getPassType(pass);
	
	int* charsetSizePtr = &charsetSize;
	charsetAdvice = deduceCharsetSizeAndAdvice(passLength, passType, charsetSizePtr);
	
	// printf("%llu\n", ULLONG_MAX);    // The largest possible integer number.
	
	entropy = pow(charsetSize, passLength); // double is enough for passwords of length up to 8180 characters. More than this is not allowed on Windows.
	passBitStrength = log2(entropy);
	seconds = entropy / KEYS_PER_SECOND;
	
	bool manySeconds = false; // Is set to true if the time is more than 1 minute
	bool tooManySeconds = false; // Is set to true if the time in seconds is more than C can handle.
	
	unsigned long long secondsULL = 0, minutes = 0, hours = 0;
	int days = 0, years = 0, centuries = 0; // I tried converting these variables to pointers and putting some code in functions by passing by reference but the app kept on crashing.
	
	if (seconds > ULLONG_MAX) {
		tooManySeconds = true;
	}
	else if (seconds >= 60.0) { // If the time is more than 1 minute
		manySeconds = true;
		secondsULL = (unsigned long long)seconds;
	} 
	if (manySeconds && !tooManySeconds) {
		if (secondsULL >= SECONDS_IN_A_CENTURY) {
			centuries = secondsULL / SECONDS_IN_A_CENTURY;
			secondsULL %= SECONDS_IN_A_CENTURY;
		}
		if (secondsULL >= SECONDS_IN_A_YEAR) {
			years = secondsULL / SECONDS_IN_A_YEAR;
			secondsULL %= SECONDS_IN_A_YEAR;
		}
		if (secondsULL >= SECONDS_IN_A_DAY) {
			days = secondsULL / SECONDS_IN_A_DAY;
			secondsULL %= SECONDS_IN_A_DAY;
		}
		if (secondsULL >= SECONDS_IN_AN_HOUR) {
			hours = secondsULL / SECONDS_IN_AN_HOUR;
			secondsULL %= SECONDS_IN_AN_HOUR;
		}
		if (secondsULL >= SECONDS_IN_A_MINUTE) {
			minutes = secondsULL / SECONDS_IN_A_MINUTE;
			secondsULL %= SECONDS_IN_A_MINUTE;
		}
	}
	
	commonPassword = isCommonPassword(pass);  
	
	if (commonPassword)
		passStrength = "VERY WEAK (COMMON PASSWORD)";
	else { 
		passwordScore += passLength;
		passwordScore += passType;
		if (passwordScore <= 10)
			passStrength = "WEAK";
		else if (passwordScore <= 17)
			passStrength = "MEDIUM";
		else
			passStrength = "STRONG";
	}
	
	printResult(passStrength, commonPassword, manySeconds, tooManySeconds, centuries, years, days, hours, minutes, secondsULL, seconds);
	printDetails(pass, passLength, charsetSize, passBitStrength, charsetAdvice);
}