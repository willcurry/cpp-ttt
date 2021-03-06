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
	Player playerOne('x');
	Player playerTwo('o');
	Game game(board, playerOne, playerTwo);
	ConsoleGameType consoleGame(game, std::cout);
	consoleGame.Start();
    return 0;
}

