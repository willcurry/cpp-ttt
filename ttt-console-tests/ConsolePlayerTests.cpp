#include "..\ttt-console\ConsolePlayer.h"
#include "..\ttt-core\Game.h"
#include "..\ttt-test-utilities\TestUtils.h"
#include "tests.h"

TEST(ConsolePlayer, KnowsNextMovesFromStream) {
	std::stringstream stream;
	stream << "1";
	ConsolePlayer player('x', stream);
	Board board(TestUtils::CreateBoardState());
	EXPECT_EQ(player.NextMove(board), 1);
}

TEST(ConsolePlayer, DoesntLetYouGoInInvalidPositions) {
	std::stringstream stream;
	stream << "0";
	stream << "1";
	ConsolePlayer playerOne('x', stream);
	ConsolePlayer playerTwo('o', stream);
	vector<int> positions;
	positions.push_back(0);
	Board board(TestUtils::CreateBoardStateWithMarks(positions, 'o'));
	Game game(board, playerOne, playerTwo);
	game.MakeMove();
	EXPECT_EQ(game.GetBoardState()[0], 'o');
	EXPECT_EQ(game.GetBoardState()[1], 'x');
}