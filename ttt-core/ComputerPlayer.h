#pragma once
#include "Player.h"
#include "Board.h"

class ComputerPlayer : public Player
{
public:
	ComputerPlayer(char mark);
	~ComputerPlayer();
	int NextMove(Board& board);
private:
	char OppositeMark(char mark);
	vector<int> Minimax(Board& board, char player, int depth);
	vector<int> AvailablePositions(Board& board);
	int Score(Board& board, char player, int depth);
	vector<int> NewScore(char player);
	vector<int> CreateScoredMove(int score, int move);
	bool IsBetterMove(char player, vector<int> scoredMove, int bestScore);
};

