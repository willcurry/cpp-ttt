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
private:
	void SwitchPlayers();
};

