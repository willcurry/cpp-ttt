#include "..\ttt-core\Game.h"
#include "..\ttt-test-utilities\TestUtils.h"
#include "tests.h"

TEST(Game, MakeMoveUpdatesBoard) {
	Board board(TestUtils::CreateBoardState());
	Game game(board);
	game.MakeMove(0);
	ASSERT_EQ(game.GetBoardState()[0], 'x');
}

TEST(Game, SwitchesPlayersAfterMove) {
	Board board(TestUtils::CreateBoardState());
	Game game(board);
	game.MakeMove(0);
	game.MakeMove(1);
	ASSERT_EQ(game.GetBoardState()[1], 'o');
}

TEST(Game, KnowsWhenItsOver) {
	vector<int> rowWin;
	rowWin.push_back(0);
	rowWin.push_back(1);
	rowWin.push_back(2);
	Board board(TestUtils::CreateBoardStateWithMarks(rowWin, 'x'));
	Game game(board);
	ASSERT_TRUE(game.IsOver());
}