#pragma once
#include "Board.h"
#include "Player.h"

class Game
{
public:
	Game(Board& board, Player& playerOne, Player& playerTwo);
	~Game();
	void MakeMove();
	vector<char> GetBoardState();
	bool IsOver();
private:
	void SwitchPlayers();
	Board* currentBoard;
	Player* activePlayer;
	Player* inactivePlayer;
};

