#pragma once
#include <vector>

using std::vector;

class Board
{
public:
	Board();
	~Board();
	vector<char> GetBoard();
	void PlaceMark(int position, char mark);
	bool PositionIsEmpty(int position);
	bool IsWon();
private:
	void SwitchPlayers();
	bool ContainsOnlyOnePlayer(vector<int> row);
	void InitialiseBoard();

	vector<vector<vector<int>>> winningFormations;
	char activePlayer;

	vector<char> board;
};

