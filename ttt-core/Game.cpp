#include "stdafx.h"
#include "Game.h"

Game::Game(Board& board)
{
	currentBoard = &board;
	activePlayer = 'x';
}

Game::~Game() {}

void Game::MakeMove(int position)
{
	*currentBoard = currentBoard->PlaceMark(position, activePlayer);
	SwitchPlayers();
}

vector<char> Game::GetBoardState()
{
	return currentBoard->GetState();
}

bool Game::IsOver()
{
	return currentBoard->IsWon() || currentBoard->IsDrawn();
}

void Game::SwitchPlayers()
{
	if (activePlayer == 'x')
		activePlayer = 'o';
	else
		activePlayer = 'x';
}
