#include "generateUI.h"

void generateUI()
{
	cout << "***************" << endl << "   * 2048 *" << endl << "***************" << endl << endl;
	cout << "1. Start game" << endl;
	cout << "2. Leaderboard" << endl;
	cout << "3. Quit" << endl << endl;

	char initialInput;
	int input;

	//a loop that asks for input until there is a valid one.
	while (true) {
		cout << "Press: 1 - to start the game, 2 - to see the leaderboard, 3 - to quit." << endl;
		cin >> initialInput;
		input = (int)initialInput - '0';
		system("CLS");

		switch (input)
		{
		case 1: startGame(); break;
		case 2: showLeaderboard(); break;
		case 3: return;
		default: cout << "Please enter a valid number." << endl; break;
		}
	}
}