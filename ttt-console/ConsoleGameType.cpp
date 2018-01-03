#include "stdafx.h"
#include "ConsoleGameType.h"

ConsoleGameType::ConsoleGameType()
{
}

ConsoleGameType::~ConsoleGameType()
{
}

void ConsoleGameType::DisplayBoard(vector<char> state, ostream& output)
{
	string board;
	for (int i = 0; i < state.size(); i++) {
		board += state[i];
	}
	output << board;
}
