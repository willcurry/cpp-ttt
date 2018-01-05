#include "stdafx.h"
#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(char mark) : Player(mark) {}
ComputerPlayer::~ComputerPlayer() {}

int ComputerPlayer::NextMove(Board& board)
{
	return Minimax(board, this->GetMark(), 8)[1];
}

char ComputerPlayer::OppositeMark(char mark)
{
	if (mark == 'x')
		return 'o';
	else
		return 'x';
}

vector<int> ComputerPlayer::Minimax(Board& board, char player, int depth)
{
	vector<int> bestScoredMove = NewScore(player);
	if (board.IsWon() || board.IsDrawn() || depth == 0) {
		return CreateScoredMove(Score(board, player, depth), bestScoredMove[1]);
	}
	vector<int> positions = AvailablePositions(board);
	for (int i = 0; i < positions.size(); i++) {
		Board newBoard = board.PlaceMark(positions[i], player);
		vector<int> scoredMove = Minimax(newBoard, OppositeMark(player), depth - 1);
		if (IsBetterMove(player, scoredMove, bestScoredMove[0])) {
			bestScoredMove = CreateScoredMove(scoredMove[0], positions[i]);
		}
	}
	return bestScoredMove;
}

vector<int> ComputerPlayer::AvailablePositions(Board& board)
{
	vector<int> positions;
	for (int i = 0; i < board.GetState().size(); i++) {
		if (board.PositionIsEmpty(i)) {
			positions.push_back(i);
		}
	}
	return positions;
}

int ComputerPlayer::Score(Board & board, char player, int depth)
{
	if (board.IsWon()) {
		if (board.GetLastMove() == this->GetMark())
			return depth;
		else
			return -depth;
	}
	return 0;
}

vector<int> ComputerPlayer::NewScore(char player)
{
	vector<int> newScore(2);
	if (player == this->GetMark())
		newScore[0] = -1000;
	else
		newScore[0] = 1000;
	newScore[1] = -1;
	return newScore;
}

vector<int> ComputerPlayer::CreateScoredMove(int score, int move)
{
	vector<int> scoredMove;
	scoredMove.push_back(score);
	scoredMove.push_back(move);
	return scoredMove;
}

bool ComputerPlayer::IsBetterMove(char player, vector<int> scoredMove, int bestScore)
{
	if (player == this->GetMark()) {
		return scoredMove[0] > bestScore;
	}
	return scoredMove[0] < bestScore;
}
