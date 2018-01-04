#include "stdafx.h"
#include "ConsoleGameType.h"

ConsoleGameType::ConsoleGameType(Game game, ostream &output, istream &input) : output(output), input(input), game(game) {}

ConsoleGameType::~ConsoleGameType()
{
}

void ConsoleGameType::DisplayBoard(vector<char> state)
{
	string board;
	for (int i = 0; i < state.size(); i++) {
		board += state[i];
	}
	output << board;
}

void ConsoleGameType::Start()
{
}
