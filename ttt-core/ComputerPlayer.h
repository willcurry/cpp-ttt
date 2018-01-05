#pragma once
#include "Player.h"
#include "Board.h"

class ComputerPlayer : public Player
{
public:
	ComputerPlayer(char mark);
	~ComputerPlayer();
	int NextMove(Board& board);
private:
	char OppositeMark();
	vector<int> AvailablePositions(Board& board);
};
