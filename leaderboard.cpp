#include "leaderboard.h"

unsigned charCountBeforeDelim(const string& str, char delim)
{
	unsigned result = 0;
	for (char ch : str) {
		if (ch == delim) {
			break;
		}
		result++;
	}
	return result;
}

//a function which compares scores from the leaderboard with scores from the file
bool isBiggerScore(const string& candidate, const string& fromLeaderboard) {
	int index = 0;
	unsigned lenCandidate = charCountBeforeDelim(candidate, ' '), lenFromLeaderboard = charCountBeforeDelim(fromLeaderboard, ' ');

	if (lenCandidate > lenFromLeaderboard)
	{
		return true;
	}
	if (lenCandidate == lenFromLeaderboard)
	{
		while (candidate[index] != ' ')
		{
			if (candidate[index] > fromLeaderboard[index])
			{
				return true;
			}
			else if (candidate[index] < fromLeaderboard[index])
			{
				return false;
			}
			index++;
		}
	}

	return false;
}

//checks if the candidate score is bigger than any of the scores on the leadearboard and it returns the spot of the candidate on the leadeboard
int spotInTop5(const string& candidate, const string* array) {
	int index = 0;
	while (index < leaderboardSize)
	{
		if (isBiggerScore(candidate, array[index])) {
			return index;
		}
		index++;
	}
	return -1; //if the candidate isn't bigger than anything on the leaderboard it returns -1
}

//moves everything to the right and puts the candidate at the appropriate spot.
void putInTop5(string* arr, int spotOnBoard, const string& candidate) {
	for (int j = leaderboardSize - 2; j >= spotOnBoard; j--)
	{
		arr[j + 1] = arr[j];
	}
	arr[spotOnBoard] = candidate;
}

//puts the top 5 scores in an array
void storeFromFileToArr(string* arr, ifstream& file) {
	string candidate;
	while (getline(file, candidate))
	{
		int spotOnLeaderboard = spotInTop5(candidate, arr);
		if (spotOnLeaderboard != -1) {       //if the candidate belongs on the leaderboard 
			putInTop5(arr, spotOnLeaderboard, candidate);
		}
	}
}

//a function which reads scores from a file
void getScoresFromFile(const string& filename, string* arr) {
	ifstream file(filename);
	if (!file.is_open())
	{
		cout << "No scores are available currently for this dimensions." << endl;
		return;
	}

	storeFromFileToArr(arr, file);
	file.close();
}

void printLeaderboard(const string* arr) {
	for (int i = 1; i <= leaderboardSize; i++)
	{
		if (!arr)
		{
			return;
		}
		if (arr[i - 1] == "\0")
		{
			return;
		}
		cout << i << ". " << arr[i - 1] << endl;
	}
}

//a function which shows the leaderboard according to the dimensions of the board
void showLeaderboard() {
	char sizeInput;
	int size;
	string arr[leaderboardSize];

	cout << "Check Leaderboard for dimensions: ";
	do
	{
		cin >> sizeInput;
		size = (int)sizeInput - '0';
		switch (size)
		{
		case 4:
			getScoresFromFile("Leaderboard_4.txt", arr);
			printLeaderboard(arr);
			break;
		case 5:
			getScoresFromFile("Leaderboard_5.txt", arr);
			printLeaderboard(arr);
			break;
		case 6:
			getScoresFromFile("Leaderboard_6.txt", arr);
			printLeaderboard(arr);
			break;
		case 7:
			getScoresFromFile("Leaderboard_7.txt", arr);
			printLeaderboard(arr);
			break;
		case 8:
			getScoresFromFile("Leaderboard_8.txt", arr);
			printLeaderboard(arr);
			break;
		case 9:
			getScoresFromFile("Leaderboard_9.txt", arr);
			printLeaderboard(arr);
			break;
		case 10:
			getScoresFromFile("Leaderboard_10.txt", arr);
			printLeaderboard(arr);
			break;
		default: cout << "Enter valid dimensions!" << endl;
			break;
		}
	} while (!checkSize(size));

}