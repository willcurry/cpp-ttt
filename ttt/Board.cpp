#include "pch.h"
#include "Board.h"

vector<char> board(9);

Board::Board()
{
	for (int i = 0; i < 9; i++) {
		board[i] = '-';
	}
}


Board::~Board()
{
}

vector<char> Board::GetBoard()
{
	return board;
}
