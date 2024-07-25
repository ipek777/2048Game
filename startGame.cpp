#include "startGame.h"

void play(int** board, int size, const string& nickname) {
	cout << endl << "How to play: press w - to move upwards, d - to move to the right, s - to move downward, a - to move to the left." << endl
		<< "You can press 3 anytime to quit" << endl;

	char command;
	int score = getScore(board, size);
	cout << "Current score: " << score << endl;
	print(board, size);


	while (isEmpty(board, size)) {

		cin >> command;
		system("CLS");

		switch (command)
		{
		case 'w':
			if (moveUp(board, size))
			{
				// A loop to make sure a number is added.
				while (score == getScore(board, size))
				{
					addNum(board, size);
				}
			}
			break;
		case 'd':
			if (moveRight(board, size))
			{
				while (score == getScore(board, size))
				{
					addNum(board, size);
				}
			}
			break;
		case 's':
			if (moveDown(board, size))
			{
				while (score == getScore(board, size))
				{
					addNum(board, size);
				}
			}
			break;
		case 'a':
			if (moveLeft(board, size))
			{
				while (score == getScore(board, size))
				{
					addNum(board, size);
				}
			}
			break;
		case '3':
			putScoreinFile(size, score, nickname);
			return;
		default:
			cout << "Enter a valid direction!" << endl;
			break;
		}

		score = getScore(board, size);
		cout << "Current score: " << score << endl;
		print(board, size);

	}
	putScoreinFile(size, score, nickname);
}

void startGame() {
	string nickname;
	cout << "Enter nickname: ";
	cin >> nickname;

	char sizeInput;
	int size;
	do
	{
		cout << "Enter the size of the board (it should be between 4-10): ";
		cin >> sizeInput;
		size = (int)sizeInput - '0';

	} while (!checkSize(size));

	int** board = createBoard(size);

	srand(time(NULL));
	addNum(board, size);
	addNum(board, size);

	play(board, size, nickname);

	freeBoard(board, size);
}