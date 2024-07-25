#pragma once
#include <string>
#include <ctime>
#include "gameboard.h"
#include "scorekeeping.h"
#include "moves.h" 
#include "randomNumberGeneration.h"
using namespace std;

void play(int** board, int size, const string& nickname);
void startGame();