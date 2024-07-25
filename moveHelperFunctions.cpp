#include "moveHelperFunctions.h"

//a function which returns the index of the first non zero element
int rightFirstNonZero(int** board, int i, int j, int size) {
	while (!board[i][j] && j != 0)
	{
		j--;
	}
	return j;
}

void rightMergeEmptySpots(int** board, int size, int i) {
	for (int j = size - 1; j >= 0; j--)
	{
		if (board[i][j] == 0) {
			int index = rightFirstNonZero(board, i, j, size);
			board[i][j] = board[i][index];
			board[i][index] = 0;
		}
	}
}

//a function which merges the same elements
void rightMergeSame(int** board, int size, int i) {
	for (int j = size - 1; j >= 0; j--)
	{
		if (board[i][j] != 0)
		{
			if (board[i][j] == board[i][j - 1])
			{
				board[i][j] *= 2;
				board[i][j - 1] = 0;
			}
		}

	}
}

void swap(int& first, int& second) {
	int temp = first;
	first = second;
	second = temp;
}

void flipHorizontally(int** board, int size) {
	for (int i = 0; i < size; i++) {
		int j = 0;
		while (j < size / 2) {
			swap(board[i][j], board[i][size - 1 - j]);
			j++;
		}
	}
}

void flipByDiagonal(int** board, int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++) {
			if (i != j)
			{
				swap(board[i][j], board[j][i]);
			}

		}
	}
}

//a function which checks if a move is valid
bool isValidMoveRight(int** board, int size, int i) {
	for (int j = 0; j < size - 1; ++j) {
		// checking if the current tile is not empty
		if (board[i][j] != 0) {
			// checking if the tile to the right is either empty or has the same value
			if (board[i][j + 1] == 0 || board[i][j + 1] == board[i][j]) {
				return true;
			}
		}
	}
	return false;
}