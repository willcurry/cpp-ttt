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