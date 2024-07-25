#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "gameboard.h"
using namespace std;

const int leaderboardSize = 5;

unsigned charCountBeforeDelim(const string& str, char delim);
bool isBiggerScore(const string& candidate, const string& fromLeaderboard);
int spotInTop5(const string& candidate, const string* array);
void putInTop5(string* arr, int spotOnBoard, const string& candidate);
void storeFromFileToArr(string* arr, ifstream& file);
void getScoresFromFile(const string& filename, string* arr);
void printLeaderboard(const string* arr);
void showLeaderboard();