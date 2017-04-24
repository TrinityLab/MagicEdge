#include "ScoreTable.h"
#include <stdio.h>

int ScoreTable::score = 0;
std::string ScoreTable::userName;

void ScoreTable::SaveScore()
{
	FILE* file;

	if (fopen_s(&file, "scores.txt", "at+") != 0)
		return;

	fprintf_s(file, "%s %d\n", userName.c_str(), score);

	fclose(file);

	int count;

	if (fopen_s(&file, "scoresCount.txt", "rt") != 0)
		count = 0;
	else
	{
		fscanf_s(file, "%d", &count);

		fclose(file);
	}

	if (fopen_s(&file, "scoresCount.txt", "wt") != 0)
		return;

	fprintf_s(file, "%d\n", count + 1);

	fclose(file);
}

vector<Result> ScoreTable::LoadScores()
{
	vector<Result> results;

	FILE* file;

	if (fopen_s(&file, "scores.txt", "rt") != 0)
		return results;

	int scoresCount;

	FILE* file2;
	if (fopen_s(&file2, "scoresCount.txt", "rt") != 0)
		return results;

	fscanf_s(file2, "%d", &scoresCount);

	fclose(file2);

	int i = 0;
	while (i < scoresCount)
	{
		Result r;
		char str[100] = {};
		int score;

		if (fscanf_s(file, "%s", str, 100) < 1)
			break;

		if (fscanf_s(file, "%d", &score) < 1)
			break;

		r.name = str;
		r.score = score;

		results.push_back(r);

		i++;
	}

	fclose(file);

	return results;
}