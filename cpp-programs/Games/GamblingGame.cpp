//Write a program that allows you(the gambler) to make a series of £1
//bets, starting with £50, and continue to play until you either go broke(i.e.lose all
//your money) or win £250.Your program should use a random number generator to
//simulate tosses of a coin(0’s for Heads and 1 for Tails).Assume you make the £1
//bets for Tails.Every time the toss comes up Tail you win £1, every time it comes up
//Head you lose £1 and continue to play until you win a total of £250 or until you do
//not have any more money to bet. I'm gonna add feature to play game 1000 times and a feature to
//change starting and final amount

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void onStart(int&, int&, int&);
int menu();
void selection(int&);
void decision(int&, int&, int&);
void game(int&, int&, int&);
bool diceroll();
void settings(int&, int&, int&);
void thousand(int&, int&, int&);
void reboot(int&, int&, int&);
void startGameText(int&, int&);
void coinTosses(int&, int&, int&); // there is a fine line between good modular programming practice and having too many fns that do small things
// I crossed that fine line. Also many of my parameters do not have to be reference parameters. This is bad practice cuz it means they can be changed
// when I don't want them to

int main()
{
	srand(static_cast<unsigned int>(time(0))); 
	int choice = 0; 
	int startingCash = 50, winningCash = 250;
	onStart(choice, startingCash, winningCash);
	system("pause");
}

void onStart(int& option, int& startingCash, int& winningCash)
{
	selection(option);
	decision(option, startingCash, winningCash);
}

int menu()
{
	int choice;
	cout << "You are playing the GAMBLING GAME! Please select an option:\n";
	cout << "1. Play game\n";
	cout << "2. Change default starting and winning cash\n";
	cout << "3. Simulate 1000 games and get statistics\n";
	cout << "4. Exit\n\n";
	cin >> choice;
	return choice;
}

void selection(int& num)
{
	num = menu();
}

void decision(int& number, int& startingCash, int& winningCash)
{
	switch (number)
	{
	case 1: game(number, startingCash, winningCash);
		break;
	case 2: settings(number, startingCash, winningCash);
		break;
	case 3: thousand(number, startingCash, winningCash);
		break;
	case 4:
		break;
	default: cout << "\nInvalid selection\n\n";
		reboot(number, startingCash, winningCash);
	}
}

void game(int& numvar, int& startingCash, int& winningCash)
{
	int counter = 0;
	const int originalStartingCash = startingCash;
	startGameText(startingCash, winningCash);
	coinTosses(startingCash, winningCash, counter);
	cout << "The game is over after " << counter << " coin tosses\n\n";
	if (startingCash == winningCash)
	{
		cout << "Congratulations!!! You won the game!\n\n";
	}
	else
	{
		cout << "You are out of cash, sorry\n\n";
	}
	startingCash = originalStartingCash; 
		reboot(numvar, startingCash, winningCash);
}

bool diceroll()
{
	if (rand() % 2) return true;
	return false;
}

void settings(int& numbvar, int& startingCash, int& winningCash)
{
	cout << "\nInput desired value for starting cash\n";
	cin >> startingCash;
	cout << "Input desired value for winning cash\n";
	cin >> winningCash;
	reboot(numbvar, startingCash, winningCash);
}

void thousand(int& novar, int& startingCash, int& winningCash)
{
	int count = 0, wins = 0, losses = 0;
	const int initialStartingCash = startingCash;
	startGameText(startingCash, winningCash);
	for (size_t i = 0; i < 1000; i++)
	{
		coinTosses(startingCash, winningCash, count);
		if (startingCash == 0) losses++;
		else wins++;
		startingCash = initialStartingCash;
	}
	cout << "\n\nSTATISTICS\n\n";
	cout << "The game was simulated 1000 times\n";
	cout << wins << " games were won and " << losses << " games were lost\n";
	cout << "The probability of winning the game is " << (static_cast<double>(wins) / (wins + losses)) * 100 << " times out of 100\n\n\n";
	reboot(novar, startingCash, winningCash);
}

void reboot(int& no, int& startingCash, int& winningCash)
{
	cout << "Returning to menu...\n\n";
	onStart(no, startingCash, winningCash);
}

void startGameText(int& startingCash, int& winningCash)
{
	cout << "\nStarting game...\n\n";
	cout << "Starting Cash: " << startingCash << endl;
	cout << "Cash needed to win: " << winningCash << endl << endl;
	cout << "You are playing for heads. Tossing coins...\n\n";
}

void coinTosses(int& startingCash, int& winningCash, int& ctr)
{
	while (startingCash != 0 && startingCash != winningCash) // not best way to put the condition with negation. I'm like while it's not 0 and not winning cash keep playing. Better if I say while it's between 0 and the winning cash and avoid the negation. Why better? cuz if by mistake I start cash at -10, it would let me play as it's not 0 or winning cash. 
	{
		bool diceResult = diceroll();
		if (diceResult) startingCash++;
		else startingCash--;
		ctr++;
	}
}