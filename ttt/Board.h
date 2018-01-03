#pragma once
#include <vector>

using std::vector;

class Board
{
public:
	Board(vector<char> state);
	~Board();
	vector<char> GetState();
	void PlaceMark(int position, char mark);
	bool PositionIsEmpty(int position);
	bool IsWon();
private:
	bool ContainsOnlyOnePlayer(vector<int> row);

	vector<vector<vector<int>>> winningFormations;
	vector<char> state;
};

