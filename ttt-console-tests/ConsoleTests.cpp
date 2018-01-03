#include "ConsoleTests.h"

ConsoleTests::ConsoleTests()
{
}


ConsoleTests::~ConsoleTests()
{
}

vector<char> ConsoleTests::CreateBoardState()
{
	vector<char> board(9);
	for (int i = 0; i < 9; i++)
		board[i] = '-';
	return board;
}
