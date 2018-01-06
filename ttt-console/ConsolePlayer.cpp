#include "stdafx.h"
#include "ConsolePlayer.h"

ConsolePlayer::ConsolePlayer(char mark, istream& input) : Player(mark), input(input) {}

ConsolePlayer::~ConsolePlayer()
{
}

int ConsolePlayer::NextMove(Board& board)
{
	int userInput;
	input >> userInput;
	if (board.PositionIsEmpty(userInput)) {
		return userInput;
	}
	return NextMove(board);
}
