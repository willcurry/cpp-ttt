#include "stdafx.h"
#include "Game.h"

Game::Game(Board &board, Player& playerOne, Player& playerTwo) : 
	currentBoard(&board), 
	activePlayer(&playerOne), 
	inactivePlayer(&playerTwo) {}
Game::~Game() {}

void Game::MakeMove()
{
	*currentBoard = currentBoard->PlaceMark(activePlayer->NextMove(), activePlayer->GetMark());
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
	Player currentPlayer = *activePlayer;
	activePlayer = inactivePlayer;
	inactivePlayer = &currentPlayer;
}
