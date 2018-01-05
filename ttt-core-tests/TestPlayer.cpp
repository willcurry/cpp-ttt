#include "TestPlayer.h"

TestPlayer::TestPlayer(char mark, vector<int> moves) : Player(mark) 
{
	this->moves = moves;
	this->nextPosition = -1;
}

TestPlayer::~TestPlayer() {}

int TestPlayer::NextMove()
{
	nextPosition++;
	return moves[nextPosition];
}
