#pragma once
#include "Board.h"

class Game
{
public:
	Game(Board& board);
	~Game();
	void MakeMove(int position);
	vector<char> GetBoardState();
private:
	void SwitchPlayers();
	Board *currentBoard;
	char activePlayer;
};

