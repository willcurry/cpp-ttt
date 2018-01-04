#include "stdafx.h"
#include "ConsoleGameType.h"

ConsoleGameType::ConsoleGameType(ostream &output, istream &input) : output(output), input(input) {}

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
