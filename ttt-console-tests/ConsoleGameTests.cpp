#include "..\ttt-console\ConsoleGameType.h"
#include "ConsoleTests.h"

TEST(ConsoleGame, DisplaysBoard) {
	ConsoleGameType consoleGame;
	std::stringstream output;
	consoleGame.DisplayBoard(ConsoleTests::CreateBoardState(), output);
	EXPECT_EQ(output.str(), "---------");
}