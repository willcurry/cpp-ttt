#include "pch.h"
#include "Game.h"

Game::Game(Board& board)
{
	currentBoard = &board;
}

Game::~Game()
{
}

void Game::MakeMove(int position)
{
	currentBoard->MakeMove(position);
}
