#include "stdafx.h"
#include "ConsolePlayer.h"

ConsolePlayer::ConsolePlayer(char mark, istream& input) : Player(mark), input(input) {}

ConsolePlayer::~ConsolePlayer()
{
}

int ConsolePlayer::NextMove()
{
	int userInput;
	input >> userInput;
	return userInput;
}
