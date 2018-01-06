#include "stdafx.h"
#include "ConsoleGameType.h"

ConsoleGameType::ConsoleGameType(Game game, ostream &output) : game(game), output(output) {}

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
		game.MakeMove();
	}
}
