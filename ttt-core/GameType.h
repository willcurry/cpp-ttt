#pragma once
#include <vector>
#include "Game.h"

using std::vector;

class GameType
{
public:
	GameType();
	~GameType();
	virtual void DisplayBoard(vector<char> state);
	virtual void Start();
};

