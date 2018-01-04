#pragma once
#include "Board.h"

class Game
{
public:
	Game(Board& board);
	~Game();
	void MakeMove(int position);
	vector<char> GetBoardState();
	bool IsOver();
private:
	void SwitchPlayers();
	Board *currentBoard;
	char activePlayer;
};

