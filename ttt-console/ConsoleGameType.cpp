#include "stdafx.h"
#include "ConsoleGameType.h"

ConsoleGameType::ConsoleGameType(Game game, ostream &output, istream &input) : output(output), input(input), game(game) {}

ConsoleGameType::~ConsoleGameType()
{
}

void ConsoleGameType::DisplayBoard()
{
	string board;
	for (int i = 0; i < game.GetBoardState().size(); i++) {
		board += game.GetBoardState()[i];
	}
	output << board;
}

void ConsoleGameType::Start()
{
	while (!game.IsOver()) {
		DisplayBoard();
		int userInput;
		input >> userInput;
		game.MakeMove(userInput);
	}
}
