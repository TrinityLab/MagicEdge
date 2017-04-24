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
public:
	static std::string userName;
	static int score;
	static void SaveScore();
	static vector<Result> LoadScores();
};