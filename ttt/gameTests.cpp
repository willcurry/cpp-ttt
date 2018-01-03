#include "pch.h"
#include "Game.h"
#include "Board.h"
#include "gmock/gmock.h"
#include "TestUtils.h"

using namespace testing;

TEST(Game, MakeMoveUpdatesBoard) {
	Board board(TestUtils::CreateBoardState());
	Game game(board);
	game.MakeMove(0);
	ASSERT_EQ(board.GetState()[0], 'x');
}

TEST(Game, SwitchesPlayersAfterMove) {
	Board board(TestUtils::CreateBoardState());
	Game game(board);
	game.MakeMove(0);
	game.MakeMove(1);
	ASSERT_EQ(board.GetState()[1], 'o');
}