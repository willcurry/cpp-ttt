#pragma once
#include <vector>

using std::vector;

class GameType
{
public:
	GameType();
	~GameType();
	void DisplayBoard(vector<char> state);
};

