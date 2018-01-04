#include "..\ttt-console\ConsoleGameType.h"
#include "..\ttt-test-utilities\TestUtils.h"
#include "tests.h"

TEST(ConsoleGame, DisplaysBoard) {
	std::stringstream stream;
	Board board(TestUtils::CreateBoardState());
	Game game(board);
	ConsoleGameType consoleGame(game, stream, stream);
	consoleGame.DisplayBoard();
	EXPECT_EQ(stream.str(), "---------");
}