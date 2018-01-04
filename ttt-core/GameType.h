#pragma once
#include <vector>

using std::vector;

class GameType
{
public:
	GameType();
	~GameType();
	virtual void DisplayBoard(vector<char> state);
	virtual void Start();
};

