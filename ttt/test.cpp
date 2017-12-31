#include "pch.h"
#include "Board.h"
#include "gmock/gmock.h"

using namespace testing;

TEST(Board, BoardIsCreated) {
	Board board;
	ASSERT_THAT(board.GetBoard(), ElementsAre(
		'-', '-', '-', 
		'-', '-', '-', 
		'-', '-', '-'));
}

TEST(Board, MoveIsMade) {
	Board board;
	board.MakeMove(0);
	ASSERT_EQ(board.GetBoard()[0], 'x');
}

TEST(Board, PlayerSwitches) {
	Board board;
	board.MakeMove(0);
	board.MakeMove(1);
	ASSERT_EQ(board.GetBoard()[0], 'x');
	ASSERT_EQ(board.GetBoard()[1], 'o');
}