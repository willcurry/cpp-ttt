#include "..\ttt-console\ConsoleGameType.h"
#include "..\ttt-test-utilities\TestUtils.h"
#include "tests.h"

TEST(ConsoleGame, DisplaysBoard) {
	std::stringstream stream;
	ConsoleGameType consoleGame(stream, stream);
	consoleGame.DisplayBoard(TestUtils::CreateBoardState());
	EXPECT_EQ(stream.str(), "---------");
}