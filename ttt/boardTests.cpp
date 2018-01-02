#include "pch.h"
#include "Board.h"
#include "gmock/gmock.h"

using namespace testing;

void MakeXWinRow(Board& board) {
	board.PlaceMark(0);
	board.PlaceMark(8);
	board.PlaceMark(1);
	board.PlaceMark(7);
	board.PlaceMark(2);
}

void MakeXWinColumn(Board& board) {
	board.PlaceMark(0);
	board.PlaceMark(1);
	board.PlaceMark(3);
	board.PlaceMark(8);
	board.PlaceMark(6);
}

void MakeXWinRightDiagonal(Board& board) {
	board.PlaceMark(0);
	board.PlaceMark(1);
	board.PlaceMark(4);
	board.PlaceMark(6);
	board.PlaceMark(8);
}

void MakeXWinLeftDiagonal(Board& board) {
	board.PlaceMark(2);
	board.PlaceMark(1);
	board.PlaceMark(4);
	board.PlaceMark(8);
	board.PlaceMark(6);
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
	board.PlaceMark(0);
	ASSERT_EQ(board.GetBoard()[0], 'x');
}

TEST(Board, PlayerSwitches) {
	Board board;
	board.PlaceMark(0);
	board.PlaceMark(1);
	ASSERT_EQ(board.GetBoard()[0], 'x');
	ASSERT_EQ(board.GetBoard()[1], 'o');
}

TEST(Board, KnowIfAPositionIsEmpty) {
	Board board;
	board.PlaceMark(0);
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
	board.PlaceMark(2);
	board.PlaceMark(1);
	ASSERT_FALSE(board.IsWon());
}