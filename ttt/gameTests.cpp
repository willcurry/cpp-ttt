#include "pch.h"
#include "Game.h"
#include "Board.h"
#include "gmock/gmock.h"

using namespace testing;

TEST(Game, MakeMoveUpdatesBoard) {
	Board board;
	Game game(board);
	game.MakeMove(0);
	ASSERT_EQ(board.GetBoard()[0], 'x');
}