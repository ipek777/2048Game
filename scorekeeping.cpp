#include "scorekeeping.h"

int getScore(int** board, int size) {
	int score = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			score += board[i][j];
		}
	}
	return score;
}
//a function which puts the score of the user in a file according to the dimensions of the board
void writeScoreToFile(const string& filename, int score, const string& nickname) {
	ofstream file(filename, ios::app);
	if (!file.is_open())
	{
		cout << "Unable to store score.";
		return;
	}
	file << score << " - " << nickname << endl;
	file.close();
}
void putScoreinFile(int size, int score, const string& nickname) {
	switch (size)
	{
	case 4:
		writeScoreToFile("Leaderboard_4.txt", score, nickname);
		break;
	case 5:
		writeScoreToFile("Leaderboard_5.txt", score, nickname);
		break;
	case 6:
		writeScoreToFile("Leaderboard_6.txt", score, nickname);
		break;
	case 7:
		writeScoreToFile("Leaderboard_7.txt", score, nickname);
		break;
	case 8:
		writeScoreToFile("Leaderboard_8.txt", score, nickname);
		break;
	case 9:
		writeScoreToFile("Leaderboard_9.txt", score, nickname);
		break;
	case 10:
		writeScoreToFile("Leaderboard_10.txt", score, nickname);
		break;
	default: cout << "Unable to store score.";
		break;
	}
}