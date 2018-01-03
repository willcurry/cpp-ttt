#include "pch.h"
#include "TestUtils.h"


TestUtils::TestUtils()
{
}


TestUtils::~TestUtils()
{
}

vector<char> TestUtils::CreateBoardState()
{
	vector<char> board(9);
	for (int i = 0; i < 9; i++)
		board[i] = '-';
	return board;
}

vector<char> TestUtils::CreateBoardStateWithMarks(vector<int> positions, char mark)
{	
	vector<char> board(9);
	board = CreateBoardState();
	for (int i = 0; i < positions.size(); i++) {
		board[positions[i]] = mark;
	}
	return board;
}