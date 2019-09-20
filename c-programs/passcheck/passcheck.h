/**
* @file passcheck.h
* @author hb20007
* @date 05/03/2017
* @brief Header file for passcheck.c
*/

#include <stdbool.h>

/* DEFINITIONS */

/**
* @brief The name of the file with the list of common passwords
* @note Sources: http://www.telegraph.co.uk/technology/2017/01/16/worlds-common-passwords-revealed-using/ and http://www.telegraph.co.uk/technology/2016/01/26/most-common-passwords-revealed---and-theyre-ridiculously-easy-to/
*/
#define COMMON_PASS_FILE_NAME "commonPasswords.dat"

/**
* @brief The number of password keys attempted per second in a brute-force attack on a core i5-6600K processor
* @note Source: https://www.betterbuys.com/estimating-password-cracking-times/
*/
#define KEYS_PER_SECOND	11344618

//@{
/** @name Entropy per character multipliers */
#define SINGLE_CASE_CHARSET_SIZE 26
#define DIGITS_CHARSET_SIZE 10
#define SYMBOLS_CHARSET_SIZE 32
//@}

//@{
/** @name Constants for converting between time units */
#define SECONDS_IN_A_CENTURY 3153600000
#define SECONDS_IN_A_YEAR 31557600
#define SECONDS_IN_A_DAY 86400
#define SECONDS_IN_AN_HOUR 3600
#define SECONDS_IN_A_MINUTE 60
//@}


/* ENUMS */

/**
* @brief Possible password types
*/
enum {DIGITS,
	  SINGLE_CASE_ALPHA,
	  SYMBOLS,	// Symbols refers to special characters like $#&*_ etc.
	  SINGLE_CASE_AND_DIGITS,
	  DIGITS_AND_SYMBOLS,
	  DOUBLE_CASE_ALPHA,
	  SINGLE_CASE_AND_SYMBOLS,
	  ALNUM,
	  SINGLE_CASE_NUMBERS_SYMBOLS,
	  DOUBLE_CASE_AND_SYMBOLS,
	  ALL};

/* FUNCTIONS */

/**
* @brief Returns the password type as defined in the enum in the header file
* @param pass The password string
* @return The password type
*/
extern int getPassType(const char* pass);

/**
* @brief Uses "passing by reference" to initialize charsetSize and returns charsetAdvice
* @param passLength The password length
* @param passType The password type
* @param charsetSizePtr Pointer to charsetSize
* @param charsetAdvice The charset advice C string
*/
extern char* deduceCharsetSizeAndAdvice(const int passLength, const int passType, int* charsetSizePtr);

/**
* @brief Checks if the password is in the list of common passwords
* @param pass The password in question
* @return true if the password is common, else false
*/
extern bool isCommonPassword(const char* pass);

/**
* @brief Prints the password analysis
* @param passLength The password length
* @param commonPassword true if the password is in the list of common passwords, else false
* @param manySeconds true if the password takes 60 seconds or more to crack, else false
* @param tooManySeconds true if the time taken to crack the password is beyond what C can store, else false
* @param centuries The centuries it takes to crack the password
* @param years The years it takes to crack the password
* @param days The days it takes to crack the password
* @param hours The hours it takes to crack the password
* @param minutes The minutes it takes to crack the password
* @param secondsULL The seconds it takes to crack the password
* @param seconds The seconds it takes to crack the password. Used if the number is less than 60.
*/
extern void printResult(const char* passStrength, const bool commonPassword, const bool manySeconds, const bool tooManySeconds, const int centuries, const int years, const int days, const unsigned long long hours, const unsigned long long minutes, const unsigned long long secondsULL, const double seconds);

/**
* @brief Prints the password analysis details
* @param pass The password
* @param passLength The password length
* @param charsetSize The size of the password's character set
* @param passBitStrength The bit strength
* @param charsetAdvice Advice based on charsetSize
*/
extern void printDetails(const char* pass, const int passLength, const int charsetSize, const double passBitStrength, const char* charsetAdvice);