#include "..\ttt-console\ConsoleGameType.h"
#include "..\ttt-test-utilities\TestUtils.h"
#include "tests.h"

TEST(ConsoleGame, DisplaysBoard) {
	std::stringstream stream;
	Board board(TestUtils::CreateBoardState());
	Player playerOne('x');
	Player playerTwo('o');
	Game game(board, playerOne, playerTwo);
	ConsoleGameType consoleGame(game, stream, stream);
	consoleGame.DisplayBoard();
	EXPECT_EQ(stream.str(), "---------");
}