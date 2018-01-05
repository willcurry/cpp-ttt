#include "stdafx.h"
#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(char mark) : Player(mark) {}

ComputerPlayer::~ComputerPlayer()
{
}

int ComputerPlayer::NextMove(Board& board)
{
	if (board.GetState()[0] == 'x' && board.GetState()[1] == 'x') {
		return 2;
	}
	return 0;
}