#include "pch.h"
#include "Board.h"
#include "gmock/gmock.h"

using namespace testing;

void MakeXWin(Board board) {
	board.MakeMove(0);
	board.MakeMove(8);
	board.MakeMove(1);
	board.MakeMove(7);
	board.MakeMove(2);
}

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

TEST(Board, KnowIfAPositionIsEmpty) {
	Board board;
	board.MakeMove(0);
	ASSERT_FALSE(board.PositionIsEmpty(0));
}

TEST(Board, WinningRow) {
	Board board;
	MakeXWin(board);
	ASSERT_TRUE(board.HasWinningRow());
}

TEST(Board, KnowsWhenThereIsNoWinner) {
	Board board;
	board.MakeMove(2);
	board.MakeMove(1);
	ASSERT_FALSE(board.HasWinningRow());
}