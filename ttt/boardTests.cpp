#include "pch.h"
#include "Board.h"
#include "gmock/gmock.h"

using namespace testing;

void MakeXWinRow(Board& board) {
	board.MakeMove(0);
	board.MakeMove(8);
	board.MakeMove(1);
	board.MakeMove(7);
	board.MakeMove(2);
}

void MakeXWinColumn(Board& board) {
	board.MakeMove(0);
	board.MakeMove(1);
	board.MakeMove(3);
	board.MakeMove(8);
	board.MakeMove(6);
}

void MakeXWinRightDiagonal(Board& board) {
	board.MakeMove(0);
	board.MakeMove(1);
	board.MakeMove(4);
	board.MakeMove(6);
	board.MakeMove(8);
}

void MakeXWinLeftDiagonal(Board& board) {
	board.MakeMove(2);
	board.MakeMove(1);
	board.MakeMove(4);
	board.MakeMove(8);
	board.MakeMove(6);
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
	MakeXWinRow(board);
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, WinningColumn) {
	Board board;
	MakeXWinColumn(board);
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, WinningRightDiagonal) {
	Board board;
	MakeXWinRightDiagonal(board);
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, WinningLeftDiagonal) {
	Board board;
	MakeXWinLeftDiagonal(board);
	ASSERT_TRUE(board.IsWon());
}

TEST(Board, KnowsWhenThereIsNoWinner) {
	Board board;
	board.MakeMove(2);
	board.MakeMove(1);
	ASSERT_FALSE(board.IsWon());
}