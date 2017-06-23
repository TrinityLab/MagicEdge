#pragma once

#include <string>
#include <vector>

using namespace std;

struct Result
{
	int score;
	string name;
};

class ScoreTable
{
private:
	static int score;

public:
	static std::string userName;
	static void SaveScore();
	static vector<Result> LoadScores();
	static void SendScore(int score);
};