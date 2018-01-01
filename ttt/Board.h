#pragma once
#include <vector>

using std::vector;

class Board
{
public:
	Board();
	~Board();
	vector<char> GetBoard();
	void MakeMove(int position);
	bool HasWinningRow();
	bool HasWinningColumn();
	bool PositionIsEmpty(int position);
private:
	void SwitchPlayers();
};

