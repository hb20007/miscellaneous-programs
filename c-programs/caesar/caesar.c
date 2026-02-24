/**
 * @file caesar.c
 * @author hb20007
 * @date 04/03/2017
 * @brief Uses command line arguments to implement Caesar encryption,
 * decryption, brute-force attack, and informed brute-force attack
 */

#include "caesar.h"
#include <ctype.h> // For isupper(), tolower(), etc.
#include <errno.h> // Defines macros for reporting and retrieving error conditions through error codes stored in a static memory location called "errno".
#include <limits.h>  // For LONG_MAX and LONG_MIN
#include <stdbool.h> // For the macros bool, true, and false
#include <stdio.h>
#include <stdlib.h> // For EXIT_FAILURE, EXIT_SUCCESS, and strtol() (There is no strtoi().)
#include <string.h>

int mod(const int a, const int b) {
  if (b < 0)
    return mod(a, -b);

  int ret = a % b;
  if (ret < 0)
    ret += b;
  return ret;
}

char caesarShift(const char toShift, const int shiftVal) {
  if (isalpha(toShift) == 0)
    return toShift;

  int charIndex;
  int aValue;
  if (islower(toShift))
    aValue = 97; // 'a' ASCII = 97
  else
    aValue = 65; // 'A' ASCII = 65
  charIndex = toShift - aValue;

  return (char)(mod(charIndex + shiftVal, 26) + aValue); // NOSONAR
}

long parseShiftValue(const char *shiftAmount) {
  /* For validating the shift_value */
  char *endptr;
  errno = 0; // To distinguish success/failure after call

  long shiftValue = strtol(shiftAmount, &endptr, 10); // strtol() rejects the '.' character as required. The second argument is an address to store the location where the conversion stops. The last argument is the base.

  /* Check for various possible errors. */
  if ((errno == ERANGE && (shiftValue == LONG_MAX || shiftValue == LONG_MIN)) || // NOSONAR
      (errno != 0 && shiftValue == 0)) { // ERANGE is an error code implying the resulting value was out of range. If an underflow occurs, strtol() returns LONG_MIN. If an overflow occurs, strtol() returns LONG_MAX.
    perror("Error (strtol)"); // void perror(const char *str) prints a descriptive error message to stderr.
    exit(EXIT_FAILURE); // The error that would be printed here is "Result too large\n", etc.
  }
  if (endptr == shiftAmount) {
    fprintf(stderr,
            "Error (strtol): No digits were found in the shift value.\n");
    exit(EXIT_FAILURE);
  }
  if (*endptr != '\0') {
    fprintf(stderr,
            "Error (strtol): The non-numerical character(s) \"%s\" were "
            "detected after the shift value.\n",
            endptr);
    exit(EXIT_FAILURE);
  }

  return shiftValue;
}

void shiftAndPrint(const long caesarKey, const char *msg) {
  const char *ptr = msg;
  while (*ptr != '\0') {
    putchar(caesarShift(*ptr, caesarKey)); // putchar() writes a single char to stdout.
    ptr++;
  }
}

void encryptDecrypt(const char *mode, const char *shiftAmt,
                    const char *message) {
  long key = parseShiftValue(shiftAmt);

  /* If we got here, strtol() successfully parsed a number in parseShiftValue(). */
  if (key > 25 || key < 1) {
    fprintf(stderr,
            "Error: The shift value should be in the range [1, 25].\n"); // If a right shift of 3 is intended, just input -3 mod 26, which is 23.
    exit(EXIT_FAILURE);
  }

  /* The algorithm begins here. */
  if (strcmp(mode, "-d") == 0)
    key -= 2 * key;
  shiftAndPrint(key, message);
  printf("\n");
}

void bruteForceAttack(const char *ciphertext) {
  for (int i = 1; i < 26; i++) { // Loop through all possible key values.
    printf("Key: %d Plaintext: ", i);
    shiftAndPrint(i - 2 * i, ciphertext); // i - 2 * i because we are decrypting, so we need to shift to the left.
    printf("\n");
  }
}

void shiftCharsOnce(char *string) {
  for (char *ptr = string; *ptr != '\0'; ptr++)
    *ptr = caesarShift(*ptr, 1);
}

void dictionaryAttack(char *word, const char *ciphertext) {
  // Shifting the ciphertext every time and checking the output for the word is tedious, so instead, we shift the word for every possible key and see if it is contained in the ciphertext to determine the key.
  bool successFlag = false;
  for (int i = 1; i < 26; i++) {
    shiftCharsOnce(word);
    if (strstr(ciphertext, word)) { // strstr() in <cstring> takes two arguments, str1 and str2, and returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1. The null pointer is 0. So if(ptr) is true if ptr is not null.
      successFlag = true;
      printf("Success! Key: %d, Plaintext: ", i);
      shiftAndPrint(i - 2 * i, ciphertext);
      printf("\n");
    }
  }

  if (!successFlag) {
    shiftCharsOnce(word); // We get back the original word.
    printf("The string \"%s\" was not a substring of any plaintext for all "
           "possible shift values.\n",
           word);
  }
}


int main(int argc, char *argv[]) {
  if (argc < 3 || argc > 4) {
    fprintf(stderr,
            "Error: The program must be called with two or three arguments. Usage: "
            "\"caesar -e|-d|-a [offset|known_substring] <ciphertext>\"\n");
    exit(EXIT_FAILURE);
  }
  if (strcmp(argv[1], "-e") != 0 && strcmp(argv[1], "-d") != 0 &&
      strcmp(argv[1], "-a") != 0) {
    fprintf(stderr,
            "Error: \"%s\" is not a valid option. Valid options: \"-e\", \"-d\", "
            "and \"-a\"\n",
            argv[1]);
    exit(EXIT_FAILURE);
  }
  if ((strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "-e") == 0) &&
      argc != 4) { // I.e., if ((argv[1] == "-d" || argv[1] == "-e") && argc != 4
    fprintf(stderr,
            "Error: With \"%s\", the program must be called with three arguments.",
            argv[1]);
    exit(EXIT_FAILURE);
  }

  if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "-e") == 0)
    encryptDecrypt(argv[1], argv[2], argv[3]);
  else // if argv[1] == "-a"
    if (argc == 3) // If a substring is not specified
      bruteForceAttack(argv[2]);
    else // argc == 4
      dictionaryAttack(argv[2], argv[3]);

  return EXIT_SUCCESS;
}
