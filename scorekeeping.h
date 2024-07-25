#pragma once
#include <iostream>
#include <fstream>

using namespace std; 

int getScore(int** board, int size);
void writeScoreToFile(const string& filename, int score, const string& nickname);
void putScoreinFile(int size, int score, const string& nickname);