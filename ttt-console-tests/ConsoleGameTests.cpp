#include "..\ttt-console\ConsoleGameType.h"
#include "..\ttt-test-utilities\TestUtils.h"
#include "tests.h"

TEST(ConsoleGame, DisplaysBoard) {
	ConsoleGameType consoleGame;
	std::stringstream output;
	consoleGame.DisplayBoard(TestUtils::CreateBoardState(), output);
	EXPECT_EQ(output.str(), "---------");
}