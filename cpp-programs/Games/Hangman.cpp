// @hb20007

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int numberOfWords = 6;

int wordPicker();
int stringSize(const char wordToGuess[]); // the 'const' here is a must cuz we're gonna pass a const array to it (and it's automatically passed by ref so the fun should not be allowed to change it)
void hangman(); 
void onVictory(int wrongGuesses, bool &endGameFlag);
void stickMan(int wrongGuesses, bool &endGameFlag, const char foodCyprus[]);
void setElementsToZero(bool array[], const int length);
void guessValidation(char &guess, bool alphabet[]);
bool checkForVictory(bool *feedbackArr, const int size);
void evaluateGuess(bool *feedbackArr, const char *word, char guessMade, int &mistakes, const int size);
void displayAlphabet(bool *alphabetArr);
void updateAlphabet(bool *alphabetArr, char guessMade);
void displayStars(bool *feedbackArr, const char *word, const int size);
void startGame();

int wordPicker()
{
	return (rand() % numberOfWords );
}

int stringSize(const char wordToGuess[])
{
	int i;
	for (i = 0; wordToGuess[i] != '\0'; i++);
	return i;
}

void hangman()
{
	int wrongGuesses = 0;
	bool endGameFlag = 0;
	char guess;
	const int index = wordPicker(), startingLives = 6;
	const char *foodCyprus[numberOfWords] = { "halloumi", "souvlaki", "soutzoukos", "melomakarona", "tzatziki", "seftalies" };
	// note if u do cout << *foodCyprus[0];      this line couts the letter 'h', but cout << foodCyprus[0]; couts halloumi
	const int wordLength = stringSize(foodCyprus[index]);
	bool *feedback, alphabet[27] = { 0 };
	feedback = new bool[wordLength];
	setElementsToZero(feedback, wordLength);
	while (!endGameFlag)
	{
		displayAlphabet(alphabet);
		cout << "\nLives: " << startingLives - wrongGuesses;
		cout << "\nGuess the word: ";
		displayStars(feedback, foodCyprus[index], wordLength);
		cout << "Type a letter: > ";
		cin >> guess;
		guessValidation(guess, alphabet);
		evaluateGuess(feedback, foodCyprus[index], guess, wrongGuesses, wordLength);
		updateAlphabet(alphabet, guess);
		cout << endl;
		stickMan(wrongGuesses, endGameFlag, foodCyprus[index]);
		if (checkForVictory(feedback, wordLength))
		{
			onVictory(wrongGuesses, endGameFlag);
		}
	}
	delete[] feedback;
	//cout << "Returning to menu...\n\n\n";
	system("pause"); // creates a little intermission
	system("cls"); // NB it's cls not clr
	startGame();
}

void onVictory(int wrongGuesses, bool &endGameFlag)
{
	cout << "\nCongratulations! You won.\n";
	if (wrongGuesses == 0) cout << "You made no wrong guesses   \\ (^-^) /\n";
	endGameFlag = 1;
}

void stickMan(int wrongGuesses, bool &endGameFlag, const char word[])
{
	switch (wrongGuesses)
	{
	case 0:
		break;
	case 1:
		cout << "\t O\n";
		break;
	case 2:
		cout << "\t O\n";
		cout << "\t |\n";
		break;
	case 3:
		cout << "\t O\n";
		cout << "\t/|\n";
		break;
	case 4:
		cout << "\t O\n";
		cout << "\t/|\\ \n";
		break;
	case 5:
		cout << "\t O\n";
		cout << "\t/|\\ \n";
		cout << "\t/ \n";
		break;
	default:
		cout << "\t O\n";
		cout << "\t/|\\ \n";
		cout << "\t/ \\ \n";
		cout << "You ran out of guesses :(\n";
		cout << "The word was: " << word << endl;
		endGameFlag = 1;
	}
}

void setElementsToZero(bool array[], const int length)
{
	for (int i = 0; i < length; i++)
	{
		array[i] = 0;
	}
//instead of this using fill or fill_n from the algorithm lib does not work... seems ppl us. use it with the vector lib
}

void guessValidation(char &guess, bool alphabet[])
{
	while (!((guess >= 97) && (guess <= 122) && (alphabet[static_cast<int>(guess - 97)] == 0)))
	{
		//if ((static_cast<int>(guess) <= 90) && (static_cast<int>(guess) >= 65)) guess = static_cast<char>(guess + 32); old code
		if ((static_cast<int>(guess) <= 90) && (static_cast<int>(guess) >= 65)) guess = tolower(guess);
		else if (alphabet[static_cast<int>(guess - 97)] == 1)
		{
			cout << "You have tried this letter before. Please insert another one: > ";
			cin >> guess;
		}
		else
		{
			cout << "That is not a letter. Please insert a letter: > ";
			cin >> guess;
		}
	}
}

bool checkForVictory(bool *feedbackArr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		if (feedbackArr[i] == 0) return false;
	}
	return true;
	//strcpy and strcmp cannot be used here cuz they are for strings not bool arrays
}

void evaluateGuess(bool *feedbackArr, const char *word, char guessMade, int &mistakes, const int size)
{
	bool badGuess = 1;
	for (int i = 0; word[i] != '\0'; i++)
	{
		if (guessMade == word[i])
		{
			feedbackArr[i] = 1;
			badGuess = 0;
		}
	}
	if (badGuess == 1)  mistakes++;
	else cout << "Good guess!\n"; 
}

void displayAlphabet(bool *alphabetArr)
{
	cout << "\n\t\t\ta b c d e f g h i j k l m n o p q r s t u v w x y z\n";
	cout << "\t\t\t";
	for (int i = 0; i < 26; i++)
	{
		if (alphabetArr[i] == 1) cout << "* ";
		else cout << "  ";
	}
}

void updateAlphabet(bool *alphabetArr, char guessMade)
{
	alphabetArr[static_cast<int>(guessMade)-97] = 1;
}

void displayStars(bool *feedbackArr, const char *word, const int size)
{
	for (int i = 0; i < size ; i++)
	{
		if (feedbackArr[i]==0) cout << "*";
		else cout << word[i];
	}
	cout << endl;
}

void startGame()
{
	char selection; //note char is better than int for the menu selection cuz if it's int and they insert a char the program will go into an infinite loop, here with the help of a validation the program will ensure the right input is achieved.
	cout << "WELCOME TO HANG-MAN \n(Category: Cypriot food)\n\n";
	cout << "1 - Start game\n";
	cout << "2 - Quit\n\n> ";
	cin >> selection;
	switch (selection)
	{
	case '1':  // note the need of the ' ' around the 1 cuz selection is a char
		hangman(); 
		break;
	case '2': 
		break;
	default: 
		cout << "\nPlease insert a valid selection. Re-initializing...\n\n";
		startGame();
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0))); // Static cast used to avoid warning about implicit data type conversion
	startGame();
	system("pause");
}
