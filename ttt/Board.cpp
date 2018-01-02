#include "pch.h"
#include "Board.h"
#include "Combinations.h"

Board::Board()
{
	InitialiseBoard();
	activePlayer = 'x';
	Combinations combinations;
	winningFormations = combinations.GetAll();
}

Board::~Board()
{
}

void Board::InitialiseBoard()
{
	board.resize(9);
	for (int i = 0; i < 9; i++)
		board[i] = '-';
}

vector<char> Board::GetBoard()
{
	return board;
}

void Board::MakeMove(int position)
{
	if (board[position]) {
		board[position] = activePlayer;
	}
	SwitchPlayers();
}

bool Board::ContainsOnlyOnePlayer(vector<int> positions)
{
	char player = board[positions[0]];
	for (int i = 0; i < positions.size(); i++) {
		int position = positions[i];
		if (PositionIsEmpty(position) || board[position] != player)
			return false;
	}
	return true;
}

bool Board::PositionIsEmpty(int position)
{
	return board[position] == '-';
}

bool Board::IsWon()
{
	for (int i = 0; i < winningFormations.size(); i++) {
		for (int j = 0; j < winningFormations[i].size(); j++) {
			if (ContainsOnlyOnePlayer(winningFormations[i][j]))
				return true;
		}
	}
	return false;
}

void Board::SwitchPlayers()
{
	if (activePlayer == 'x') {
		activePlayer = 'o';
	} else {
		activePlayer = 'x';
	}
}