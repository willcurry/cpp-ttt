#include "pch.h"
#include "Board.h"
#include "Combinations.h"

Board::Board(vector<char> state)
{
	this->state = state;
	Combinations combinations;
	winningFormations = combinations.GetAll();
}

Board::~Board(){}

vector<char> Board::GetState()
{
	return state;
}

Board Board::PlaceMark(int position, char mark)
{
	vector<char> newState(9);
	newState.swap(state);
	newState[position] = mark;
	Board board(newState);
	return board;
}

bool Board::ContainsOnlyOnePlayer(vector<int> positions)
{
	char player = state[positions[0]];
	for (int i = 0; i < positions.size(); i++) {
		int position = positions[i];
		if (PositionIsEmpty(position) || state[position] != player)
			return false;
	}
	return true;
}

bool Board::PositionIsEmpty(int position)
{
	return state[position] == '-';
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