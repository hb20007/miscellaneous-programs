/**
* @file caesar.h
* @author hb20007
* @date 04/03/2017
* @brief Header file for caesar.c, contains function prototypes
*/

/**
* @brief Modulus function (works with negative numbers)
* @param a The first integer
* @param b The second integer
* @return The result
*/
extern int mod (const int a, const int b);

/**
* @brief Shifts a character based on the shift value if it is a letter. Leaves it untouched if not.
* @param toShift The character
* @param shiftVal The value by which to offset the character
* @return The Caesar-shifted character
*/
extern char caesarShift(const char toShift, const int shiftVal);

/**
* @brief Converts the shift value from a string to a long and exits if there are any errors
* @param shiftAmount The shift value
* @return The shift value as a long integer
*/
extern long parseShiftValue(const char* shiftAmount);

/**
* @brief Shifts the message according to the key and prints the output
* @param caesarKey The shift value
* @param msg The message
*/
extern void shiftAndPrint(const long caesarKey, const char* msg);

/**
* @brief Performs the encryption and decryption functions of the program
* @param mode Indicates whether we are in encryption or decryption mode
* @param shiftAmt The amount by which to shift
* @param message The message to encrypt or decrypt
*/
extern void encryptDecrypt(const char* mode, const char* shiftAmt, const char* message);

/**
* @brief Performs a brute force attack with all possible shift values
* @param ciphertext The message to decrypt
*/
extern void bruteForceAttack(const char* ciphertext);

/**
* @brief Shifts the characters in the message to the right once
* @param string The message
*/
extern void shiftCharsOnce(char* string);

/**
* @brief Performs a dictionary attack with a particular word and all possible shift values
* @param word The dictionary word to check for in this function call
* @param ciphertext The message to decrypt
*/
extern void dictionaryAttack(char* word, const char* ciphertext);