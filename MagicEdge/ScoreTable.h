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
	static void AddScore(int score);
	static void SetScore(int score);
	static void SaveScore();
	static vector<Result> LoadScores();
};