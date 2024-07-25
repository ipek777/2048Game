#include "randomNumberGeneration.h"

//a function which checks for empty spots on the board
bool isEmpty(int** board, int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == 0)
				return true;
		}
	}
	return false;
}

int randomIndex(int size) {
	int index;
	index = rand() % size + 0;
	return index;
}

//a function which adds 2 or 4 on a random spot on the board
void addNum(int** board, int size) {
	int i = randomIndex(size);
	int j = randomIndex(size);
	if (board[i][j] == 0)
	{
		//randomly generating 2 or 4
		int randomNum = randomIndex(10);
		if (randomNum <= 5) {
			board[i][j] = 2;
		}
		else {
			board[i][j] = 4;
		}
	}
}