#include "gameboard.h"

bool checkSize(int size) { 
	return size >= MIN_BOARD_SIZE && size <= MAX_BOARD_SIZE;  
}   

int** createBoard(int size) {
	if (!checkSize(size))
	{
		return nullptr;
	}
	int** board = new int* [size];
	for (int i = 0; i < size; i++)
	{
		board[i] = new int[size] {0};
	}
	return board;
}

void freeBoard(int** board, int size) {
	if (!board)
	{
		return;
	}
	for (int i = 0; i < size; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}

void print(int** board, int size)
{
	if (!board)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << board[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}