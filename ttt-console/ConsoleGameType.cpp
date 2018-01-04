#include "stdafx.h"
#include "ConsoleGameType.h"

ConsoleGameType::ConsoleGameType(ostream &output) : output(output){}

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
