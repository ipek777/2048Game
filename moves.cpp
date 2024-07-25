#include "moves.h"

bool moveRight(int** board, int size) {
	int validation = 0;

	for (int i = 0; i < size; i++)
	{
		if (isValidMoveRight(board, size, i))
		{
			rightMergeEmptySpots(board, size, i);
			rightMergeSame(board, size, i);
			rightMergeEmptySpots(board, size, i);
			//validation holds information about whether or not there are any valid moves on a row  
			validation++;
		}
	}
	//one valid row is enough for the whole movement to be considered valid
	return validation;
}

//flipping the matrix horizontally so I can reuse the merge right functions
bool moveLeft(int** board, int size) {
	flipHorizontally(board, size);
	bool validMove = moveRight(board, size);
	flipHorizontally(board, size);

	return validMove;
}

//flipping the matrix by its diagonal so I can reuse the merge right functions
bool moveDown(int** board, int size) {
	flipByDiagonal(board, size);
	bool validMove = moveRight(board, size);
	flipByDiagonal(board, size);

	return validMove;
}

//flipping the matrix horizontally and by its diagonal so I can reuse the merge right functions
bool moveUp(int** board, int size) {
	flipByDiagonal(board, size);
	flipHorizontally(board, size);
	bool validMove = moveRight(board, size);
	flipHorizontally(board, size);
	flipByDiagonal(board, size);

	return validMove;
}