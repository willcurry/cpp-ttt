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

bool Board::HasWinningRow()
{
	for (int i = 0; i < 9; i = i + 3) {
		int count = 0;
		char player;
		for (int j = i; j < i + 3; j++) {
			player = board[j];
			if (PositionIsEmpty(j)) break;
			if (board[j] == player) {
				count++;
			}
		}
		if (count == 3) return true;
	}
	return false;
}

bool Board::HasWinningDiagonal()
{
	return HasWinningRightDiagonal() || HasWinningLeftDiagonal();
}

bool Board::HasWinningRightDiagonal()
{
	int count = 0;
	char player = board[0];
	for (int i = 0; i < 3; i++) {
		int position = i * 3 + i;
		if (PositionIsEmpty(position)) break;
		if (board[position] == player) {
			count++;
		}
	}
	if (count == 3) return true;
	else return false;
}

bool Board::HasWinningLeftDiagonal()
{
	int count = 0;
	char player = board[2];
	for (int i = 3; i > 0; i--) {
		int position = i * 3 - i;
		if (PositionIsEmpty(position)) break;
		if (board[position] == player) {
			count++;
		}
	}
	if (count == 3) return true;
	else return false;
}

bool Board::HasWinningColumn()
{
	for (int i = 0; i < 3; i++) {
		int count = 0;
		char player;
		for (int j = i; j < 9; j = j + 3) {
			player = board[j];
			if (PositionIsEmpty(j)) break;
			if (board[j] == player) {
				count++;
			}
		}
		if (count == 3) return true;
	}
	return false;
}

bool Board::PositionIsEmpty(int position)
{
	return board[position] == '-';
}

bool Board::IsWon()
{
	return HasWinningRow() || HasWinningColumn() || HasWinningDiagonal();
}

void Board::SwitchPlayers()
{
	if (activePlayer == 'x') {
		activePlayer = 'o';
	} else {
		activePlayer = 'x';
	}
}
