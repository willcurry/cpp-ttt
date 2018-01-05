#pragma once
#include <vector>

using std::vector;

class Board
{
public:
	Board(vector<char> state, int size = 3, char lastMove = '-');
	~Board();
	vector<char> GetState();
	Board PlaceMark(int position, char mark);
	bool PositionIsEmpty(int position);
	bool IsWon();
	bool IsDrawn();
	char GetLastMove();
private:
	bool ContainsOnlyOnePlayer(vector<int> row);
	vector<vector<vector<int>>> winningFormations;
	vector<char> state;
	int size;
	char lastMove;
};

