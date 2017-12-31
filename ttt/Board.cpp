#include "pch.h"
#include "Board.h"

vector<char> board(9);
char activePlayer;

Board::Board()
{
	for (int i = 0; i < 9; i++) {
		board[i] = '-';
	}
	activePlayer = 'x';
}


Board::~Board()
{
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

void Board::SwitchPlayers()
{
	if (activePlayer == 'x') {
		activePlayer = 'o';
	} else {
		activePlayer = 'x';
	}
}
