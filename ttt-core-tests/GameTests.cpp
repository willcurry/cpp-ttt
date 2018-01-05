#include "..\ttt-core\Game.h"
#include "..\ttt-test-utilities\TestUtils.h"
#include "TestPlayer.h"
#include "tests.h"

TEST(Game, MakeMoveUpdatesBoard) {
	Board board(TestUtils::CreateBoardState());
	Player playerOne('x');
	Player playerTwo('o');
	Game game(board, playerOne, playerTwo);
	game.MakeMove();
	ASSERT_EQ(game.GetBoardState()[0], 'x');
}

TEST(Game, SwitchesPlayersAfterMove) {
	Board board(TestUtils::CreateBoardState());

	vector<int> playerOneMoves;
	playerOneMoves.push_back(0);
	TestPlayer playerOne('x', playerOneMoves);
	vector<int> playerTwoMoves;
	playerTwoMoves.push_back(1);
	TestPlayer playerTwo('o', playerTwoMoves);

	Game game(board, playerOne, playerTwo);
	game.MakeMove();
	game.MakeMove();
	ASSERT_EQ(game.GetBoardState()[1], 'o');
}

TEST(Game, KnowsWhenItsOver) {
	vector<int> rowWin;
	rowWin.push_back(0);
	rowWin.push_back(1);
	rowWin.push_back(2);
	Board board(TestUtils::CreateBoardStateWithMarks(rowWin, 'x'));
	Player playerOne('x');
	Player playerTwo('o');
	Game game(board, playerOne, playerTwo);
	ASSERT_TRUE(game.IsOver());
}