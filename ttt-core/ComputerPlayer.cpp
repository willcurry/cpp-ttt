#include "stdafx.h"
#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(char mark) : Player(mark) {}

ComputerPlayer::~ComputerPlayer()
{
}

int ComputerPlayer::NextMove(Board& board)
{
	vector<int> positions = AvailablePositions(board);
	for (int i = 0; i < positions.size(); i++) {
		Board newBoard = board.PlaceMark(positions[i], OppositeMark());
		if (newBoard.IsWon()) {
			return positions[i];
		}
	}
	return positions[0];
}

char ComputerPlayer::OppositeMark()
{
	char mark = this->GetMark();
	if (mark == 'x')
		return 'o';
	else
		return 'x';
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
