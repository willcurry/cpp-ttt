#include "pch.h"
#include "Board.h"

vector<char> board(9);
vector<vector<vector<int>>> winningFormations;
char activePlayer;

Board::Board()
{
	winningFormations.reserve(8);
	InitialiseBoard();
	activePlayer = 'x';
}

Board::~Board()
{
}

void Board::InitialiseBoard()
{
	for (int i = 0; i < 9; i++)
		board[i] = '-';
	InitialiseRows();
	InitialiseColumns();
	InitialiseDiagonals();
}

void Board::InitialiseRows()
{
	vector<vector<int>> rows;
	rows.reserve(3);
	for (int i = 0; i < 9; i = i + 3) {
		vector<int> row;
		row.reserve(3);
		for (int j = i; j < i + 3; j++) {
			row.push_back(j);
		}
		rows.push_back(row);
	}
	winningFormations.push_back(rows);
}

void Board::InitialiseColumns()
{
	vector<vector<int>> columns;
	columns.reserve(3);
	for (int i = 0; i < 3; i++) {
		vector<int> column;
		column.reserve(3);
		for (int j = i; j < 9; j = j + 3) {
			column.push_back(j);
		}
		columns.push_back(column);
	}
	winningFormations.push_back(columns);
}

void Board::InitialiseDiagonals()
{
	vector<vector<int>> diagonals;
	diagonals.reserve(2);
	diagonals.push_back(GetLeftDiagonal());
	diagonals.push_back(GetRightDiagonal());
	winningFormations.push_back(diagonals);
}

vector<int> Board::GetLeftDiagonal()
{
	vector<int> leftDiagonal;
	leftDiagonal.reserve(3);
	for (int i = 3; i > 0; i--) {
		int position = i * 3 - i;
		leftDiagonal.push_back(position);
	}
	return leftDiagonal;
}

vector<int> Board::GetRightDiagonal()
{
	vector<int> rightDiagonal;
	rightDiagonal.reserve(3);
	for (int i = 0; i < 3; i++) {
		int position = i * 3 + i;
		rightDiagonal.push_back(position);
	}
	return rightDiagonal;
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