#pragma once
#include "Board.h"

class Player
{
public:
	Player(char mark);
	~Player();
	virtual char GetMark();
	virtual int NextMove(Board& board);
private:
	char mark;
};

