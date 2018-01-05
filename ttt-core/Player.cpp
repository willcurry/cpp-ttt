#include "stdafx.h"
#include "Player.h"


Player::Player(char mark)
{
	this->mark = mark;
}


Player::~Player()
{
}

char Player::GetMark()
{
	return this->mark;
}
