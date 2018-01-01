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
	bool PositionIsEmpty(int position);
	bool IsWon();
private:
	void SwitchPlayers();
	bool HasWinningColumn();
	bool HasWinningRow();
	bool HasWinningDiagonal();
};

