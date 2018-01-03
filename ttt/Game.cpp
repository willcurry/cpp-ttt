#include "pch.h"
#include "Game.h"

Game::Game(Board& board)
{
	currentBoard = &board;
	activePlayer = 'x';
}

Game::~Game()
{
}

void Game::MakeMove(int position)
{
	currentBoard->PlaceMark(position, activePlayer);
	SwitchPlayers();
}

void Game::SwitchPlayers()
{
	if (activePlayer == 'x')
		activePlayer = 'o';
	else
		activePlayer = 'x';
}
