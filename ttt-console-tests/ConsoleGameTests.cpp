#include "..\ttt-console\ConsoleGameType.h"
#include "..\ttt-test-utilities\TestUtils.h"
#include "tests.h"

TEST(ConsoleGame, DisplaysBoard) {
	std::stringstream output;
	ConsoleGameType consoleGame(output);
	consoleGame.DisplayBoard(TestUtils::CreateBoardState());
	EXPECT_EQ(output.str(), "---------");
}