#pragma once
#include <vector>
#include "Game.h"

using std::vector;

class GameType
{
public:
	GameType();
	~GameType();
	virtual void DisplayBoard();
	virtual void Start();
};

