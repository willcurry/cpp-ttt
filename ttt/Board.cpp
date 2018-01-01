#include "pch.h"
#include "Board.h"

vector<char> board(9);
vector<vector<int>> rows;
vector<vector<int>> columns;
vector<vector<int>> diagonals;
char activePlayer;

Board::Board()
{
	rows.reserve(3);
	columns.reserve(3);
	diagonals.reserve(3);
	InitialiseBoard();
	activePlayer = 'x';
}

Board::~Board()
{
}

void Board::InitialiseBoard()
{
	for (int i = 0; i < 9; i++) {
		board[i] = '-';
	}
	InitialiseRows();
	InitialiseColumns();
	InitialiseDiagonals();
}

void Board::InitialiseRows()
{
	for (int i = 0; i < 9; i = i + 3) {
		vector<int> row;
		rows.reserve(3);
		for (int j = i; j < i + 3; j++) {
			row.push_back(j);
		}
		rows.push_back(row);
	}
}

void Board::InitialiseColumns()
{
	for (int i = 0; i < 3; i++) {
		vector<int> column;
		column.reserve(3);
		for (int j = i; j < 9; j = j + 3) {
			column.push_back(j);
		}
		columns.push_back(column);
	}
}

void Board::InitialiseDiagonals()
{
	InitialiseLeftDiagonal();
	InitialiseRightDiagonal();
}

void Board::InitialiseLeftDiagonal()
{
	vector<int> leftDiagonal;
	leftDiagonal.reserve(3);
	for (int i = 3; i > 0; i--) {
		int position = i * 3 - i;
		leftDiagonal.push_back(position);
	}
	diagonals.push_back(leftDiagonal);
}

void Board::InitialiseRightDiagonal()
{
	vector<int> rightDiagonal;
	rightDiagonal.reserve(3);
	for (int i = 0; i < 3; i++) {
		int position = i * 3 + i;
		rightDiagonal.push_back(position);
	}
	diagonals.push_back(rightDiagonal);
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

bool Board::HasWinningRow()
{
	for (int i = 0; i < rows.size(); i++) {
		if (ContainsOnlyOnePlayer(rows[i])) 
			return true;
	}
	return false;
}

bool Board::HasWinningColumn()
{
	for (int i = 0; i < columns.size(); i++) {
		if (ContainsOnlyOnePlayer(columns[i])) 
			return true;
	}
	return false;
}

bool Board::HasWinningDiagonal()
{
	for (int i = 0; i < diagonals.size(); i++) {
		if (ContainsOnlyOnePlayer(diagonals[i])) 
			return true;
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