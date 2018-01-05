#include "stdafx.h"
#include "Board.h"
#include "Combinations.h"

Board::Board(vector<char> state, int size, char lastMove)
{
	this->state = state;
	this->size = size;
	this->lastMove = lastMove;
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
	vector<char> newState(state);
	newState[position] = mark;
	Board newBoard(newState, this->size, mark);
	return newBoard;
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

char Board::GetLastMove()
{
	return this->lastMove;
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

bool Board::IsDrawn()
{
	for (int i = 0; i < state.size(); i++) {
		if (PositionIsEmpty(i))
			return false;
	}
	return true;
}