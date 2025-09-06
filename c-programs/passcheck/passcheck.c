/**
 * @file passcheck.c
 * @author hb20007
 * @date 05/03/2017
 * @brief Checks the strength of the given password
 */

#define _CRT_SECURE_NO_WARNINGS
#include "passcheck.h"
#include <limits.h>
#include <math.h> // For log2() and pow()
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strlen()

int getPassType(const char *pass) { // #lizard forgives
  bool charTypes[4] = {false}; // Lower case letter, upper case letter, digit, symbol
  for (const char *ptr = pass; *ptr != '\0'; ptr++) {
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
  else if ((charTypes[0] && charTypes[2] && charTypes[3]) ||
           (charTypes[1] && charTypes[2] && charTypes[3]))
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

char const *deduceCharsetSizeAndAdvice(const int passLength, const int passType,
                                       int *charsetSizePtr) {
  switch (passType) {
  case SINGLE_CASE_ALPHA:
    *charsetSizePtr = SINGLE_CASE_CHARSET_SIZE;
    return "Try varying the case of letters and including numbers and symbols.";
  case DOUBLE_CASE_ALPHA:
    *charsetSizePtr = 2 * SINGLE_CASE_CHARSET_SIZE;
    return "Try including numbers and symbols.";
  case DIGITS:
    *charsetSizePtr = DIGITS_CHARSET_SIZE;
    return "Try including letters and symbols.";
  case SINGLE_CASE_AND_DIGITS:
    *charsetSizePtr = SINGLE_CASE_CHARSET_SIZE + DIGITS_CHARSET_SIZE;
    return "Try varying the case of letters and including symbols.";
  case ALNUM:
    *charsetSizePtr = 2 * SINGLE_CASE_CHARSET_SIZE + DIGITS_CHARSET_SIZE;
    return "Try including symbols (e.g., '_', '-').";
  case SYMBOLS:
    *charsetSizePtr = SYMBOLS_CHARSET_SIZE;
    return "Try including letters and numbers.";
  case SINGLE_CASE_AND_SYMBOLS:
    *charsetSizePtr = SINGLE_CASE_CHARSET_SIZE + SYMBOLS_CHARSET_SIZE;
    return "Try varying the case of letters and including numbers.";
  case SINGLE_CASE_NUMBERS_SYMBOLS:
    *charsetSizePtr =
        SINGLE_CASE_CHARSET_SIZE + DIGITS_CHARSET_SIZE + SYMBOLS_CHARSET_SIZE;
    return "Try varying the case of letters used in the password.";
  case DOUBLE_CASE_AND_SYMBOLS:
    *charsetSizePtr = 2 * SINGLE_CASE_CHARSET_SIZE + SYMBOLS_CHARSET_SIZE;
    return "Try including numbers.";
  case DIGITS_AND_SYMBOLS:
    *charsetSizePtr = DIGITS_CHARSET_SIZE + SYMBOLS_CHARSET_SIZE;
    return "Try including letters.";
  default: // ALL
    *charsetSizePtr = 2 * SINGLE_CASE_CHARSET_SIZE + DIGITS_CHARSET_SIZE +
                      SYMBOLS_CHARSET_SIZE;
    // Password length check:
    if (passLength < 8)
      return "Try making your password longer.";
    if (passLength < 13)
      return "The password is fairly secure, and skilled hackers may need good "
             "computing power to crack it.\nTry making it longer for even "
             "extra security.";
    if (passLength < 25)
      return "The password is good enough to safely guard sensitive or "
             "financial information.";
    return "The password is virtually impossible to crack. Often, this level "
           "of security is overkill.";
  }
}

bool isCommonPassword(const char *pass) {
  FILE *fp = fopen(COMMON_PASS_FILE_NAME, "r"); // Flawfinder: ignore. The most straightforward way to read from a file in C is line by line, so the passwords in the file are separated by new lines.
  if (fp != NULL) { // For multiple fields of data. This can also be used for .csv: http://stackoverflow.com/questions/26443492/read-comma-separated-values-from-a-text-file-in-c
    char password[20]; // Flawfinder: ignore. 20 = Arbitrary max length
    while (fgets(password, sizeof password, fp) != NULL) {
      // Trick to remove trailing newline characters from fgets() input:
      size_t ln = strlen(password) - 1; // Flawfinder: ignore
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

void printResult(const char *passStrength, const bool isPasswordCommon,
                 const bool manySeconds, const bool tooManySeconds,
                 const int centuries, const int years, const int days,
                 const unsigned long long hours,
                 const unsigned long long minutes,
                 const unsigned long long secondsULL, const double seconds) {
  printf("Your password strength is %s.\n", passStrength);
  if (isPasswordCommon)
    printf("It can be cracked instantly.\n\n");
  else if (!manySeconds && !tooManySeconds)
    printf("It can be cracked in %f seconds on a modern processor.\n\n",
           seconds);
  else if (tooManySeconds)
    printf("Cracking this password would take hundreds of centuries on a "
           "modern processor.\n\n");
  else {
    printf("It can be cracked in ");
    if (centuries > 0)
      printf("%d centuries ", centuries);
    if (years > 0)
      printf("%d year(s) ", years);
    if (days > 0)
      printf("%d day(s) ", days);
    if (hours > 0)
      printf("%llu hour(s) ", hours);
    if (minutes > 0)
      printf("%llu minute(s) ", minutes);
    if (secondsULL > 0)
      printf("%llu second(s) ", secondsULL);
    printf("on a modern processor.\n\n");
  }
}

void printDetails(const char *pass, const int passLength, const int charsetSize,
                  const double passBitStrength, const char *charsetAdvice) {
  printf("DETAILS\n");
  printf("- Password: %s\n", pass);
  printf("- Password length: %d characters\n", passLength);
  printf("- Charset size: %d characters\n", charsetSize);
  printf("- Entropy: %.1f bits\n", passBitStrength);
  printf("- Advice: %s.\n", charsetAdvice);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(
        stderr,
        "Error: The program must be called with one argument, the password.\n");
    exit(EXIT_FAILURE);
  }

  const char *pass = argv[1];
  int passLength = static_cast<int>(strlen(pass)); // Flawfinder: ignore.
  int charsetSize = 0;
  const char *charsetAdvice = "temp"; // The arbitrary initialization here is a must because the pointer will be assigned a value later, and would otherwise have been pointing to a random place in memory. An alt to this is using malloc().
  int passType;
  bool isPasswordCommon = false;
  const char *passStrength = "temp";
  double entropy;
  double passBitStrength;
  double seconds;

  passType = getPassType(pass);

  int *charsetSizePtr = &charsetSize;
  charsetAdvice =
      deduceCharsetSizeAndAdvice(passLength, passType, charsetSizePtr);

  entropy = pow(charsetSize, passLength); // double is enough for passwords of length up to 8180 characters, which is the limit on Windows.
  passBitStrength = log2(entropy);
  seconds = entropy / KEYS_PER_SECOND;

  bool manySeconds = false; // Set to true if the time is more than 1 minute.
  bool tooManySeconds = false; // Set to true if the time in seconds is more than C can handle.

  unsigned long long secondsULL = 0;
  unsigned long long minutes = 0;
  unsigned long long hours = 0;
  int days = 0;
  int years = 0;
  int centuries = 0;

  if (seconds > static_cast<double>(ULLONG_MAX))
    tooManySeconds = true;
  else if (seconds >= 60.0) {
    manySeconds = true;
    secondsULL = (unsigned long long)seconds;
  }
  if (manySeconds && !tooManySeconds) {
    if (secondsULL >= SECONDS_IN_A_CENTURY) {
      centuries = static_cast<int>(secondsULL) / SECONDS_IN_A_CENTURY;
      secondsULL %= SECONDS_IN_A_CENTURY;
    }
    if (secondsULL >= SECONDS_IN_A_YEAR) {
      years = static_cast<int>(secondsULL) / SECONDS_IN_A_YEAR;
      secondsULL %= SECONDS_IN_A_YEAR;
    }
    if (secondsULL >= SECONDS_IN_A_DAY) {
      days = static_cast<int>(secondsULL) / SECONDS_IN_A_DAY;
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

  isPasswordCommon = isCommonPassword(pass);

  if (isPasswordCommon)
    passStrength = "VERY WEAK (COMMON PASSWORD)";
  else {
    int passwordScore = 0; // The passwordScore is my invention. It is a function of the password length and type.
    passwordScore += passLength;
    passwordScore += passType;

    if (passwordScore <= 10)
      passStrength = "WEAK";
    else if (passwordScore <= 17)
      passStrength = "MEDIUM";
    else
      passStrength = "STRONG";
  }

  printResult(passStrength, isPasswordCommon, manySeconds, tooManySeconds,
              centuries, years, days, hours, minutes, secondsULL, seconds);
  printDetails(pass, passLength, charsetSize, passBitStrength, charsetAdvice);
}
