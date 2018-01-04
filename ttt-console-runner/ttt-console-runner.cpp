#include "stdafx.h"
#include "..\ttt-console\ConsoleGameType.h"
#include <iostream>
#include <vector>

using std::vector;

vector<char> EmptyBoardState() {
	vector<char> state(9);
	for (int i = 0; i < 9; i++) {
		state[i] = '-';
	}
	return state;
}

int main()
{
	Board board(EmptyBoardState());
	Game game(board);
	ConsoleGameType consoleGame(game, std::cout, std::cin);
	consoleGame.Start();
    return 0;
}

