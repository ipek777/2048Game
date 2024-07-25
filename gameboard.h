#pragma once
#include <iostream>
using namespace std;

const int MAX_BOARD_SIZE = 10, MIN_BOARD_SIZE = 4;

bool checkSize(int size);
int** createBoard(int size);
void freeBoard(int** board, int size);
void print(int** board, int size);