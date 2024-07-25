#pragma once

int rightFirstNonZero(int** board, int i, int j, int size);
void rightMergeEmptySpots(int** board, int size, int i);
void rightMergeSame(int** board, int size, int i);
void swap(int& first, int& second);
void flipHorizontally(int** board, int size);
void flipByDiagonal(int** board, int size);
bool isValidMoveRight(int** board, int size, int i);