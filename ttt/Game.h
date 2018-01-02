#pragma once
#include "Board.h"

class Game
{
public:
	Game(Board board);
	~Game();
	void MakeMove(int position);
};

