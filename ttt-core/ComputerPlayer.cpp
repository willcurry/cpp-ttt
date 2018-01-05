#include "stdafx.h"
#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(char mark) : Player(mark) {}

ComputerPlayer::~ComputerPlayer()
{
}

int ComputerPlayer::NextMove(Board& board)
{
	return AvailablePositions(board)[0];
}

vector<int> ComputerPlayer::AvailablePositions(Board& board)
{
	vector<int> positions;
	for (int i = 0; i < board.GetState().size(); i++) {
		if (board.PositionIsEmpty(i)) {
			positions.push_back(i);
		}
	}
	return positions;
}
